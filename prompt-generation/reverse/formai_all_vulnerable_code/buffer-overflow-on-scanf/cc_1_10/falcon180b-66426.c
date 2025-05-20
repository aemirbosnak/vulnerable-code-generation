//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} item;

int num_categories = 0;
char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];

void add_category(char* name) {
    strcpy(categories[num_categories], name);
    num_categories++;
}

int find_category(char* name) {
    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(name, categories[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int num_items = 0;
item items[MAX_ITEMS];

void add_item(char* name, char* category, char* price) {
    strcpy(items[num_items].name, name);
    strcpy(items[num_items].category, category);
    strcpy(items[num_items].price, price);
    num_items++;
}

void print_items() {
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s - %s - $%s\n", items[i].name, items[i].category, items[i].price);
    }
}

int main() {
    int choice;
    char input[100];

    do {
        printf("Expense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add item\n");
        printf("3. Print items\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter category name: ");
                scanf("%s", input);
                add_category(input);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", input);
                printf("Enter category: ");
                scanf("%s", input);
                printf("Enter price: ");
                scanf("%s", input);
                add_item(input, input, input);
                break;
            case 3:
                print_items();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}