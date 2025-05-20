//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    char manufacturer[20];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

void add_medicine(Medicine *medicines, int *count) {
    printf("\nEnter medicine details:");
    printf("\nID: ");
    scanf("%d", &medicines[*count].id);

    printf("Name: ");
    scanf("%s", medicines[*count].name);

    printf("Manufacturer: ");
    scanf("%s", medicines[*count].manufacturer);

    printf("Quantity: ");
    scanf("%d", &medicines[*count].quantity);

    printf("Price: ");
    scanf("%f", &medicines[*count].price);

    (*count)++;
}

void display_medicines(Medicine *medicines, int count) {
    printf("\nID  -  Name                    -  Manufacturer        -  Quantity  -  Price\n");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-4d%-25s%-20s%-11d%7.2f\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
    printf("------------------------------------------------------------------------\n");
}

void search_medicine(Medicine *medicines, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine Found!\n");
            printf("ID: %d\nName: %s\nManufacturer: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void update_medicine(Medicine *medicines, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            printf("\nEnter new details for medicine:");
            printf("\nName: ");
            scanf("%s", medicines[i].name);

            printf("Manufacturer: ");
            scanf("%s", medicines[i].manufacturer);

            printf("Quantity: ");
            scanf("%d", &medicines[i].quantity);

            printf("Price: ");
            scanf("%f", &medicines[i].price);

            printf("\nMedicine details updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void sell_medicine(Medicine *medicines, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            int quantity;
            printf("\nEnter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= medicines[i].quantity) {
                medicines[i].quantity -= quantity;
                float price = quantity * medicines[i].price;
                printf("\nMedicine sold successfully!");
                printf("\nTotal amount: %.2f\n", price);
            } else {
                printf("\nSorry, insufficient stock!\n");
            }
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

int main() {
    Medicine medicines[100];
    int count = 0;
    int choice, id;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("\n1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Update Medicine\n5. Sell Medicine\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(medicines, &count);
                break;
            case 2:
                display_medicines(medicines, count);
                break;
            case 3:
                printf("\nEnter ID of medicine to search: ");
                scanf("%d", &id);
                search_medicine(medicines, count, id);
                break;
            case 4:
                printf("\nEnter ID of medicine to update: ");
                scanf("%d", &id);
                update_medicine(medicines, count, id);
                break;
            case 5:
                printf("\nEnter ID of medicine to sell: ");
                scanf("%d", &id);
                sell_medicine(medicines, count, id);
                break;
            case 6:
                printf("\nThank you for using the system!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}