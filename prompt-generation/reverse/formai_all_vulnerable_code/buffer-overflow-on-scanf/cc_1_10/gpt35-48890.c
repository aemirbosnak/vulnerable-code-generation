//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX 1000

// Structure to store bank record
struct record
{
    int account_no;
    char name[50];
    float balance;
    char date[20];
};

// Function to print record
void print_record(struct record r)
{
    printf("Account Number: %d\nName: %s\nBalance: %.2f\nLast Transaction Date: %s\n\n", r.account_no, r.name, r.balance, r.date);
}

// Function to add record
int add_record(int fd)
{
    struct record r;
    printf("Enter Account Number: ");
    scanf("%d", &r.account_no);
    printf("Enter Name: ");
    scanf("%s", r.name);
    printf("Enter Balance: ");
    scanf("%f", &r.balance);
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(r.date, sizeof r.date, "%c", tm);

    int n = write(fd, &r, sizeof(r));
    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }
    printf("Record added successfully!\n\n");
    return 1;
}

// Function to search record
int search_record(int fd)
{
    int acc_no;
    printf("Enter Account Number to search: ");
    scanf("%d", &acc_no);

    int n = lseek(fd, 0, SEEK_SET);
    
    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    struct record r;
    n = read(fd, &r, sizeof(r));

    while (n > 0)
    {
        if (r.account_no == acc_no)
        {
            printf("Record found!\n");
            print_record(r);
            return 1;
        }
        n = read(fd, &r, sizeof(r));
    }

    printf("Record not found!\n\n");    
    return 0;
}

// Function to display all records
int display_all_records(int fd)
{
    int n = lseek(fd, 0, SEEK_SET);
    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    struct record r;
    n = read(fd, &r, sizeof(r));

    while (n > 0)
    {
        print_record(r);
        n = read(fd, &r, sizeof(r));
    }

    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    return 1;
}

// Function to update record
int update_record(int fd)
{
    int acc_no;
    printf("Enter Account Number to update: ");
    scanf("%d", &acc_no);

    int n = lseek(fd, 0, SEEK_SET);

    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    struct record r;
    n = read(fd, &r, sizeof(r));

    while (n > 0)
    {
        if (r.account_no == acc_no)
        {
            printf("Record found!\n");
            printf("Enter new Name: ");
            scanf("%s", r.name);
            printf("Enter new Balance: ");
            scanf("%f", &r.balance);

            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            strftime(r.date, sizeof r.date, "%c", tm);

            lseek(fd, -sizeof(r), SEEK_CUR);
            n = write(fd, &r, sizeof(r));

            if (n == -1)
            {
                printf("Error %d: %s\n", errno, strerror(errno));
                return 0;
            }
            printf("Record updated successfully!\n");
            return 1;
        }
        n = read(fd, &r, sizeof(r));
    }

    printf("Record not found!\n\n");
    return 0;
}

// Function to delete record
int delete_record(int fd)
{
    int acc_no;
    printf("Enter Account Number to delete: ");
    scanf("%d", &acc_no);

    int n = lseek(fd, 0, SEEK_SET);

    if (n == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 0;
    }

    struct record r;
    n = read(fd, &r, sizeof(r));

    while (n > 0)
    {
        if (r.account_no == acc_no)
        {
            printf("Record found!\n");
            char choice;
            printf("Are you sure you want to delete this record? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y')
            {
                lseek(fd, -sizeof(r), SEEK_CUR);
                n = write(fd, "", sizeof(r));
                if (n == -1)
                {
                    printf("Error %d: %s\n", errno, strerror(errno));
                    return 0;
                }
                printf("Record deleted successfully!\n");
                return 1;
            }
            printf("Record not deleted!\n");
            return 0;
        }
        n = read(fd, &r, sizeof(r));
    }

    printf("Record not found!\n\n");
    return 0;
}

int main()
{
    int fd = open("bank_record.bin", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (fd == -1)
    {
        printf("Error %d: %s\n", errno, strerror(errno));
        return 1;
    }

    int choice;
    do
    {
        printf("========= Bank Record System =========\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_record(fd);
                break;
            case 2:
                search_record(fd);
                break;
            case 3:
                display_all_records(fd);
                break;
            case 4:
                update_record(fd);
                break;
            case 5:
                delete_record(fd);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice!\n\n");
        }
    } while (choice != 6);

    close(fd);

    return 0;
}