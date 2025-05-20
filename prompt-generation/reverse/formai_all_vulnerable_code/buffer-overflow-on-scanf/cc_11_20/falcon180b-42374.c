//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int amount;
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_items;
    Item items[MAX_ITEMS];
} Category;

int main() {
    Category categories[MAX_CATEGORIES];
    int num_categories = 0;
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. View categories\n");
        printf("4. View items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_categories >= MAX_CATEGORIES) {
                printf("Maximum number of categories reached.\n");
            } else {
                printf("Enter category name: ");
                scanf("%s", categories[num_categories].name);
                categories[num_categories].num_items = 0;
                num_categories++;
            }
            break;

        case 2:
            printf("Enter category name: ");
            scanf("%s", categories[0].name);
            printf("Enter item name: ");
            scanf("%s", categories[0].items[0].name);
            printf("Enter item amount: ");
            scanf("%s", categories[0].items[0].amount);
            categories[0].num_items++;
            break;

        case 3:
            for (int i = 0; i < num_categories; i++) {
                printf("%s\n", categories[i].name);
            }
            break;

        case 4:
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (categories[0].items[i].name[0]!= '\0') {
                    printf("%s - $%s\n", categories[0].items[i].name, categories[0].items[i].amount);
                }
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}