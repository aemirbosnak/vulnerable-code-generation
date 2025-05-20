//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banking_record {
    char name[50];
    int account_no;
    float balance;
};

void print_record(struct banking_record r) {
    printf("Name: %s\n", r.name);
    printf("Account Number: %d\n", r.account_no);
    printf("Balance: $%.2f\n\n", r.balance);
}

int main() {
    struct banking_record records[100];
    int num_records = 0;
    int option;

    do {
        printf("Welcome to the C Banking Record System!\n");
        printf("1. Add a new record\n");
        printf("2. Edit an existing record\n");
        printf("3. Delete a record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                {
                    struct banking_record new_record;
                    printf("Enter name: ");
                    scanf("%s", new_record.name);
                    printf("Enter account number: ");
                    scanf("%d", &new_record.account_no);
                    printf("Enter balance: ");
                    scanf("%f", &new_record.balance);

                    records[num_records++] = new_record;

                    printf("Record added successfully!\n\n");
                }
                break;

            case 2:
                {
                    int search_account_no;
                    printf("Enter account number to search: ");
                    scanf("%d", &search_account_no);

                    int found_record_index = -1;
                    for(int i = 0; i < num_records; ++i) {
                        if(records[i].account_no == search_account_no) {
                            found_record_index = i;
                            break;
                        }
                    }

                    if(found_record_index == -1) {
                        printf("Record not found!\n\n");
                    } else {
                        struct banking_record new_record;
                        printf("Enter name: ");
                        scanf("%s", new_record.name);
                        printf("Enter account number: ");
                        scanf("%d", &new_record.account_no);
                        printf("Enter balance: ");
                        scanf("%f", &new_record.balance);

                        records[found_record_index] = new_record;

                        printf("Record edited successfully!\n\n");
                    }
                }
                break;

            case 3:
                {
                    int search_account_no;
                    printf("Enter account number to delete: ");
                    scanf("%d", &search_account_no);

                    int found_record_index = -1;
                    for(int i = 0; i < num_records; ++i) {
                        if(records[i].account_no == search_account_no) {
                            found_record_index = i;
                            break;
                        }
                    }

                    if(found_record_index == -1) {
                        printf("Record not found!\n\n");
                    } else {
                        for(int i = found_record_index; i < num_records - 1; ++i) {
                            records[i] = records[i + 1];
                        }
                        num_records--;
                        printf("Record deleted successfully!\n\n");
                    }
                }
                break;

            case 4:
                for(int i = 0; i < num_records; ++i) {
                    print_record(records[i]);
                }
                break;

            case 5:
                printf("Thank you for using the C Banking Record System!\n");
                break;

            default:
                printf("Invalid option! Please try again.\n\n");
                break;
        }
    } while(option != 5);

    return 0;
}