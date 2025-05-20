//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int category;
} Expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int count;
} Category;

int main() {
    char input[100];
    Expense expenses[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];
    int num_expenses = 0, num_categories = 0;
    char choice;
    
    do {
        printf("Enter an expense in the format Name:Amount:Category\n");
        scanf("%s", input);
        
        if (strcmp(input, "Add Category") == 0) {
            printf("Enter category name:\n");
            scanf("%s", input);
            strcpy(categories[num_categories].name, input);
            num_categories++;
        }
        else if (strcmp(input, "Add Expense") == 0) {
            printf("Enter expense name:\n");
            scanf("%s", input);
            strcpy(expenses[num_expenses].name, input);
            printf("Enter amount:\n");
            scanf("%f", &expenses[num_expenses].amount);
            printf("Enter category:\n");
            scanf("%s", input);
            for (int i = 0; i < num_categories; i++) {
                if (strcmp(input, categories[i].name) == 0) {
                    expenses[num_expenses].category = i;
                    break;
                }
            }
            num_expenses++;
        }
        else if (strcmp(input, "View Expenses") == 0) {
            printf("Name\tAmount\tCategory\n");
            for (int i = 0; i < num_expenses; i++) {
                printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            }
        }
        else if (strcmp(input, "View Categories") == 0) {
            printf("Name\tCount\n");
            for (int i = 0; i < num_categories; i++) {
                printf("%s\t%d\n", categories[i].name, categories[i].count);
            }
        }
        else if (strcmp(input, "Exit") == 0) {
            break;
        }
        else {
            printf("Invalid input\n");
        }
        
        printf("\n");
    } while (1);
    
    return 0;
}