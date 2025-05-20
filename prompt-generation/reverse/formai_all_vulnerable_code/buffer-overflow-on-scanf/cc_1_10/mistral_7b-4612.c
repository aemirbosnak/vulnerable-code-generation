//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 50

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Store is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", store[count].name);

    printf("Enter stock: ");
    scanf("%d", &store[count].stock);

    printf("Enter price: ");
    scanf("%f", &store[count].price);

    count++;
}

void deleteMedicine() {
    char name[50];
    int index = -1;

    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        store[i] = store[i + 1];
    }

    count--;
}

void viewMedicines() {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Stock: %d, Price: %.2f\n", i + 1, store[i].name, store[i].stock, store[i].price);
    }
}

void searchMedicine() {
    char name[50];
    int index = -1;

    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    printf("Medicine found: %s, Stock: %d, Price: %.2f\n", store[index].name, store[index].stock, store[index].price);
}

int main() {
    int choice;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. View Medicines\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                viewMedicines();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}