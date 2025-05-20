//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h> // header file for standard input/output functions
#include <string.h> // header file for string handling functions

typedef struct {
    char medicineName[50];
    int medicineID;
    int price;
    int quantity;
} Medicine; // defining a Medicine struct

void printMenu(); // function to print the menu options
void addMedicine(Medicine medicine[], int* count); // function to add new medicine
void removeMedicine(Medicine medicine[], int* count, int medicineID); // function to remove medicine by ID
void updateMedicine(Medicine medicine[], int count, int medicineID); // function to update medicine by ID
void displayInventory(Medicine medicine[], int count); // function to display medicine inventory

int main() {
    Medicine medicine[100]; // create an array of Medicine structs
    int count = 0; // variable to keep track of number of medicines

    int choice = 0; // variable to store user's choice

    do {
        printMenu(); // print menu options
        scanf("%d", &choice); // read user's choice

        switch (choice) {
            case 1:
                addMedicine(medicine, &count); // add new medicine
                break;
            case 2:
                printf("Enter medicine ID: ");
                int medicineID;
                scanf("%d", &medicineID);
                removeMedicine(medicine, &count, medicineID); // remove medicine by ID
                break;
            case 3:
                printf("Enter medicine ID to update: ");
                int updateID;
                scanf("%d", &updateID);
                updateMedicine(medicine, count, updateID); // update medicine by ID
                break;
            case 4:
                displayInventory(medicine, count); // display medicine inventory
                break;
            case 5:
                printf("Thank you for using our store management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n"); // handle invalid input
                break;
        }
    } while (choice != 5); // continue until user chooses to exit

    return 0;
}

void printMenu() {
    printf("\n\t\tMEDICAL STORE MANAGEMENT SYSTEM\n\n");
    printf("1. Add new medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Update medicine\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addMedicine(Medicine medicine[], int* count) {
    printf("\nEnter details of the medicine:\n");
    printf("Name: ");
    scanf("%s", medicine[*count].medicineName);
    printf("ID: ");
    scanf("%d", &medicine[*count].medicineID);
    printf("Price: ");
    scanf("%d", &medicine[*count].price);
    printf("Quantity: ");
    scanf("%d", &medicine[*count].quantity);

    *count += 1; // increment medicine count
    printf("Medicine added successfully.\n");
}

void removeMedicine(Medicine medicine[], int* count, int medicineID) {
    int index = -1;
    // search for medicine by ID
    for (int i = 0; i < *count; i++) {
        if (medicine[i].medicineID == medicineID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No medicine found with ID %d.\n", medicineID);
        return;
    }

    // shift array elements to remove medicine
    for (int i = index; i < *count - 1; i++) {
        strcpy(medicine[i].medicineName, medicine[i + 1].medicineName);
        medicine[i].medicineID = medicine[i + 1].medicineID;
        medicine[i].price = medicine[i + 1].price;
        medicine[i].quantity = medicine[i + 1].quantity;
    }

    *count -= 1; // decrement medicine count
    printf("Medicine with ID %d removed successfully.\n", medicineID);
}

void updateMedicine(Medicine medicine[], int count, int medicineID) {
    int index = -1;
    // search for medicine by ID
    for (int i = 0; i < count; i++) {
        if (medicine[i].medicineID == medicineID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No medicine found with ID %d.\n", medicineID);
        return;
    }

    // update medicine details
    printf("Enter new details for the medicine:\n");
    printf("Name: ");
    scanf("%s", medicine[index].medicineName);
    printf("Price: ");
    scanf("%d", &medicine[index].price);
    printf("Quantity: ");
    scanf("%d", &medicine[index].quantity);

    printf("Medicine with ID %d updated successfully.\n", medicineID);
}

void displayInventory(Medicine medicine[], int count) {
    if (count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n\t\tMEDICINE INVENTORY\n\n");
    for (int i = 0; i < count; i++) {
        printf("%d) Name: %s\n", i + 1, medicine[i].medicineName);
        printf("   ID: %d\n", medicine[i].medicineID);
        printf("   Price: %d\n", medicine[i].price);
        printf("   Quantity: %d\n", medicine[i].quantity);
    }
}