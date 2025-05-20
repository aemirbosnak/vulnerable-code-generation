//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

int main() {
    int n;
    printf("Enter number of medicines: ");
    scanf("%d", &n);

    medicine *meds = malloc(sizeof(medicine) * n);

    for (int i = 0; i < n; i++) {
        printf("Enter medicine name: ");
        scanf("%s", meds[i].name);

        printf("Enter quantity: ");
        scanf("%d", &meds[i].quantity);

        printf("Enter price: ");
        scanf("%f", &meds[i].price);
    }

    // Display the medicines
    printf("\n Medicines in stock:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", meds[i].name, meds[i].quantity, meds[i].price);
    }

    // Search for a medicine
    char search_name[50];
    printf("\nEnter medicine name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(meds[i].name, search_name) == 0) {
            printf("Medicine found:\n");
            printf("%s %d %f\n", meds[i].name, meds[i].quantity, meds[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }

    // Update medicine quantity
    char update_name[50];
    int update_quantity;
    printf("\nEnter medicine name to update quantity: ");
    scanf("%s", update_name);

    printf("Enter new quantity: ");
    scanf("%d", &update_quantity);

    for (int i = 0; i < n; i++) {
        if (strcmp(meds[i].name, update_name) == 0) {
            meds[i].quantity = update_quantity;
            printf("Quantity updated.\n");
        }
    }

    // Display the medicines
    printf("\n Medicines in stock:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %f\n", meds[i].name, meds[i].quantity, meds[i].price);
    }

    free(meds);
    return 0;
}