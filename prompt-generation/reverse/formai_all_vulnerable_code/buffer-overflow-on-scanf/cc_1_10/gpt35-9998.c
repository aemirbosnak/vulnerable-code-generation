//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct bankRecord {
    int acc_no;
    char customer_name[30];
    float balance;
};

void addRecord(struct bankRecord records[], int *total_records) {
    printf("Enter Customer Name: ");
    scanf("%s", records[*total_records].customer_name);

    printf("Enter Account Number: ");
    scanf("%d", &records[*total_records].acc_no);
    
    printf("Enter Balance: ");
    scanf("%f", &records[*total_records].balance);

    (*total_records)++;
    printf("\nRecord Added.\n");
}

void showRecord(struct bankRecord record) {
    printf("\nCustomer Name: %s\n", record.customer_name);
    printf("Account Number: %d\n", record.acc_no);
    printf("Balance: %.2f\n", record.balance);
}

void displayAllRecords(struct bankRecord records[], int total_records) {
    printf("\nBank Records: \n");

    for (int i = 0; i < total_records; i++) {
        showRecord(records[i]);
    }
}

void searchRecord(struct bankRecord records[], int total_records) {
    int search_acc_no;
    printf("\nSearch by Account Number: ");
    scanf("%d", &search_acc_no);

    for (int i = 0; i < total_records; i++) {
        if (records[i].acc_no == search_acc_no) {
            showRecord(records[i]);
            return;
        }
    }

    printf("\nNo record found with Account Number: %d", search_acc_no);
}

void updateRecord(struct bankRecord records[], int total_records) {
    int update_acc_no;
    printf("\nUpdate by Account Number: ");
    scanf("%d", &update_acc_no);

    for (int i = 0; i < total_records; i++) {
        if (records[i].acc_no == update_acc_no) {
            printf("\nEnter new Customer Name: ");
            scanf("%s", records[i].customer_name);

            printf("Enter new Balance: ");
            scanf("%f", &records[i].balance);

            printf("\nRecord Updated.\n");
            return;
        }
    }

    printf("\nNo record found with Account Number: %d", update_acc_no);
}

void deleteRecord(struct bankRecord records[], int *total_records) {
    int delete_acc_no;
    printf("\nDelete by Account Number: ");
    scanf("%d", &delete_acc_no);

    for (int i = 0; i < *total_records; i++) {
        if (records[i].acc_no == delete_acc_no) {
            for (int j = i; j < (*total_records - 1); j++) {
                records[j] = records[j + 1];
            }
            (*total_records)--;
            printf("\nRecord Deleted.\n");
            return;
        }
    }

    printf("\nNo record found with Account Number: %d", delete_acc_no);
}

int displayMenu() {
    int option;

    printf("\n=================");
    printf("\nBank Record System");
    printf("\n=================\n");
    printf("1. Add Record\n");
    printf("2. Display All Records\n");
    printf("3. Search Record\n");
    printf("4. Update Record\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &option);

    return option;
}

int main() {
    struct bankRecord records[100];
    int total_records = 0;
    int option;

    while ((option = displayMenu()) != 6) {
        switch (option) {
            case 1:
                addRecord(records, &total_records);
                break;
            case 2:
                if (total_records > 0) {
                    displayAllRecords(records, total_records);
                } else {
                    printf("\nNo records found.\n");
                }
                break;
            case 3:
                if (total_records > 0) {
                    searchRecord(records, total_records);
                } else {
                    printf("\nNo records found.\n");
                }
                break;
            case 4:
                if (total_records > 0) {
                    updateRecord(records, total_records);
                } else {
                    printf("\nNo records found.\n");
                }
                break;
            case 5:
                if (total_records > 0) {
                    deleteRecord(records, &total_records);
                } else {
                    printf("\nNo records found.\n");
                }
                break;
            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}