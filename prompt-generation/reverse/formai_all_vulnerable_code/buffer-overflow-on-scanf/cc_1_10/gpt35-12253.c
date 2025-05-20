//FormAI DATASET v1.0 Category: Banking Record System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct banking_record {
    int acc_no;
    char name[50];
    float balance;
};

void display_menu() {
    printf("Banking Record System\n");
    printf("1. Add a new record\n");
    printf("2. Display all records\n");
    printf("3. Search for a record\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Exit\n");
}

void add_record(struct banking_record records[], int* count_ptr) {
    printf("Enter account number: ");
    scanf("%d", &records[*count_ptr].acc_no);
    printf("Enter name: ");
    scanf("%s", records[*count_ptr].name);
    printf("Enter balance: ");
    scanf("%f", &records[*count_ptr].balance);
    (*count_ptr)++;
}

void display_all_records(struct banking_record records[], int count) {
    printf("%-10s%-20s%-10s\n", "Acc No", "Name", "Balance");
    for (int i = 0; i < count; i++) {
        printf("%-10d%-20s%-10.2f\n", records[i].acc_no, records[i].name, records[i].balance);
    }
}

void search_record(struct banking_record records[], int count) {
    int acc_no;
    printf("Enter account number to search: ");
    scanf("%d", &acc_no);
    for (int i = 0; i < count; i++) {
        if (records[i].acc_no == acc_no) {
            printf("%-10s%-20s%-10s\n", "Acc No", "Name", "Balance");
            printf("%-10d%-20s%-10.2f\n", records[i].acc_no, records[i].name, records[i].balance);
            return;
        }
    }
    printf("Record not found!\n");
}

void update_record(struct banking_record records[], int count) {
    int acc_no;
    printf("Enter account number to update: ");
    scanf("%d", &acc_no);
    for (int i = 0; i < count; i++) {
        if (records[i].acc_no == acc_no) {
            printf("Enter name: ");
            scanf("%s", records[i].name);
            printf("Enter balance: ");
            scanf("%f", &records[i].balance);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

void delete_record(struct banking_record records[], int* count_ptr) {
    int acc_no;
    printf("Enter account number to delete: ");
    scanf("%d", &acc_no);
    for (int i = 0; i < *count_ptr; i++) {
        if (records[i].acc_no == acc_no) {
            memcpy(&records[i], &records[i + 1], (*count_ptr - i - 1) * sizeof(struct banking_record));
            (*count_ptr)--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    struct banking_record records[100];
    int count = 0, choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                display_all_records(records, count);
                break;
            case 3:
                search_record(records, count);
                break;
            case 4:
                update_record(records, count);
                break;
            case 5:
                delete_record(records, &count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 6);
    return 0;
}