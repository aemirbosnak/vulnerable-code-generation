//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    float amount;
} ExpenseItem;

void addItem(ExpenseItem* items, int* numItems) {
    printf("Enter expense name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter expense description: ");
    scanf("%s", items[*numItems].description);
    printf("Enter expense amount: ");
    scanf("%f", &items[*numItems].amount);
    (*numItems)++;
}

void deleteItem(ExpenseItem* items, int* numItems) {
    printf("Enter expense name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int i, found = 0;
    for (i = 0; i < *numItems; i++) {
        if (strcmp(name, items[i].name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        memmove(items + i, items + i + 1, (*numItems - i - 1) * sizeof(ExpenseItem));
        (*numItems)--;
    } else {
        printf("Expense not found.\n");
    }
}

void displayItems(ExpenseItem* items, int numItems) {
    printf("Name\tDescription\tAmount\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%s\t%.2f\n", items[i].name, items[i].description, items[i].amount);
    }
}

int main() {
    ExpenseItem items[MAX_ITEMS];
    int numItems = 0;
    int choice;
    do {
        printf("1. Add expense\n2. Delete expense\n3. Display expenses\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, &numItems);
                break;
            case 2:
                deleteItem(items, &numItems);
                break;
            case 3:
                displayItems(items, numItems);
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