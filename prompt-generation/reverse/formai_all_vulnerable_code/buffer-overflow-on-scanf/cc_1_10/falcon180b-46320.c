//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item;

item items[MAX_ITEMS];
int num_items = 0;

int add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item category: ");
    scanf("%s", items[num_items].category);
    printf("Enter item price: ");
    scanf("%s", items[num_items].price);
    num_items++;
    return 0;
}

int view_items() {
    printf("Item Name\tCategory\tPrice\n");
    for(int i=0; i<num_items; i++) {
        printf("%s\t%s\t%s\n", items[i].name, items[i].category, items[i].price);
    }
    return 0;
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    int choice;
    while(1) {
        printf("\n");
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                view_items();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}