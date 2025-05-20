//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000

typedef struct {
    char name[50];
    int acc_num;
    char branch[50];
    float balance;
} Record;

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    char option;

    // Display menu options
    printf("Welcome to the C Banking Record System!\n\n");
    printf("Choose an option:\n");
    printf("1. Add a record\n");
    printf("2. Search by account number\n");
    printf("3. Update a record\n");
    printf("4. Display all records\n");
    printf("5. Quit\n");

    do {
        printf("\nEnter your choice: ");
        scanf(" %c", &option);  // Allow only single character input
        switch (option) {
            case '1': {
                // Add a new record
                printf("\nEnter name: ");
                scanf("%s", records[num_records].name);
                printf("Enter account number: ");
                scanf("%d", &records[num_records].acc_num);
                printf("Enter branch: ");
                scanf("%s", records[num_records].branch);
                printf("Enter balance: ");
                scanf("%f", &records[num_records].balance);

                num_records++;
                printf("\nRecord added successfully!\n");
                break;
            }
            case '2': {
                // Search by account number
                int search_acc_num;
                printf("\nEnter account number: ");
                scanf("%d", &search_acc_num);

                // Linear search through records
                int i;
                for (i = 0; i < num_records; i++) {
                    if (records[i].acc_num == search_acc_num) {
                        printf("\nRecord Found!\n");
                        printf("Name: %s\n", records[i].name);
                        printf("Account Number: %d\n", records[i].acc_num);
                        printf("Branch: %s\n", records[i].branch);
                        printf("Balance: %.2f\n", records[i].balance);
                        break;
                    }
                }

                if (i == num_records) {
                    printf("\nRecord not found.\n");
                }
                break;
            }
            case '3': {
                // Update a record
                int update_acc_num;
                printf("\nEnter account number: ");
                scanf("%d", &update_acc_num);

                // Linear search through records
                int i;
                for (i = 0; i < num_records; i++) {
                    if (records[i].acc_num == update_acc_num) {
                        printf("\nEnter new name: ");
                        scanf("%s", records[i].name);
                        printf("Enter new branch: ");
                        scanf("%s", records[i].branch);
                        printf("Enter new balance: ");
                        scanf("%f", &records[i].balance);
                        printf("\nRecord updated successfully!\n");
                        break;
                    }
                }

                if (i == num_records) {
                    printf("\nRecord not found.\n");
                }
                break;
            }
            case '4': {
                // Display all records
                printf("\nRecords:\n");
                int i;
                for (i = 0; i < num_records; i++) {
                    printf("\nRecord %d:\n", i + 1);
                    printf("Name: %s\n", records[i].name);
                    printf("Account Number: %d\n", records[i].acc_num);
                    printf("Branch: %s\n", records[i].branch);
                    printf("Balance: %.2f\n", records[i].balance);
                }
                break;
            }
            case '5': {
                // Quit the program
                printf("\nThank you for using the C Banking Record System!\n");
                break;
            }
            default: {
                printf("\nInvalid Option!\n");
                break;
            }
        }
    } while (option != '5');
    
    return 0;
}