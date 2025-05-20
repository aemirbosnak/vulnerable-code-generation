//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float cost;
    int category;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float totalCost;
    int numItems;
} Category;

int main() {
    char input[100];
    int choice;
    int numItems = 0;
    int numCategories = 0;

    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];

    printf("Welcome to the Expense Tracker!\n");

    // Initialize categories
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        categories[i].name[0] = '\0';
        categories[i].totalCost = 0;
        categories[i].numItems = 0;
    }

    // Main loop
    while (1) {
        printf("\nEnter choice:\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. View categories\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numItems == MAX_ITEMS) {
                printf("Maximum number of items reached!\n");
            } else {
                printf("Enter item name: ");
                scanf("%s", items[numItems].name);
                printf("Enter item cost: ");
                scanf("%f", &items[numItems].cost);
                printf("Enter item category (0-%d): ", numCategories - 1);
                scanf("%d", &items[numItems].category);
                numItems++;
            }
            break;
        case 2:
            printf("\nItem List:\n");
            for (int i = 0; i < numItems; i++) {
                printf("%s - $%.2f - Category: %d\n", items[i].name, items[i].cost, items[i].category);
            }
            break;
        case 3:
            printf("\nCategory List:\n");
            for (int i = 0; i < numCategories; i++) {
                printf("%s - Total Cost: $%.2f - Number of Items: %d\n", categories[i].name, categories[i].totalCost, categories[i].numItems);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}