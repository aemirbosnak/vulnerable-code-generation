//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct Medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Declare the array of medicines
Medicine medicines[MAX_MEDICINES];

// Declare the number of medicines
int num_medicines = 0;

// Function to add a new medicine
void add_medicine() {
    // Get the medicine details from the user
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[num_medicines].name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[num_medicines].price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[num_medicines].quantity);

    // Increment the number of medicines
    num_medicines++;
}

// Function to display all medicines
void display_medicines() {
    // Print the header
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");

    // Loop through the array of medicines
    for (int i = 0; i < num_medicines; i++) {
        // Print the details of the medicine
        printf("%-5d %-20s %-10.2f %-10d\n", i + 1, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// Function to search for a medicine
void search_medicine() {
    // Get the name of the medicine from the user
    char name[50];
    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    // Loop through the array of medicines
    for (int i = 0; i < num_medicines; i++) {
        // Check if the name of the medicine matches the search query
        if (strcmp(medicines[i].name, name) == 0) {
            // Print the details of the medicine
            printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
            printf("%-5d %-20s %-10.2f %-10d\n", i + 1, medicines[i].name, medicines[i].price, medicines[i].quantity);

            // Break out of the loop
            break;
        }
    }
}

// Function to update the quantity of a medicine
void update_medicine() {
    // Get the ID of the medicine from the user
    int id;
    printf("Enter the ID of the medicine: ");
    scanf("%d", &id);

    // Check if the ID is valid
    if (id < 1 || id > num_medicines) {
        printf("Invalid ID\n");
        return;
    }

    // Get the new quantity of the medicine from the user
    int quantity;
    printf("Enter the new quantity of the medicine: ");
    scanf("%d", &quantity);

    // Update the quantity of the medicine
    medicines[id - 1].quantity = quantity;
}

// Function to delete a medicine
void delete_medicine() {
    // Get the ID of the medicine from the user
    int id;
    printf("Enter the ID of the medicine: ");
    scanf("%d", &id);

    // Check if the ID is valid
    if (id < 1 || id > num_medicines) {
        printf("Invalid ID\n");
        return;
    }

    // Shift the medicines after the deleted medicine to the left
    for (int i = id - 1; i < num_medicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    // Decrement the number of medicines
    num_medicines--;
}

// Function to display the menu
void display_menu() {
    printf("1. Add a new medicine\n");
    printf("2. Display all medicines\n");
    printf("3. Search for a medicine\n");
    printf("4. Update the quantity of a medicine\n");
    printf("5. Delete a medicine\n");
    printf("6. Exit\n");
}

// Function to get the user's choice
int get_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    // Display the menu
    display_menu();

    // Get the user's choice
    int choice = get_choice();

    // Loop until the user chooses to exit
    while (choice != 6) {
        // Switch on the user's choice
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            default:
                printf("Invalid choice\n");
        }

        // Display the menu again
        display_menu();

        // Get the user's choice again
        choice = get_choice();
    }

    return 0;
}