//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine
void addMedicine(medicine *list, int *count) {
    printf("Enter medicine name: ");
    scanf(" %[^\n]%*c", list[*count].name);
    printf("Enter brand name: ");
    scanf(" %[^\n]%*c", list[*count].brand);
    printf("Enter price: ");
    scanf(" %f", &list[*count].price);
    printf("Enter quantity: ");
    scanf(" %d", &list[*count].quantity);
    (*count)++;
}

// Function to search for a medicine by name
int searchMedicine(medicine *list, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update the quantity of a medicine
void updateQuantity(medicine *list, int count, char *name, int quantity) {
    int index = searchMedicine(list, count, name);
    if (index != -1) {
        list[index].quantity += quantity;
    }
}

// Function to generate a bill
void generateBill(medicine *list, int count) {
    float total = 0;
    printf("%-5s %-20s %-20s %-10s %-10s\n", "No.", "Name", "Brand", "Price", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-20s %-10.2f %-10d\n", i + 1, list[i].name, list[i].brand, list[i].price, list[i].quantity);
        total += list[i].price * list[i].quantity;
    }
    printf("Total: %.2f\n", total);
}

// Main function
int main() {
    medicine list[100];
    int count = 0;
    int choice;
    char name[50];
    int quantity;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Update the quantity of a medicine\n");
        printf("4. Generate a bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                addMedicine(list, &count);
                break;
            case 2:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                int index = searchMedicine(list, count, name);
                if (index == -1) {
                    printf("Medicine not found!\n");
                } else {
                    printf("Medicine found:\n");
                    printf("Name: %s\n", list[index].name);
                    printf("Brand: %s\n", list[index].brand);
                    printf("Price: %.2f\n", list[index].price);
                    printf("Quantity: %d\n", list[index].quantity);
                }
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter quantity to update: ");
                scanf(" %d", &quantity);
                updateQuantity(list, count, name, quantity);
                break;
            case 4:
                generateBill(list, count);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}