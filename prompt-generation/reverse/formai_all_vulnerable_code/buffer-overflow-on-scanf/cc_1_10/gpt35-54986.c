//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define constants for maximum length of strings
#define MAX_NAME_LENGTH 50
#define MAX_AREA_LENGTH 20
#define MAX_MEDICINES 100

// Struct for storing medicines
struct Medicine {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float cost_price;
    float selling_price;
    char area[MAX_AREA_LENGTH];
};

// Function to add a new medicine to the store
void add_medicine(struct Medicine *medicines, int *num_medicines) {
    // Check if maximum number of medicines has been reached
    if (*num_medicines >= MAX_MEDICINES) {
        printf("Maximum number of medicines reached!\n");
        return;
    }

    // Prompt user for medicine details
    printf("Enter medicine name: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    printf("Enter medicine cost price: ");
    scanf("%f", &medicines[*num_medicines].cost_price);
    printf("Enter medicine selling price: ");
    scanf("%f", &medicines[*num_medicines].selling_price);
    printf("Enter medicine area: ");
    scanf("%s", medicines[*num_medicines].area);

    // Increment number of medicines
    (*num_medicines)++;

    printf("Medicine added successfully!\n");
}

// Function to search for a medicine by name and display its details
void search_medicine(struct Medicine *medicines, int num_medicines) {
    // Prompt user for medicine name
    char search_name[MAX_NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", search_name);

    // Iterate over all medicines to find the one matching the search name
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, search_name) == 0) {
            // Medicine found, display details
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Cost price: %.2f\n", medicines[i].cost_price);
            printf("Selling price: %.2f\n", medicines[i].selling_price);
            printf("Area: %s\n", medicines[i].area);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    // Allocate memory for array of medicines
    struct Medicine *medicines = (struct Medicine *) malloc(MAX_MEDICINES * sizeof(struct Medicine));
    int num_medicines = 0;

    // Main program loop
    int choice;
    do {
        // Display menu options
        printf("\n\n1. Add new medicine\n");
        printf("2. Search for medicine\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                search_medicine(medicines, num_medicines);
                break;
            case 3:
                // User wants to exit, free memory and exit program
                free(medicines);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
}