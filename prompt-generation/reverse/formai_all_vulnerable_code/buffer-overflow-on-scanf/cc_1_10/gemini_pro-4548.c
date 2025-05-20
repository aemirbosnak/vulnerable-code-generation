//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *num_medicines) {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf(" %s", inventory[*num_medicines].name);
    printf("Enter the price of the medicine: ");
    scanf(" %f", &inventory[*num_medicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf(" %d", &inventory[*num_medicines].quantity);

    // Increment the number of medicines in the inventory
    (*num_medicines)++;
}

// Function to search for a medicine by name
int search_medicine(medicine *inventory, int num_medicines, char *name) {
    // Loop through the inventory and compare the name of each medicine to the given name
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }

    // If the medicine was not found, return -1
    return -1;
}

// Function to update the quantity of a medicine
void update_quantity(medicine *inventory, int num_medicines, char *name, int quantity) {
    // Get the index of the medicine in the inventory
    int index = search_medicine(inventory, num_medicines, name);

    // If the medicine was found, update its quantity
    if (index != -1) {
        inventory[index].quantity += quantity;
    } else {
        printf("Medicine not found.\n");
    }
}

// Function to delete a medicine from the inventory
void delete_medicine(medicine *inventory, int *num_medicines, char *name) {
    // Get the index of the medicine in the inventory
    int index = search_medicine(inventory, *num_medicines, name);

    // If the medicine was found, delete it
    if (index != -1) {
        for (int i = index; i < *num_medicines - 1; i++) {
            inventory[i] = inventory[i + 1];
        }

        (*num_medicines)--;
    } else {
        printf("Medicine not found.\n");
    }
}

// Function to print the inventory
void print_inventory(medicine *inventory, int num_medicines) {
    // Loop through the inventory and print the details of each medicine
    for (int i = 0; i < num_medicines; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Price: %.2f\n", inventory[i].price);
        printf("Quantity: %d\n\n", inventory[i].quantity);
    }
}

// Main function
int main() {
    // Create an array of medicines
    medicine inventory[100];

    // Initialize the number of medicines in the inventory to 0
    int num_medicines = 0;

    // Add some medicines to the inventory
    add_medicine(inventory, &num_medicines);
    add_medicine(inventory, &num_medicines);
    add_medicine(inventory, &num_medicines);

    // Print the inventory
    print_inventory(inventory, num_medicines);

    // Search for a medicine by name
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf(" %s", name);
    int index = search_medicine(inventory, num_medicines, name);
    if (index != -1) {
        printf("Medicine found:\n");
        printf("Name: %s\n", inventory[index].name);
        printf("Price: %.2f\n", inventory[index].price);
        printf("Quantity: %d\n\n", inventory[index].quantity);
    } else {
        printf("Medicine not found.\n");
    }

    // Update the quantity of a medicine
    int quantity;
    printf("Enter the name of the medicine you want to update the quantity of: ");
    scanf(" %s", name);
    printf("Enter the new quantity: ");
    scanf(" %d", &quantity);
    update_quantity(inventory, num_medicines, name, quantity);

    // Print the updated inventory
    print_inventory(inventory, num_medicines);

    // Delete a medicine from the inventory
    printf("Enter the name of the medicine you want to delete: ");
    scanf(" %s", name);
    delete_medicine(inventory, &num_medicines, name);

    // Print the updated inventory
    print_inventory(inventory, num_medicines);

    return 0;
}