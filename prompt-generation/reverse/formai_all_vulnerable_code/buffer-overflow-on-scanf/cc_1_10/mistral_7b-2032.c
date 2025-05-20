//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

int mainMenu() {
    int choice;
    printf("\n1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine Stock\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addMedicine(Medicine *medicines, int *num) {
    if (*num >= MAX) {
        printf("\nArray is full. Cannot add medicine.\n");
        return;
    }

    printf("\nEnter medicine name: ");
    scanf("%s", medicines[*num].name);

    printf("Enter medicine stock: ");
    scanf("%d", &medicines[*num].stock);

    printf("Enter medicine price: ");
    scanf("%f", &medicines[*num].price);

    (*num)++;
}

void displayMedicines(Medicine *medicines, int num) {
    int i;

    printf("\nList of Medicines:\n");

    for (i = 0; i < num; i++) {
        printf("\nName: %s\n", medicines[i].name);
        printf("Stock: %d\n", medicines[i].stock);
        printf("Price: %.2f\n", medicines[i].price);
    }
}

void updateStock(Medicine *medicines, int num) {
    int index, newStock;

    printf("\nEnter index of the medicine to update stock: ");
    scanf("%d", &index);

    if (index < 0 || index >= num) {
        printf("\nInvalid index.\n");
        return;
    }

    printf("Enter new stock for medicine %s: ", medicines[index].name);
    scanf("%d", &newStock);

    medicines[index].stock = newStock;
}

void deleteMedicine(Medicine *medicines, int *num, int index) {
    int i;

    if (index < 0 || index >= *num) {
        printf("\nInvalid index.\n");
        return;
    }

    for (i = index; i < *num - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    (*num)--;
}

int main() {
    Medicine medicines[MAX];
    int num = 0;
    int choice;

    while (1) {
        choice = mainMenu();

        switch (choice) {
            case 1:
                addMedicine(medicines, &num);
                break;
            case 2:
                displayMedicines(medicines, num);
                break;
            case 3: {
                int index;
                printf("\nEnter index of the medicine to update stock: ");
                scanf("%d", &index);
                updateStock(medicines, num);
                break;
            }
            case 4: {
                int index;
                printf("\nEnter index of the medicine to delete: ");
                scanf("%d", &index);
                deleteMedicine(medicines, &num, index);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}