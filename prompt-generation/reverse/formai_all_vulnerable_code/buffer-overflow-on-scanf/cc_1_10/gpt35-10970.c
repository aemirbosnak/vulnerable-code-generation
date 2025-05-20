//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    float price;
};

void add_record(struct Record records[], int *count)
{
    if (*count == MAX_RECORDS) {
        printf("Database is full, cannot add more records!\n");
        return;
    }

    struct Record new_record;
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    printf("Enter Name: ");
    scanf("%s", new_record.name);
    printf("Enter Price: ");
    scanf("%f", &new_record.price);

    records[*count] = new_record;
    *count += 1;

    printf("Record added successfully!\n");
}

void delete_record(struct Record records[], int *count, int id)
{
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            records[i] = records[i+1];
        }

        *count -= 1;
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void modify_record(struct Record records[], int *count, int id)
{
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter new Name: ");
        scanf("%s", records[index].name);
        printf("Enter new Price: ");
        scanf("%f", &records[index].price);

        printf("Record modified successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void print_records(struct Record records[], int count)
{
    printf("| %-10s | %-20s | %-10s |\n", "ID", "Name", "Price");
    printf("+------------+-----------------------+------------+\n");

    for (int i = 0; i < count; i++) {
        printf("| %-10d | %-20s | %-10.2f |\n", records[i].id, records[i].name, records[i].price);
    }

    printf("+------------+-----------------------+------------+\n");
}

int main()
{
    struct Record records[MAX_RECORDS];
    int count = 0;

    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Modify record\n");
        printf("4. Print records\n");
        printf("5. Exit\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                printf("Enter ID to delete: ");
                int id_to_delete;
                scanf("%d", &id_to_delete);
                delete_record(records, &count, id_to_delete);
                break;
            case 3:
                printf("Enter ID to modify: ");
                int id_to_modify;
                scanf("%d", &id_to_modify);
                modify_record(records, &count, id_to_modify);
                break;
            case 4:
                print_records(records, count);
                break;
            case 5:
                printf("Have a nice day! :)\n");
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }

    return 0;
}