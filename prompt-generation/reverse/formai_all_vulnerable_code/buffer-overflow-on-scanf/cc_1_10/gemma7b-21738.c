//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU_SIZE 5

typedef struct Item {
    char name[50];
    int price;
    int quantity;
} Item;

Item items[MENU_SIZE] = {
    {"Coffee", 50, 0},
    {"Tea", 40, 0},
    {"Juice", 30, 0},
    {"Smoothie", 60, 0},
    {"Biscuits", 20, 0}
};

void printMenu() {
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%s - %d\n", items[i].name, items[i].price);
    }
}

int calculateTotal(int quantity, int price) {
    return quantity * price;
}

void generateBill() {
    char name[50];
    int quantity;
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the quantity of each item: ");
    for (int i = 0; i < MENU_SIZE; i++) {
        scanf("%d", &quantity);
        items[i].quantity += quantity;
    }

    int total = 0;
    for (int i = 0; i < MENU_SIZE; i++) {
        total += calculateTotal(items[i].quantity, items[i].price);
    }

    printf("Bill:\n");
    printf("Name: %s\n", name);
    printf("Items:\n");
    for (int i = 0; i < MENU_SIZE; i++) {
        printf("%s - %d x %d = %d\n", items[i].name, items[i].quantity, items[i].price, calculateTotal(items[i].quantity, items[i].price));
    }

    printf("Total: %d\n", total);
    printf("Thank you for your visit!\n");
}

int main() {
    generateBill();
    return 0;
}