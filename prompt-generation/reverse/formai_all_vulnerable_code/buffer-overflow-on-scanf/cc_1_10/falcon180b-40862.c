//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 100
#define MAX_CATEGORY_NAME 50
#define MAX_CUSTOMER_NAME 100
#define MAX_CUSTOMER_ADDRESS 200
#define MAX_CUSTOMER_CONTACT 100

typedef struct {
    int id;
    char name[MAX_MEDICINE_NAME];
    char category[MAX_CATEGORY_NAME];
    float price;
    int quantity;
} Medicine;

typedef struct {
    int id;
    char name[MAX_CUSTOMER_NAME];
    char address[MAX_CUSTOMER_ADDRESS];
    char contact[MAX_CUSTOMER_CONTACT];
} Customer;

void addMedicine(Medicine* medicines, int* medicineCount) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*medicineCount].name);
    printf("Enter medicine category: ");
    scanf("%s", medicines[*medicineCount].category);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*medicineCount].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*medicineCount].quantity);
    (*medicineCount)++;
}

void displayMedicines(Medicine* medicines, int medicineCount) {
    printf("\nMedicines:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d. %s - %s - %.2f - %d\n", i+1, medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
    }
}

void addCustomer(Customer* customers, int* customerCount) {
    printf("\nEnter customer name: ");
    scanf("%s", customers[*customerCount].name);
    printf("Enter customer address: ");
    scanf("%s", customers[*customerCount].address);
    printf("Enter customer contact: ");
    scanf("%s", customers[*customerCount].contact);
    (*customerCount)++;
}

void displayCustomers(Customer* customers, int customerCount) {
    printf("\nCustomers:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("%d. %s - %s - %s\n", i+1, customers[i].name, customers[i].address, customers[i].contact);
    }
}

int main() {
    Medicine medicines[100];
    int medicineCount = 0;
    Customer customers[100];
    int customerCount = 0;

    addMedicine(medicines, &medicineCount);
    displayMedicines(medicines, medicineCount);

    addCustomer(customers, &customerCount);
    displayCustomers(customers, customerCount);

    return 0;
}