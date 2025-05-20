//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store details of a medicine
typedef struct Medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

// Function to add a new medicine to the store
void add_medicine(Medicine *store, int *count) {
    printf("Enter the name of the medicine: ");
    scanf("%s", store[*count].name);

    printf("Enter the manufacturer of the medicine: ");
    scanf("%s", store[*count].manufacturer);

    printf("Enter the price of the medicine: ");
    scanf("%f", &store[*count].price);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &store[*count].quantity);

    (*count)++;
}

// Function to search for a medicine in the store
int search_medicine(Medicine *store, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Function to sell a medicine from the store
void sell_medicine(Medicine *store, int *count, char *name, int quantity) {
    int index = search_medicine(store, *count, name);

    if (index == -1) {
        printf("Medicine not found!\n");
        return;
    }

    if (store[index].quantity < quantity) {
        printf("Insufficient quantity!\n");
        return;
    }

    store[index].quantity -= quantity;
}

// Function to print the details of all medicines in the store
void print_medicines(Medicine *store, int count) {
    printf("Name\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\t%d\n", store[i].name, store[i].manufacturer, store[i].price, store[i].quantity);
    }
}

// Main function
int main() {
    // Initialize the medicine store
    Medicine store[100];
    int count = 0;

    // Add some medicines to the store
    add_medicine(store, &count);
    add_medicine(store, &count);
    add_medicine(store, &count);

    // Print the details of all medicines in the store
    print_medicines(store, count);

    // Search for a medicine in the store
    char name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", name);

    int index = search_medicine(store, count, name);

    if (index == -1) {
        printf("Medicine not found!\n");
    } else {
        printf("Medicine found!\n");
    }

    // Sell a medicine from the store
    int quantity;
    printf("Enter the name of the medicine to sell: ");
    scanf("%s", name);

    printf("Enter the quantity to sell: ");
    scanf("%d", &quantity);

    sell_medicine(store, &count, name, quantity);

    // Print the details of all medicines in the store
    print_medicines(store, count);

    return 0;
}