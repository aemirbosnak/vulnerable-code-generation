//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM 100

typedef struct {
    char name[50];
    float price;
} Item;

Item items[MAX_ITEM];
int num_items = 0;

void add_item(const char* name, float price) {
    if (num_items >= MAX_ITEM) {
        printf("Cart is full!\n");
        return;
    }
    strcpy(items[num_items].name, name);
    items[num_items].price = price;
    num_items++;
}

void print_cart() {
    printf("\nCart Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\t\t%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

float calculate_total() {
    float total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price;
    }
    return total;
}

int main() {
    char input_name[50];
    float input_price;
    int choice;

    while (1) {
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. Add Item\n");
        printf("2. Print Cart\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", input_name);
                printf("Enter item price: ");
                scanf("%f", &input_price);
                add_item(input_name, input_price);
                break;
            case 2:
                print_cart();
                break;
            case 3:
                printf("Total bill: %.2f\n", calculate_total());
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}