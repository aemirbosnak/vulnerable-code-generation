//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    int expenses[MAX_EXPENSES];
    int num_expenses;
} Category;

Category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    int i;
    char input[50];
    printf("Enter category name: ");
    scanf("%s", input);
    for (i = 0; i < num_categories; i++) {
        if (strcmp(input, categories[i].name) == 0) {
            printf("Category already exists.\n");
            return;
        }
    }
    strcpy(categories[num_categories].name, input);
    categories[num_categories].num_expenses = 0;
    num_categories++;
}

void add_expense() {
    int i, j;
    char input[50];
    int amount;
    printf("Enter category name: ");
    scanf("%s", input);
    for (i = 0; i < num_categories; i++) {
        if (strcmp(input, categories[i].name) == 0) {
            printf("Enter expense amount: ");
            scanf("%d", &amount);
            categories[i].expenses[categories[i].num_expenses] = amount;
            categories[i].num_expenses++;
            return;
        }
    }
    printf("Category not found.\n");
}

void display_categories() {
    int i;
    for (i = 0; i < num_categories; i++) {
        printf("%s: ", categories[i].name);
        int j;
        for (j = 0; j < categories[i].num_expenses; j++) {
            printf("%d ", categories[i].expenses[j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add category\n2. Add expense\n3. Display categories\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                display_categories();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}