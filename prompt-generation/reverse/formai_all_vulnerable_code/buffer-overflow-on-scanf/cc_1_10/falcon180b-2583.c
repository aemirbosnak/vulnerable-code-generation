//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
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
    
    do {
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. Display expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                if (num_categories >= MAX_CATEGORIES) {
                    printf("Maximum number of categories reached!\n");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[num_categories].name);
                    categories[num_categories].num_items = 0;
                    num_categories++;
                }
                break;
            }
            case 2: {
                printf("Enter category name: ");
                scanf("%s", categories[num_categories-1].name);
                printf("Enter item name: ");
                scanf("%s", categories[num_categories-1].items[categories[num_categories-1].num_items].name);
                printf("Enter item amount: ");
                scanf("%f", &categories[num_categories-1].items[categories[num_categories-1].num_items].amount);
                categories[num_categories-1].num_items++;
                break;
            }
            case 3: {
                printf("Category\tItem\tAmount\n");
                for (int i = 0; i < num_categories; i++) {
                    printf("%s:\n", categories[i].name);
                    for (int j = 0; j < categories[i].num_items; j++) {
                        printf("\t%s\t%.2f\n", categories[i].items[j].name, categories[i].items[j].amount);
                    }
                    printf("\n");
                }
                break;
            }
            case 4: {
                printf("Exiting program...\n");
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while(choice!= 4);
    
    return 0;
}