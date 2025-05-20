//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Medicine {
    char name[50];
    int id;
    int quantity;
    float price;
};

void addMedicine(struct Medicine *medicines, int count) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[count].name);
    printf("Enter quantity: ");
    scanf("%d", &medicines[count].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[count].price);
    medicines[count].id = rand() % 1000 + 1;
    printf("Medicine added with id %d.\n", medicines[count].id);
}

void updateMedicine(struct Medicine *medicines, int count) {
    int id;
    printf("Enter medicine id: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (id == medicines[i].id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully.\n");
            break;
        }
    }
    if (!found) printf("Medicine with id %d not found.\n", id);
}

void printMedicines(struct Medicine *medicines, int count) {
    printf("%-15s%-15s%-15s%s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-15d%-15s%-15d$%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void printLowStock(struct Medicine *medicines, int count) {
    printf("%-15s%-15s%-15s%s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        if (medicines[i].quantity < 10) {
            printf("%-15d%-15s%-15d$%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
        }
    }
}

void searchMedicine(struct Medicine *medicines, int count) {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    int found = 0;
    printf("%-15s%-15s%-15s%s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            found = 1;
            printf("%-15d%-15s%-15d$%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
            break;
        }
    }
    if (!found) printf("Medicine with name %s not found.\n", name);
}

int main() {
    struct Medicine medicines[100];
    int count = 0;
    int choice;
    srand(time(0));
    do {
        printf("Welcome to Medical Store Management System\n");
        printf("1. Add medicine\n");
        printf("2. Update medicine\n");
        printf("3. Print all medicines\n");
        printf("4. Print low stock medicines\n");
        printf("5. Search medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, count);
                count++;
                break;
            case 2:
                updateMedicine(medicines, count);
                break;
            case 3:
                printMedicines(medicines, count);
                break;
            case 4:
                printLowStock(medicines, count);
                break;
            case 5:
                searchMedicine(medicines, count);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}