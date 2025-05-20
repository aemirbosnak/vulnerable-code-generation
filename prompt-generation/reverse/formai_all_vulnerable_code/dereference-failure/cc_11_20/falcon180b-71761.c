//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
} item;

int main() {
    int num_items, i;
    item *items = (item*)malloc(MAX_ITEMS * sizeof(item));
    num_items = 0;

    while(1) {
        printf("\nEnter 1 to add an item, 2 to remove an item, 3 to view expenses, 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_items == MAX_ITEMS) {
                    printf("\nError: Maximum number of items reached\n");
                } else {
                    printf("\nEnter item name:\n");
                    scanf("%s", items[num_items].name);
                    printf("\nEnter item price:\n");
                    scanf("%s", items[num_items].price);
                    num_items++;
                }
                break;
            case 2:
                if(num_items == 0) {
                    printf("\nError: No items to remove\n");
                } else {
                    printf("\nEnter item to remove:\n");
                    scanf("%s", items[0].name);
                    for(i = 0; i < num_items; i++) {
                        if(strcmp(items[i].name, items[0].name) == 0) {
                            memmove(&items[i], &items[i+1], (num_items-i-1)*sizeof(item));
                            num_items--;
                            break;
                        }
                    }
                }
                break;
            case 3:
                if(num_items == 0) {
                    printf("\nError: No items to view\n");
                } else {
                    printf("\nItem\t\tPrice\n");
                    for(i = 0; i < num_items; i++) {
                        printf("%s\t\t$%.2f\n", items[i].name, atof(items[i].price));
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nError: Invalid choice\n");
        }
    }

    return 0;
}