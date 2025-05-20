//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[20];
    float amount;
    char date[15];
};
typedef struct expense Expense;


void addExpense(FILE *fp) {
    char category[20], date[15];
    float amount;
    Expense newExpense;
    
    printf("Enter category: ");
    scanf("%s", category);
    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date);
    
    strcpy(newExpense.category, category);
    newExpense.amount = amount;
    strcpy(newExpense.date, date);
    
    fwrite(&newExpense, sizeof(newExpense), 1, fp);
    printf("\nExpense added!\n");
}

void displayExpenses(FILE *fp) {
    Expense currentExpense;
    
    printf("\nCategory\tAmount\tDate\n");
    while (fread(&currentExpense, sizeof(currentExpense), 1, fp)) {
        printf("%s\t%.2f\t%s\n", currentExpense.category, currentExpense.amount, currentExpense.date);
    }
}

void searchExpenses(FILE *fp) {
    char searchCategory[20];
    float totalExpense = 0;
    Expense currentExpense;

    printf("\nEnter category to search for: ");
    scanf("%s", searchCategory);
    
    printf("Category\tAmount\t\tDate\n");
    while (fread(&currentExpense, sizeof(currentExpense), 1, fp)) {
        if (strcmp(currentExpense.category, searchCategory) == 0) {
            printf("%s\t\t%.2f\t%s\n", currentExpense.category, currentExpense.amount, currentExpense.date);
            totalExpense += currentExpense.amount; 
        }
    }
    if (totalExpense == 0) {
        printf("\nNo expenses found for category: %s\n", searchCategory);
    } else {
        printf("\nTotal expenses for category %s: Rs. %.2f\n", searchCategory, totalExpense);
    }
}

int main() {
    FILE *fp;
    int choice;
    
    fp = fopen("expenses.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening or creating file!");
        exit(0);
    }
    
    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add an expense\n");
        printf("2. Display all expenses\n");
        printf("3. Search expenses by category\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExpense(fp);
                break;
            case 2:
                displayExpenses(fp);
                break;
            case 3:
                searchExpenses(fp);
                break;
            case 4:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid option!");
                break;
        }
    }
    return 0;
}