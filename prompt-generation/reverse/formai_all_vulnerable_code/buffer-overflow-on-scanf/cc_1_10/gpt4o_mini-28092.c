//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char currencyName[20];
    double rateToUSD;
    double amount;
} Transaction;

void displayMenu() {
    printf("\nCurrency Converter Menu:\n");
    printf("1. Convert currency\n");
    printf("2. View transaction history\n");
    printf("3. Calculate average conversion rate\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void convertCurrency(Transaction transactions[], int *transactionCount) {
    char currency[20];
    double amount;

    printf("Enter the currency you want to convert from (Example: EUR): ");
    scanf("%s", currency);
    printf("Enter the amount in %s: ", currency);
    scanf("%lf", &amount);

    double conversionRate;
    printf("Enter the conversion rate to USD: ");
    scanf("%lf", &conversionRate);

    transactions[*transactionCount].rateToUSD = conversionRate;
    transactions[*transactionCount].amount = amount;
    snprintf(transactions[*transactionCount].currencyName, sizeof(transactions[*transactionCount].currencyName), "%s", currency);
    (*transactionCount)++;

    double convertedAmount = amount * conversionRate;
    printf("Converted Amount: %.2f USD\n", convertedAmount);
}

void viewTransactions(Transaction transactions[], int transactionCount) {
    if (transactionCount == 0) {
        printf("No transactions made yet.\n");
        return;
    }

    printf("\nTransaction History:\n");
    printf("%-10s %-15s %-10s\n", "Currency", "Amount", "Rate (to USD)");
    for (int i = 0; i < transactionCount; i++) {
        printf("%-10s %-15.2f %-10.2f\n", transactions[i].currencyName, transactions[i].amount, transactions[i].rateToUSD);
    }
}

void calculateAverageRate(Transaction transactions[], int transactionCount) {
    if (transactionCount == 0) {
        printf("No transactions made yet.\n");
        return;
    }

    double sumRates = 0;
    for (int i = 0; i < transactionCount; i++) {
        sumRates += transactions[i].rateToUSD;
    }
    double averageRate = sumRates / transactionCount;
    printf("Average Conversion Rate to USD: %.2f\n", averageRate);
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                convertCurrency(transactions, &transactionCount);
                break;
            case 2:
                viewTransactions(transactions, transactionCount);
                break;
            case 3:
                calculateAverageRate(transactions, transactionCount);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}