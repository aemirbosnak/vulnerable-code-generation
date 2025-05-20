//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int num_items;
    int total_cost;
} Category;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int category_id;
    int cost;
} Item;

int main() {
    int num_categories, num_items;
    Category categories[MAX_CATEGORIES];
    Item items[MAX_ITEMS];

    printf("Welcome to the Expense Tracker!\n");
    printf("How many categories do you want to create? ");
    scanf("%d", &num_categories);

    for(int i=0; i<num_categories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
        categories[i].num_items = 0;
        categories[i].total_cost = 0;
    }

    printf("\nCategories created successfully!\n");

    int choice;
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an item\n");
        printf("2. View expenses by category\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the name of the item: ");
                scanf("%s", items[num_items].name);
                printf("Enter the category ID (1-%d): ", num_categories);
                scanf("%d", &items[num_items].category_id);
                printf("Enter the cost of the item: ");
                scanf("%d", &items[num_items].cost);
                num_items++;
                break;
            }
            case 2: {
                printf("\nExpenses by category:\n");
                for(int i=0; i<num_categories; i++) {
                    printf("Category %s:\n", categories[i].name);
                    printf("Total cost: $%d\n", categories[i].total_cost);
                    printf("Items:\n");
                    for(int j=0; j<num_items; j++) {
                        if(items[j].category_id == i+1) {
                            printf("- %s: $%d\n", items[j].name, items[j].cost);
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}