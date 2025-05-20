//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int stock;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int count = 0;

void add_medicine() {
    if (count >= MAX_MEDICINES) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[count].name);

    printf("Enter initial stock: ");
    scanf("%d", &inventory[count].stock);

    count++;
}

void view_inventory() {
    printf("\nCurrent inventory:\n");

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].stock);
    }
}

void update_stock() {
    char name[50];
    int new_stock, index = -1;

    printf("Enter medicine name: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    printf("Enter new stock: ");
    scanf("%d", &new_stock);

    inventory[index].stock = new_stock;
}

void remove_medicine() {
    char name[50];
    int index = -1;

    printf("Enter medicine name: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        strcpy(inventory[i].name, inventory[i + 1].name);
        inventory[i].stock = inventory[i + 1].stock;
    }

    count--;
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add medicine\n");
        printf("2. View inventory\n");
        printf("3. Update medicine stock\n");
        printf("4. Remove medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_inventory();
                break;
            case 3:
                update_stock();
                break;
            case 4:
                remove_medicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}