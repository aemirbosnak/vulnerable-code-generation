//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
} medicines[MAX];

int count = 0;

void displayMenu() {
    printf("\n------------------------------");
    printf("\n         MEDICINE STORE       ");
    printf("\n------------------------------");
    printf("\n1. Add New Medicine");
    printf("\n2. Delete Medicine");
    printf("\n3. Search Medicine");
    printf("\n4. Display Available Medicines");
    printf("\n5. Exit");
    printf("\n------------------------------");
    printf("\nPlease enter your choice (1-5): ");
}

void addMedicine() {
    if (count == MAX) {
        printf("\nMedicine store is full.");
        return;
    }
    struct Medicine newMedicine;
    printf("\nEnter the medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newMedicine.price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &newMedicine.quantity);
    newMedicine.id = ++count;
    medicines[count-1] = newMedicine;
    printf("\nMedicine added successfully!");
}

void deleteMedicine() {
    int id, i, j;
    printf("\nEnter the ID of the medicine to be deleted: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            for (j = i; j < count-1; j++)
                medicines[j] = medicines[j+1];
            count--;
            printf("\nMedicine deleted successfully!");
            return;
        }
    }
    printf("\nMedicine not found with ID %d", id);
}

void searchMedicine() {
    char name[50];
    int found = 0, i;
    printf("\nEnter the name of the medicine: ");
    scanf("%s", name);
    printf("\nID\tNAME\tPRICE\tQUANTITY");
    for (i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\n%d\t%s\t%.2f\t%d", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
            found = 1;
        }
    }
    if (!found)
        printf("\nMedicine not found with name %s", name);
}

void displayMedicines() {
    int i;
    printf("\nID\tNAME\tPRICE\tQUANTITY");
    for (i = 0; i < count; i++) {
        printf("\n%d\t%s\t%.2f\t%d", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                displayMedicines();
                break;
            case 5:
                printf("\n\nExiting the program...\n\n");
                break;
            default:
                printf("\nInvalid choice, please try again!");
        }
    } while (choice != 5);
    return 0;
}