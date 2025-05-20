//FormAI DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char date[10];
    char category[20];
    float amount;
};

int main() {
    int n;
    printf("Enter number of expenses: ");
    scanf("%d", &n);

    struct expense *expenses = (struct expense*) malloc(n * sizeof(struct expense));

    for(int i=0; i<n; i++) {
        printf("Enter expense details for expense #%d:\n", i+1);
        printf("Date (DD/MM/YYYY): ");
        scanf("%s", (expenses + i)->date);
        printf("Category: ");
        scanf("%s", (expenses + i)->category);
        printf("Amount: ");
        scanf("%f", &(expenses + i)->amount);
    }

    printf("\nExpense Report\n");
    printf("--------------------------------------------------\n");
    printf("Date\t\tCategory\tAmount\n");
    printf("--------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t\t%.2f\n", (expenses + i)->date, (expenses + i)->category, (expenses + i)->amount);
    }

    char category[20];
    printf("\nEnter name of category to get total amount spent: ");
    scanf("%s", category);

    float total = 0;
    for(int i=0; i<n; i++) {
        if(strcmp((expenses + i)->category, category) == 0) {
            total += (expenses + i)->amount;
        }
    }
    printf("Total amount spent on %s: %.2f\n", category, total);

    free(expenses);

    return 0;
}