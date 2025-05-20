//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    int id;
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine* medicines, int* count);
void removeMedicine(Medicine* medicines, int* count);
void searchMedicine(Medicine* medicines, int* count);
void displayList(Medicine* medicines, int* count);
void updateMedicineQuantity(Medicine* medicines, int* count);

int main() {
    int count = 0;
    Medicine* medicines = malloc(sizeof(Medicine));
    int choice;

    while(1) {
        printf("\n\nMedical Store Management System");
        printf("\n1.Add Medicine\n2.Remove Medicine\n3.Search Medicine\n4.Display List\n5.Update Medicine Quantity\n6.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(medicines, &count);
                break;

            case 2:
                removeMedicine(medicines, &count);
                break;

            case 3:
                searchMedicine(medicines, &count);
                break;

            case 4:
                displayList(medicines, &count);
                break;

            case 5:
                updateMedicineQuantity(medicines, &count);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice! Please Try Again.");
        }
    }
    free(medicines);
    return 0;
}

void addMedicine(Medicine* medicines, int* count) {
    printf("\nAdding Medicine");
    (*count)++;
    medicines = realloc(medicines, (*count) * sizeof(Medicine));

    printf("\nEnter ID: ");
    scanf("%d", &medicines[*count - 1].id);

    printf("\nEnter Name: ");
    scanf(" %[^\n]", medicines[*count - 1].name);

    printf("\nEnter Manufacturer: ");
    scanf(" %[^\n]", medicines[*count - 1].manufacturer);

    printf("\nEnter Quantity: ");
    scanf("%d", &medicines[*count - 1].quantity);

    printf("\nEnter Price: ");
    scanf("%f", &medicines[*count - 1].price);

    printf("\nMedicine Added Successfully!");
}

void removeMedicine(Medicine* medicines, int* count) {
    int id;
    int flag = 0;

    if (*count == 0) {
        printf("\nNo Medicines Available!");
        return;
    }

    printf("\nRemoving Medicine");
    printf("\nEnter ID of the Medicine to be Removed: ");
    scanf("%d", &id);

    for (int i=0; i<*count; i++) {
        if (medicines[i].id == id) {
            flag = 1;
            for(int j=i; j<(*count)-1; j++) {
                medicines[j] = medicines[j+1];
            }
            (*count)--;
            medicines = realloc(medicines, (*count) * sizeof(Medicine));
            printf("\nRemoved Successfully!");
            break;
        }
    }

    if (flag == 0) {
        printf("\nMedicine Not Found!");
    }
}

void searchMedicine(Medicine* medicines, int* count) {
    int id;
    int flag = 0;

    if (*count == 0) {
        printf("\nNo Medicines Available!");
        return;
    }

    printf("\nSearching Medicine");
    printf("\nEnter ID of the Medicine to be Searched: ");
    scanf("%d", &id);

    for (int i=0; i<*count; i++) {
        if (medicines[i].id == id) {
            flag = 1;
            printf("\nID: %d", medicines[i].id);
            printf("\nName: %s", medicines[i].name);
            printf("\nManufacturer: %s", medicines[i].manufacturer);
            printf("\nQuantity: %d", medicines[i].quantity);
            printf("\nPrice: %.2f", medicines[i].price);
            break;
        }
    }

    if (flag == 0) {
        printf("\nMedicine Not Found!");
    }
}

void displayList(Medicine* medicines, int* count) {
    if (*count == 0) {
        printf("\nNo Medicines Available!");
        return;
    }
    printf("\nID\t\tName\t\tManufacturer\tQuantity\tPrice");
    for (int i=0; i<*count; i++) {
        printf("\n%d\t\t%s\t\t%s\t\t%d\t\t%.2f", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
}

void updateMedicineQuantity(Medicine* medicines, int* count) {
    int id;
    int flag = 0;

    if (*count == 0) {
        printf("\nNo Medicines Available!");
        return;
    }

    printf("\nUpdating Medicine Quantity");
    printf("\nEnter ID of the Medicine to be Updated: ");
    scanf("%d", &id);

    for (int i=0; i<*count; i++) {
        if (medicines[i].id == id) {
            flag = 1;
            printf("\nEnter New Quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("\nUpdated Successfully!");
            break;
        }
    }

    if (flag == 0) {
        printf("\nMedicine Not Found!");
    }
}