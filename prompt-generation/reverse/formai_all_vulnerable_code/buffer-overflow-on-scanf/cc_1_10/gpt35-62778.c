//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MED 10 // Max number of medicines that can be added

// Structure to store details of each medicine
struct medicine {
    int id;
    char name[20];
    float price;
    int quantity;
};

// Global array to store medicines
struct medicine medicines[MAX_MED];

// Function to add new medicine
void add_medicine() {
    int id, quantity;
    char name[20];
    float price;

    // Determine the id for the new medicine
    if (medicines[0].id == 0) {
        id = 1;
    } else {
        id = medicines[MAX_MED - 1].id + 1;
    }

    // Take input for the new medicine
    printf("Enter name of medicine: ");
    scanf("%s", name);
    printf("Enter price of medicine: ");
    scanf("%f", &price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &quantity);

    // Add the new medicine to the array
    struct medicine new_medicine = {id, name, price, quantity};
    medicines[id - 1] = new_medicine;

    // Display success message
    printf("New medicine with id %d added successfully.\n", id);
}

// Function to remove a medicine
void remove_medicine() {
    int id;

    // Take input for the id of the medicine to remove
    printf("Enter id of medicine to remove: ");
    scanf("%d", &id);

    // Find the medicine in the array
    int index = -1;
    for (int i = 0; i < MAX_MED; i++) {
        if (medicines[i].id == id) {
            index = i;
            break;
        }
    }

    // If the medicine is found, remove it from the array
    if (index != -1) {
        for (int i = index; i < MAX_MED - 1; i++) {
            medicines[i] = medicines[i + 1];
        }

        // Display success message
        printf("Medicine with id %d removed successfully.\n", id);
    } else {
        // Display error message
        printf("Medicine with id %d not found.\n", id);
    }
}

// Function to display details of all medicines
void display_medicines() {
    // Display heading
    printf("ID\tName\tPrice\tQuantity\n");

    // Loop through all medicines and display their details
    for (int i = 0; i < MAX_MED; i++) {
        if (medicines[i].id != 0) {
            printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
        }
    }
}

int main() {
    int choice;

    // Display menu
    printf("Welcome to Medical Store Management System\n");
    printf("1. Add new medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Display all medicines\n");
    printf("4. Exit\n");

    // Loop to take user input and perform corresponding action
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                display_medicines();
                break;
            case 4:
                printf("Thank you for using Medical Store Management System.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}