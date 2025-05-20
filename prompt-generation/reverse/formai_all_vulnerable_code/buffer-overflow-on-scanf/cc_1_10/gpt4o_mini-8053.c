//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

void addMedicine(Medicine medicines[], int *count);
void displayMedicines(Medicine medicines[], int count);
void purchaseMedicine(Medicine medicines[], int count);
void searchMedicine(Medicine medicines[], int count);
void saveToFile(Medicine medicines[], int count);
void loadFromFile(Medicine medicines[], int *count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    loadFromFile(medicines, &count);

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Purchase Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                purchaseMedicine(medicines, count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                saveToFile(medicines, count);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Cannot add more medicines, storage full.\n");
        return;
    }

    Medicine newMedicine;
    newMedicine.id = *count + 1;

    printf("Enter medicine name: ");
    scanf(" %[^\n]s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicines[*count] = newMedicine;
    (*count)++;

    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nID\tName\t\tPrice\tQuantity\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void purchaseMedicine(Medicine medicines[], int count) {
    int id, qty;

    printf("Enter medicine ID to purchase: ");
    scanf("%d", &id);
    if (id < 1 || id > count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    printf("Enter quantity to purchase: ");
    scanf("%d", &qty);

    if (qty > medicines[id - 1].quantity) {
        printf("Insufficient stock available!\n");
    } else {
        medicines[id - 1].quantity -= qty;
        printf("Purchased %d unit(s) of %s successfully!\n", qty, medicines[id - 1].name);
    }
}

void searchMedicine(Medicine medicines[], int count) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(medicines[i].name, name) == 0) {
            printf("Found: %d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

void saveToFile(Medicine medicines[], int count) {
    FILE *file = fopen("medicines.txt", "w");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f %d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }

    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile(Medicine medicines[], int *count) {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("No previous data found, starting fresh!\n");
        return;
    }

    while (fscanf(file, "%d %[^\n] %f %d", &medicines[*count].id, medicines[*count].name, &medicines[*count].price, &medicines[*count].quantity) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Data loaded successfully! Total medicines: %d\n", *count);
}