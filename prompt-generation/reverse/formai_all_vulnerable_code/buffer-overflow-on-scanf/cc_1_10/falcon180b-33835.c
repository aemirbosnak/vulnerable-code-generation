//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int quantity;
    float price;
} Item;

void add_item(Item items[], int *size) {
    printf("Enter item name: ");
    scanf("%s", (*size)? items[*size - 1].name : items[0].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    (*size)++;
}

void display_items(Item items[], int size) {
    printf("Item\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculate_total(Item items[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("Total: %.2f\n", total);
}

int main() {
    int size = 0;
    Item items[100];
    char choice;
    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n2. Display items\n3. Calculate total\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                add_item(items, &size);
                break;
            case '2':
                display_items(items, size);
                break;
            case '3':
                calculate_total(items, size);
                break;
            case '4':
                printf("Thank you for using our Cafe Billing System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');
    return 0;
}