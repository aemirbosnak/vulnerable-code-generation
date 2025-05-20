//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 50

typedef struct {
    int code;
    char name[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    int id;
    char name[50];
    char address[150];
} Customer;

int numMedicines = 0;
Medicine medicines[MAX_MEDICINES];

int numCustomers = 0;
Customer customers[MAX_CUSTOMERS];

void addMedicine() {
    if (numMedicines == MAX_MEDICINES) {
        printf("ERROR: Could not add medicine. Maximum limit reached.\n");
        return;
    }

    Medicine newMedicine;

    printf("\nEnter details of new medicine:\n");
    printf("  Code: ");
    scanf("%d", &newMedicine.code);

    for (int i = 0; i < numMedicines; i++) {
        if (newMedicine.code == medicines[i].code) {
            printf("\nERROR: Medicine with the same code already exists!\n");
            return;
        }
    }

    printf("  Name: ");
    scanf("%s", newMedicine.name);
    printf("  Price: ");
    scanf("%f", &newMedicine.price);
    printf("  Quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicines[numMedicines++] = newMedicine;

    printf("\nNew medicine added successfully.\n");
}

void searchMedicine() {
    int code;

    printf("\nEnter code of the medicine to search: ");
    scanf("%d", &code);

    for (int i = 0; i < numMedicines; i++) {
        if (code == medicines[i].code) {
            printf("\nDetails of medicine with code %d:\n", code);
            printf("  Name: %s\n", medicines[i].name);
            printf("  Price: %.2f\n", medicines[i].price);
            printf("  Quantity: %d\n", medicines[i].quantity);
            return;
        }
    }

    printf("\nERROR: Medicine with code %d does not exist!\n", code);
}

void updateMedicine() {
    int code;

    printf("\nEnter code of the medicine to update: ");
    scanf("%d", &code);

    for (int i = 0; i < numMedicines; i++) {
        if (code == medicines[i].code) {
            printf("\nEnter new details of medicine with code %d:\n", code);
            printf("  Name: ");
            scanf("%s", medicines[i].name);
            printf("  Price: ");
            scanf("%f", &medicines[i].price);
            printf("  Quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("\nMedicine with code %d updated successfully.\n", code);
            return;
        }
    }

    printf("\nERROR: Medicine with code %d does not exist!\n", code);
}

void deleteMedicine() {
    int code;

    printf("\nEnter code of the medicine to delete: ");
    scanf("%d", &code);

    for (int i = 0; i < numMedicines; i++) {
        if (code == medicines[i].code) {
            for (int j = i; j < numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            numMedicines--;
            printf("\nMedicine with code %d deleted successfully.\n", code);
            return;
        }
    }

    printf("\nERROR: Medicine with code %d does not exist!\n", code);
}

void addCustomer() {
    if (numCustomers == MAX_CUSTOMERS) {
        printf("ERROR: Could not add customer. Maximum limit reached.\n");
        return;
    }

    Customer newCustomer;

    printf("\nEnter details of new customer:\n");
    printf("  ID: ");
    scanf("%d", &newCustomer.id);

    for (int i = 0; i < numCustomers; i++) {
        if (newCustomer.id == customers[i].id) {
            printf("\nERROR: Customer with the same ID already exists!\n");
            return;
        }
    }

    printf("  Name: ");
    scanf("%s", newCustomer.name);
    printf("  Address: ");
    scanf("%s", newCustomer.address);

    customers[numCustomers++] = newCustomer;

    printf("\nNew customer added successfully.\n");
}

void searchCustomer() {
    int id;

    printf("\nEnter ID of the customer to search: ");
    scanf("%d", &id);

    for (int i = 0; i < numCustomers; i++) {
        if (id == customers[i].id) {
            printf("\nDetails of customer with ID %d:\n", id);
            printf("  Name: %s\n", customers[i].name);
            printf("  Address: %s\n", customers[i].address);
            return;
        }
    }

    printf("\nERROR: Customer with ID %d does not exist!\n", id);
}

void updateCustomer() {
    int id;

    printf("\nEnter ID of the customer to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numCustomers; i++) {
        if (id == customers[i].id) {
            printf("\nEnter new details of customer with ID %d:\n", id);
            printf("  Name: ");
            scanf("%s", customers[i].name);
            printf("  Address: ");
            scanf("%s", customers[i].address);
            printf("\nCustomer with ID %d updated successfully.\n", id);
            return;
        }
    }

    printf("\nERROR: Customer with ID %d does not exist!\n", id);
}

void deleteCustomer() {
    int id;

    printf("\nEnter ID of the customer to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < numCustomers; i++) {
        if (id == customers[i].id) {
            for (int j = i; j < numCustomers - 1; j++) {
                customers[j] = customers[j + 1];
            }
            numCustomers--;
            printf("\nCustomer with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("\nERROR: Customer with ID %d does not exist!\n", id);
}

void sellMedicine() {
    int code, qty;

    printf("\nEnter code of the medicine to sell: ");
    scanf("%d", &code);

    for (int i = 0; i < numMedicines; i++) {
        if (code == medicines[i].code) {
            printf("\nEnter quantity to sell: ");
            scanf("%d", &qty);

            if (qty > medicines[i].quantity) {
                printf("\nERROR: Insufficient stock!\n");
                return;
            }

            medicines[i].quantity -= qty;

            printf("\nEnter ID of customer: ");
            int id;
            scanf("%d", &id);

            for (int j = 0; j < numCustomers; j++) {
                if (id == customers[j].id) {
                    printf("\nMedicine sold to customer with ID %d successfully!\n", id);
                    return;
                }
            }

            printf("\nERROR: Customer with ID %d does not exist!\n", id);
            return;
        }
    }

    printf("\nERROR: Medicine with code %d does not exist!\n", code);
}

void printInventory() {
    printf("\nCurrent Stock:\n");
    printf("Code  | Name                            | Quantity | Price\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < numMedicines; i++) {
        printf("%-5d | %-30s | %-8d | Rs. %.2f\n", medicines[i].code, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }

    printf("\n");
}

void printCustomers() {
    printf("\nCurrent Customers:\n");
    printf("ID   | Name                            | Address\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < numCustomers; i++) {
        printf("%-4d | %-30s | %s\n", customers[i].id, customers[i].name, customers[i].address);
    }

    printf("\n");
}

void showMenu() {
    printf("----------------------------------------------------------\n");
    printf("|                       MENU                             |\n");
    printf("----------------------------------------------------------\n");
    printf("| 1. Add New Medicine                                     |\n");
    printf("| 2. Search Medicine                                      |\n");
    printf("| 3. Update Medicine                                      |\n");
    printf("| 4. Delete Medicine                                      |\n");
    printf("| 5. Add New Customer                                     |\n");
    printf("| 6. Search Customer                                      |\n");
    printf("| 7. Update Customer                                      |\n");
    printf("| 8. Delete Customer                                      |\n");
    printf("| 9. Sell Medicine                                        |\n");
    printf("| 10. Print Inventory                                     |\n");
    printf("| 11. Print Customers                                     |\n");
    printf("| 12. Exit                                                |\n");
    printf("----------------------------------------------------------\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;

            case 2:
                searchMedicine();
                break;

            case 3:
                updateMedicine();
                break;

            case 4:
                deleteMedicine();
                break;

            case 5:
                addCustomer();
                break;

            case 6:
                searchCustomer();
                break;

            case 7:
                updateCustomer();
                break;

            case 8:
                deleteCustomer();
                break;

            case 9:
                sellMedicine();
                break;

            case 10:
                printInventory();
                break;

            case 11:
                printCustomers();
                break;

            case 12:
                printf("\nExiting program. Goodbye.\n");
                break;

            default:
                printf("\nERROR: Invalid choice!\n");
                break;
        }
    } while (choice != 12);

    return 0;
}