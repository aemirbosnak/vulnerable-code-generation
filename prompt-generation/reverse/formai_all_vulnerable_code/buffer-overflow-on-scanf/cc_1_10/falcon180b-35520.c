//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    int quantity;
} Item;

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} Customer;

void addItem(Item items[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);
    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);
    (*numItems)++;
}

void displayItems(Item items[], int numItems) {
    printf("\nItem List:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - %.2f - %d\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
}

void addCustomer(Customer customers[], int *numCustomers) {
    printf("Enter customer name: ");
    scanf("%s", customers[*numCustomers].name);
    printf("Enter customer age: ");
    scanf("%d", &customers[*numCustomers].age);
    printf("Enter customer gender (M/F): ");
    scanf(" %c", &customers[*numCustomers].gender);
    (*numCustomers)++;
}

void displayCustomers(Customer customers[], int numCustomers) {
    printf("\nCustomer List:\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d. %s - %d years old - %c\n", i+1, customers[i].name, customers[i].age, customers[i].gender);
    }
}

void generateBill(Item items[], Customer customers[], int numItems, int numCustomers) {
    printf("\nBill:\n");
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < numCustomers; j++) {
            if (strcmp(items[i].name, customers[j].name) == 0) {
                printf("%s bought %d %s(s) for %.2f each.\n", customers[j].name, items[i].quantity, items[i].name, items[i].price);
            }
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    Customer customers[MAX_ITEMS];
    int numItems = 0, numCustomers = 0;

    addItem(items, &numItems);
    addCustomer(customers, &numCustomers);

    displayItems(items, numItems);
    displayCustomers(customers, numCustomers);

    generateBill(items, customers, numItems, numCustomers);

    return 0;
}