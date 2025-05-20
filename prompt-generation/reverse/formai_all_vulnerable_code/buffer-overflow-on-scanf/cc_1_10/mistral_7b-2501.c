//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
    time_t date;
} Transaction;

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0, choice;
    float totalBalance = 0.0;

    while (1) {
        printf("\n1. Add Transaction\n");
        printf("2. Display Transactions\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numTransactions >= MAX_TRANSACTIONS) {
                    printf("Error: Array is full.\n");
                    continue;
                }
                printf("Enter transaction description: ");
                scanf("%s", transactions[numTransactions].description);
                scanf("%*c"); // consume newline left by previous scanf
                printf("Enter transaction amount: ");
                scanf("%f", &transactions[numTransactions].amount);
                totalBalance += transactions[numTransactions].amount;
                transactions[numTransactions].date = time(NULL);
                numTransactions++;
                break;
            case 2:
                if (numTransactions == 0) {
                    printf("No transactions found.\n");
                    break;
                }
                printf("\nTransaction History:\n");
                for (int i = 0; i < numTransactions; i++) {
                    printf("\nTransaction %d:\n", i + 1);
                    printf("Description: %s\n", transactions[i].description);
                    printf("Amount: %.2f\n", transactions[i].amount);
                    printf("Date: %s\n", ctime(&transactions[i].date));
                }
                break;
            case 3:
                printf("Total Balance: %.2f\n", totalBalance);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}