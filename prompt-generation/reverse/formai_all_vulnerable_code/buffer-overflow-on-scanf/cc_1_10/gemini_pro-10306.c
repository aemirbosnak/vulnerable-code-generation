//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the inventory
void add_medicine(medicine *inventory, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter company name: ");
    scanf("%s", inventory[*count].company);
    printf("Enter quantity: ");
    scanf("%d", &inventory[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[*count].price);
    (*count)++;
}

// Function to search for a medicine by name
void search_medicine(medicine *inventory, int count) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Company: %s\n", inventory[i].company);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %f\n", inventory[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to update the quantity of a medicine
void update_quantity(medicine *inventory, int count) {
    char name[50];
    int quantity;
    printf("Enter medicine name to update quantity: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Quantity updated.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to delete a medicine from the inventory
void delete_medicine(medicine *inventory, int *count) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*count)--;
            printf("Medicine deleted.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to display the inventory
void display_inventory(medicine *inventory, int count) {
    printf("Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("Company: %s\n", inventory[i].company);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %f\n\n", inventory[i].price);
    }
}

// Main function
int main() {
    medicine inventory[100];
    int count = 0;

    // Menu-driven program
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update the quantity of a medicine\n");
        printf("4. Delete a medicine\n");
        printf("5. Display the inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(inventory, &count);
                break;
            case 2:
                search_medicine(inventory, count);
                break;
            case 3:
                update_quantity(inventory, count);
                break;
            case 4:
                delete_medicine(inventory, &count);
                break;
            case 5:
                display_inventory(inventory, count);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid number.\n");
        }
    } while (choice != 6);

    return 0;
}