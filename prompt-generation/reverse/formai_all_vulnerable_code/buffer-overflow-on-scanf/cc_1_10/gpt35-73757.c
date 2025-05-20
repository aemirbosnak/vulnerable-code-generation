//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing each medicine record
typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

// Function to display the menu options
void displayMenu() {
    printf("\n\n*** Welcome to Happy Medical Store ***\n");
    printf("\n1. Add a new medicine\n");
    printf("2. Sell a medicine\n");
    printf("3. Display the current stock of medicines\n");
    printf("4. Total revenue generated\n");
    printf("5. Exit the program\n");
}

// Function to add a new medicine to the inventory
void addMedicine(medicine inventory[], int *count) {
    printf("\nEnter the name of the medicine: ");
    scanf("%s", inventory[*count].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
    printf("\nMedicine added successfully!\n");
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine inventory[], int count, float *revenue) {
    char name[50];
    int qty_sold, i;
    float price;
    printf("\nEnter the name of the medicine to sell: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Enter the quantity of medicine to sell: ");
            scanf("%d", &qty_sold);
            if (qty_sold > inventory[i].quantity) {
                printf("Sorry, we do not have enough stock of %s\n", inventory[i].name);
                break;
            }
            price = qty_sold * inventory[i].price;
            inventory[i].quantity -= qty_sold;
            *revenue += price;
            printf("\nSold %d %s for $%.2f\n", qty_sold, inventory[i].name, price);
            break;
        }
    }
    if (i == count) {
        printf("Sorry, %s is not available in our store\n", name);
    }
}

// Function to display the current stock of medicines
void displayInventory(medicine inventory[], int count) {
    int i;
    printf("\n\nMedicine Name\tQuantity\tPrice per unit\n");
    for (i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int option, count = 0;
    float revenue = 0.0;
    // Define an array to store the medicines
    medicine inventory[50];
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                sellMedicine(inventory, count, &revenue);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("\nTotal revenue generated so far: $%.2f\n", revenue);
                break;
            case 5:
                printf("\nThank you for using Happy Medical Store. Goodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid option selected. Please try again.\n");
        }
    } while (1);
    return 0;
}