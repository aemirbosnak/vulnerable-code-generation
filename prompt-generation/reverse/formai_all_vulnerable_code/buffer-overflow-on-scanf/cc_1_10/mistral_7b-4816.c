//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define NUM_ITEMS 5
#define MIN_BALANCE 1.50

typedef struct {
    char name[20];
    float price;
    int stock;
} Item;

Item items[NUM_ITEMS] = {
    {"Coke", 1.25, 10},
    {"Pepsi", 1.35, 5},
    {"Chips", 0.75, 20},
    {"Chocolate", 1.00, 8},
    {"Gum", 0.65, 30}
};

void printMenu() {
    printf("\n*** Welcome to the Vending Machine ***\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

int main() {
    float balance;
    int choice, quantity;

    printf("Insert your money: $");
    scanf("%f", &balance);

    if (balance < MIN_BALANCE) {
        printf("Insufficient balance! Please insert at least $%.2f.\n", MIN_BALANCE);
        return 1;
    }

    printMenu();

    do {
        printf("\nSelect an item (enter the number): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > NUM_ITEMS) {
            printf("Invalid selection! Please try again.\n");
            continue;
        }

        printf("How many items would you like to buy? ");
        scanf("%d", &quantity);

        if (items[choice-1].stock < quantity) {
            printf("Insufficient stock for item %s! Only %d left.\n", items[choice-1].name, items[choice-1].stock);
            continue;
        }

        float cost = items[choice-1].price * quantity;
        balance -= cost;
        items[choice-1].stock -= quantity;
        printf("Dispensing %d %s(s)...\n", quantity, items[choice-1].name);
        printf("Your remaining balance is: $%.2f\n", balance);

    } while (choice != 0);

    printf("\nThank you for using the vending machine!");

    return 0;
}