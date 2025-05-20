//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
   char name[50];
   int id;
   float price;
   int quantity;
};

void addMedicine(struct medicine m[], int num)
{
    printf("\nEnter details of medicines:\n");
    for (int i = 0; i < num; i++) {
        printf("\nMedicine %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &m[i].id);
        printf("Name: ");
        scanf("%s", m[i].name);
        printf("Price: ");
        scanf("%f", &m[i].price);
        printf("Quantity: ");
        scanf("%d", &m[i].quantity);
    }
    printf("\nMedicine added successfully.\n");
}

void displayMedicine(struct medicine m[], int num)
{
    printf("\nMedicines list:\n");
    printf("\nID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t%s\t%.2f\t%d\n",
            m[i].id,
            m[i].name,
            m[i].price,
            m[i].quantity
        );
    }
}

int searchMedicine(struct medicine m[], int num, int id)
{
    for (int i = 0; i < num; i++) {
        if (m[i].id == id) {
            return i;
        }
    }
    return -1;
}

void updateMedicine(struct medicine m[], int num, int id)
{
    int index = searchMedicine(m, num, id);
    if (index == -1) {
        printf("\nMedicine with ID %d not found.\n", id);
    } else {
        printf("\nEnter updated details of the medicine:\n");
        printf("Name: ");
        scanf("%s", m[index].name);
        printf("Price: ");
        scanf("%f", &m[index].price);
        printf("Quantity: ");
        scanf("%d", &m[index].quantity);
        printf("\nMedicine updated successfully.\n");
    }
}

void deleteMedicine(struct medicine m[], int *num, int id)
{
    int index = searchMedicine(m, *num, id);
    if (index == -1) {
        printf("\nMedicine with ID %d not found.\n", id);
    } else {
        for (int i = index; i < *num-1; i++) {
            m[i] = m[i+1];
        }
        (*num)--;
        printf("\nMedicine deleted successfully.\n");
    }
}

int main()
{
    struct medicine med[100];
    int menu_choice, num_medicine = 0, id;

    while(1) {
        printf("\n******************\n");
        printf("Medical Store Management\n");
        printf("******************\n");
        printf("1. Add medicine\n");
        printf("2. Display medicine\n");
        printf("3. Update medicine\n");
        printf("4. Delete medicine\n");
        printf("0. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 0:
                exit(0);
            case 1:
                printf("\nEnter number of medicines to add: ");
                scanf("%d", &num_medicine);
                addMedicine(med, num_medicine);
                break;
            case 2:
                displayMedicine(med, num_medicine);
                break;
            case 3:
                printf("\nEnter ID of medicine to update: ");
                scanf("%d", &id);
                updateMedicine(med, num_medicine, id);
                break;
            case 4:
                printf("\nEnter ID of medicine to delete: ");
                scanf("%d", &id);
                deleteMedicine(med, &num_medicine, id);
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}