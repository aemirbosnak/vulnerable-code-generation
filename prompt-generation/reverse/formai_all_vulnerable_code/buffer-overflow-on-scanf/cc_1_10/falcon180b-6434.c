//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    double cost;
} item_t;

int main() {
    item_t items[MAX_ITEMS];
    int num_items = 0;
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("-----------------\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    printf("Enter item name (up to %d characters): ", MAX_NAME_LENGTH-1);
                    scanf("%s", items[num_items].name);

                    printf("Enter item description (up to %d characters): ", MAX_DESCRIPTION_LENGTH-1);
                    scanf("%s", items[num_items].description);

                    printf("Enter item cost: ");
                    scanf("%lf", &items[num_items].cost);

                    num_items++;
                }
                break;

            case '2':
                if(num_items == 0) {
                    printf("No items found.\n");
                } else {
                    printf("Item list:\n");
                    for(int i=0; i<num_items; i++) {
                        printf("ID: %d\nName: %s\nDescription: %s\nCost: $%.2f\n", i+1, items[i].name, items[i].description, items[i].cost);
                    }
                }
                break;

            case '3':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '3');

    return 0;
}