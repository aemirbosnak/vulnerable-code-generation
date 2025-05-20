//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char name[50];
    int account_number;
    float balance;
} Customer;

void create_account(Customer* customer);
void update_balance(Customer* customer);
void display_account(Customer customer);

int main() {
    Customer bank[50];
    int index = 0;
    int choice = 0;

    printf("Welcome to the Fun Bank Record System!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Create a New Account\n");
        printf("2. Update Account Balance\n");
        printf("3. Display Account Information\n");
        printf("4. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) == 0) {
            printf("Whoops, that's not a valid choice! Try again.\n");
        } else if (choice == 1) {
            create_account(&bank[index]);
            index++;
        } else if (choice == 2) {
            update_balance(&bank[index]);
        } else if (choice == 3) {
            display_account(bank[index]);
        } else if (choice == 4) {
            printf("Goodbye, thanks for using the Fun Bank Record System!\n");
            return 0;
        } else {
            printf("Whoops, that's not a valid choice! Try again.\n");
        }
    } while (1);

    return 0;
}

void create_account(Customer* customer) {
    printf("\nEnter customer name: ");
    scanf("%s", customer->name);

    if (strlen(customer->name) % 2 == 0) {
        printf("Sorry, we can only accept names with odd number of characters. Don't worry, we still love you.\n");
    }

    printf("Enter account number: ");
    scanf("%d", &customer->account_number);

    if (customer->account_number < 100 || customer->account_number > 500) {
        printf("Account number must be between 100 and 500, otherwise how we will guess it? Please try again.\n");
    }

    printf("Enter opening balance: ");
    scanf("%f", &customer->balance);

    if (customer->balance < 0) {
        printf("Uhhh, the opening balance cannot be negative. You know that right? Well, anyways we won't judge..much.\n");
    }
}

void update_balance(Customer* customer) {
    float deposit = 0;
    float withdraw = 0;

    printf("\nEnter deposit amount (0 to skip): ");
    scanf("%f", &deposit);

    printf("Enter withdraw amount (0 to skip): ");
    scanf("%f", &withdraw);

    if (abs(deposit) == abs(withdraw)) {
        printf("You can deposit or withdraw money, not both at the same time! Please try again.\n");
        return;
    }

    if (deposit < 0 || withdraw < 0) {
        printf("Transactions must have positive values, we can't give free money for now..sorry.\n");
        return;
    }

    customer->balance += deposit - withdraw;
    printf("Transaction completed. Your new balance is: %.2f\n", customer->balance);

    if (customer->balance < 0) {
        printf("Whoops, you are in debt! Don't worry, we won't send the mob after you..yet.\n");
    }
}

void display_account(Customer customer) {
    printf("\nCustomer Name: %s\n", customer.name);
    printf("Account Number: %d\n", customer.account_number);
    printf("Account Balance: %.2f\n", customer.balance);
}