//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float amount;
} Customer;

void addItem(Item items[], int *size) {
    printf("Enter item ID: ");
    scanf("%d", &items[*size].id);
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    (*size)++;
}

void displayItems(Item items[], int size) {
    printf("\nItem ID\tItem Name\tPrice\tQuantity\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }
}

void addCustomer(Customer customers[], int *size) {
    printf("Enter customer name: ");
    scanf("%s", customers[*size].name);
    printf("Enter quantity purchased: ");
    scanf("%d", &customers[*size].quantity);
    printf("Enter amount paid: ");
    scanf("%f", &customers[*size].amount);
    (*size)++;
}

void displayCustomers(Customer customers[], int size) {
    printf("\nCustomer Name\tQuantity\tAmount\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t%.2f\n", customers[i].name, customers[i].quantity, customers[i].amount);
    }
}

void searchItem(Item items[], int size, int id) {
    for(int i=0; i<size; i++) {
        if(items[i].id == id) {
            printf("\nItem found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Price: %.2f\n", items[i].price);
            printf("Quantity: %d\n", items[i].quantity);
        }
    }
}

int main() {
    Item items[100];
    int sizeItems=0;
    Customer customers[100];
    int sizeCustomers=0;

    addItem(items, &sizeItems);

    displayItems(items, sizeItems);

    addCustomer(customers, &sizeCustomers);

    displayCustomers(customers, sizeCustomers);

    searchItem(items, sizeItems, 1);

    return 0;
}