//FormAI DATASET v1.0 Category: Banking Record System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankRecord {
    char account_holder[30];
    int account_number;
    double balance;
    int password;
};

int main() {
    struct BankRecord records[100];
    int record_count = 0;
    
    int choice;
    printf("Welcome to the Medieval Bank Record System!\n");
    
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Create a new account\n");
        printf("2. Update an existing account\n");
        printf("3. Display all accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char holder[30];
                int number, password;
                double balance;
                
                printf("Enter account holder name: ");
                scanf("%s", holder);
                
                printf("Enter account number: ");
                scanf("%d", &number);
                
                printf("Enter initial balance: ");
                scanf("%lf", &balance);
                
                printf("Enter password: ");
                scanf("%d", &password);
                
                struct BankRecord new_record;
                strcpy(new_record.account_holder, holder);
                new_record.account_number = number;
                new_record.balance = balance;
                new_record.password = password;
                records[record_count++] = new_record;
                printf("New account created successfully!\n");
                break;
            }
            case 2: {
                int account_number, password, found = 0;
                
                printf("Enter account number: ");
                scanf("%d", &account_number);
                
                printf("Enter password: ");
                scanf("%d", &password);
                
                for (int i = 0; i < record_count; i++) {
                    if (records[i].account_number == account_number && records[i].password == password) {
                        printf("Account found! Enter the new balance: ");
                        scanf("%lf", &records[i].balance);
                        printf("Account balance updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                
                if (!found) {
                    printf("Invalid account number or password!\n");
                }
                break;
            }
            case 3: {
                printf("All accounts:\n\n");
                
                for (int i = 0; i < record_count; i++) {
                    printf("Account holder: %s\n", records[i].account_holder);
                    printf("Account number: %d\n", records[i].account_number);
                    printf("Balance: %.2lf\n\n", records[i].balance);
                }
                
                break;
            }
            case 4:
                printf("Thank you for using the Medieval Bank Record System!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
    }
    
    return 0;
}