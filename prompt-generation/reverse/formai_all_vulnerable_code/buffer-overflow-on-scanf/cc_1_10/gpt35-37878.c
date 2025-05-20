//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for medicines
typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

// Define function prototypes
void add_medicine(Medicine *medicines, int *count);
void sell_medicine(Medicine *medicines, int *count);
void display_medicines(Medicine *medicines, int count);

int main() {
    int count = 0;
    Medicine *medicines = malloc(sizeof(Medicine));

    // Display the menu options
    printf("Welcome to the Medical Store Management System!\n");
    printf("Choose an option from the following:\n");
    printf("1. Add a Medicine\n");
    printf("2. Sell a Medicine\n");
    printf("3. Display all Medicines\n");

    int option;
    scanf("%d", &option);

    while (option) {
        switch(option) {
            case 1:
                add_medicine(medicines, &count);
                break;
            case 2:
                sell_medicine(medicines, &count);
                break;
            case 3:
                display_medicines(medicines, count);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

        // Display the menu options again after each operation
        printf("\nChoose an option from the following:\n");
        printf("1. Add a Medicine\n");
        printf("2. Sell a Medicine\n");
        printf("3. Display all Medicines\n");

        scanf("%d", &option);
    }

    free(medicines);
    return 0;
}

// Function to add medicines to the inventory
void add_medicine(Medicine *medicines, int *count) {
    // Increment the count of the medicines
    (*count)++;

    // Allocate memory for the new medicine
    medicines = realloc(medicines, (*count) * sizeof(Medicine));

    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*count - 1].name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[*count - 1].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[*count - 1].price);
}

// Function to sell medicines from the inventory
void sell_medicine(Medicine *medicines, int *count) {
    printf("Enter the name of the medicine: ");
    char name[50];
    scanf("%s", name);

    // Search for the medicine in the inventory
    int index = -1;
    for (int i = 0; i < (*count); i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found in the inventory!\n");
    } else {
        printf("Enter the quantity to sell: ");
        int quantity;
        scanf("%d", &quantity);

        if (medicines[index].quantity < quantity) {
            printf("Insufficient quantity in the inventory!\n");
        } else {
            // Update the quantity and display the bill
            medicines[index].quantity -= quantity;
            float total_price = quantity * medicines[index].price;
            printf("Total bill amount: %.2f\n", total_price);
        }
    }
}

// Function to display all medicines in the inventory
void display_medicines(Medicine *medicines, int count) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}