//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME_LENGTH 100
#define MAX_MEDICINE_DESCRIPTION_LENGTH 200
#define MAX_MEDICINE_QUANTITY 1000
#define MAX_MEDICINE_PRICE 100000

typedef struct {
    char name[MAX_MEDICINE_NAME_LENGTH];
    char description[MAX_MEDICINE_DESCRIPTION_LENGTH];
    int quantity;
    int price;
} Medicine;

typedef struct {
    char name[MAX_MEDICINE_NAME_LENGTH];
    char address[MAX_MEDICINE_DESCRIPTION_LENGTH];
    int phone_number;
} Supplier;

void create_medicine(Medicine* medicine) {
    printf("Enter medicine name: ");
    scanf("%s", medicine->name);
    printf("Enter medicine description: ");
    scanf("%s", medicine->description);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine->quantity);
    printf("Enter medicine price: ");
    scanf("%d", &medicine->price);
}

void display_medicine(Medicine* medicine) {
    printf("Medicine name: %s\n", medicine->name);
    printf("Medicine description: %s\n", medicine->description);
    printf("Medicine quantity: %d\n", medicine->quantity);
    printf("Medicine price: %d\n", medicine->price);
}

void create_supplier(Supplier* supplier) {
    printf("Enter supplier name: ");
    scanf("%s", supplier->name);
    printf("Enter supplier address: ");
    scanf("%s", supplier->address);
    printf("Enter supplier phone number: ");
    scanf("%d", &supplier->phone_number);
}

void display_supplier(Supplier* supplier) {
    printf("Supplier name: %s\n", supplier->name);
    printf("Supplier address: %s\n", supplier->address);
    printf("Supplier phone number: %d\n", supplier->phone_number);
}

int main() {
    Medicine medicine;
    Supplier supplier;

    create_medicine(&medicine);
    create_supplier(&supplier);

    display_medicine(&medicine);
    display_supplier(&supplier);

    return 0;
}