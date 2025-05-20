//FormAI DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPENSES 100

struct expense {
    char category[20];
    float cost;
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    struct expense e;
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter cost: ");
    scanf("%f", &e.cost);

    expenses[num_expenses] = e;
    num_expenses++;

    printf("Expense added!\n\n");
}

void print_expenses() {
    printf("Category\tCost\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t\t$%.2f\n", expenses[i].category, expenses[i].cost);
    }
    printf("\n");
}

void save_expenses(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file!\n\n");
        return;
    }

    for (int i = 0; i < num_expenses; i++) {
        fprintf(file, "%s,%.2f\n", expenses[i].category, expenses[i].cost);
    }

    fclose(file);
    printf("Expenses saved to %s\n\n", filename);
}

void load_expenses(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n\n");
        return;
    }

    char category[20];
    float cost;
    while (fscanf(file, "%[^,],%f\n", category, &cost) != EOF) {
        struct expense e;
        strcpy(e.category, category);
        e.cost = cost;
        expenses[num_expenses] = e;
        num_expenses++;
    }

    fclose(file);
    printf("Expenses loaded from %s\n\n", filename);
}

int main() {
    printf("Welcome to the expense tracker!\n");

    while (1) {
        printf("Menu:\n");
        printf("(1) Add expense\n");
        printf("(2) Print expenses\n");
        printf("(3) Save expenses\n");
        printf("(4) Load expenses\n");
        printf("(5) Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                save_expenses("expenses.csv");
                break;
            case 4:
                load_expenses("expenses.csv");
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    }

    return 0;
}