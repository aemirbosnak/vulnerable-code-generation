//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
} customer;

void addMedicine(medicine *med, int *numMeds) {
    printf("Enter medicine name: ");
    scanf("%s", med[*numMeds].name);
    printf("Enter quantity: ");
    scanf("%d", &med[*numMeds].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*numMeds].price);
    (*numMeds)++;
}

void addCustomer(customer *cust, int *numCusts) {
    printf("Enter customer name: ");
    scanf("%s", cust[*numCusts].name);
    printf("Enter address: ");
    scanf("%s", cust[*numCusts].address);
    printf("Enter phone: ");
    scanf("%s", cust[*numCusts].phone);
    (*numCusts)++;
}

void sellMedicine(medicine *med, int *numMeds, customer *cust, int *numCusts) {
    char medName[50];
    int quantity;
    float total;

    printf("Enter medicine name: ");
    scanf("%s", medName);

    int found = 0;
    for (int i = 0; i < *numMeds; i++) {
        if (strcmp(medName, med[i].name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= med[i].quantity) {
                total = quantity * med[i].price;
                printf("Total: %.2f\n", total);

                med[i].quantity -= quantity;
                found = 1;
                break;
            } else {
                printf("Insufficient stock\n");
            }
        }
    }

    if (!found) {
        printf("Medicine not found\n");
    }
}

void displayStock(medicine *med, int *numMeds) {
    printf("Medicine Stock:\n");
    for (int i = 0; i < *numMeds; i++) {
        printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

void displayCustomers(customer *cust, int *numCusts) {
    printf("Customer List:\n");
    for (int i = 0; i < *numCusts; i++) {
        printf("%s\t%s\t%s\n", cust[i].name, cust[i].address, cust[i].phone);
    }
}

int main() {
    medicine med[100];
    customer cust[100];

    int numMeds = 0, numCusts = 0;
    int choice;

    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Add Customer\n");
        printf("3. Sell Medicine\n");
        printf("4. Display Stock\n");
        printf("5. Display Customers\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(med, &numMeds);
                break;
            case 2:
                addCustomer(cust, &numCusts);
                break;
            case 3:
                sellMedicine(med, &numMeds, cust, &numCusts);
                break;
            case 4:
                displayStock(med, &numMeds);
                break;
            case 5:
                displayCustomers(cust, &numCusts);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}