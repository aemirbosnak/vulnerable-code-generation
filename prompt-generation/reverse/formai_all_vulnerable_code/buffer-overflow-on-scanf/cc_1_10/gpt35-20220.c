//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of strings
#define MAX_STRING_LENGTH 50

// Define the maximum number of medicines
#define MAX_MEDICINES 100

// Define the structure for a medicine
struct Medicine {
    char name[MAX_STRING_LENGTH];
    char manufacturer[MAX_STRING_LENGTH];
    int quantity;
    float price;
};

// Define a global array of medicines
struct Medicine medicines[MAX_MEDICINES];

// Define a function to add a medicine
void add_medicine() {
    // Define a variable to hold the index of the next available slot
    static int next_slot = 0;

    // Check if the maximum number of medicines has been reached
    if (next_slot >= MAX_MEDICINES) {
        printf("Error: Maximum number of medicines reached\n");
        return;
    }

    // Prompt the user for the details of the medicine
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[next_slot].name);
    printf("Enter the name of the manufacturer: ");
    scanf("%s", medicines[next_slot].manufacturer);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[next_slot].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[next_slot].price);

    // Increment the index of the next available slot
    next_slot++;

    // Confirm to the user that the medicine has been added
    printf("Medicine added successfully\n");
}

// Define a function to search for a medicine by name
void search_medicine_by_name() {
    // Prompt the user for the name of the medicine
    char search_name[MAX_STRING_LENGTH];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", search_name);

    // Loop through all the medicines and search for the one with the matching name
    bool found = false;
    for (int i = 0; i < MAX_MEDICINES; i++) {
        if (strcmp(medicines[i].name, search_name) == 0) {
            printf("Name: %s\nManufacturer: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
            found = true;
            break;
        }
    }

    // If the medicine wasn't found, inform the user
    if (!found) {
        printf("Medicine not found\n");
    }
}

// Define a function to search for a medicine by manufacturer
void search_medicine_by_manufacturer() {
    // Prompt the user for the name of the manufacturer
    char search_manufacturer[MAX_STRING_LENGTH];
    printf("Enter the name of the manufacturer to search for: ");
    scanf("%s", search_manufacturer);

    // Loop through all the medicines and search for the ones with the matching manufacturer
    bool found = false;
    for (int i = 0; i < MAX_MEDICINES; i++) {
        if (strcmp(medicines[i].manufacturer, search_manufacturer) == 0) {
            printf("Name: %s\nManufacturer: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
            found = true;
        }
    }

    // If no medicines were found, inform the user
    if (!found) {
        printf("No medicines found\n");
    }
}

// Define a function to display all medicines
void display_all_medicines() {
    // Loop through all the medicines and display their details
    for (int i = 0; i < MAX_MEDICINES; i++) {
        printf("Name: %s\nManufacturer: %s\nQuantity: %d\nPrice: %.2f\n\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
}

// Define the main function
int main() {
    // Display a welcome message
    printf("Welcome to the Medical Store Management System\n");

    // Define a variable to hold the user's choice
    int choice;

    // Loop forever until the user chooses to exit
    while (true) {
        // Display the menu
        printf("\nMenu:\n1. Add a medicine\n2. Search for a medicine by name\n3. Search for a medicine by manufacturer\n4. Display all medicines\n5. Exit\n");
        
        // Prompt the user for their choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the corresponding function based on the user's choice
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                search_medicine_by_name();
                break;
            case 3:
                search_medicine_by_manufacturer();
                break;
            case 4:
                display_all_medicines();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    // Return 0 to indicate success
    return 0;
}