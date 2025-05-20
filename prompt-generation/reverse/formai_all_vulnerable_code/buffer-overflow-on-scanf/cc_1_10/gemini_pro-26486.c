//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} medicine_t;

void add_medicine(medicine_t *medicines, int *num_medicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*num_medicines].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    (*num_medicines)++;
}

void sell_medicine(medicine_t *medicines, int *num_medicines) {
    char name[50];
    printf("Enter medicine name to sell: ");
    scanf("%s", name);
    for (int i = 0; i < *num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Medicine sold successfully.\n");
            } else {
                printf("Insufficient quantity.\n");
            }
            return;
        }
    }
    printf("Medicine not found.\n");
}

void print_medicines(medicine_t *medicines, int num_medicines) {
    printf("Medicines:\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%s %.2f %d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

int main() {
    medicine_t medicines[100];
    int num_medicines = 0;
    int choice;

    while (1) {
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Print medicines\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                sell_medicine(medicines, &num_medicines);
                break;
            case 3:
                print_medicines(medicines, num_medicines);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}