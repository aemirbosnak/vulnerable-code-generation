//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 50

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Store is full!\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", medicines[count].name);

    printf("Enter stock: ");
    scanf("%d", &medicines[count].stock);

    printf("Enter price: ");
    scanf("%f", &medicines[count].price);

    count++;
}

void deleteMedicine() {
    char name[50];
    int i;

    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}

void searchMedicine() {
    char name[50];
    int i;

    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Name: %s\n", medicines[i].name);
            printf("Stock: %d\n", medicines[i].stock);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void display() {
    int i;

    printf("\nMedicines in the store:\n");

    for (i = 0; i < count; i++) {
        printf("Name: %s\n", medicines[i].name);
        printf("Stock: %d\n", medicines[i].stock);
        printf("Price: %.2f\n", medicines[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add medicine\n2. Delete medicine\n3. Search medicine\n4. Display medicines\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}