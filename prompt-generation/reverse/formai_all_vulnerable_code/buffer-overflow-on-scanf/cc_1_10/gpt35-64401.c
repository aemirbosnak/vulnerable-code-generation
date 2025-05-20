//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing medicine information
struct medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to add new medicine to the system
void add_medicine(struct medicine *med, int *num_meds) {
    printf("Enter medicine ID: ");
    scanf("%d", &(med + *num_meds)->id);
    printf("Enter medicine name: ");
    scanf("%s", (med + *num_meds)->name);
    printf("Enter medicine price: ");
    scanf("%f", &(med + *num_meds)->price);
    printf("Enter medicine quantity: ");
    scanf("%d", &(med + *num_meds)->quantity);
    (*num_meds)++;
}

// Function to search for medicine by name
void search_medicine(struct medicine *med, int num_meds) {
    char search_name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_meds; i++) {
        if (strcmp((med + i)->name, search_name) == 0) {
            printf("Medicine Found!\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", (med + i)->id, (med + i)->name, (med + i)->price, (med + i)->quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

// Function to update medicine price
void update_price(struct medicine *med, int num_meds) {
    int id;
    float new_price;
    printf("Enter ID of medicine to update price: ");
    scanf("%d", &id);
    for (int i = 0; i < num_meds; i++) {
        if ((med + i)->id == id) {
            printf("Enter new price: ");
            scanf("%f", &new_price);
            (med + i)->price = new_price;
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

// Main function
int main() {
    struct medicine *med;
    med = (struct medicine*) malloc(10 * sizeof(struct medicine)); // Allocate memory for 10 medicines
    int num_meds = 0;
    int option;
    do {
        printf("\n");
        printf("1. Add new medicine\n");
        printf("2. Search for medicine\n");
        printf("3. Update medicine price\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        printf("\n");
        switch(option) {
            case 1:
                add_medicine(med, &num_meds);
                break;
            case 2:
                search_medicine(med, num_meds);
                break;
            case 3:
                update_price(med, num_meds);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != 4);
    free(med); // Free allocated memory
    return 0;
}