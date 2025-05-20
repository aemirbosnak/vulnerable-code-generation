//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medicine details
struct medicine {
    char name[50];
    int quantity;
    float price;
};

// Define a function to add a medicine to the store
void add_medicine(struct medicine *med) {
    printf("Enter the name of the medicine: ");
    scanf("%s", med->name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med->quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &med->price);
}

// Define a function to display all medicines
void display_medicines(struct medicine *med) {
    printf("List of medicines:\n");
    for (int i = 0; i < med->quantity; i++) {
        printf("%s - %d - %.2f\n", med->name, med->quantity, med->price);
    }
}

// Define a function to search for a medicine
void search_medicine(struct medicine *med) {
    char search_name[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", search_name);

    for (int i = 0; i < med->quantity; i++) {
        if (strcmp(med->name, search_name) == 0) {
            printf("Found: %s - %d - %.2f\n", med->name, med->quantity, med->price);
        }
    }
}

int main() {
    struct medicine medicines[100];
    int num_medicines = 0;

    // Add a few medicines to the store
    add_medicine(&medicines[num_medicines++]);
    add_medicine(&medicines[num_medicines++]);
    add_medicine(&medicines[num_medicines++]);

    // Display all medicines
    display_medicines(medicines);

    // Search for a medicine
    search_medicine(medicines);

    return 0;
}