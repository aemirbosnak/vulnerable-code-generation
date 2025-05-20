//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

struct customer {
    char name[100];
    float discount;
};

struct item {
    char name[100];
    int quantity;
    float price;
};

int main() {
    struct customer cust;
    struct item items[10];

    printf("Welcome to the Peaceful Cafe! Please enter your name: ");
    fgets(cust.name, sizeof(cust.name), stdin);
    cust.discount = 0.05;

    printf("Please enter the items you want to buy: \n");
    for(int i=0; i<10; i++) {
        printf("Enter item name: ");
        fgets(items[i].name, sizeof(items[i].name), stdin);
        printf("Enter item quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter item price: ");
        scanf("%f", &items[i].price);
    }

    float total_price = 0;
    for(int i=0; i<10; i++) {
        total_price += items[i].quantity * items[i].price;
    }

    printf("Total price of items: %.2f\n", total_price);

    int choice;
    printf("Do you want to add or remove items from the bill? (1-Add, 2-Remove)\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter item name: ");
        fgets(items[10].name, sizeof(items[10].name), stdin);
        printf("Enter item quantity: ");
        scanf("%d", &items[10].quantity);
        printf("Enter item price: ");
        scanf("%f", &items[10].price);
        total_price += items[10].quantity * items[10].price;
        printf("Total price of items: %.2f\n", total_price);
    } else if(choice == 2) {
        int item_index;
        printf("Enter item index to remove: ");
        scanf("%d", &item_index);
        if(item_index >= 0 && item_index < 10) {
            total_price -= items[item_index].quantity * items[item_index].price;
            printf("Total price of items: %.2f\n", total_price);
        } else {
            printf("Invalid item index\n");
        }
    } else {
        printf("Invalid choice\n");
    }

    printf("Thank you for shopping at the Peaceful Cafe! Your bill is:\n");
    for(int i=0; i<10; i++) {
        printf("%s x %d @ %.2f = %.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].quantity * items[i].price);
    }
    printf("Total price of items: %.2f\n", total_price);

    return 0;
}