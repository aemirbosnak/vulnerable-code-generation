//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int stock;
} Medicine;

void menu() {
    printf("1. Add Medicine\n");
    printf("2. View Medicine List\n");
    printf("3. Update Medicine Details\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
}

void addMedicine(Medicine *medicines, int *count) {
    printf("Enter name of medicine: ");
    fflush(stdin);
    fgets(medicines[*count].name, 50, stdin);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    printf("Enter stock: ");
    scanf("%d", &medicines[*count].stock);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void viewMedicineList(Medicine *medicines, int count) {
    printf("Name\t\tPrice\t\tStock\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t\t%d\n", medicines[i].name, medicines[i].price, medicines[i].stock);
    }
}

void updateMedicineDetails(Medicine *medicines, int count) {
    char name[50];
    printf("Enter name of medicine to update: ");
    fflush(stdin);
    fgets(name, 50, stdin);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new stock: ");
            scanf("%d", &medicines[i].stock);
            printf("Medicine details updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(Medicine *medicines, int *count) {
    char name[50];
    printf("Enter name of medicine to delete: ");
    fflush(stdin);
    fgets(name, 50, stdin);

    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < (*count)-1; j++) {
                strcpy(medicines[j].name, medicines[j+1].name);
                medicines[j].price = medicines[j+1].price;
                medicines[j].stock = medicines[j+1].stock;
            }
            (*count)--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    Medicine *medicines = (Medicine*) malloc(sizeof(Medicine) * 100);
    int count = 0;
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicineList(medicines, count);
                break;
            case 3:
                updateMedicineDetails(medicines, count);
                break;
            case 4:
                deleteMedicine(medicines, &count);
                break;
            case 5:
                free(medicines);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}