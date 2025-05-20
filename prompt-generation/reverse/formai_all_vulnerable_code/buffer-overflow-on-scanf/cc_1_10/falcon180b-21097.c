//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 64
#define MAX_CATEGORY_LENGTH 64

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double price;
} item;

int num_items = 0;
item items[MAX_ITEMS];

void add_item(char* name, char* category, double price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Too many items.\n");
        return;
    }
    strcpy(items[num_items].name, name);
    strcpy(items[num_items].category, category);
    items[num_items].price = price;
    num_items++;
}

void print_items() {
    printf("Name\tCategory\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-20s\t%-20s\t$%.2f\n", items[i].name, items[i].category, items[i].price);
    }
}

int main() {
    char input[256];
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double price;

    printf("Welcome to the Post-Apocalyptic Expense Tracker!\n");
    while (1) {
        printf("Enter an item name (up to %d characters): ", MAX_NAME_LENGTH - 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(name, input);
        printf("Enter an item category (up to %d characters): ", MAX_CATEGORY_LENGTH - 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(category, input);
        printf("Enter the item price: ");
        if (scanf("%lf", &price)!= 1) {
            printf("Error: Invalid price.\n");
            continue;
        }
        add_item(name, category, price);
    }

    while (1) {
        printf("\nExpenses:\n");
        print_items();
        printf("\nEnter 'q' to quit or any other key to continue: ");
        if (scanf(" %c", &input[0]) == 1 && tolower(input[0]) == 'q') {
            break;
        }
    }

    return 0;
}