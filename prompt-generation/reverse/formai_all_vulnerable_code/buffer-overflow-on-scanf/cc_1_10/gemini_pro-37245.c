//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
    char expiry_date[11];
} medicine;

// Function to add a new medicine
void add_medicine(medicine *med, int *num_med) {
    printf("Enter medicine name: ");
    scanf("%s", med[*num_med].name);
    printf("Enter quantity: ");
    scanf("%d", &med[*num_med].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*num_med].price);
    printf("Enter expiry date (dd/mm/yyyy): ");
    scanf("%s", med[*num_med].expiry_date);
    (*num_med)++;
}

// Function to delete a medicine
void delete_medicine(medicine *med, int *num_med) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *num_med; i++) {
        if (strcmp(med[i].name, name) == 0) {
            // Shift all medicines after the deleted one to the left
            for (int j = i; j < *num_med - 1; j++) {
                med[j] = med[j + 1];
            }
            (*num_med)--;
            printf("Medicine deleted successfully\n");
            return;
        }
    }
    printf("Medicine not found\n");
}

// Function to display all medicines
void display_medicines(medicine *med, int num_med) {
    printf("\n%-20s %-10s %-10s %-15s\n", "Name", "Quantity", "Price", "Expiry Date");
    for (int i = 0; i < num_med; i++) {
        printf("%-20s %-10d %-10.2f %-15s\n", med[i].name, med[i].quantity, med[i].price, med[i].expiry_date);
    }
    printf("\n");
}

// Function to search for a medicine
void search_medicine(medicine *med, int num_med) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_med; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("\n%-20s %-10s %-10s %-15s\n", "Name", "Quantity", "Price", "Expiry Date");
            printf("%-20s %-10d %-10.2f %-15s\n", med[i].name, med[i].quantity, med[i].price, med[i].expiry_date);
            return;
        }
    }
    printf("Medicine not found\n");
}

// Function to sort medicines by name
void sort_medicines(medicine *med, int num_med) {
    for (int i = 0; i < num_med - 1; i++) {
        for (int j = i + 1; j < num_med; j++) {
            if (strcmp(med[i].name, med[j].name) > 0) {
                // Swap medicines i and j
                medicine temp = med[i];
                med[i] = med[j];
                med[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Initialize the array of medicines
    medicine med[100];

    // Initialize the number of medicines to 0
    int num_med = 0;

    // Display the main menu
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add a medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Display all medicines\n");
        printf("4. Search for a medicine\n");
        printf("5. Sort medicines by name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_medicine(med, &num_med);
                break;
            case 2:
                delete_medicine(med, &num_med);
                break;
            case 3:
                display_medicines(med, num_med);
                break;
            case 4:
                search_medicine(med, num_med);
                break;
            case 5:
                sort_medicines(med, num_med);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}