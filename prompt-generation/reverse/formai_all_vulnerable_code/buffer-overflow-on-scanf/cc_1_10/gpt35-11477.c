//FormAI DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include<stdio.h>

//Define a structure to hold customer information
struct customer {
    char name[30];
    int accountNumber;
    float balance;
};

//Function to display menu and get user choice
int menu() {
    int choice;
    printf("\n\nBanking Record System\n");
    printf("1. Add a new customer\n");
    printf("2. View customer details\n");
    printf("3. Update customer balance\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    //Array to hold customer records
    struct customer customers[50];
    int count = 0;

    int choice;
    do {
        choice = menu();

        switch (choice) {
            case 1: //Add a new customer
                printf("\nAdd a new customer\n");
                printf("Enter name: ");
                scanf("%s", &customers[count].name);
                printf("Enter account number: ");
                scanf("%d", &customers[count].accountNumber);
                printf("Enter balance: ");
                scanf("%f", &customers[count].balance);
                count++;
                break;
            case 2: //View customer details
                printf("\nView customer details\n");
                printf("Enter account number: ");
                int accountNumber;
                scanf("%d", &accountNumber);
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (customers[i].accountNumber == accountNumber) {
                        printf("Name: %s\n", customers[i].name);
                        printf("Account Number: %d\n", customers[i].accountNumber);
                        printf("Balance: %.2f\n", customers[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Customer not found.\n");
                }
                break;
            case 3: //Update customer balance
                printf("\nUpdate customer balance\n");
                printf("Enter account number: ");
                int updateAccountNumber;
                scanf("%d", &updateAccountNumber);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (customers[i].accountNumber == updateAccountNumber) {
                        printf("Current balance of customer %s: %.2f\n", customers[i].name, customers[i].balance);
                        printf("Enter new balance: ");
                        scanf("%f", &customers[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Customer not found.\n");
                }
                break;
            case 4: //Exit
                printf("\nThank you for using Banking Record System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}