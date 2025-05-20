//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE_LEN 10

// Define the structure of a drug
typedef struct drug {
    char name[MAX_NAME_LEN];
    char price[MAX_PRICE_LEN];
    int quantity;
} drug;

// Function to add a drug to the inventory
void add_drug(drug *inventory, int *num_drugs) {
    // Get the drug's name, price, and quantity from the user
    printf("Enter the name of the drug: ");
    scanf("%s", inventory[*num_drugs].name);
    printf("Enter the price of the drug: ");
    scanf("%s", inventory[*num_drugs].price);
    printf("Enter the quantity of the drug: ");
    scanf("%d", &inventory[*num_drugs].quantity);

    // Increment the number of drugs in the inventory
    (*num_drugs)++;
}

// Function to sell a drug from the inventory
void sell_drug(drug *inventory, int *num_drugs) {
    // Get the name of the drug to be sold from the user
    char drug_name[MAX_NAME_LEN];
    printf("Enter the name of the drug to be sold: ");
    scanf("%s", drug_name);

    // Find the drug in the inventory
    int drug_index = -1;
    for (int i = 0; i < *num_drugs; i++) {
        if (strcmp(inventory[i].name, drug_name) == 0) {
            drug_index = i;
            break;
        }
    }

    // If the drug was not found, print an error message
    if (drug_index == -1) {
        printf("Error: Drug not found.\n");
        return;
    }

    // Get the quantity of the drug to be sold from the user
    int quantity_sold;
    printf("Enter the quantity of the drug to be sold: ");
    scanf("%d", &quantity_sold);

    // If the quantity to be sold is greater than the quantity in stock, print an error message
    if (quantity_sold > inventory[drug_index].quantity) {
        printf("Error: Not enough drugs in stock.\n");
        return;
    }

    // Update the quantity of the drug in stock
    inventory[drug_index].quantity -= quantity_sold;

    // Print a success message
    printf("Drug sold successfully.\n");
}

// Function to print the inventory
void print_inventory(drug *inventory, int num_drugs) {
    // Print the header
    printf("Inventory:\n");
    printf("Name\tPrice\tQuantity\n");

    // Print each drug in the inventory
    for (int i = 0; i < num_drugs; i++) {
        printf("%s\t%s\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Main function
int main() {
    // Create an array of drugs to store the inventory
    drug inventory[MAX_DRUGS];

    // Initialize the number of drugs in the inventory to 0
    int num_drugs = 0;

    // Get the user's choice
    int choice;
    do {
        // Print the menu
        printf("1. Add a drug\n");
        printf("2. Sell a drug\n");
        printf("3. Print the inventory\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_drug(inventory, &num_drugs);
                break;
            case 2:
                sell_drug(inventory, &num_drugs);
                break;
            case 3:
                print_inventory(inventory, num_drugs);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}