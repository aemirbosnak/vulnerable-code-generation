//FormAI DATASET v1.0 Category: Expense Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char item[50];
    float cost;
    char category[20];
};

struct Category {
    char name[20];
    float budget;
    float spent;
};

int main() {
    //initializing categories
    struct Category food = {"Food", 200, 0};
    struct Category transportation = {"Transportation", 100, 0};
    struct Category entertainment = {"Entertainment", 150, 0};
    
    struct Expense expenses[10]; //max of 10 expenses for now
    
    int expenseIndex = 0;
    char continueInput = 'y';
    
    while (continueInput == 'y') {
        printf("Enter item name: ");
        scanf("%s", expenses[expenseIndex].item);
        printf("Enter cost: ");
        scanf("%f", &expenses[expenseIndex].cost);
        printf("Enter category: ");
        scanf("%s", expenses[expenseIndex].category);
        
        if(strcmp(expenses[expenseIndex].category, "Food") == 0) {
            food.spent += expenses[expenseIndex].cost;
        } else if(strcmp(expenses[expenseIndex].category, "Transportation") == 0) {
            transportation.spent += expenses[expenseIndex].cost;
        } else if(strcmp(expenses[expenseIndex].category, "Entertainment") == 0) {
            entertainment.spent += expenses[expenseIndex].cost;
        }
        
        printf("\nWould you like to input another expense? (y/n)");
        scanf(" %c", &continueInput);
        expenseIndex++;
    }
    
    printf("\n\nCategory Summary:\n");
    printf("-------------------------\n");
    printf("Category   | Budget   | Spent\n");
    printf("-------------------------\n");
    printf("%-10s | $%.2f  | $%.2f\n", food.name, food.budget, food.spent);
    printf("%-10s | $%.2f  | $%.2f\n", transportation.name, transportation.budget, transportation.spent);
    printf("%-10s | $%.2f  | $%.2f\n", entertainment.name, entertainment.budget, entertainment.spent);
    
    return 0;
}