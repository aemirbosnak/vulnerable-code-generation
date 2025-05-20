//FormAI DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

struct expense {
    char category[MAX_LENGTH];
    float amount;
};

int main() {
    struct expense expenses[MAX_ENTRIES];
    int num_entries = 0;
    char input[MAX_LENGTH];
    char *token;

    while (strcmp(input, "QUIT") != 0) {
        printf("Enter expense category and amount (ex. FOOD 50.80), or type QUIT to exit: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = '\0';

        token = strtok(input, " ");
        strcpy(expenses[num_entries].category, token);

        token = strtok(NULL, " ");
        expenses[num_entries].amount = atof(token);

        num_entries++;
    }

    float total_spent = 0;
    int num_categories = 0;
    char categories[MAX_ENTRIES][MAX_LENGTH];
    float category_totals[MAX_ENTRIES];

    // calculate total spent and create list of unique categories
    for (int i = 0; i < num_entries; i++) {
        total_spent += expenses[i].amount;

        int found = 0;

        for (int j = 0; j < num_categories; j++) {
            if (strcmp(categories[j], expenses[i].category) == 0) {
                category_totals[j] += expenses[i].amount;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(categories[num_categories], expenses[i].category);
            category_totals[num_categories] = expenses[i].amount;
            num_categories++;
        }
    }

    printf("\nTotal spent: $%.2f\n\n", total_spent);

    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%.2f\n", categories[i], category_totals[i]);
    }

    return 0;
}