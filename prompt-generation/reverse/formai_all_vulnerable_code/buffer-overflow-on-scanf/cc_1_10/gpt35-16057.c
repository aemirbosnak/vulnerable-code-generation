//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define medication struct
typedef struct {
    char name[20];
    int quantity;
    float price;
} medication;

// Function prototypes
void add_medication(medication**, int*);
void remove_medication(medication**, int*);
void display_inventory(medication*, int);

int main() {
    int num_medications = 0;
    medication* inventory = NULL;
    char option;

    // Main program loop
    do {
        printf("Welcome to the Medical Store Management System!\n\n");
        printf("Select an option:\n");
        printf("a) Add medication\n");
        printf("b) Remove medication\n");
        printf("c) Display inventory\n");
        printf("q) Quit program\n");
        scanf(" %c", &option);

        switch(option) {
            case 'a':
                add_medication(&inventory, &num_medications);
                break;
            case 'b':
                remove_medication(&inventory, &num_medications);
                break;
            case 'c':
                display_inventory(inventory, num_medications);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Try again.\n");
        }
    } while (option != 'q');

    return 0;
}

void add_medication(medication** inventory, int* num_medications) {
    // Get info about new medication from user
    char name[20];
    int quantity;
    float price;

    printf("Enter medication name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);

    // Add new medication to inventory
    (*num_medications)++;
    *inventory = (medication*)realloc(*inventory, (*num_medications) * sizeof(medication));
    strcpy((*inventory)[*num_medications - 1].name, name);
    (*inventory)[*num_medications - 1].quantity = quantity;
    (*inventory)[*num_medications - 1].price = price;

    printf("Medication added to inventory.\n");
}

void remove_medication(medication** inventory, int* num_medications) {
    // Get name of medication to remove from user
    char name[20];
    printf("Enter name of medication to remove: ");
    scanf("%s", name);

    // Search for medication in inventory
    int index = -1;
    for (int i = 0; i < *num_medications; i++) {
        if (strcmp((*inventory)[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If medication was found, remove it from inventory
    if (index != -1) {
        for (int i = index; i < *num_medications - 1; i++) {
            strcpy((*inventory)[i].name, (*inventory)[i + 1].name);
            (*inventory)[i].quantity = (*inventory)[i + 1].quantity;
            (*inventory)[i].price = (*inventory)[i + 1].price;
        }
        (*num_medications)--;
        *inventory = (medication*)realloc(*inventory, (*num_medications) * sizeof(medication));
        printf("Medication removed from inventory.\n");
    } else {
        printf("Medication not found in inventory.\n");
    }
}

void display_inventory(medication* inventory, int num_medications) {
    // Print table header
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    // Print each medication in the inventory
    for (int i = 0; i < num_medications; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}