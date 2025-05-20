//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct record {
    int account_no;
    char name[50];
    float balance;
};

void menu() {
    printf("\n---Banking Record System---\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Modify Record\n");
    printf("4. Delete Record\n");
    printf("5. Display Record\n");
    printf("6. Exit\n");
    printf("---------------------------\n");
}

int get_record_count() {
    int count = 0;
    FILE *fp = fopen("record.txt", "r");
    if (fp == NULL) {
        return count;
    }
    struct record r;
    while (fread(&r, sizeof(r), 1, fp)) {
        count++;
    }
    fclose(fp);
    return count;
}

void add_record() {
    FILE *fp;
    struct record r;

    fp = fopen("record.txt", "a");

    printf("\nEnter Account No.: ");
    scanf("%d", &r.account_no);

    printf("Enter Name: ");
    scanf("%s", &r.name);

    printf("Enter Balance: ");
    scanf("%f", &r.balance);

    fwrite(&r, sizeof(r), 1, fp);
    fclose(fp);

    printf("\nRecord added successfully!\n");
}

void search_record() {
    FILE *fp;
    int found = 0;
    int account_no;
    struct record r;

    fp = fopen("record.txt", "r");

    printf("\nEnter Account No. to search: ");
    scanf("%d", &account_no);

    while (fread(&r, sizeof(r), 1, fp)) {
        if (r.account_no == account_no) {
            printf("\nRecord Found!\n");
            printf("Account No.: %d\n", r.account_no);
            printf("Name: %s\n", r.name);
            printf("Balance: %.2f\n", r.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found!\n");
    }

    fclose(fp);
}

void modify_record() {
    FILE *fp;
    int found = 0;
    int account_no;
    struct record r;

    fp = fopen("record.txt", "r+");

    printf("\nEnter Account No. to modify: ");
    scanf("%d", &account_no);

    while (fread(&r, sizeof(r), 1, fp)) {
        if (r.account_no == account_no) {
            printf("\nRecord Found!\n");
            printf("Account No.: %d\n", r.account_no);
            printf("Name: %s\n", r.name);
            printf("Balance: %.2f\n", r.balance);

            printf("\nEnter New Name: ");
            scanf("%s", &r.name);

            printf("Enter New Balance: ");
            scanf("%f", &r.balance);

            fseek(fp, -sizeof(r), SEEK_CUR);
            fwrite(&r, sizeof(r), 1, fp);
            found = 1;

            printf("\nRecord updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nRecord not found!\n");
    }

    fclose(fp);
}

void delete_record() {
    FILE *fp, *temp;
    int found = 0;
    int account_no;
    struct record r;

    fp = fopen("record.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Account No. to delete: ");
    scanf("%d", &account_no);

    while (fread(&r, sizeof(r), 1, fp)) {
        if (r.account_no == account_no) {
            printf("\nRecord Found!\n");
            printf("Account No.: %d\n", r.account_no);
            printf("Name: %s\n", r.name);
            printf("Balance: %.2f\n", r.balance);

            found = 1;
        } else {
            fwrite(&r, sizeof(r), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        printf("\nRecord not found!\n");
        remove("temp.txt");
    } else {
        remove("record.txt");
        rename("temp.txt", "record.txt");
        printf("\nRecord deleted successfully!\n");
    }
}

void display_record() {
    FILE *fp;
    int count = 0;
    struct record r;

    fp = fopen("record.txt", "r");

    printf("\n---All Records---\n");

    while (fread(&r, sizeof(r), 1, fp)) {
        printf("Account No.: %d\n", r.account_no);
        printf("Name: %s\n", r.name);
        printf("Balance: %.2f\n", r.balance);
        printf("------------------\n");
        count++;
    }

    if (count == 0) {
        printf("\nNo Records Found!\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                modify_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                display_record();
                break;
            case 6:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}