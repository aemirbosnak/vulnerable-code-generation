//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct {
    char name[100];
    int quantity;
    double price;
} medicine;

void addMedicine(medicine *medicineArray, int size, medicine newMedicine) {
    if (size < 100) {
        strcpy(newMedicine.name, newMedicine.name);
        newMedicine.quantity = newMedicine.quantity;
        newMedicine.price = newMedicine.price;
        medicineArray[size++] = newMedicine;
        printf("Medicine added successfully.\n");
    } else {
        printf("No more medicines can be added.\n");
    }
}

void removeMedicine(medicine *medicineArray, int size, medicine medicineToRemove) {
    int index = 0;
    while (index < size) {
        if (strcmp(medicineArray[index].name, medicineToRemove.name) == 0) {
            strcpy(medicineArray[index].name, medicineArray[size-1].name);
            medicineArray[index].quantity = medicineArray[size-1].quantity;
            medicineArray[index].price = medicineArray[size-1].price;
            medicineArray[size--] = medicineArray[index];
            printf("Medicine removed successfully.\n");
            break;
        }
        index++;
    }
}

void displayMedicine(medicine *medicineArray, int size) {
    int index = 0;
    while (index < size) {
        printf("%s - %d - %.2f\n", medicineArray[index].name, medicineArray[index].quantity, medicineArray[index].price);
        index++;
    }
}

int main() {
    medicine medicineArray[100];
    int size = 0;
    char choice;
    do {
        printf("1. Add medicine\n2. Remove medicine\n3. Display medicine\n4. Exit\nEnter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter medicine details:\n");
                scanf("%s %d %lf", medicineArray[size].name, &medicineArray[size].quantity, &medicineArray[size].price);
                addMedicine(medicineArray, size, medicineArray[size]);
                break;
            case '2':
                printf("Enter medicine details:\n");
                scanf("%s %d %lf", medicineArray[size].name, &medicineArray[size].quantity, &medicineArray[size].price);
                removeMedicine(medicineArray, size, medicineArray[size]);
                break;
            case '3':
                displayMedicine(medicineArray, size);
                break;
            case '4':
                printf("Thank you for using the Medical Store Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice!= '4');
    return 0;
}