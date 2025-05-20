//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to store the details of each medicine
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Define global variables
struct Medicine inventory[100]; // Stores the inventory of medicines
int num_medicines = 0; // Keeps count of the number of medicines in inventory

// Function to add a new medicine to the inventory
void add_medicine() {
    struct Medicine new_medicine;

    printf("Enter medicine details:\n");
    printf("ID: ");
    scanf("%d", &new_medicine.id);
    printf("Name: ");
    scanf("%s", new_medicine.name);
    printf("Price: ");
    scanf("%f", &new_medicine.price);
    printf("Quantity: ");
    scanf("%d", &new_medicine.quantity);

    inventory[num_medicines] = new_medicine;
    num_medicines++;

    printf("Medicine added successfully.\n");
}

// Function to display the list of medicines in the inventory
void display_inventory() {
    printf("Current inventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");

    for (int i=0; i<num_medicines; i++) {
        printf("%d\t%s\t%.2f\t%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to search for a medicine by ID
int search_medicine(int id) {
    for (int i=0; i<num_medicines; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }

    return -1; // Returns -1 if medicine with given ID is not found
}

// Function to update the quantity of a medicine
void update_quantity() {
    int id, qty;
    printf("Enter medicine ID: ");
    scanf("%d", &id);

    int medicine_index = search_medicine(id);

    if (medicine_index == -1) {
        printf("Medicine with ID %d not found.\n", id);
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &qty);

    inventory[medicine_index].quantity = qty;

    printf("Medicine quantity updated successfully.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Add medicine\n");
        printf("2. Display inventory\n");
        printf("3. Update quantity\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                update_quantity();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}