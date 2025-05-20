//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

// Structure to represent a medicine
typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

// To enchant the world, let’s create a love story of medicines
void loveStory(Medicine *medicines, int count) {
    printf("In our little medical store, a tale unfolds...\n");
    for (int i = 0; i < count; i++) {
        printf("Medicine: %s, Quantity: %d, Price: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("The medicines linger like sweet memories, waiting to soothe the aches of love...\n");
}

// Function to display all available medicines
void displayMedicines(Medicine *medicines, int count) {
    printf("\n**** Available Medicines ****\n");
    loveStory(medicines, count);
}

// Function to add a new medicine to the store
void addMedicine(Medicine *medicines, int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Our store is full, dear. We cannot add more medicines.\n");
        return;
    }
    printf("Enter the name of the medicine: ");
    scanf(" %[^\n]%*c", medicines[*count].name);
    
    printf("Enter the quantity: ");
    scanf("%d", &medicines[*count].quantity);

    printf("Enter the price: ");
    scanf("%f", &medicines[*count].price);

    (*count)++;
    printf("A new medicine has found its way into our hearts!\n");
}

// Function to sell a medicine
void sellMedicine(Medicine *medicines, int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to sell: ");
    scanf(" %[^\n]%*c", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            if (medicines[i].quantity > 0) {
                medicines[i].quantity--;
                printf("Sold one %s. Only %d left.\n", medicines[i].name, medicines[i].quantity);
            } else {
                printf("Oh no! We are out of %s.\n", medicines[i].name);
            }
            return;
        }
    }
    printf("Alas, we do not have that medicine in our store.\n");
}

// Function to restock a medicine
void restockMedicine(Medicine *medicines, int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to restock: ");
    scanf(" %[^\n]%*c", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int quantity;
            printf("How many %s would you like to add?: ", medicines[i].name);
            scanf("%d", &quantity);
            medicines[i].quantity += quantity;
            printf("Restocked %d of %s. Now we have %d.\n", quantity, medicines[i].name, medicines[i].quantity);
            return;
        }
    }
    printf("Oh dear! We do not carry %s in our beloved store!\n", name);
}

// Main function
int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    do {
        printf("\n**** Medical Store Management System ****\n");
        printf("1. Add Medicine\n");
        printf("2. Sell Medicine\n");
        printf("3. Restock Medicine\n");
        printf("4. Display Medicines\n");
        printf("5. Exit\n");
        printf("Choose your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                sellMedicine(medicines, count);
                break;
            case 3:
                restockMedicine(medicines, count);
                break;
            case 4:
                displayMedicines(medicines, count);
                break;
            case 5:
                printf("Thank you for visiting our store! Come back soon with more love!\n");
                break;
            default:
                printf("Oh dear! That option does not exist in our love story...\n");
        }
    } while (choice != 5);

    return 0;
}