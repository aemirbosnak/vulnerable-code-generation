//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine *inventory;
int num_medicines;

void add_medicine() {
    Medicine *new_medicine = malloc(sizeof(Medicine));
    printf("Enter medicine name: ");
    gets(new_medicine->name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine->quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine->price);

    inventory = realloc(inventory, (num_medicines + 1) * sizeof(Medicine));
    inventory[num_medicines++] = *new_medicine;

    printf("Medicine added successfully!\n");
}

void list_medicines() {
    printf("Medicine List:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d. %s (%d units, %.2f each)\n", i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    gets(name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Quantity: %d units\n", inventory[i].quantity);
            printf("Price: %.2f each\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    gets(name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            int choice;
            printf("1. Update quantity\n");
            printf("2. Update price\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    break;
                case 2:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].price);
                    break;
                default:
                    printf("Invalid choice!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void delete_medicine() {
    char name[50];
    printf("Enter medicine name: ");
    gets(name);

    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found!\n");
            for (int j = i; j < num_medicines - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_medicines--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    inventory = malloc(0);
    num_medicines = 0;

    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. List Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                list_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}