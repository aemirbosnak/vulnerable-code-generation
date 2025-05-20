//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct expense {
    char item[50];
    float amount;
    char date[20];
};

void addExpense(struct expense *expenses, int *count) {
    printf("Enter the expense item:\n");
    scanf("%s", expenses[*count].item);
    printf("Enter the expense amount:\n");
    scanf("%f", &expenses[*count].amount);
    printf("Enter the expense date (dd/mm/yyyy):\n");
    scanf("%s", expenses[*count].date);
    
    (*count)++;
    printf("Successfully added expense!\n");
}

void viewExpenses(struct expense *expenses, int count) {
    printf("Expense List\n");
    printf("============\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d. Item: %s\tAmount: %.2f\tDate: %s\n", i+1, expenses[i].item, expenses[i].amount, expenses[i].date);
    }
}

void saveExpensesToFile(struct expense *expenses, int count) {
    FILE *fp;
    fp = fopen("expenses.txt", "w");
    
    for (int i = 0; i < count; i++) {
        fprintf(fp, "Item: %s, Amount: %.2f, Date: %s\n", expenses[i].item, expenses[i].amount, expenses[i].date);
    }
    
    fclose(fp);
    printf("Successfully saved expenses to file!\n");
}

int main() {
    struct expense expenses[100];
    int count = 0;
    int choice;
    
    printf("Expense Tracker\n");
    printf("=================\n");
    
    while (1) {
        printf("\nEnter choice:\n");
        printf("1) Add Expense\n");
        printf("2) View Expenses\n");
        printf("3) Save Expenses to File\n");
        printf("4) Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                saveExpensesToFile(expenses, count);
                break;
            case 4:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}