//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine med[], int *medCount);
void sellMedicine(struct medicine med[], int medCount);
void displayMedicines(struct medicine med[], int medCount);
void updatePrice(struct medicine med[], int medCount);

int main() {
    int option, medCount = 0;
    struct medicine med[100];

    printf("========== Medical Store Management System ==========\n");

    do {
        printf("\nEnter an option:\n");
        printf("1. Add new medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Display all medicines\n");
        printf("4. Update medicine prices\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1: addMedicine(med, &medCount); break;
            case 2: sellMedicine(med, medCount); break;
            case 3: displayMedicines(med, medCount); break;
            case 4: updatePrice(med, medCount); break;
            case 5: printf("\nThank you for using our system!\n"); break;
            default: printf("\nInvalid option selected. Please try again.\n"); break;
        }
    } while(option != 5);

    return 0;
}

void addMedicine(struct medicine med[], int *medCount) {
    printf("\nEnter the medicine name: ");
    scanf("%s", med[*medCount].name);

    printf("Enter the quantity: ");
    scanf("%d", &med[*medCount].quantity);

    printf("Enter the price: ");
    scanf("%f", &med[*medCount].price);

    printf("\nMedicine added successfully!\n");
    (*medCount)++;
}

void sellMedicine(struct medicine med[], int medCount) {
    char name[50];
    int soldQuantity, i;

    printf("\nEnter the medicine name: ");
    scanf("%s", name);

    for (i = 0; i < medCount; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("Enter the quantity to sell: ");
            scanf("%d", &soldQuantity);

            if (soldQuantity > med[i].quantity) {
                printf("\nNot enough quantity available to sell.\n");
                return;
            }

            med[i].quantity -= soldQuantity;
            printf("\nMedicine sold successfully!\n");
            return;
        }
    }

    printf("\nMedicine not found.\n");
}

void displayMedicines(struct medicine med[], int medCount) {
    int i;

    printf("\nMedicine Name\tQuantity\tPrice\n");
    for (i = 0; i < medCount; i++) {
        printf("%s\t\t%d\t\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

void updatePrice(struct medicine med[], int medCount) {
    char name[50];
    float price;
    int i;

    printf("\nEnter the medicine name: ");
    scanf("%s", name);

    for (i = 0; i < medCount; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("Enter the new price: ");
            scanf("%f", &price);

            med[i].price = price;
            printf("\nPrice updated successfully!\n");
            return;
        }
    }

    printf("\nMedicine not found.\n");
}