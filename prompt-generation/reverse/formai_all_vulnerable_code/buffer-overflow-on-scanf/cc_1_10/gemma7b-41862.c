//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: optimized
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

void display_medicine(Medicine *med) {
    printf("Name: %s\n", med->name);
    printf("Dosage: %s\n", med->dosage);
    printf("Quantity: %d\n", med->quantity);
    printf("Price: %.2f\n", med->price);
    printf("-----------------------\n");
}

void add_medicine(Medicine *med) {
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter medicine dosage: ");
    scanf("%s", med->dosage);

    printf("Enter medicine quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter medicine price: ");
    scanf("%f", &med->price);

    printf("Medicine added successfully!\n");
}

void update_medicine(Medicine *med) {
    printf("Enter medicine name: ");
    scanf("%s", med->name);

    printf("Enter new medicine dosage: ");
    scanf("%s", med->dosage);

    printf("Enter new medicine quantity: ");
    scanf("%d", &med->quantity);

    printf("Enter new medicine price: ");
    scanf("%f", &med->price);

    printf("Medicine updated successfully!\n");
}

void search_medicine(Medicine *med) {
    char name[50];

    printf("Enter medicine name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX; i++) {
        if (strcmp(med[i].name, name) == 0) {
            display_medicine(&med[i]);
        }
    }
}

int main() {
    Medicine med[MAX];

    add_medicine(med);
    add_medicine(med);
    add_medicine(med);

    update_medicine(med);
    search_medicine(med);

    return 0;
}