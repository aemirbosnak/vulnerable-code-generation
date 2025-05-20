//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the store
void addMedicine(Medicine *store, int *size) {
    printf("Enter the name of the medicine: ");
    scanf(" %s", store[*size].name);
    
    printf("Enter the price of the medicine: ");
    scanf(" %f", &store[*size].price);
    
    printf("Enter the quantity of the medicine: ");
    scanf(" %d", &store[*size].quantity);
    
    (*size)++;
}

// Function to search for a medicine in the store
int searchMedicine(Medicine *store, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(store[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to sell a medicine from the store
void sellMedicine(Medicine *store, int size, char *name, int quantity) {
    int index = searchMedicine(store, size, name);
    if (index == -1) {
        printf("Medicine not found.\n");
    } else {
        if (store[index].quantity >= quantity) {
            store[index].quantity -= quantity;
            printf("Medicine sold successfully.\n");
        } else {
            printf("Insufficient quantity of medicine.\n");
        }
    }
}

// Function to display the details of all the medicines in the store
void displayMedicines(Medicine *store, int size) {
    printf("\nThe medicines in the store are:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - Rs. %.2f - %d units\n", store[i].name, store[i].price, store[i].quantity);
    }
}

// Main function
int main() {
    Medicine store[100];
    int size = 0;
    int choice;
    char name[50];
    int quantity;
    
    do {
        printf("\n\n\n");
        printf("**********************************\n");
        printf("* Welcome to the Medical Store!  *\n");
        printf("**********************************\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Sell a medicine\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(store, &size);
                break;
            case 2:
                printf("Enter the name of the medicine: ");
                scanf(" %s", name);
                int index = searchMedicine(store, size, name);
                if (index == -1) {
                    printf("Medicine not found.\n");
                } else {
                    printf("Medicine found: %s - Rs. %.2f - %d units\n", store[index].name, store[index].price, store[index].quantity);
                }
                break;
            case 3:
                printf("Enter the name of the medicine: ");
                scanf(" %s", name);
                printf("Enter the quantity to be sold: ");
                scanf(" %d", &quantity);
                sellMedicine(store, size, name, quantity);
                break;
            case 4:
                displayMedicines(store, size);
                break;
            case 5:
                printf("Thank you for using the Medical Store. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}