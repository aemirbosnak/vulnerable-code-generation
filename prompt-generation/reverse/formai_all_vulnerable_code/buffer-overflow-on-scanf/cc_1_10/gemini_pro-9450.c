//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
// Neon City Medical Store Management System
// Access granted: Nightcrawler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-themed data structures
typedef struct {
    char* name;
    int quantity;
    float price;
} Cyberware;

typedef struct {
    char* id;
    char* name;
    int location;
    Cyberware* inventory;
    int num_items;
} MedicalStore;

// Initialize the system with hardcoded data
MedicalStore* init_system() {
    MedicalStore* system = malloc(sizeof(MedicalStore));

    system->id = "MED-001";
    system->name = "Trauma Corp";
    system->location = 27;

    // Add some cyberware to the inventory
    system->inventory = malloc(sizeof(Cyberware) * 3);
    system->num_items = 3;
    
    strcpy(system->inventory[0].name, "Neuralink");
    system->inventory[0].quantity = 5;
    system->inventory[0].price = 1000.0;
    
    strcpy(system->inventory[1].name, "Cybernetic Arm");
    system->inventory[1].quantity = 1;
    system->inventory[1].price = 5000.0;
    
    strcpy(system->inventory[2].name, "Biotech Heart");
    system->inventory[2].quantity = 2;
    system->inventory[2].price = 2000.0;

    return system;
}

// Display the system's inventory
void display_inventory(MedicalStore* system) {
    printf("Welcome to %s, runner. Accessing inventory:\n", system->name);
    for (int i = 0; i < system->num_items; i++) {
        printf("%d. %s - Quantity: %d, Price: %f\n", i+1, system->inventory[i].name, system->inventory[i].quantity, system->inventory[i].price);
    }
    printf("End of inventory.\n");
}

// Process a transaction
void process_transaction(MedicalStore* system) {
    int item_index;
    int quantity;
    printf("Enter the item index you wish to purchase: ");
    scanf("%d", &item_index);
    if (item_index < 1 || item_index > system->num_items) {
        printf("Invalid item index. Transaction aborted.\n");
        return;
    }

    printf("Enter the quantity you wish to purchase: ");
    scanf("%d", &quantity);
    if (quantity <= 0 || quantity > system->inventory[item_index-1].quantity) {
        printf("Invalid quantity. Transaction aborted.\n");
        return;
    }

    // Calculate the total cost
    float total_cost = system->inventory[item_index-1].price * quantity;
    printf("\nTotal cost: %f\n", total_cost);

    // Process the payment
    int payment_option;
    printf("Choose a payment method:\n1. Credsticks\n2. Bitcoin\n3. Cybernetic implants (not recommended)\n");
    scanf("%d", &payment_option);
    switch (payment_option) {
        case 1:
            printf("Transaction successful. Insert credsticks now.\n");
            break;
        case 2:
            printf("Transaction successful. Send bitcoins to wallet ID: %s\n", "walletID");
            break;
        case 3:
            printf("Transaction aborted. Cybernetic implants are not a valid payment method at this time.\n");
            break;
        default:
            printf("Invalid payment option. Transaction aborted.\n");
    }

    // Update the inventory
    system->inventory[item_index-1].quantity -= quantity;
}

// Main program
int main() {
    // Initialize the system
    MedicalStore* system = init_system();

    // Display the main menu
    int choice;
    while (1) {
        printf("\nNEON CITY MEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("1. Display Inventory\n2. Process Transaction\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_inventory(system);
                break;
            case 2:
                process_transaction(system);
                break;
            case 3:
                printf("Exiting the system. Have a nice night in Neon City.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}