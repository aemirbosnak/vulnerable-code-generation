//FormAI DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int account_no;
    char name[50];
    float balance;
};

int main() {
    int option;
    struct Record *record;
    int num_records = 0;
    int i;

    do {
        printf("\n\n1. Create Record\n2. View Records\n3. Update Record\n4. Delete Record\n0. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                record = (struct Record *) malloc(sizeof(struct Record));
                printf("\nEnter account number: ");
                scanf("%d", &(record->account_no));
                printf("Enter name: ");
                scanf("%s", &(record->name));
                printf("Enter balance: ");
                scanf("%f", &(record->balance));
                num_records++;
                printf("\nRecord created successfully!\n");
                break;

            case 2:
                if (num_records == 0) {
                    printf("\nNo records found.\n");
                } else {
                    printf("\n%-15s %-15s %-15s\n", "Account No.", "Name", "Balance");

                    for (i = 0; i < num_records; i++) {
                        printf("%-15d %-15s %-15.2f\n", (record+i)->account_no, (record+i)->name, (record+i)->balance);
                    }
                }
                break;

            case 3:
                if (num_records == 0) {
                    printf("\nNo records found.\n");
                } else {
                    printf("\nEnter the account number of the record you want to update: ");
                    int account_no;
                    scanf("%d", &account_no);
                    int found = 0;

                    for (i = 0; i < num_records; i++) {
                        if ((record+i)->account_no == account_no) {
                            printf("Enter updated name: ");
                            scanf("%s", &(record+i)->name);
                            printf("Enter updated balance: ");
                            scanf("%f", &(record+i)->balance);
                            found = 1;
                            printf("\nRecord updated successfully!\n");
                            break;
                        }
                    }

                    if (!found) {
                        printf("\nRecord not found.\n");
                    }
                }
                break;

            case 4:
                if (num_records == 0) {
                    printf("\nNo records found.\n");
                } else {
                    printf("\nEnter the account number of the record you want to delete: ");
                    int account_no;
                    scanf("%d", &account_no);

                    for (i = 0; i < num_records; i++) {
                        if ((record+i)->account_no == account_no) {
                            if (i < num_records-1) {
                                memcpy(record+i, record+num_records-1, sizeof(struct Record));
                            }
                            num_records--;
                            printf("\nRecord deleted successfully!\n");
                            break;
                        }
                    }
                }
                break;

            case 0:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option.\n");
        }
    } while (option != 0);

    free(record);

    return 0;
}