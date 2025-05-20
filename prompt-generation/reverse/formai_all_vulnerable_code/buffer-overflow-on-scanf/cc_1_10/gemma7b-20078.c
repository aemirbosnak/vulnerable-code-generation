//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

void display_medicine(Medicine *med) {
    printf("Name: %s\n", med->name);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
}

void add_medicine(Medicine *med) {
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter price: ");
    scanf("%f", &med->price);
}

void update_medicine(Medicine *med) {
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter new quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter new price: ");
    scanf("%f", &med->price);
}

void search_medicine(Medicine *med, char *name) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(med[i].name, name) == 0) {
            display_medicine(&med[i]);
            break;
        }
    }
}

int main() {
    Medicine med[MAX];

    // Add some medicine
    add_medicine(&med[0]);
    add_medicine(&med[1]);
    add_medicine(&med[2]);

    // Display all medicine
    for (int i = 0; i < MAX; i++) {
        display_medicine(&med[i]);
    }

    // Search for a medicine
    search_medicine(med, "Acetaminophen");

    return 0;
}