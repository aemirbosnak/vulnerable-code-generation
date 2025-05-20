//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME 50
#define MAX_BATCH 10

typedef struct {
    char name[MAX_NAME];
    char id[MAX_BATCH];
    int qty;
    float price;
} Medicine;

void printMenu();
void addMedicine(Medicine medicines[], int *count);
void removeMedicine(Medicine medicines[], int *count);
void updateMedicine(Medicine medicines[], int count);
void searchMedicine(Medicine medicines[], int count);
void sortMedicine(Medicine medicines[], int count);
void printMedicineList(Medicine medicines[], int count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    do {
        printMenu();
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                removeMedicine(medicines, &count);
                break;
            case 3:
                updateMedicine(medicines, count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                sortMedicine(medicines, count);
                break;
            case 6:
                printMedicineList(medicines, count);
                break;
            case 7:
                printf("\nThank you for using the Medical Store Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

void printMenu() {
    printf("\nMedical Store Management System");
    printf("\n--------------------------------");
    printf("\n1. Add Medicine");
    printf("\n2. Remove Medicine");
    printf("\n3. Update Medicine");
    printf("\n4. Search Medicine");
    printf("\n5. Sort Medicines");
    printf("\n6. Print Medicine List");
    printf("\n7. Exit");
}

void addMedicine(Medicine medicines[], int *count) {
    Medicine newMedicine;

    printf("\nPlease enter the medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Please enter the batch id: ");
    scanf("%s", newMedicine.id);
    printf("Please enter the quantity: ");
    scanf("%d", &newMedicine.qty);
    printf("Please enter the price: ");
    scanf("%f", &newMedicine.price);

    medicines[*count] = newMedicine;
    (*count)++;

    printf("\nMedicine added successfully.\n");
}

void removeMedicine(Medicine medicines[], int *count) {
    char searchId[MAX_BATCH];
    int index = -1;

    printf("\nPlease enter the batch id of the medicine you want to remove: ");
    scanf("%s", searchId);

    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].id, searchId) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nMedicine not found.\n");
        return;
    }

    for (int i = index; i < (*count) - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    (*count)--;

    printf("\nMedicine removed successfully.\n");
}

void updateMedicine(Medicine medicines[], int count) {
    char searchId[MAX_BATCH];
    int index = -1;

    printf("\nPlease enter the batch id of the medicine you want to update: ");
    scanf("%s", searchId);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].id, searchId) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nMedicine not found.\n");
        return;
    }

    Medicine updatedMedicine = medicines[index];

    printf("\nPlease enter the new medicine name (or press enter to keep as %s): ", updatedMedicine.name);
    char input[MAX_NAME];
    scanf("%s", input);
    if (strlen(input) > 0) {
        strcpy(updatedMedicine.name, input);
    }

    printf("Please enter the new quantity (or enter -1 to keep as %d): ", updatedMedicine.qty);
    int qty;
    scanf("%d", &qty);
    if (qty >= 0) {
        updatedMedicine.qty = qty;
    }

    printf("Please enter the new price (or enter -1 to keep as %.2f): ", updatedMedicine.price);
    float price;
    scanf("%f", &price);
    if (price >= 0) {
        updatedMedicine.price = price;
    }

    medicines[index] = updatedMedicine;

    printf("\nMedicine updated successfully.\n");
}

void searchMedicine(Medicine medicines[], int count) {
    char searchName[MAX_NAME];
    int foundCount = 0;

    printf("\nPlease enter the medicine name to search for: ");
    scanf("%s", searchName);

    printf("\nSearch results:");
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("\nName: %s, Batch ID: %s, Quantity: %d, Price: %.2f", medicines[i].name, medicines[i].id, medicines[i].qty, medicines[i].price);
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("\nNo medicines found with the given name.\n");
    }
}

void sortMedicine(Medicine medicines[], int count) {
    // Selection sort implementation
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(medicines[j].name, medicines[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Medicine temp = medicines[i];
            medicines[i] = medicines[minIndex];
            medicines[minIndex] = temp;
        }
    }

    printf("\nMedicines sorted successfully.\n");
}

void printMedicineList(Medicine medicines[], int count) {
    printf("\nMedicine list:");
    for (int i = 0; i < count; i++) {
        printf("\nName: %s, Batch ID: %s, Quantity: %d, Price: %.2f", medicines[i].name, medicines[i].id, medicines[i].qty, medicines[i].price);
    }
}