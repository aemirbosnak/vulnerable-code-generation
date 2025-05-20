//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Create a list of medicines
Medicine medicines[] = {
    {"Tylenol", 100, 2.50},
    {"Ibuprofen", 50, 2.25},
    {"Acetaminophen", 75, 2.75},
    {"Aspirin", 25, 2.00},
    {"Cough Syrup", 150, 3.00},
    {"Tums", 125, 1.50}
};

// Define the number of medicines in the list
int num_medicines = 6;

// Function to search for a medicine
void search_medicine(char *name) {
    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

// Function to add a medicine
void add_medicine() {
    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &price);

    Medicine new_medicine;
    strcpy(new_medicine.name, name);
    new_medicine.quantity = quantity;
    new_medicine.price = price;

    medicines[num_medicines++] = new_medicine;

    printf("Medicine added successfully.\n");
}

// Function to remove a medicine
void remove_medicine(char *name) {
    int i;
    for (i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            medicines[i] = medicines[num_medicines - 1];
            num_medicines--;
            printf("Medicine removed successfully.\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

// Main menu loop
int main() {
    int choice;
    char name[50];

    printf("Welcome to the Cyberpunk Medical Store!\n");
    printf("Please select an option:\n");
    printf("1. Search for a medicine\n");
    printf("2. Add a medicine\n");
    printf("3. Remove a medicine\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the name of the medicine: ");
            scanf("%s", name);
            search_medicine(name);
            break;
        case 2:
            add_medicine();
            break;
        case 3:
            printf("Enter the name of the medicine: ");
            scanf("%s", name);
            remove_medicine(name);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}