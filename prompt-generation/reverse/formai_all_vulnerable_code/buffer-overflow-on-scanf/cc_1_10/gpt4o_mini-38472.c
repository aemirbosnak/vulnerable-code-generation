//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine *medicines, int *count);
void viewMedicines(Medicine *medicines, int count);
void sellMedicine(Medicine *medicines, int count);
void saveMedicines(Medicine *medicines, int count);
void loadMedicines(Medicine *medicines, int *count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    loadMedicines(medicines, &count);

    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                sellMedicine(medicines, count);
                break;
            case 4:
                saveMedicines(medicines, count);
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMedicine(Medicine *medicines, int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    printf("Enter medicine name: ");
    fgets(medicines[*count].name, NAME_LENGTH, stdin);
    medicines[*count].name[strcspn(medicines[*count].name, "\n")] = '\0'; // remove newline
    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void viewMedicines(Medicine *medicines, int count) {
    printf("\n--- Medicines in Stock ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n", i + 1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    if (count == 0) {
        printf("No medicines in stock.\n");
    }
}

void sellMedicine(Medicine *medicines, int count) {
    if (count == 0) {
        printf("No medicines available to sell.\n");
        return;
    }
    int index;
    printf("Enter the medicine number to sell (1 to %d): ", count);
    scanf("%d", &index);
    if (index < 1 || index > count) {
        printf("Invalid medicine number!\n");
        return;
    }
    index--; // adjust for 0-based array
    if (medicines[index].quantity == 0) {
        printf("Out of stock for %s!\n", medicines[index].name);
        return;
    }
    medicines[index].quantity--;
    printf("Sold 1 unit of %s. Remaining stock: %d\n", medicines[index].name, medicines[index].quantity);
}

void saveMedicines(Medicine *medicines, int count) {
    FILE *file = fopen("medicines.dat", "wb");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fwrite(medicines, sizeof(Medicine), count, file);
    fclose(file);
    printf("Medicines saved to file.\n");
}

void loadMedicines(Medicine *medicines, int *count) {
    FILE *file = fopen("medicines.dat", "rb");
    if (file == NULL) {
        printf("No existing medicine data found. Starting fresh!\n");
        return;
    }
    *count = fread(medicines, sizeof(Medicine), MAX_MEDICINES, file);
    fclose(file);
    printf("Loaded %d medicines from file.\n", *count);
}