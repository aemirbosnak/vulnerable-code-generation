//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define DESCR_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char description[DESCR_LENGTH];
    float price;
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} MedicalStore;

// Function prototypes
void addMedicine(MedicalStore *store);
void displayMedicines(const MedicalStore *store);
void romanticMessage();

int main() {
    MedicalStore store = { .count = 0 };
    int choice;

    romanticMessage();

    while (1) {
        printf("\nWelcome to the Medical Store of Love!\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Exit\n");
        printf("Please choose your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&store);
                break;
            case 2:
                displayMedicines(&store);
                break;
            case 3:
                printf("Thank you for visiting the Medical Store of Love! Until we meet again...\n");
                exit(0);
            default:
                printf("Oh dear! That’s not a valid choice. Try again, sweet soul.\n");
        }
    }

    return 0;
}

void addMedicine(MedicalStore *store) {
    if (store->count >= MAX_MEDICINES) {
        printf("Our heart has filled to the brim with medicines! Cannot add more.\n");
        return;
    }

    Medicine newMedicine;

    printf("Enter the name of the medicine: ");
    scanf(" %[^\n]", newMedicine.name);
    
    printf("Enter a romantic description: ");
    scanf(" %[^\n]", newMedicine.description);

    printf("Set a price for this love potion: ");
    scanf("%f", &newMedicine.price);

    printf("How many of these delightful love potions do we have? ");
    scanf("%d", &newMedicine.quantity);
    
    store->medicines[store->count++] = newMedicine;

    printf("Ah, the lovely medicine '%s' has been added to our store!\n", newMedicine.name);
}

void displayMedicines(const MedicalStore *store) {
    if (store->count == 0) {
        printf("The shelves are bare, but our hearts are still full of love!\n");
        return;
    }

    printf("\nHere are the enchanting medicines in our love lair:\n");
    for (int i = 0; i < store->count; i++) {
        Medicine m = store->medicines[i];
        printf("Medicine %d: %s\n", i + 1, m.name);
        printf("Description: %s\n", m.description);
        printf("Price: $%.2f\n", m.price);
        printf("Quantity: %d\n", m.quantity);
        printf("------------------------------\n");
    }
}

void romanticMessage() {
    printf("Welcome to the Medical Store of Love!\n");
    printf("Where every medicine carries a whisper of romance.\n");
    printf("Let us take care of your health and heart!\n");
}