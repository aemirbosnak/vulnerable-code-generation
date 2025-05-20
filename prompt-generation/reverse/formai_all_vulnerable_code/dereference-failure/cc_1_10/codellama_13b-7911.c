//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
/*
 * C Expense Tracker Example Program
 */

#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char description[100];
    float amount;
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char input[100];
    char *token;
    float amount;
    int i;

    // Read input and add to array
    while (1) {
        printf("Enter expense description and amount (e.g. 'Groceries 100'): ");
        fgets(input, 100, stdin);

        // Check for exit condition
        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        // Parse input
        token = strtok(input, " ");
        strcpy(entries[num_entries].description, token);
        token = strtok(NULL, " ");
        amount = atof(token);
        entries[num_entries].amount = amount;

        // Increment entry count
        num_entries++;
    }

    // Print expenses
    printf("Expenses:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s: $%.2f\n", entries[i].description, entries[i].amount);
    }

    return 0;
}