//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
    float total;
} Item;

typedef struct {
    int num_items;
    Item items[100];
    float total_amount;
} Bill;

void print_menu() {
    printf("Welcome to the Cafe Billing System!\n");
    printf("-------------------------------------\n");
    printf("Menu:\n");
    printf("1. Add item to bill\n");
    printf("2. Print bill\n");
    printf("3. Exit\n");
    printf("-------------------------------------\n");
}

void add_item_to_bill(Bill *bill) {
    Item item;
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter price: ");
    scanf("%f", &item.price);
    item.total = item.quantity * item.price;
    bill->items[bill->num_items] = item;
    bill->num_items++;
    bill->total_amount += item.total;
}

void print_bill(Bill *bill) {
    printf("Bill:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price, bill->items[i].total);
    }
    printf("-------------------------------------\n");
    printf("Total Amount: %.2f\n", bill->total_amount);
}

int main() {
    Bill bill;
    bill.num_items = 0;
    bill.total_amount = 0.0;

    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item_to_bill(&bill);
                break;
            case 2:
                print_bill(&bill);
                break;
            case 3:
                printf("Thank you for using the Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}