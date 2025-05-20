//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[100];
    int num_medicines;
} MedicalStore;

MedicalStore medical_store;

void add_medicine() {
    printf("Enter the name of the medicine: ");
    scanf("%s", medical_store.medicines[medical_store.num_medicines].name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medical_store.medicines[medical_store.num_medicines].quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medical_store.medicines[medical_store.num_medicines].price);

    medical_store.num_medicines++;
}

void remove_medicine() {
    char name[50];

    printf("Enter the name of the medicine to remove: ");
    scanf("%s", name);

    for (int i = 0; i < medical_store.num_medicines; i++) {
        if (strcmp(medical_store.medicines[i].name, name) == 0) {
            for (int j = i + 1; j < medical_store.num_medicines; j++) {
                medical_store.medicines[j - 1] = medical_store.medicines[j];
            }
            medical_store.num_medicines--;
            break;
        }
    }
}

void update_medicine() {
    char name[50];
    int choice;

    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medical_store.num_medicines; i++) {
        if (strcmp(medical_store.medicines[i].name, name) == 0) {
            printf("What do you want to update?\n");
            printf("1. Name\n");
            printf("2. Quantity\n");
            printf("3. Price\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter the new name: ");
                    scanf("%s", medical_store.medicines[i].name);
                    break;
                case 2:
                    printf("Enter the new quantity: ");
                    scanf("%d", &medical_store.medicines[i].quantity);
                    break;
                case 3:
                    printf("Enter the new price: ");
                    scanf("%f", &medical_store.medicines[i].price);
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        }
    }
}

void display_medicines() {
    printf("Name\t\tQuantity\tPrice\n");
    for (int i = 0; i < medical_store.num_medicines; i++) {
        printf("%s\t\t%d\t\t%.2f\n", medical_store.medicines[i].name, medical_store.medicines[i].quantity, medical_store.medicines[i].price);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Update medicine\n");
        printf("4. Display medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                display_medicines();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}