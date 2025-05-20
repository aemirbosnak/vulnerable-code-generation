//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

int main() {
    medicine *inventory = NULL;
    int num_medicines = 0;

    while (1) {
        printf("1. Add medicine\n2. Remove medicine\n3. Search medicine\n4. Print inventory\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter medicine name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);

                printf("Enter price: ");
                float price;
                scanf("%f", &price);

                inventory = realloc(inventory, (num_medicines + 1) * sizeof(medicine));
                strcpy(inventory[num_medicines].name, name);
                inventory[num_medicines].quantity = quantity;
                inventory[num_medicines].price = price;
                num_medicines++;

                printf("Medicine added to inventory.\n");
                break;

            case 2:
                printf("Enter medicine name: ");
                char name2[50];
                scanf("%s", name2);

                int found = 0;
                for (int i = 0; i < num_medicines; i++) {
                    if (strcmp(inventory[i].name, name2) == 0) {
                        found = 1;

                        printf("Enter quantity to remove: ");
                        int quantity2;
                        scanf("%d", &quantity2);

                        if (quantity2 > inventory[i].quantity) {
                            printf("Invalid quantity.\n");
                        } else {
                            inventory[i].quantity -= quantity2;
                            if (inventory[i].quantity == 0) {
                                for (int j = i; j < num_medicines - 1; j++) {
                                    inventory[j] = inventory[j + 1];
                                }
                                num_medicines--;
                                inventory = realloc(inventory, num_medicines * sizeof(medicine));
                            }
                        }
                    }
                }

                if (!found) {
                    printf("Medicine not found.\n");
                }
                break;

            case 3:
                printf("Enter medicine name: ");
                char name3[50];
                scanf("%s", name3);

                int found2 = 0;
                for (int i = 0; i < num_medicines; i++) {
                    if (strcmp(inventory[i].name, name3) == 0) {
                        found2 = 1;

                        printf("Medicine found:\n");
                        printf("Name: %s\n", inventory[i].name);
                        printf("Quantity: %d\n", inventory[i].quantity);
                        printf("Price: %f\n", inventory[i].price);
                    }
                }

                if (!found2) {
                    printf("Medicine not found.\n");
                }
                break;

            case 4:
                printf("Inventory:\n");
                for (int i = 0; i < num_medicines; i++) {
                    printf("Name: %s\n", inventory[i].name);
                    printf("Quantity: %d\n", inventory[i].quantity);
                    printf("Price: %f\n", inventory[i].price);
                    printf("\n");
                }
                break;

            case 5:
                free(inventory);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}