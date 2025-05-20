//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct for medicines
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

// Function to add medicine
void addMedicine(struct Medicine *medicines, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

// Function to display all medicines
void displayMedicines(struct Medicine *medicines, int count) {
    printf("\nMedicines in stock:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Quantity: %d | Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for a medicine by name
void searchMedicine(struct Medicine *medicines, int count) {
    char searchName[50];
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("\nMedicine found!\nName: %s | Quantity: %d | Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to sell medicine
void sellMedicine(struct Medicine *medicines, int count) {
    char sellName[50];
    printf("Enter medicine name to sell: ");
    scanf("%s", sellName);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, sellName) == 0) {
            int sellQuantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &sellQuantity);
            if (sellQuantity <= medicines[i].quantity) {
                medicines[i].quantity -= sellQuantity;
                printf("Medicine sold successfully!\n");
                return;
            }
            else {
                printf("Error: Insufficient quantity.\n");
                return;
            }
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    struct Medicine medicines[100];
    int count = 0;
    int choice;
    while (1) {
        printf("\n==========\n");
        printf("Menu:\n1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Sell Medicine\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addMedicine(medicines, &count);
            break;
        case 2:
            displayMedicines(medicines, count);
            break;
        case 3:
            searchMedicine(medicines, count);
            break;
        case 4:
            sellMedicine(medicines, count);
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}