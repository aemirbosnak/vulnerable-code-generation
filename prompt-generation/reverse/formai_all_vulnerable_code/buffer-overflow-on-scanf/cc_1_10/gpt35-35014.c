//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100 // Maximum number of medicines that can be stored in the system.

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES]; // Array to store the medicines.

int num_medicines = 0; // Variable to keep track of the number of medicines stored in the system.

// Function to display the main menu of the program.
void display_menu() {
    printf("Welcome to the Medical Store Management System!\n");
    printf("1. Add a medicine\n");
    printf("2. Search for a medicine\n");
    printf("3. Update a medicine\n");
    printf("4. Delete a medicine\n");
    printf("5. Display all medicines\n");
    printf("6. Exit\n");
}

// Function to add a medicine to the system.
void add_medicine() {
    Medicine medicine;
    printf("Enter the name of the medicine: ");
    scanf("%s", medicine.name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine.quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine.price);
    medicines[num_medicines++] = medicine;
    printf("Medicine added successfully!\n");
}

// Function to search for a medicine in the system.
void search_medicine() {
    char name[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %f\n", medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, the medicine was not found.\n");
    }
}

// Function to update a medicine in the system.
void update_medicine() {
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter the new price of the medicine: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, the medicine was not found.\n");
    }
}

// Function to delete a medicine from the system.
void delete_medicine() {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            num_medicines--;
            printf("Medicine deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Sorry, the medicine was not found.\n");
    }
}

// Function to display all medicines in the system.
void display_medicines() {
    if (num_medicines == 0) {
        printf("No medicines found.\n");
        return;
    }
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s\t%d\t%f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                search_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                delete_medicine();
                break;
            case 5:
                display_medicines();
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}