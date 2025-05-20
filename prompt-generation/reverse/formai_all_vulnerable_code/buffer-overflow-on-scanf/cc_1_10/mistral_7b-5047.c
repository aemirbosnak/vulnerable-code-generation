//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50

typedef struct {
    char name[50];
    float price;
    int stock;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[num_medicines].name);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[num_medicines].price);
    printf("Enter initial stock: ");
    scanf("%d", &inventory[num_medicines].stock);

    num_medicines++;
}

void update_medicine() {
    int index;
    char name[50];

    printf("Enter medicine name to update: ");
    scanf("%s", name);

    for (index = 0; index < num_medicines; index++) {
        if (strcmp(inventory[index].name, name) == 0) {
            printf("Enter new medicine price: ");
            scanf("%f", &inventory[index].price);
            printf("Enter new stock: ");
            scanf("%d", &inventory[index].stock);
            break;
        }
    }

    if (index >= num_medicines) {
        printf("Medicine not found.\n");
    }
}

void delete_medicine() {
    int index, i;
    char name[50];

    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    for (index = 0; index < num_medicines; index++) {
        if (strcmp(inventory[index].name, name) == 0) {
            for (i = index; i < num_medicines - 1; i++) {
                inventory[i] = inventory[i+1];
            }
            num_medicines--;
            break;
        }
    }

    if (index >= num_medicines) {
        printf("Medicine not found.\n");
    }
}

void view_inventory() {
    int index;

    printf("\nCurrent inventory:\n");

    for (index = 0; index < num_medicines; index++) {
        printf("%s\t%.2f\t%d\n", inventory[index].name, inventory[index].price, inventory[index].stock);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add medicine\n2. Update medicine\n3. Delete medicine\n4. View inventory\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                update_medicine();
                break;
            case 3:
                delete_medicine();
                break;
            case 4:
                view_inventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}