//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int account_no;
    double balance;
    struct Record* next;
} Record;

Record* insert_record(Record* head) {
    Record* new_record = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", new_record->name);
    printf("Enter account number: ");
    scanf("%d", &new_record->account_no);
    printf("Enter balance: ");
    scanf("%lf", &new_record->balance);

    if (head == NULL) {
        head = new_record;
    } else {
        new_record->next = head;
        head = new_record;
    }

    return head;
}

void search_record(Record* head) {
    char search_name[50];
    int search_account_no;

    printf("Enter name: ");
    scanf("%s", search_name);

    printf("Enter account number: ");
    scanf("%d", &search_account_no);

    Record* current_record = head;

    while (current_record) {
        if (strcmp(current_record->name, search_name) == 0 && current_record->account_no == search_account_no) {
            printf("Name: %s\n", current_record->name);
            printf("Account Number: %d\n", current_record->account_no);
            printf("Balance: %.2lf\n", current_record->balance);
            break;
        }

        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    }
}

void update_record(Record* head) {
    char update_name[50];
    int update_account_no;
    double update_balance;

    printf("Enter name: ");
    scanf("%s", update_name);

    printf("Enter account number: ");
    scanf("%d", &update_account_no);

    printf("Enter new balance: ");
    scanf("%lf", &update_balance);

    Record* current_record = head;

    while (current_record) {
        if (strcmp(current_record->name, update_name) == 0 && current_record->account_no == update_account_no) {
            current_record->balance = update_balance;
            break;
        }

        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    } else {
        printf("Record updated.\n");
    }
}

void delete_record(Record* head) {
    char delete_name[50];
    int delete_account_no;

    printf("Enter name: ");
    scanf("%s", delete_name);

    printf("Enter account number: ");
    scanf("%d", &delete_account_no);

    Record* current_record = head;
    Record* previous_record = NULL;

    while (current_record) {
        if (strcmp(current_record->name, delete_name) == 0 && current_record->account_no == delete_account_no) {
            if (previous_record) {
                previous_record->next = current_record->next;
            } else {
                head = current_record->next;
            }
            free(current_record);
            break;
        }

        previous_record = current_record;
        current_record = current_record->next;
    }

    if (current_record == NULL) {
        printf("Record not found.\n");
    } else {
        printf("Record deleted.\n");
    }
}

int main() {
    Record* head = NULL;

    while (1) {
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert_record(head);
                break;
            case 2:
                search_record(head);
                break;
            case 3:
                update_record(head);
                break;
            case 4:
                delete_record(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        if (choice == 0) {
            break;
        }
    }

    return 0;
}