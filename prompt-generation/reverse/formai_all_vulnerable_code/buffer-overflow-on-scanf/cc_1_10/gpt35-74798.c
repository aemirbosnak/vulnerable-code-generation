//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine **medicines, int *num_medicines);
void viewInventory(medicine *medicines, int num_medicines);
void searchMedicine(medicine *medicines, int num_medicines, char *name);
void updatePrice(medicine *medicines, int num_medicines, char *name, float new_price);
void sellMedicine(medicine *medicines, int num_medicines, char *name, int quantity_sold);

int main() {
    int option, num_medicines = 0;
    medicine *medicines = NULL;
    char name[50];
    float new_price;
    int quantity_sold;

    do {
        printf("\n------------------------------\n");
        printf("1. Add medicine\n");
        printf("2. View inventory\n");
        printf("3. Search medicine\n");
        printf("4. Update price\n");
        printf("5. Sell medicine\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addMedicine(&medicines, &num_medicines);
                break;
            case 2:
                viewInventory(medicines, num_medicines);
                break;
            case 3:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                searchMedicine(medicines, num_medicines, name);
                break;
            case 4:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter new price of medicine: ");
                scanf("%f", &new_price);
                updatePrice(medicines, num_medicines, name, new_price);
                break;
            case 5:
                printf("Enter name of medicine: ");
                scanf("%s", name);
                printf("Enter quantity sold: ");
                scanf("%d", &quantity_sold);
                sellMedicine(medicines, num_medicines, name, quantity_sold);
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 6);

    free(medicines);

    return 0;
}

void addMedicine(medicine **medicines, int *num_medicines) {
    *num_medicines += 1;
    *medicines = (medicine*) realloc(*medicines, sizeof(medicine) * (*num_medicines));

    printf("\nMedicine %d\n", *num_medicines);

    printf("Enter name of medicine: ");
    scanf("%s", (*medicines)[*num_medicines - 1].name);

    printf("Enter quantity of medicine: ");
    scanf("%d", &((*medicines)[*num_medicines - 1].quantity));

    printf("Enter price of medicine: ");
    scanf("%f", &((*medicines)[*num_medicines - 1].price));

    printf("Medicine added successfully.\n");
}

void viewInventory(medicine *medicines, int num_medicines) {
    printf("\nInventory\n");
    printf("%-50s%-15s%-15s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < num_medicines; i++) {
        printf("%-50s%-15d%-15.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(medicine *medicines, int num_medicines, char *name) {
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            printf("\nMedicine Found\n");
            printf("%-50s%-15s%-15s\n", "Name", "Quantity", "Price");
            printf("%-50s%-15d%-15.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

void updatePrice(medicine *medicines, int num_medicines, char *name, float new_price) {
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            medicines[i].price = new_price;
            printf("\nPrice of medicine updated successfully.\n");
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

void sellMedicine(medicine *medicines, int num_medicines, char *name, int quantity_sold) {
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            if (medicines[i].quantity >= quantity_sold) {
                medicines[i].quantity -= quantity_sold;
                printf("\nMedicine sold successfully.\n");
                return;
            }
            else {
                printf("\nNot enough quantity of medicine available.\n");
                return;
            }
        }
    }
    printf("\nMedicine not found.\n");
}