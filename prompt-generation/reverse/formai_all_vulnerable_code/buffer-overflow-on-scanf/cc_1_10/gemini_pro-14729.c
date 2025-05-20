//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[30];
    int quantity;
    float price;
};

// Function to add a new medicine to the store
void add_medicine(struct medicine *store, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*size].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*size].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*size].price);
    (*size)++;
}

// Function to sell a medicine from the store
void sell_medicine(struct medicine *store, int *size) {
    char name[30];
    int quantity;
    printf("Enter the name of the medicine you want to sell: ");
    scanf("%s", name);
    printf("Enter the quantity of the medicine you want to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *size; i++) {
        if (strcmp(store[i].name, name) == 0) {
            if (store[i].quantity >= quantity) {
                store[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
            } else {
                printf("Insufficient quantity of the medicine!\n");
            }
            break;
        }
    }
}

// Function to display the inventory of the store
void display_inventory(struct medicine *store, int size) {
    printf("\n\nInventory of the store:\n\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\n", store[i].name, store[i].quantity, store[i].price);
    }
}

// Main function
int main() {
    struct medicine store[100];
    int size = 0;
    int choice;
    do {
        printf("\n\nMedical Store Management System\n\n");
        printf("1. Add a new medicine\n");
        printf("2. Sell a medicine\n");
        printf("3. Display the inventory\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(store, &size);
                break;
            case 2:
                sell_medicine(store, &size);
                break;
            case 3:
                display_inventory(store, size);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}