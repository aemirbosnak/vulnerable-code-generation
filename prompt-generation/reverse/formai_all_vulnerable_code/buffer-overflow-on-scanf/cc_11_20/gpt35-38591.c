//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

int main() {
    struct medicine med[100];

    int choice, n = 0;
    float total_price = 0;

    printf("Welcome to Medical Store Management System\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Remove Medicine\n");
        printf("4. View Medicine List\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter medicine name: ");
                scanf("%s", med[n].name);

                printf("Enter manufacturer name: ");
                scanf("%s", med[n].manufacturer);

                printf("Enter quantity: ");
                scanf("%d", &med[n].quantity);

                printf("Enter price: ");
                scanf("%f", &med[n].price);

                n++;

                printf("\nMedicine added successfully!\n");
                break;


            case 2:
                printf("\nEnter medicine name to update: ");
                char update_name[50];
                scanf("%s", update_name);

                int index = -1;
                for (int i = 0; i < n; i++) {
                    if (strcmp(med[i].name, update_name) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nMedicine not found!\n");
                } else {
                    printf("\nEnter new medicine name: ");
                    scanf("%s", med[index].name);

                    printf("Enter new manufacturer name: ");
                    scanf("%s", med[index].manufacturer);

                    printf("Enter new quantity: ");
                    scanf("%d", &med[index].quantity);

                    printf("Enter new price: ");
                    scanf("%f", &med[index].price);

                    printf("\nMedicine updated successfully!\n");
                }
                break;


            case 3:
                printf("\nEnter medicine name to remove: ");
                char remove_name[50];
                scanf("%s", remove_name);

                index = -1;
                for (int i = 0; i < n; i++) {
                    if (strcmp(med[i].name, remove_name) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nMedicine not found!\n");
                } else {
                    for (int i = index; i < n - 1; i++) {
                        med[i] = med[i + 1];
                    }
                    n--;

                    printf("\nMedicine removed successfully!\n");
                }
                break;


            case 4:
                printf("\nMedicine List\n");
                printf("=================================================================\n");
                printf("%-20s%-20s%-10s%-10s\n", "Medicine Name", "Manufacturer Name", "Quantity", "Price");
                printf("=================================================================\n");

                for (int i = 0; i < n; i++) {
                    printf("%-20s%-20s%-10d%-10.2f\n", med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
                    total_price += med[i].price;
                }

                printf("=================================================================\n");
                printf("Total Price: %.2f\n", total_price);
                break;


            case 5:
                printf("\nThank you for using Medical Store Management System!\n");
                break;


            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}