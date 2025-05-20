//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// structure for medicine details
struct medicine {
    char name[100];
    int id;
    float price;
    int quantity;
};

// function prototypes
void addMedicine(struct medicine[]);
void deleteMedicine(struct medicine[]);
void searchMedicine(struct medicine[]);
void updateMedicine(struct medicine[]);
void displayMedicine(struct medicine[]);

int main() {
    // initializing the medicine store with 10 slots for medicines
    struct medicine medStore[10];
    int choice;
    
    do {
        // printing the main menu
        printf("\n\nMedical Store Management System\n\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Display Medicine\n");
        printf("6. Exit\n\n");
        printf("Enter your choice (1-6): ");

        // getting the user's choice
        scanf("%d", &choice);

        // performing the user's selected operation
        switch (choice) {
            case 1: addMedicine(medStore);
                    break;
            case 2: deleteMedicine(medStore);
                    break;
            case 3: searchMedicine(medStore);
                    break;
            case 4: updateMedicine(medStore);
                    break;
            case 5: displayMedicine(medStore);
                    break;
            case 6: printf("\nGoodbye!\n");
                    break;
            default: printf("\nInvalid choice. Please enter a valid choice (1-6).");
        }

    } while (choice != 6);
    
    return 0;
}

// function to add medicine to store
void addMedicine(struct medicine medStore[]) {
    int i, id, quantity;
    float price;
    char name[100];

    // get the details of medicine to add
    printf("\nEnter the details of the medicine to be added.\n");
    printf("Medicine name: ");
    scanf("%s", name);
    printf("Medicine id: ");
    scanf("%d", &id);
    printf("Medicine price: ");
    scanf("%f", &price);
    printf("Medicine quantity: ");
    scanf("%d", &quantity);

    // check if the id is already taken
    for (i = 0; i < 10; i++) {
        if (medStore[i].id == id) {
            printf("\nError: An item with the same id already exists.\n");
            return;
        }
    }

    // add the medicine to store
    for (i = 0; i < 10; i++) {
        if (medStore[i].id == 0) {
            strcpy(medStore[i].name, name);
            medStore[i].id = id;
            medStore[i].price = price;
            medStore[i].quantity = quantity;
            printf("\nMedicine added successfully!\n");
            return;
        }
    }

    // if the medicine store is full
    printf("\nError: The medicine store is full.\n");
}

// function to remove medicine from store
void deleteMedicine(struct medicine medStore[]) {
    int i, id, found = 0;

    // get the id of medicine to remove
    printf("\nEnter the id of the medicine to be removed: ");
    scanf("%d", &id);

    // remove the medicine with given id
    for (i = 0; i < 10; i++) {
        if (medStore[i].id == id) {
            medStore[i].id = 0;
            medStore[i].price = 0;
            medStore[i].quantity = 0;
            strcpy(medStore[i].name, "");
            printf("\nMedicine removed successfully!\n");
            found = 1;
            break;
        }
    }

    // if medicine with given id is not found
    if (!found)
        printf("\nError: Medicine with id %d not found!\n", id);
}

// function to search for a medicine
void searchMedicine(struct medicine medStore[]) {
    int i, id, found = 0;

    // get the id of medicine to search for
    printf("\nEnter the id of the medicine to search for: ");
    scanf("%d", &id);

    // search for the medicine with given id
    for (i = 0; i < 10; i++) {
        if (medStore[i].id == id) {
            printf("\nMedicine Details:");
            printf("\nName: %s", medStore[i].name);
            printf("\nId: %d", medStore[i].id);
            printf("\nPrice: %.2f", medStore[i].price);
            printf("\nQuantity: %d", medStore[i].quantity);
            found = 1;
            break;
        }
    }

    // if medicine with given id is not found
    if (!found)
        printf("\nError: Medicine with id %d not found!\n", id);
}

// function to update a medicine
void updateMedicine(struct medicine medStore[]) {
    int i, id, quantity;
    float price;
    char name[100];
    int found = 0;

    // get the id of medicine to update
    printf("\nEnter the id of the medicine to update: ");
    scanf("%d", &id);

    // search for the medicine with given id
    for (i = 0; i < 10; i++) {
        if (medStore[i].id == id) {
            // get the updated details of medicine
            printf("\nEnter the updated details of the medicine.\n");
            printf("Medicine name: ");
            scanf("%s", name);
            printf("Medicine price: ");
            scanf("%f", &price);
            printf("Medicine quantity: ");
            scanf("%d", &quantity);

            strcpy(medStore[i].name, name);
            medStore[i].price = price;
            medStore[i].quantity = quantity;

            printf("\nMedicine updated successfully!\n");
            found = 1;
            break;
        }
    }

    // if medicine with given id is not found
    if (!found)
        printf("\nError: Medicine with id %d not found!\n", id);
}

// function to display all medicines
void displayMedicine(struct medicine medStore[]) {
    int i;

    printf("\nMedicine Details\n");
    printf("%-15s %-10s %-10s %-10s\n", "Name", "Id", "Price", "Quantity");

    for (i = 0; i < 10; i++) {
        if (medStore[i].id != 0) {
            printf("%-15s %-10d %-10.2f %-10d\n", medStore[i].name, medStore[i].id, medStore[i].price, medStore[i].quantity);
        }
    }
}