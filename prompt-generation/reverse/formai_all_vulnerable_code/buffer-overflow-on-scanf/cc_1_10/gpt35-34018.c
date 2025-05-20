//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

// Struct for medicine
struct Medicine {
    char name[20];
    char manufacturer[20];
    int quantity;
    float price;
};

// Global variables
int n = 0;
struct Medicine medicines[SIZE];

// Function to create a new medicine
void createMedicine() {
    struct Medicine medicine;
    printf("Enter name of medicine: ");
    scanf("%s", &medicine.name);
    printf("Enter the manufacturer: ");
    scanf("%s", &medicine.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &medicine.price);
    medicines[n++] = medicine;
}

// Function to display all the medicines
void displayMedicines() {
    printf("\nMedicines available are:\n\n");
    printf("%-20s%-20s%-20s%-20s\n", "Name", "Manufacturer", "Quantity", "Price");
    for (int i = 0; i < n; i++) {
        printf("%-20s%-20s%-20d%-20.2f\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for a medicine by name
void searchMedicine() {
    char name[20];
    printf("Enter name of medicine: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("%-20s%-20s%-20s%-20s\n", "Name", "Manufacturer", "Quantity", "Price");
            printf("%-20s%-20s%-20d%-20.2f\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

// Function for the main menu
void mainMenu() {
    printf("\n******Medical Store Management System******\n\n");
    printf("1. Add a Medicine\n");
    printf("2. Display all Medicines\n");
    printf("3. Search for a Medicine\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                printf("\nThanks for using Medical Store Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (1);
    return 0;
}