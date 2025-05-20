//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct Medicine meds[], int *numMeds); // function to add medicine
void displayMedicine(struct Medicine meds[], int numMeds); // function to display all medicine
void searchMedicine(struct Medicine meds[], int numMeds, char name[]); // function to search medicine
void sellMedicine(struct Medicine meds[], int numMeds, char name[], int qty); // function to sell medicine

int main() {
    struct Medicine meds[100]; // array of medicine
    int numMeds = 0; // current number of medicines in array
    int choice, qty;
    char name[50];

    while (1) {
        // menu
        printf("1. Add medicine\n");
        printf("2. Display all medicine\n");
        printf("3. Search medicine\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add medicine
                addMedicine(meds, &numMeds);
                break;
            case 2: // Display all medicine
                displayMedicine(meds, numMeds);
                break;
            case 3: // Search medicine
                printf("Enter medicine name: ");
                scanf("%s", name);
                searchMedicine(meds, numMeds, name);
                break;
            case 4: // Sell medicine
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &qty);
                sellMedicine(meds, numMeds, name, qty);
                break;
            case 5: // Exit
                exit(0);
            default: // Invalid choice
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void addMedicine(struct Medicine meds[], int *numMeds) {
    struct Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price: ");
    scanf("%f", &m.price);

    meds[*numMeds] = m;
    (*numMeds)++;

    printf("Medicine added successfully\n");
}

void displayMedicine(struct Medicine meds[], int numMeds) {
    if (numMeds == 0) {
        printf("No medicine found\n");
        return;
    }

    printf("List of medicine:\n");
    for (int i = 0; i < numMeds; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void searchMedicine(struct Medicine meds[], int numMeds, char name[]) {
    if (numMeds == 0) {
        printf("No medicine found\n");
        return;
    }

    for (int i = 0; i < numMeds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Name: %s, Quantity: %d, Price: %.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
            return;
        }
    }

    printf("Medicine not found\n");
}

void sellMedicine(struct Medicine meds[], int numMeds, char name[], int qty) {
    if (numMeds == 0) {
        printf("No medicine found\n");
        return;
    }

    for (int i = 0; i < numMeds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            if (meds[i].quantity >= qty) {
                meds[i].quantity -= qty;
                printf("Sold successfully. Total price: %.2f\n", qty * meds[i].price);
                return;
            }
            else {
                printf("Insufficient quantity\n");
                return;
            }
        }
    }

    printf("Medicine not found\n");
}