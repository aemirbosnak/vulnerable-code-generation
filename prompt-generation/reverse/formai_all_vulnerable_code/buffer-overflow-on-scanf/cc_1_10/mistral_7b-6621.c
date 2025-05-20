//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_STOCK 1000

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines == MAX_MEDICINES) {
        printf("Store is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", medicines[num_medicines].name);

    printf("Enter stock: ");
    scanf("%d", &medicines[num_medicines].stock);

    printf("Enter price: ");
    scanf("%f", &medicines[num_medicines].price);

    num_medicines++;

    printf("%s added to the store!\n", medicines[num_medicines - 1].name);
}

void display_inventory() {
    printf("\nCurrent Inventory:\n");

    for (int i = 0; i < num_medicines; i++) {
        printf("%s - Stock: %d, Price: %.2f\n", medicines[i].name, medicines[i].stock, medicines[i].price);
    }
}

void sell_medicine() {
    char name[50];
    int quantity;

    printf("Enter medicine name: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity > medicines[i].stock) {
                printf("Insufficient stock!\n");
                return;
            }

            medicines[i].stock -= quantity;
            printf("%d units of %s sold.\n", quantity, name);
            break;
        }
    }

    printf("Medicine not found in the store!\n");
}

int main() {
    char choice[10];

    while (1) {
        printf("\n1. Add Medicine\n2. Display Inventory\n3. Sell Medicine\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        switch (choice[0]) {
            case '1':
                add_medicine();
                break;
            case '2':
                display_inventory();
                break;
            case '3':
                sell_medicine();
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}