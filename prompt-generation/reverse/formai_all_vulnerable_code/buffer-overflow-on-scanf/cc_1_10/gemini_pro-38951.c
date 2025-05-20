//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    int quantity;
    float price;
    struct medicine *next;
} medicine;

// Head of the linked list
medicine *head = NULL;

// Function to add a new medicine to the list
void addMedicine(char *name, int quantity, float price) {
    // Allocate memory for the new medicine
    medicine *newMedicine = (medicine *)malloc(sizeof(medicine));
    
    // Check if memory was allocated successfully
    if (newMedicine == NULL) {
        printf("Error: Could not allocate memory for new medicine.\n");
        exit(1);
    }

    // Copy the medicine details to the new node
    strcpy(newMedicine->name, name);
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    newMedicine->next = NULL;

    // Add the new medicine to the list
    if (head == NULL) {
        head = newMedicine;
    } else {
        medicine *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMedicine;
    }

    printf("Medicine added successfully.\n");
}

// Function to display the list of medicines
void displayMedicines() {
    printf("\nList of Medicines:\n");
    medicine *current = head;
    if (current == NULL) {
        printf("No medicines in the list.\n");
    } else {
        while (current != NULL) {
            printf("Name: %s\n", current->name);
            printf("Quantity: %d\n", current->quantity);
            printf("Price: %.2f\n\n", current->price);
            current = current->next;
        }
    }
}

// Function to search for a medicine by name
void searchMedicine(char *name) {
    medicine *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("Name: %s\n", current->name);
            printf("Quantity: %d\n", current->quantity);
            printf("Price: %.2f\n\n", current->price);
            return;
        }
        current = current->next;
    }

    printf("Medicine not found.\n");
}

// Function to delete a medicine by name
void deleteMedicine(char *name) {
    medicine *current = head;
    medicine *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Medicine deleted successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Medicine not found.\n");
}

// Main function
int main() {
    int choice;
    char name[50];
    int quantity;
    float price;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new medicine\n");
        printf("2. Display the list of medicines\n");
        printf("3. Search for a medicine by name\n");
        printf("4. Delete a medicine by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the medicine: ");
                scanf(" %s", name);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &quantity);
                printf("Enter the price of the medicine: ");
                scanf("%f", &price);
                addMedicine(name, quantity, price);
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                printf("Enter the name of the medicine you want to search for: ");
                scanf(" %s", name);
                searchMedicine(name);
                break;
            case 4:
                printf("Enter the name of the medicine you want to delete: ");
                scanf(" %s", name);
                deleteMedicine(name);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}