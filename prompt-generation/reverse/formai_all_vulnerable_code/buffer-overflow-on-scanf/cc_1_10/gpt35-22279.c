//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Record {
    char name[50];
    int account_number;
    int balance;
};

int main() {

    struct Record record[100];
    int choice, count = 0;

    while(1) {
        printf("Welcome to the Banking Record System\n");
        printf("1. Add Record\n");
        printf("2. View Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", record[count].name);
                printf("Enter account number: ");
                scanf("%d", &record[count].account_number);
                printf("Enter balance: ");
                scanf("%d", &record[count].balance);
                count++;
                break;
            case 2:
                if(count == 0) {
                    printf("No records found!\n");
                } else {
                    for(int i = 0; i < count; i++) {
                        printf("Name: %s\n", record[i].name);
                        printf("Account Number: %d\n", record[i].account_number);
                        printf("Balance: %d\n", record[i].balance);
                        printf("\n");
                    }
                }
                break;
            case 3:
                printf("Thank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}