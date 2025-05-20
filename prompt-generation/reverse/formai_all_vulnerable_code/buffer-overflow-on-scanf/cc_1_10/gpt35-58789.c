//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int qty;
};

typedef struct medicine Medicine;

void display(Medicine *medicines, int num_medicines) {
    printf("\nID\tMedicine Name\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].qty);
    }
}

void addMedicine(Medicine *medicines, int *num_medicines) {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int qty;
    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);
    printf("Enter Medicine Name: ");
    scanf("%s", name);
    printf("Enter Manufacturer: ");
    scanf("%s", manufacturer);
    printf("Enter Price: ");
    scanf("%f", &price);
    printf("Enter Quantity: ");
    scanf("%d", &qty);
    medicines[*num_medicines].id = id;
    strcpy(medicines[*num_medicines].name, name);
    strcpy(medicines[*num_medicines].manufacturer, manufacturer);
    medicines[*num_medicines].price = price;
    medicines[*num_medicines].qty = qty;
    *num_medicines += 1;
}

void searchMedicine(Medicine *medicines, int num_medicines) {
    int id, found = 0;
    printf("\nEnter Medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            found = 1;
            printf("\nID\tMedicine Name\tManufacturer\tPrice\tQuantity\n");
            printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].qty);
            break;
        }
    }
    if (found == 0) {
        printf("\nMedicine not found.\n");
    }
}

void editMedicine(Medicine *medicines, int num_medicines) {
    int id, found = 0;
    printf("\nEnter Medicine ID to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            found = 1;
            printf("\nMedicine found:");
            printf("\nID\tMedicine Name\tManufacturer\tPrice\tQuantity\n");
            printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].qty);
            printf("\nEnter new details:");
            printf("\nEnter Medicine Name: ");
            scanf("%s", medicines[i].name);
            printf("Enter Manufacturer: ");
            scanf("%s", medicines[i].manufacturer);
            printf("Enter Price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter Quantity: ");
            scanf("%d", &medicines[i].qty);
            printf("\nDetails updated.\n");
            break;
        }
    }
    if (found == 0) {
        printf("\nMedicine not found.\n");
    }
}

void deleteMedicine(Medicine *medicines, int *num_medicines) {
    int id, index = -1;
    printf("\nEnter Medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *num_medicines; i++) {
        if (medicines[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *num_medicines - 1; i++) {
            medicines[i] = medicines[i+1];
        }
        *num_medicines -= 1;
        printf("\nMedicine deleted successfully.\n");
    } else {
        printf("\nMedicine not found.\n");
    }
}

int main() {
    Medicine medicines[100];
    int num_medicines = 0, choice;
    while (1) {
        printf("\n-------Medical Store Management System-------");
        printf("\n1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Edit Medicine\n5. Delete Medicine\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, &num_medicines);
                break;
            case 2:
                display(medicines, num_medicines);
                break;
            case 3:
                searchMedicine(medicines, num_medicines);
                break;
            case 4:
                editMedicine(medicines, num_medicines);
                break;
            case 5:
                deleteMedicine(medicines, &num_medicines);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}