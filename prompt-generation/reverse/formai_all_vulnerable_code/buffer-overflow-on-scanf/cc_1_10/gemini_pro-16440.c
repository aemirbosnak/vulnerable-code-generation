//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    char type[50];
    int quantity;
    float price;
} medicine;

// Function to add a new medicine to the inventory
void addMedicine(medicine *inventory, int *numMedicines) {
    // Get the details of the new medicine
    printf("Enter medicine name: ");
    scanf("%s", inventory[*numMedicines].name);
    printf("Enter medicine company: ");
    scanf("%s", inventory[*numMedicines].company);
    printf("Enter medicine type: ");
    scanf("%s", inventory[*numMedicines].type);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[*numMedicines].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*numMedicines].price);

    // Increment the number of medicines in the inventory
    (*numMedicines)++;
}

// Function to search for a medicine in the inventory by name
int searchMedicineByName(medicine *inventory, int numMedicines, char *name) {
    // Loop through the inventory and search for the medicine by name
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }

    // Return -1 if the medicine is not found
    return -1;
}

// Function to sell a medicine from the inventory
void sellMedicine(medicine *inventory, int *numMedicines, char *name, int quantity) {
    // Search for the medicine in the inventory by name
    int index = searchMedicineByName(inventory, *numMedicines, name);

    // Check if the medicine is found
    if (index == -1) {
        printf("Medicine not found in inventory.\n");
        return;
    }

    // Check if the quantity is available
    if (inventory[index].quantity < quantity) {
        printf("Insufficient quantity of medicine in inventory.\n");
        return;
    }

    // Deduct the quantity from the inventory
    inventory[index].quantity -= quantity;

    // Print the receipt
    printf("Medicine Name: %s\n", inventory[index].name);
    printf("Medicine Company: %s\n", inventory[index].company);
    printf("Medicine Type: %s\n", inventory[index].type);
    printf("Medicine Quantity: %d\n", quantity);
    printf("Medicine Price: %f\n", inventory[index].price);
    printf("Total Price: %f\n", inventory[index].price * quantity);
}

// Function to print the inventory
void printInventory(medicine *inventory, int numMedicines) {
    printf("Medicine Inventory:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("Medicine Name: %s\n", inventory[i].name);
        printf("Medicine Company: %s\n", inventory[i].company);
        printf("Medicine Type: %s\n", inventory[i].type);
        printf("Medicine Quantity: %d\n", inventory[i].quantity);
        printf("Medicine Price: %f\n\n", inventory[i].price);
    }
}

// Main function
int main() {
    // Initialize the inventory
    medicine inventory[100];
    int numMedicines = 0;

    // Add some initial medicines to the inventory
    addMedicine(inventory, &numMedicines);
    addMedicine(inventory, &numMedicines);
    addMedicine(inventory, &numMedicines);

    // Print the inventory
    printInventory(inventory, numMedicines);

    // Search for a medicine by name
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int index = searchMedicineByName(inventory, numMedicines, name);
    if (index == -1) {
        printf("Medicine not found in inventory.\n");
    } else {
        printf("Medicine found:\n");
        printf("Medicine Name: %s\n", inventory[index].name);
        printf("Medicine Company: %s\n", inventory[index].company);
        printf("Medicine Type: %s\n", inventory[index].type);
        printf("Medicine Quantity: %d\n", inventory[index].quantity);
        printf("Medicine Price: %f\n\n", inventory[index].price);
    }

    // Sell a medicine from the inventory
    char nameToSell[50];
    int quantityToSell;
    printf("Enter medicine name to sell: ");
    scanf("%s", nameToSell);
    printf("Enter medicine quantity to sell: ");
    scanf("%d", &quantityToSell);
    sellMedicine(inventory, &numMedicines, nameToSell, quantityToSell);

    // Print the updated inventory
    printInventory(inventory, numMedicines);

    return 0;
}