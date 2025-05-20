//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    float amount;
    int category;
} Transaction;

#define NUM_CATEGORIES 7

int main(void) {
    Transaction transactions[100];
    int current_transaction = 0;
    int category_choices[NUM_CATEGORIES] = {1, 2, 3, 4, 5, 6, 7};
    int category;
    float total_income = 0, total_expenses = 0, net_worth;

    srand(time(NULL));

    while (1) {
        printf("\nWelcome to the Mystical Financial Wonderland!\n");
        printf("Enter your name: ");
        scanf("%s", transactions[current_transaction].name);
        printf("Choose a category for your transaction (1-7): ");
        scanf("%d", &category);

        if (category < 1 || category > NUM_CATEGORIES) {
            printf("Invalid category choice. Please try again.\n");
            continue;
        }

        category--;

        printf("Enter the amount of your transaction: $");
        scanf("%f", &transactions[current_transaction].amount);

        transactions[current_transaction].category = category_choices[category];
        current_transaction++;

        total_income += transactions[current_transaction - 1].amount;
        total_expenses += transactions[current_transaction - 1].amount * transactions[current_transaction - 1].category;

        if (transactions[current_transaction - 1].amount > 0) {
            total_income += transactions[current_transaction - 1].amount;
        } else {
            total_expenses += transactions[current_transaction - 1].amount;
        }

        if (current_transaction >= 99) {
            net_worth = total_income - total_expenses;
            printf("\nTotal income: $%.2f\n", total_income);
            printf("Total expenses: $%.2f\n", total_expenses);
            printf("Net worth: $%.2f\n", net_worth);
            break;
        }

        int random_event = rand() % 3;

        switch (random_event) {
            case 0:
                printf("A fairy has granted you a random gift of $50!\n");
                total_income += 50;
                break;
            case 1:
                printf("A dragon has stolen $100 from you!\n");
                total_expenses += 100;
                break;
            case 2:
                printf("A magic potion has doubled the value of your latest transaction!\n");
                transactions[current_transaction - 1].amount *= 2;
                total_income += transactions[current_transaction - 1].amount;
                break;
        }

        printf("\nPress Enter to continue...\n");
        getchar();
        system("clear"); // or use '\033[H\033[2J' for non-Unix systems
    }

    return 0;
}