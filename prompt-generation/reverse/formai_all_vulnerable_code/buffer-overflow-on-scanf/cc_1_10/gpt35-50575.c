//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int menu() {
    int choice;

    printf("\n");
    printf("WELCOME TO HAPPY MEDICAL STORE MANAGEMENT SYSTEM!\n");
    printf("===============MENU===============\n");
    printf("| 1. Add Medicine                |\n");
    printf("| 2. Remove Medicine             |\n");
    printf("| 3. Display Medicines           |\n");
    printf("| 4. Update Stock                |\n");
    printf("| 5. Search Medicine             |\n");
    printf("| 6. Other Pharmacy Information  |\n");
    printf("| 7. Exit                        |\n");
    printf("==================================\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int findMedicineIndex(struct Medicine *medicines, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void addMedicine(struct Medicine *medicines, int *count) {
    if (*count >= MAX_ITEMS) {
        printf("ERROR: The medicine store is full!\n");
        return;
    }

    char name[50];
    int quantity;
    float price;

    printf("Enter Name: ");
    scanf("%s", name);

    int index = findMedicineIndex(medicines, *count, name);
    if (index >= 0) {
        printf("ERROR: The medicine is already present in the store!\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    printf("Enter Price: ");
    scanf("%f", &price);

    struct Medicine medicine;
    strcpy(medicine.name, name);
    medicine.quantity = quantity;
    medicine.price = price;

    medicines[*count] = medicine;
    (*count)++;

    printf("The medicine has been added successfully!\n");
}

void removeMedicine(struct Medicine *medicines, int *count) {
    if (*count <= 0) {
        printf("ERROR: The medicine store is empty!\n");
        return;
    }

    char name[50];
    printf("Enter Name: ");
    scanf("%s", name);

    int index = findMedicineIndex(medicines, *count, name);
    if (index < 0) {
        printf("ERROR: The medicine is not present in the store!\n");
        return;
    }

    for (int i = index; i < (*count - 1); i++) {
        medicines[i] = medicines[i+1];
    }

    (*count)--;

    printf("The medicine has been removed successfully!\n");
}

void displayMedicines(struct Medicine *medicines, int count) {
    if (count <= 0) {
        printf("The medicine store is empty!\n");
        return;
    }

    printf("MEDICINES AVAILABLE IN THE STORE:\n");
    printf("================================\n");
    printf("|     NAME     | QUANTITY | PRICE |\n");
    printf("================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-12s | %8d | $%.2f |\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    printf("================================\n");
}

void updateStock(struct Medicine *medicines, int count) {
    if (count <= 0) {
        printf("There are no medicines in the store to update the stock!\n");
        return;
    }

    char name[50];
    printf("Enter Name: ");
    scanf("%s", name);

    int index = findMedicineIndex(medicines, count, name);
    if (index < 0) {
        printf("ERROR: The medicine is not present in the store!\n");
        return;
    }

    int quantity;
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    medicines[index].quantity += quantity;

    printf("The stock for %s has been updated successfully!\n", name);
}

void searchMedicine(struct Medicine *medicines, int count) {
    if (count <= 0) {
        printf("There are no medicines in the store to search!\n");
        return;
    }

    char name[50];
    printf("Enter Name: ");
    scanf("%s", name);

    int index = findMedicineIndex(medicines, count, name);
    if (index < 0) {
        printf("The medicine is not present in the store!\n");
        return;
    }

    printf("MEDICINES FOUND IN THE SEARCH:\n");
    printf("================================\n");
    printf("|     NAME     | QUANTITY | PRICE |\n");
    printf("================================\n");
    printf("| %-12s | %8d | $%.2f |\n", medicines[index].name, medicines[index].quantity, medicines[index].price);
    printf("================================\n");
}

void otherPharmacyInformation() {
    printf("Our pharmacy is dedicated to provide you with the best health and medical care available!\n");
    printf("We have a wide selection of medicines for all your health needs.\n");
    printf("Our experienced pharmacists will help you find the right medicine for your health needs.\n");
    printf("We also provide free home delivery for all online orders within our service areas.\n");
}

int main() {
    struct Medicine medicines[MAX_ITEMS];
    int count = 0;

    while (1) {
        int choice = menu();

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;

            case 2:
                removeMedicine(medicines, &count);
                break;

            case 3:
                displayMedicines(medicines, count);
                break;

            case 4:
                updateStock(medicines, count);
                break;

            case 5:
                searchMedicine(medicines, count);
                break;

            case 6:
                otherPharmacyInformation();
                break;

            case 7:
                printf("Thank you for using Happy Medical Store Management System!\n");
                exit(0);

            default:
                printf("ERROR: Invalid Choice!\n");
                break;
        }
    }

    return 0;
}