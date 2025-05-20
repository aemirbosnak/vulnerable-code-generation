//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ITEMS 1000

struct item {
    char name[50];
    double price;
    time_t date;
};

struct item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, double price) {
    struct item new_item;
    strcpy(new_item.name, name);
    new_item.price = price;
    new_item.date = time(NULL);
    if (num_items >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }
    items[num_items] = new_item;
    num_items++;
}

void print_items(void) {
    printf("\nItem Name\tPrice\tDate\n");
    for (int i = 0; i < num_items; i++) {
        printf("%-30s $%.2f %s\n", items[i].name, items[i].price, ctime(&items[i].date));
    }
}

void search_item(char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("\nItem Found:\n");
            printf("Name: %s\n", items[i].name);
            printf("Price: $%.2f\n", items[i].price);
            printf("Date: %s\n", ctime(&items[i].date));
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    char input[100];
    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Add item\n");
        printf("2. Print items\n");
        printf("3. Search item\n");
        printf("4. Exit\n");
        scanf("%s", input);
        switch (atoi(input)) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", input);
            printf("Enter item price: ");
            scanf("%lf", &items[num_items - 1].price);
            break;
        case 2:
            print_items();
            break;
        case 3:
            printf("Enter item name to search: ");
            scanf("%s", input);
            search_item(input);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }
    return 0;
}