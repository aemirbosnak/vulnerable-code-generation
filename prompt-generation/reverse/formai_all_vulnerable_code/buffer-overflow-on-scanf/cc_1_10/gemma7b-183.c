//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine {
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

void displayMedicine(Medicine *med) {
    printf("Name: %s\n", med->name);
    printf("Dosage: %s\n", med->dosage);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
}

void addMedicine(Medicine *med) {
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter medicine dosage: ");
    scanf("%s", med->dosage);

    printf("Enter medicine quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter medicine price: ");
    scanf("%f", &med->price);
}

void searchMedicine(Medicine *med, char *name) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(med[i].name, name) == 0) {
            displayMedicine(&med[i]);
            break;
        }
    }
}

int main() {
    Medicine med[MAX];

    // Add some medicines
    addMedicine(&med[0]);
    addMedicine(&med[1]);
    addMedicine(&med[2]);

    // Search for a medicine
    searchMedicine(&med[0], "Acetaminophen");

    return 0;
}