//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
struct Medicine {
    char name[50];
    char brand[50];
    int quantity;
    float price;
    float discount;
};

// Function to display the menu
void displayMenu() {
    printf("\n\t\tMedical Store Management System\n\n");
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine\n");
    printf("4. Sell a medicine\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

// Function to add a new medicine
void addMedicine() {
    struct Medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine brand: ");
    scanf("%s", medicine.brand);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    printf("Enter medicine discount: ");
    scanf("%f", &medicine.discount);
    
    // Open the file in append mode
    FILE *fp = fopen("medicines.txt", "a");
    
    // Write the medicine details to the file
    fprintf(fp, "%s %s %d %f %f\n", medicine.name, medicine.brand, medicine.quantity, medicine.price, medicine.discount);
    
    // Close the file
    fclose(fp);
    
    printf("Medicine added successfully!\n");
}

// Function to display all medicines
void displayMedicines() {
    // Open the file in read mode
    FILE *fp = fopen("medicines.txt", "r");
    
    // Read the medicine details from the file
    struct Medicine medicine;
    while (fscanf(fp, "%s %s %d %f %f\n", medicine.name, medicine.brand, &medicine.quantity, &medicine.price, &medicine.discount) != EOF) {
        // Print the medicine details
        printf("Medicine name: %s\n", medicine.name);
        printf("Medicine brand: %s\n", medicine.brand);
        printf("Medicine quantity: %d\n", medicine.quantity);
        printf("Medicine price: %f\n", medicine.price);
        printf("Medicine discount: %f\n\n", medicine.discount);
    }
    
    // Close the file
    fclose(fp);
}

// Function to search for a medicine
void searchMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    
    // Open the file in read mode
    FILE *fp = fopen("medicines.txt", "r");
    
    // Read the medicine details from the file
    struct Medicine medicine;
    int found = 0;
    while (fscanf(fp, "%s %s %d %f %f\n", medicine.name, medicine.brand, &medicine.quantity, &medicine.price, &medicine.discount) != EOF) {
        // Check if the medicine name matches the search term
        if (strcmp(medicine.name, name) == 0) {
            // Print the medicine details
            printf("Medicine name: %s\n", medicine.name);
            printf("Medicine brand: %s\n", medicine.brand);
            printf("Medicine quantity: %d\n", medicine.quantity);
            printf("Medicine price: %f\n", medicine.price);
            printf("Medicine discount: %f\n", medicine.discount);
            found = 1;
            break;
        }
    }
    
    // Close the file
    fclose(fp);
    
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to sell a medicine
void sellMedicine() {
    char name[50];
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    // Open the file in read mode
    FILE *fp = fopen("medicines.txt", "r");
    
    // Read the medicine details from the file
    struct Medicine medicine;
    int found = 0;
    while (fscanf(fp, "%s %s %d %f %f\n", medicine.name, medicine.brand, &medicine.quantity, &medicine.price, &medicine.discount) != EOF) {
        // Check if the medicine name matches the search term
        if (strcmp(medicine.name, name) == 0) {
            // Check if the quantity is available
            if (medicine.quantity >= quantity) {
                // Calculate the total price
                float total_price = medicine.price * quantity * (1 - medicine.discount/100);
                
                // Deduct the quantity from the stock
                medicine.quantity -= quantity;
                
                // Open the file in write mode
                FILE *fp = fopen("medicines.txt", "w");
                
                // Write the updated medicine details to the file
                fprintf(fp, "%s %s %d %f %f\n", medicine.name, medicine.brand, medicine.quantity, medicine.price, medicine.discount);
                
                // Close the file
                fclose(fp);
                
                printf("Medicine sold successfully!\n");
                printf("Total price: %f\n", total_price);
                found = 1;
                break;
            } else {
                printf("Insufficient quantity!\n");
                found = 1;
                break;
            }
        }
    }
    
    // Close the file
    fclose(fp);
    
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Main function
int main() {
    int choice;
    do {
        // Display the menu
        displayMenu();
        
        // Get the user's choice
        scanf("%d", &choice);
        
        // Perform the selected action
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}