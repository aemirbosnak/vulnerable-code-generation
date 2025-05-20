//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants
#define MAX_MEDICINES 100
#define MAX_MED_NAME 50

// Defining medicine structure
struct medicine {
    char name[MAX_MED_NAME];
    int quantity;
    float price;
};

// Function prototypes
void add_medicine(struct medicine medicines[], int *num_medicines);
void remove_medicine(struct medicine medicines[], int *num_medicines);
void update_price(struct medicine medicines[], int num_medicines);
void update_quantity(struct medicine medicines[], int num_medicines);
void display_medicines(struct medicine medicines[], int num_medicines);

int main() {
    struct medicine medicines[MAX_MEDICINES];
    int num_medicines = 0;
    int choice;
    int exit = 0;
    
    while (!exit) {
        printf("\n========= Medical Store Management System =========\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Update Price\n");
        printf("4. Update Quantity\n");
        printf("5. Display Medicines\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                remove_medicine(medicines, &num_medicines);
                break;
            case 3:
                update_price(medicines, num_medicines);
                break;
            case 4:
                update_quantity(medicines, num_medicines);
                break;
            case 5:
                display_medicines(medicines, num_medicines);
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}

// Function to add a medicine to the inventory
void add_medicine(struct medicine medicines[], int *num_medicines) {
    if (*num_medicines == MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }
    
    struct medicine med;
    printf("\nEnter medicine name: ");
    scanf("%s", med.name);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);
    printf("Enter price: ");
    scanf("%f", &med.price);
    
    medicines[*num_medicines] = med;
    (*num_medicines)++;
    
    printf("Medicine added successfully.\n");
}

// Function to remove a medicine from the inventory
void remove_medicine(struct medicine medicines[], int *num_medicines) {
    char name[MAX_MED_NAME];
    int found = 0;
    
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            found = 1;
            medicines[i] = medicines[(*num_medicines - 1)];
            (*num_medicines)--;
            printf("Medicine removed successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to update price of a medicine
void update_price(struct medicine medicines[], int num_medicines) {
    char name[MAX_MED_NAME];
    int found = 0;
    float price;
    
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            found = 1;
            printf("Enter new price: ");
            scanf("%f", &price);
            medicines[i].price = price;
            printf("Price updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to update quantity of a medicine
void update_quantity(struct medicine medicines[], int num_medicines) {
    char name[MAX_MED_NAME];
    int found = 0;
    int quantity;
    
    printf("\nEnter medicine name: ");
    scanf("%s", name);
    
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            medicines[i].quantity = quantity;
            printf("Quantity updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to display list of medicines in inventory
void display_medicines(struct medicine medicines[], int num_medicines) {
    printf("\nMedicines in inventory:\n");
    printf("=================================================\n");
    printf("Medicine Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%-20s\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("=================================================\n");
}