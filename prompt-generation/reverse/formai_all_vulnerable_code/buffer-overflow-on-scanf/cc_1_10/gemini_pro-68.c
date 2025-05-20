//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

// Function to add new medicine
void add_medicine(medicine *meds, int *num_meds) {
    printf("Enter medicine name: ");
    scanf(" %s", meds[*num_meds].name);
    printf("Enter medicine company: ");
    scanf(" %s", meds[*num_meds].company);
    printf("Enter medicine quantity: ");
    scanf(" %d", &meds[*num_meds].quantity);
    printf("Enter medicine price: ");
    scanf(" %f", &meds[*num_meds].price);
    (*num_meds)++;
}

// Function to display all medicines
void display_medicines(medicine *meds, int num_meds) {
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Quantity", "Price");
    for (int i = 0; i < num_meds; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", meds[i].name, meds[i].company, meds[i].quantity, meds[i].price);
    }
}

// Function to search for a medicine
void search_medicine(medicine *meds, int num_meds) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < num_meds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Quantity", "Price");
            printf("%-20s %-20s %-10d %-10.2f\n", meds[i].name, meds[i].company, meds[i].quantity, meds[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to update medicine quantity
void update_medicine_quantity(medicine *meds, int num_meds) {
    char name[50];
    int quantity;
    printf("Enter medicine name to update quantity: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < num_meds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Enter new medicine quantity: ");
            scanf(" %d", &quantity);
            meds[i].quantity = quantity;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to delete a medicine
void delete_medicine(medicine *meds, int *num_meds) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf(" %s", name);
    int found = 0;
    for (int i = 0; i < *num_meds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            for (int j = i; j < *num_meds - 1; j++) {
                meds[j] = meds[j + 1];
            }
            (*num_meds)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Main function
int main() {
    // Array of medicines
    medicine meds[100];
    int num_meds = 0;

    // Main menu loop
    int choice;
    do {
        printf("\n1. Add new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Update medicine quantity\n");
        printf("5. Delete a medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_medicine(meds, &num_meds);
                break;
            case 2:
                display_medicines(meds, num_meds);
                break;
            case 3:
                search_medicine(meds, num_meds);
                break;
            case 4:
                update_medicine_quantity(meds, num_meds);
                break;
            case 5:
                delete_medicine(meds, &num_meds);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}