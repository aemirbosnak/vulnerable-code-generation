//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

int main() {
    int choice, i, j, n;
    char name[50];
    medicine m[100];

    printf("Medical Store Management System\n");
    printf("1. Add a new medicine\n");
    printf("2. Delete a medicine\n");
    printf("3. Update a medicine\n");
    printf("4. Search for a medicine\n");
    printf("5. Display all medicines\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the medicine: ");
                scanf("%s", m[i].name);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &m[i].quantity);
                printf("Enter the price of the medicine: ");
                scanf("%f", &m[i].price);
                i++;
                break;

            case 2:
                printf("Enter the name of the medicine to be deleted: ");
                scanf("%s", name);
                for (j = 0; j < i; j++) {
                    if (strcmp(m[j].name, name) == 0) {
                        for (int k = j; k < i; k++) {
                            m[k] = m[k + 1];
                        }
                        i--;
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the name of the medicine to be updated: ");
                scanf("%s", name);
                for (j = 0; j < i; j++) {
                    if (strcmp(m[j].name, name) == 0) {
                        printf("Enter the new quantity of the medicine: ");
                        scanf("%d", &m[j].quantity);
                        printf("Enter the new price of the medicine: ");
                        scanf("%f", &m[j].price);
                        break;
                    }
                }
                break;

            case 4:
                printf("Enter the name of the medicine to be searched: ");
                scanf("%s", name);
                for (j = 0; j < i; j++) {
                    if (strcmp(m[j].name, name) == 0) {
                        printf("Medicine found:\n");
                        printf("Name: %s\n", m[j].name);
                        printf("Quantity: %d\n", m[j].quantity);
                        printf("Price: %f\n", m[j].price);
                        break;
                    }
                }
                break;

            case 5:
                printf("All medicines:\n");
                for (j = 0; j < i; j++) {
                    printf("Name: %s\n", m[j].name);
                    printf("Quantity: %d\n", m[j].quantity);
                    printf("Price: %f\n\n", m[j].price);
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}