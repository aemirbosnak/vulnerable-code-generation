//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_OF_MEDICINES 100
#define MAX_MEDICINE_NAME_LENGTH 50
#define MAX_MEDICINE_QUANTITY 1000

typedef struct {
    char name[MAX_MEDICINE_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

int main() {
    int number_of_medicines;
    Medicine medicines[MAX_NUMBER_OF_MEDICINES];

    // Prompt user to enter number of medicines
    printf("Enter the number of medicines: ");
    scanf("%d", &number_of_medicines);

    // Initialize all medicines to NULL
    for (int i = 0; i < number_of_medicines; i++) {
        strcpy(medicines[i].name, "NULL");
        medicines[i].quantity = 0;
        medicines[i].price = 0.0;
    }

    // Prompt user to enter medicine details
    printf("Enter medicine details:\n");
    for (int i = 0; i < number_of_medicines; i++) {
        printf("Enter medicine name: ");
        scanf("%s", medicines[i].name);
        printf("Enter medicine quantity: ");
        scanf("%d", &medicines[i].quantity);
        printf("Enter medicine price: ");
        scanf("%f", &medicines[i].price);
    }

    // Calculate total value of all medicines
    float total_value = 0.0;
    for (int i = 0; i < number_of_medicines; i++) {
        total_value += medicines[i].quantity * medicines[i].price;
    }

    // Print medicine details and total value
    printf("\nMedicine Details:\n");
    printf("----------------------------------------------------\n");
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < number_of_medicines; i++) {
        printf("%s\t\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("----------------------------------------------------\n");
    printf("Total value of all medicines: %.2f\n", total_value);

    return 0;
}