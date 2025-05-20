//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} medicine;

int main() {
    int choice, quantity;
    medicine list[100];
    int i = 0;
    char name[50];
    float price;
    int id;

    while (1) {
        printf("1. Add a new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search a medicine by name\n");
        printf("4. Search a medicine by ID\n");
        printf("5. Sell a medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the medicine's ID: ");
                scanf("%d", &id);
                printf("Enter the medicine's name: ");
                scanf(" %[^\n]s", name);
                printf("Enter the medicine's price: ");
                scanf("%f", &price);
                printf("Enter the medicine's quantity: ");
                scanf("%d", &quantity);

                list[i].id = id;
                strcpy(list[i].name, name);
                list[i].price = price;
                list[i].quantity = quantity;
                i++;

                printf("Medicine added successfully!\n");
                break;

            case 2:
                printf("ID\tName\tPrice\tQuantity\n");
                for (int j = 0; j < i; j++) {
                    printf("%d\t%s\t%.2f\t%d\n", list[j].id, list[j].name, list[j].price, list[j].quantity);
                }
                break;

            case 3:
                printf("Enter the medicine's name: ");
                scanf(" %[^\n]s", name);

                int found = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(list[j].name, name) == 0) {
                        printf("ID: %d\n", list[j].id);
                        printf("Name: %s\n", list[j].name);
                        printf("Price: %.2f\n", list[j].price);
                        printf("Quantity: %d\n", list[j].quantity);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Medicine not found!\n");
                }
                break;

            case 4:
                printf("Enter the medicine's ID: ");
                scanf("%d", &id);

                found = 0;
                for (int j = 0; j < i; j++) {
                    if (list[j].id == id) {
                        printf("ID: %d\n", list[j].id);
                        printf("Name: %s\n", list[j].name);
                        printf("Price: %.2f\n", list[j].price);
                        printf("Quantity: %d\n", list[j].quantity);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Medicine not found!\n");
                }
                break;

            case 5:
                printf("Enter the medicine's ID: ");
                scanf("%d", &id);

                found = 0;
                for (int j = 0; j < i; j++) {
                    if (list[j].id == id) {
                        printf("Enter the quantity to be sold: ");
                        scanf("%d", &quantity);

                        if (quantity <= list[j].quantity) {
                            list[j].quantity -= quantity;
                            printf("Medicine sold successfully!\n");
                        } else {
                            printf("Insufficient quantity!\n");
                        }

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Medicine not found!\n");
                }
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}