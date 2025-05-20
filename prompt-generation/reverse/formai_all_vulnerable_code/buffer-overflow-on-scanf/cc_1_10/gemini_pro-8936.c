//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} medicine;

int main() {
    int num_medicines;
    printf("Enter the number of medicines: ");
    scanf("%d", &num_medicines);

    medicine *medicines = malloc(sizeof(medicine) * num_medicines);

    for (int i = 0; i < num_medicines; i++) {
        printf("Enter the ID of medicine %d: ", i + 1);
        scanf("%d", &medicines[i].id);

        printf("Enter the name of medicine %d: ", i + 1);
        scanf("%s", medicines[i].name);

        printf("Enter the quantity of medicine %d: ", i + 1);
        scanf("%d", &medicines[i].quantity);

        printf("Enter the price of medicine %d: ", i + 1);
        scanf("%f", &medicines[i].price);
    }

    // Display the medicines
    printf("\nMedicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("ID: %d\n", medicines[i].id);
        printf("Name: %s\n", medicines[i].name);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: %.2f\n\n", medicines[i].price);
    }

    // Search for a medicine by name
    char search_name[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, search_name) == 0) {
            printf("Medicine found:\n");
            printf("ID: %d\n", medicines[i].id);
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }

    free(medicines);

    return 0;
}