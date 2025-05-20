//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int quantity;
    float price;
} Medicine;

void printMenu() {
    printf("Welcome to our Medical Store Management System!\n\n");
    printf("1. Add new medicine\n");
    printf("2. Update medicine quantity\n");
    printf("3. Update medicine price\n");
    printf("4. Remove medicine\n");
    printf("5. List all medicines\n");
    printf("6. Exit\n\n");
    printf("Enter your choice (1-6): ");
}

int addMedicine(Medicine *medicines, int count) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[count].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[count].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[count].price);
    return ++count;
}

void updateQuantity(Medicine *medicines, int count) {
    char name[100];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int quantity;
            printf("Enter updated quantity for %s: ", medicines[i].name);
            scanf("%d", &quantity);
            medicines[i].quantity = quantity;
            printf("%s quantity updated successfully!\n", medicines[i].name);
            return;
        }
    }
    printf("Medicine with name %s not found.\n", name);
}

void updatePrice(Medicine *medicines, int count) {
    char name[100];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            float price;
            printf("Enter updated price for %s: ", medicines[i].name);
            scanf("%f", &price);
            medicines[i].price = price;
            printf("%s price updated successfully!\n", medicines[i].name);
            return;
        }
    }
    printf("Medicine with name %s not found.\n", name);
}

int removeMedicine(Medicine *medicines, int count) {
    char name[100];
    printf("Enter name of medicine to remove: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            printf("%s removed successfully!\n", name);
            return --count;
        }
    }
    printf("Medicine with name %s not found.\n", name);
    return count;
}

void listMedicines(Medicine *medicines, int count) {
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    int count = 0;
    Medicine medicines[100];
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                count = addMedicine(medicines, count);
                break;
            case 2:
                updateQuantity(medicines, count);
                break;
            case 3:
                updatePrice(medicines, count);
                break;
            case 4:
                count = removeMedicine(medicines, count);
                break;
            case 5:
                listMedicines(medicines, count);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    } while (choice != 6);
    return 0;
}