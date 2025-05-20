//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for medicine
struct medicine {
    char name[20];
    int quantity;
    float price;
};

// Define global variables
struct medicine inventory[50];
int num_medicines = 0;

// Function to add medicine to inventory
void add_medicine() {
    // Check if inventory is full
    if (num_medicines >= 50) {
        printf("Error: Inventory is full.\n");
        return;
    }

    // Get medicine details from user
    printf("Enter name of medicine: ");
    scanf("%s", inventory[num_medicines].name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &inventory[num_medicines].quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &inventory[num_medicines].price);
    
    // Increment number of medicines in inventory
    num_medicines++;
}

// Function to remove medicine from inventory
void remove_medicine() {
    // Check if inventory is empty
    if (num_medicines == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    // Get medicine name from user
    char name[20];
    printf("Enter name of medicine to remove: ");
    scanf("%s", name);

    // Find medicine in inventory
    int index;
    for (index = 0; index < num_medicines; index++) {
        if (strcmp(inventory[index].name, name) == 0) {
            break;
        }
    }

    // Check if medicine was found
    if (index == num_medicines) {
        printf("Error: Medicine not found.\n");
        return;
    }

    // Remove medicine from inventory
    for (int i = index; i < num_medicines - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    num_medicines--;
}

// Function to search for medicine by name
void search_medicine() {
    // Check if inventory is empty
    if (num_medicines == 0) {
        printf("Error: Inventory is empty.\n");
        return;
    }

    // Get medicine name from user
    char name[20];
    printf("Enter name of medicine to search: ");
    scanf("%s", name);

    // Find medicine in inventory
    int index;
    for (index = 0; index < num_medicines; index++) {
        if (strcmp(inventory[index].name, name) == 0) {
            break;
        }
    }

    // Check if medicine was found
    if (index == num_medicines) {
        printf("Error: Medicine not found.\n");
        return;
    }

    // Print medicine details
    struct medicine m = inventory[index];
    printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", m.name, m.quantity, m.price);
}

int main() {
    int choice;

    do {
        // Print menu
        printf("\nMedical Store Management System\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Search medicine\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}