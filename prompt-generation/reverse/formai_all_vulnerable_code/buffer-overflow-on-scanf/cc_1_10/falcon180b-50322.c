//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
    int isExpense;
} item;

int main() {
    int numItems = 0;
    item *items = (item*) malloc(MAX_ITEMS * sizeof(item));

    while (numItems < MAX_ITEMS) {
        printf("Enter the name of the item (or leave blank to stop): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);

        if (strlen(name) == 0) {
            break;
        }

        printf("Enter the amount (e.g. $12.34): ");
        char amount[MAX_AMOUNT_LEN];
        scanf("%s", amount);

        if (strlen(amount) > MAX_AMOUNT_LEN) {
            printf("Amount too long. Please try again.\n");
            continue;
        }

        items[numItems].name[0] = toupper(name[0]);
        strcpy(items[numItems].name + 1, &name[1]);

        items[numItems].isExpense = 0;
        if (amount[0] == '-') {
            items[numItems].isExpense = 1;
            strcpy(items[numItems].amount, &amount[1]);
        } else {
            strcpy(items[numItems].amount, amount);
        }

        numItems++;
    }

    printf("Expense Tracker\n");
    printf("================\n");

    printf("Name\tAmount\n");
    for (int i = 0; i < numItems; i++) {
        if (items[i].isExpense) {
            printf("%-20s$%.2f\n", items[i].name, atof(items[i].amount));
        } else {
            printf("%-20s$%.2f\n", items[i].name, atof(items[i].amount));
        }
    }

    free(items);
    return 0;
}