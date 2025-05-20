//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Medicine {
    char name[30];
    int quantity;
    float price;
};

typedef struct Medicine Medicine;

int main() {
    Medicine database[MAX_SIZE];
    int num_medicines = 0, choice = 0;
    char search_name[30];
    float total_revenue = 0;

    while (choice != 5) {
        printf("Welcome to C Medical Store Management System\n");
        printf("1. Add new medicine\n2. Search for medicine\n3. Update medicine quantity\n4. View inventory\n5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_medicines == MAX_SIZE) {
                    printf("Error: Database is full\n");
                    break;
                }

                Medicine new_medicine;

                printf("Enter medicine name: ");
                scanf("%s", new_medicine.name);

                printf("Enter medicine quantity: ");
                scanf("%d", &new_medicine.quantity);

                printf("Enter medicine price: ");
                scanf("%f", &new_medicine.price);

                database[num_medicines] = new_medicine;

                num_medicines++;

                printf("Medicine added to inventory.\n");

                break;
            case 2:
                printf("Enter name of medicine to search: ");
                scanf("%s", search_name);

                for (int i = 0; i < num_medicines; i++) {
                    if (strcmp(search_name, database[i].name) == 0) {
                        printf("%-30s %6d %.2f\n", database[i].name, database[i].quantity, database[i].price);
                        break;
                    }
                }

                printf("Medicine not found in inventory.\n");

                break;
            case 3:
                printf("Enter name of medicine to update quantity: ");
                scanf("%s", search_name);

                for (int i = 0; i < num_medicines; i++) {
                    if (strcmp(search_name, database[i].name) == 0) {
                        int new_quantity;

                        printf("Enter new quantity: ");
                        scanf("%d", &new_quantity);

                        database[i].quantity = new_quantity;

                        printf("Medicine quantity updated.\n");

                        break;
                    }
                }

                printf("Medicine not found in inventory.\n");

                break;
            case 4:
                printf("%-30s %6s %6s\n", "Name", "Qty", "Price");

                for (int i = 0; i < num_medicines; i++) {
                    printf("%-30s %6d %.2f\n", database[i].name, database[i].quantity, database[i].price);

                    total_revenue += (float)(database[i].quantity * database[i].price);
                }

                printf("Total revenue: %.2f\n", total_revenue);

                break;
            case 5:
                printf("Exiting program...\n");

                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}