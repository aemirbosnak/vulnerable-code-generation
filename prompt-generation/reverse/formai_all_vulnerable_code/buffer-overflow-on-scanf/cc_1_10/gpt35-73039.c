//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
    char expiration_date[50];
} Medicine;

// Declare global variables
Medicine inventory[100]; // Array to store medicine inventory
int num_medicines = 0; // Number of medicines currently in inventory

// Function to add medicine to inventory
void addMedicine() {
    printf("Enter medicine name: ");
    scanf("%s", inventory[num_medicines].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[num_medicines].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[num_medicines].price);
    printf("Enter expiration date: ");
    scanf("%s", inventory[num_medicines].expiration_date);
    num_medicines++;
    printf("Medicine added to inventory successfully!\n");
}

// Function to search for medicine in inventory by name
void searchMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for(int i = 0; i < num_medicines; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine details:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Expiration date: %s\n", inventory[i].expiration_date);
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

// Function to display the entire inventory
void displayInventory() {
    printf("\nCurrent inventory:\n");
    printf("Name\tQuantity\tPrice\tExpiration date\n");
    for(int i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%.2f\t%s\n", inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].expiration_date);
    }
}

int main() {
    int choice;
    do {
        // Display menu
        printf("\n1. Add medicine to inventory\n");
        printf("2. Search for medicine by name\n");
        printf("3. Display entire inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform corresponding action based on choice
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}