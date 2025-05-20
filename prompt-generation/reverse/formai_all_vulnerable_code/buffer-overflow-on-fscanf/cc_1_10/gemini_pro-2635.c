//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
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
void addMedicine(medicine *inventory, int *size) {
    printf("Enter the name of the medicine: ");
    scanf("%s", inventory[*size].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &inventory[*size].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &inventory[*size].quantity);
    (*size)++;
}

// Function to search for a medicine by name
void searchMedicine(medicine *inventory, int size) {
    char name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\n", inventory[i].name);
            printf("Price: %f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to display the inventory
void displayInventory(medicine *inventory, int size) {
    printf("Medicine Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s %f %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to sort the inventory by name
void sortInventory(medicine *inventory, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(inventory[i].name, inventory[j].name) > 0) {
                medicine temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

// Function to save the inventory to a file
void saveInventory(medicine *inventory, int size) {
    FILE *fp;
    fp = fopen("inventory.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %f %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    fclose(fp);
}

// Function to load the inventory from a file
void loadInventory(medicine *inventory, int *size) {
    FILE *fp;
    fp = fopen("inventory.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(fp, "%s %f %d", inventory[*size].name, &inventory[*size].price, &inventory[*size].quantity) != EOF) {
        (*size)++;
    }
    fclose(fp);
}

// Main function
int main() {
    medicine inventory[100];
    int size = 0;
    int choice;

    while (1) {
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Display the inventory\n");
        printf("4. Sort the inventory\n");
        printf("5. Save the inventory to a file\n");
        printf("6. Load the inventory from a file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &size);
                break;
            case 2:
                searchMedicine(inventory, size);
                break;
            case 3:
                displayInventory(inventory, size);
                break;
            case 4:
                sortInventory(inventory, size);
                break;
            case 5:
                saveInventory(inventory, size);
                printf("Inventory saved to file.\n");
                break;
            case 6:
                loadInventory(inventory, &size);
                printf("Inventory loaded from file.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}