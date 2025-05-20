//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
    char name[20];
    int quantity;
    float price;
};

void manageInventory(struct Medicine *med) {
    printf("Enter the name of the medicine: ");
    scanf("%s", med->name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med->quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &med->price);
}

void displayInventory(struct Medicine *med) {
    printf("Name: %s\n", med->name);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
}

int main() {
    struct Medicine med;
    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("Enter 1 to manage inventory, 2 to display inventory, 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageInventory(&med);
                break;
            case 2:
                displayInventory(&med);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}