//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int main() {
    FILE *fp;
    char filename[MAX_NAME_LEN];
    item expenses[MAX_ITEMS];
    int num_expenses = 0;
    int i;

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in expenses
    while (fscanf(fp, "%s %s", expenses[num_expenses].name, expenses[num_expenses].price)!= EOF) {
        num_expenses++;
        if (num_expenses >= MAX_ITEMS) {
            printf("Maximum number of expenses exceeded.\n");
            exit(1);
        }
    }

    // Sort expenses by price
    for (i = 0; i < num_expenses - 1; i++) {
        if (strcmp(expenses[i].price, expenses[i+1].price) > 0) {
            item temp = expenses[i];
            expenses[i] = expenses[i+1];
            expenses[i+1] = temp;
        }
    }

    // Display expenses
    printf("Expenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%s - $%s\n", expenses[i].name, expenses[i].price);
    }

    // Close the file
    fclose(fp);

    return 0;
}