//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
struct medicine {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new medicine
void add_medicine(struct medicine *med, int *num_med) {
    printf("Enter medicine name: ");
    scanf("%s", med[*num_med].name);
    printf("Enter quantity: ");
    scanf("%d", &med[*num_med].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*num_med].price);
    (*num_med)++;
}

// Function to sell a medicine
void sell_medicine(struct medicine *med, int *num_med) {
    char name[50];
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *num_med; i++) {
        if (strcmp(med[i].name, name) == 0) {
            if (med[i].quantity >= quantity) {
                med[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
            } else {
                printf("Insufficient quantity!\n");
            }
            break;
        }
    }
}

// Function to search for a medicine
void search_medicine(struct medicine *med, int num_med) {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < num_med; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", med[i].name);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %f\n", med[i].price);
            break;
        }
    }
}

// Function to display all medicines
void display_medicines(struct medicine *med, int num_med) {
    printf("Medicine List:\n");
    for (int i = 0; i < num_med; i++) {
        printf("%s\t%d\t%f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

// Main function
int main() {
    // Define an array of medicines
    struct medicine med[100];

    // Initialize the number of medicines to 0
    int num_med = 0;

    // Loop to display the menu
    while (1) {
        printf("\n1. Add Medicine\n2. Sell Medicine\n3. Search Medicine\n4. Display Medicines\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        // Switch case to handle the user's choice
        switch (choice) {
            case 1:
                add_medicine(med, &num_med);
                break;
            case 2:
                sell_medicine(med, &num_med);
                break;
            case 3:
                search_medicine(med, num_med);
                break;
            case 4:
                display_medicines(med, num_med);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}