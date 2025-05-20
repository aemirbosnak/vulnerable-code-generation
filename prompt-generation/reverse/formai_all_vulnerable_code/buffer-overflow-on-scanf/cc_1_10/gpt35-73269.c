//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDICINES 50 // Maximum number of medicines that the medical store can hold

// Structure declaration for a Medicine
struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
};

// Function declarations
void addMedicine(struct Medicine *medicines, int *count);
void removeMedicine(struct Medicine *medicines, int *count);
void displayMedicines(struct Medicine *medicines, int count);
void searchMedicine(struct Medicine *medicines, int count);

// Main function
int main() {
    struct Medicine medicines[MAX_MEDICINES]; // Array of medicines
    int count = 0; // Number of medicines in the array

    int choice;
    do {
        // Print the menu
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Display Medicines\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                removeMedicine(medicines, &count);
                break;
            case 3:
                displayMedicines(medicines, count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                printf("Thank you for using the Medical Store Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void addMedicine(struct Medicine *medicines, int *count) {
    if (*count == MAX_MEDICINES) {
        printf("Unable to add Medicine. Maximum limit reached.\n");
        return;
    }

    struct Medicine *medicine = &medicines[*count];

    printf("\nEnter Medicine Details:\n");
    printf("Name: ");
    scanf("%s", medicine->name);
    printf("Manufacturer: ");
    scanf("%s", medicine->manufacturer);
    printf("Price: ");
    scanf("%f", &medicine->price);
    printf("Quantity: ");
    scanf("%d", &medicine->quantity);

    (*count)++;

    printf("Medicine added successfully.\n");
}

void removeMedicine(struct Medicine *medicines, int *count) {
    if (*count == 0) {
        printf("No Medicines found.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the medicine to remove: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine named \"%s\" not found.\n", name);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        medicines[i] = medicines[i+1];
    }

    (*count)--;

    printf("Medicine removed successfully.\n");
}

void displayMedicines(struct Medicine *medicines, int count) {
    if (count == 0) {
        printf("No Medicines found.\n");
        return;
    }

    printf("%-20s%-20s%10s%10s\n", "Name", "Manufacturer", "Price", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-20s%-20s%10.2f%10d\n", medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(struct Medicine *medicines, int count) {
    if (count == 0) {
        printf("No Medicines found.\n");
        return;
    }

    char name[50];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine named \"%s\" not found.\n", name);
        return;
    }

    printf("%-20s%-20s%10s%10s\n", "Name", "Manufacturer", "Price", "Quantity");
    printf("%-20s%-20s%10.2f%10d\n", medicines[index].name, medicines[index].manufacturer, medicines[index].price, medicines[index].quantity);
}