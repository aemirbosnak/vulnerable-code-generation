//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

struct item {
    char name[100];
    int quantity;
    float price;
};

float calculate_total(struct item items[], int num_items);
void print_bill(struct item items[], int num_items, float total);
void add_item(struct item items[], int *num_items);
void print_menu();

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;
    float total = 0;

    printf("Welcome to C Cafe!\n");
    print_menu();

    while (1) {
        char choice[10];

        printf("Enter choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            add_item(items, &num_items);
        } else if (strcmp(choice, "2") == 0) {
            total = calculate_total(items, num_items);
            print_bill(items, num_items, total);
            break;
        } else {
            printf("Invalid choice, please try again.\n");
            print_menu();
        }
    }

    return 0;
}

float calculate_total(struct item items[], int num_items) {
    float total = 0;

    for (int i = 0; i < num_items; i++) {
        total += items[i].quantity * items[i].price;
    }

    return total;
}

void print_bill(struct item items[], int num_items, float total) {
    printf("\nC Cafe Bill\n");
    printf("---------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s x %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("---------------\n");
    printf("Total - $%.2f\n", total);
}

void add_item(struct item items[], int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Maximum items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);

    printf("Enter quantity: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter price: ");
    scanf("%f", &items[*num_items].price);

    (*num_items)++;
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Add item\n");
    printf("2. Print bill and exit\n");
}