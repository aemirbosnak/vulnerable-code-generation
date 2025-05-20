//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUDGET_ITEMS 10

typedef struct {
    char name[50];
    float amount;
} BudgetItem;

void addBudgetItem(BudgetItem *item, int index) {
    printf("Enter the name of item #%d: ", index + 1);
    fgets(item[index].name, sizeof(item[index].name), stdin);
    item[index].name[strcspn(item[index].name, "\n")] = 0; // Remove newline

    printf("Enter the amount for '%s': $", item[index].name);
    scanf("%f", &item[index].amount);
    getchar(); // Consume the newline character after floating point input
}

void displayBudget(const BudgetItem *item, int count) {
    printf("\nYour Budget Breakdown:\n");
    for(int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, item[i].name, item[i].amount);
    }
}

float calculateTotal(const BudgetItem *item, int count) {
    float total = 0.0f;
    for(int i = 0; i < count; i++) {
        total += item[i].amount;
    }
    return total;
}

void displayFunnyMessage(float total) {
    if (total <= 100) {
        printf("\nCongratulations! You're as frugal as a squirrel saving up for winter!\n");
    } else if (total <= 500) {
        printf("\nYou're doing well! Just remember, money doesn't grow on trees... but they make great cookies!\n");
    } else if (total <= 1000) {
        printf("\nLook at you! Living large! Just remember, wallets can be like your stomach; if they're too full, they can burst!\n");
    } else {
        printf("\nHoly guacamole! Did you win the lottery or are you just living in a cartoon?\n");
    }
}

int main() {
    BudgetItem budget[MAX_BUDGET_ITEMS];
    int budgetCount = 0;
    
    printf("Welcome to the 'Not-So-Serious Personal Finance Planner'!\n");
    printf("Let's keep track of your spending so you don’t end up living in a van down by the river!\n");

    while (1) {
        printf("\nHow many budget items do you want to enter (1 to %d)? Enter 0 to finalize: ", MAX_BUDGET_ITEMS);
        scanf("%d", &budgetCount);
        getchar(); // Consume the newline

        if (budgetCount == 0) {
            printf("Finalizing your budget input. Let's take a look...\n");
            break;
        }
        if (budgetCount > MAX_BUDGET_ITEMS) {
            printf("Uh-oh! That's more than we can handle! Please stick to %d or less.\n", MAX_BUDGET_ITEMS);
            continue;
        }

        for(int i = 0; i < budgetCount; i++) {
            addBudgetItem(budget, i);
        }

        displayBudget(budget, budgetCount);
        float total = calculateTotal(budget, budgetCount);
        printf("\nTotal Budget Amount: $%.2f\n", total);
        displayFunnyMessage(total);

        // Reset the budget array for the next iteration
        for (int i = 0; i < MAX_BUDGET_ITEMS; i++) {
            budget[i].amount = 0; // Clear amounts
            budget[i].name[0] = '\0'; // Clear names
        }
    }

    printf("Thanks for using our Not-So-Serious Personal Finance Planner! Now go buy something ridiculous—but not too expensive!\n");
    return 0;
}