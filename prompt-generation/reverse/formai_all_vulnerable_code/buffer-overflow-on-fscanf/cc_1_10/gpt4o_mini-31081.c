//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} BudgetItem;

typedef struct {
    BudgetItem items[MAX_BUDGET_ITEMS];
    int count;
} Budget;

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Budget Item\n");
    printf("2. View Budget\n");
    printf("3. Calculate Total Budget\n");
    printf("4. Remove Budget Item\n");
    printf("5. Save Budget to File\n");
    printf("6. Load Budget from File\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

void addItem(Budget *budget) {
    if (budget->count >= MAX_BUDGET_ITEMS) {
        printf("Budget is full! Cannot add more items.\n");
        return;
    }
    BudgetItem item;
    printf("Enter description of the budget item: ");
    scanf(" %[^\n]s", item.description);
    printf("Enter amount: ");
    scanf("%f", &item.amount);
    
    budget->items[budget->count] = item;
    budget->count++;
    printf("Item added successfully!\n");
}

void viewBudget(const Budget *budget) {
    if (budget->count == 0) {
        printf("No budget items available.\n");
        return;
    }

    printf("\n=== Budget Items ===\n");
    for (int i = 0; i < budget->count; i++) {
        printf("%d. %s - %.2f\n", i + 1, budget->items[i].description, budget->items[i].amount);
    }
}

float calculateTotal(const Budget *budget) {
    float total = 0.0;
    for (int i = 0; i < budget->count; i++) {
        total += budget->items[i].amount;
    }
    return total;
}

void removeItem(Budget *budget) {
    if (budget->count == 0) {
        printf("No budget items to remove.\n");
        return;
    }
    int index;
    printf("Enter the item number to remove (1-%d): ", budget->count);
    scanf("%d", &index);
    
    if (index < 1 || index > budget->count) {
        printf("Invalid item number.\n");
        return;
    }

    for (int i = index - 1; i < budget->count - 1; i++) {
        budget->items[i] = budget->items[i + 1];
    }
    budget->count--;

    printf("Item removed successfully!\n");
}

void saveToFile(const Budget *budget) {
    FILE *file = fopen("budget.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < budget->count; i++) {
        fprintf(file, "%s\n%.2f\n", budget->items[i].description, budget->items[i].amount);
    }
    fclose(file);
    printf("Budget saved to budget.txt successfully!\n");
}

void loadFromFile(Budget *budget) {
    FILE *file = fopen("budget.txt", "r");
    if (!file) {
        printf("No saved budget found.\n");
        return;
    }
    budget->count = 0;
    while (fscanf(file, " %[^\n]s", budget->items[budget->count].description) != EOF) {
        fscanf(file, "%f", &budget->items[budget->count].amount);
        budget->count++;
    }
    fclose(file);
    printf("Budget loaded successfully!\n");
}

int main() {
    Budget budget;
    budget.count = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                addItem(&budget);
                break;
            case 2:
                viewBudget(&budget);
                break;
            case 3:
                printf("Total Budget: %.2f\n", calculateTotal(&budget));
                break;
            case 4:
                removeItem(&budget);
                break;
            case 5:
                saveToFile(&budget);
                break;
            case 6:
                loadFromFile(&budget);
                break;
            case 0:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}