//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 50

struct Item {
    char name[20];
    float price;
} items[MAX_ITEMS];

int num_items = 0;

void add_item() {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    num_items++;
}

void display_items() {
    printf("\nItems:\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void add_to_bill(int item_num, int quantity) {
    float total = (float)quantity * items[item_num-1].price;
    printf("\nAdded %d x %s to bill. Total cost: $%.2f\n", quantity, items[item_num-1].name, total);
}

int main() {
    int choice;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item\n2. Display items\n3. Add to bill\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                printf("Enter item number: ");
                scanf("%d", &choice);
                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);
                add_to_bill(choice, quantity);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice!= 4);

    return 0;
}