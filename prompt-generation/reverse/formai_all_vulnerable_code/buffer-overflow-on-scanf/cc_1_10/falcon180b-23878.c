//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<locale.h>

typedef struct {
    char name[30];
    int quantity;
    float price;
} item;

typedef struct {
    char name[30];
    int quantity;
    float price;
} order;

void addItem(item* menu, int *numItems) {
    printf("Enter item name: ");
    scanf("%s", menu[*numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &menu[*numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &menu[*numItems].price);
    (*numItems)++;
}

void displayMenu(item menu[], int numItems) {
    printf("Menu:\n");
    for(int i=0; i<numItems; i++) {
        printf("%s - %d - %.2f\n", menu[i].name, menu[i].quantity, menu[i].price);
    }
}

void placeOrder(order *bill, item menu[], int numItems) {
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    if(choice >= 1 && choice <= numItems) {
        strcpy(bill->name, menu[choice-1].name);
        bill->quantity = menu[choice-1].quantity;
        bill->price = menu[choice-1].price;
        printf("Order placed successfully!\n");
    }
    else {
        printf("Invalid choice.\n");
    }
}

void generateBill(order bill, float discount) {
    float total = bill.quantity * bill.price;
    if(discount > 0 && discount <= 0.5) {
        total *= (1 - discount);
    }
    printf("Total amount: %.2f\n", total);
}

int main() {
    setlocale(LC_ALL, "English");
    item menu[100];
    int numItems = 0;
    addItem(menu, &numItems);
    addItem(menu, &numItems);
    addItem(menu, &numItems);
    displayMenu(menu, numItems);
    order bill;
    placeOrder(&bill, menu, numItems);
    generateBill(bill, 0.2);
    return 0;
}