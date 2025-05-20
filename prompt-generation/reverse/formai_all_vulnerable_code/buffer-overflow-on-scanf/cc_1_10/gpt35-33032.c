//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct Medicine *medicines, int *num) {
    struct Medicine medicine;
    printf("Enter name of medicine: ");
    scanf("%s", medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &medicine.price);
    medicines[*num] = medicine;
    *num += 1;
    printf("Medicine added successfully!\n");
}

void searchMedicine(struct Medicine *medicines, int num) {
    char name[50];
    printf("Enter name of medicine: ");
    scanf("%s", name);
    for (int i = 0; i < num; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void sellMedicine(struct Medicine *medicines, int num) {
    char name[50];
    printf("Enter name of medicine: ");
    scanf("%s", name);
    for (int i = 0; i < num; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            int quantity;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            if (quantity > medicines[i].quantity) {
                printf("Only %d %s available!\n", medicines[i].quantity, medicines[i].name);
                return;
            }
            medicines[i].quantity -= quantity;
            printf("Total price: %.2f\n", medicines[i].price * quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMedicines(struct Medicine *medicines, int num) {
    printf("Medicines in stock:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < num; i++) {
        printf("%s\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    int choice, num = 0;
    struct Medicine medicines[100];

    while (1) {
        printf("1. Add medicine\n");
        printf("2. Search medicine\n");
        printf("3. Sell medicine\n");
        printf("4. Display medicines\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &num);
                break;
            case 2:
                searchMedicine(medicines, num);
                break;
            case 3:
                sellMedicine(medicines, num);
                break;
            case 4:
                displayMedicines(medicines, num);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }

    return 0;
}