//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct Medicine {
    char name[MAX_SIZE];
    float price;
    int stock;
} Medicine;

Medicine medicines[MAX_SIZE];
int count = 0;

void addMedicine();
void viewMedicines();
void searchMedicine();
void updateMedicine();
void deleteMedicine();

void main() {
    int choice;

    while(1) {
        printf("\n--- MEDICAL STORE MANAGEMENT SYSTEM ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

void addMedicine() {
    Medicine newMedicine;

    printf("Enter Medicine Name: ");
    scanf("%s", newMedicine.name);

    printf("Enter Medicine Price: ");
    scanf("%f", &newMedicine.price);

    printf("Enter Medicine Stock: ");
    scanf("%d", &newMedicine.stock);

    medicines[count++] = newMedicine;

    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    int i;

    if(count == 0) {
        printf("No medicines in stock!\n");
        return;
    }

    printf("\n--- MEDICINES IN STOCK ---\n");

    for(i = 0; i < count; i++) {
        printf("\nName: %s", medicines[i].name);
        printf("\nPrice: %.2f", medicines[i].price);
        printf("\nStock: %d", medicines[i].stock);
    }
}

void searchMedicine() {
    char name[MAX_SIZE];
    int i;

    printf("Enter Medicine Name to search: ");
    scanf("%s", name);

    for(i = 0; i < count; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("\nName: %s", medicines[i].name);
            printf("\nPrice: %.2f", medicines[i].price);
            printf("\nStock: %d", medicines[i].stock);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void updateMedicine() {
    char name[MAX_SIZE];
    int i;

    printf("Enter Medicine Name to update: ");
    scanf("%s", name);

    for(i = 0; i < count; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("Enter new Medicine Price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new Medicine Stock: ");
            scanf("%d", &medicines[i].stock);

            printf("Medicine updated successfully!\n");
            return;
        }
    }

    printf("Medicine not found!\n");
}