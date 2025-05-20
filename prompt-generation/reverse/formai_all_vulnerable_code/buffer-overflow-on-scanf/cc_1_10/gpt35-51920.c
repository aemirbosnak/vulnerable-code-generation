//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structures for medicines and customers
typedef struct {
    int id;
    char name[50];
    char category[50];
    float price;
    int quantity;
} Medicine;

typedef struct {
    int id;
    char name[50];
    char address[50];
    char phone[15];
} Customer;

int menu();
void addMedicine(Medicine* medicines, int* numMedicines);
void displayMedicines(Medicine* medicines, int numMedicines);
void searchMedicine(Medicine* medicines, int numMedicines);
void deleteMedicine(Medicine* medicines, int* numMedicines);
void addCustomer(Customer* customers, int* numCustomers);
void displayCustomers(Customer* customers, int numCustomers);
void searchCustomer(Customer* customers, int numCustomers);
void deleteCustomer(Customer* customers, int* numCustomers);

int main() {
    Medicine medicines[100];
    int numMedicines = 0;
    Customer customers[100];
    int numCustomers = 0;
    int choice;
    
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                displayMedicines(medicines, numMedicines);
                break;
            case 3:
                searchMedicine(medicines, numMedicines);
                break;
            case 4:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 5:
                addCustomer(customers, &numCustomers);
                break;
            case 6:
                displayCustomers(customers, numCustomers);
                break;
            case 7:
                searchCustomer(customers, numCustomers);
                break;
            case 8:
                deleteCustomer(customers, &numCustomers);
                break;
            case 9:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

int menu() {
    int choice;
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Add Customer\n");
    printf("6. Display Customers\n");
    printf("7. Search Customer\n");
    printf("8. Delete Customer\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void addMedicine(Medicine* medicines, int* numMedicines) {
    Medicine m;
    m.id = *numMedicines + 1;
    printf("Enter medicine name: ");
    scanf(" %[^\n]s", m.name);
    printf("Enter medicine category: ");
    scanf(" %[^\n]s", m.category);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);
    medicines[*numMedicines] = m;
    (*numMedicines)++;
}

void displayMedicines(Medicine* medicines, int numMedicines) {
    printf("Medicine ID\tMedicine Name\tMedicine Category\tMedicine Price\tMedicine Quantity\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t\t%s\t\t%s\t\t\t%.2f\t\t%d\n", medicines[i].id, medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(Medicine* medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine ID\tMedicine Name\tMedicine Category\tMedicine Price\tMedicine Quantity\n");
            printf("%d\t\t%s\t\t%s\t\t\t%.2f\t\t%d\n", medicines[i].id, medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine(Medicine* medicines, int* numMedicines) {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *numMedicines; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < (*numMedicines)-1; j++) {
                medicines[j] = medicines[j+1];
            }
            (*numMedicines)--;
            printf("Medicine with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void addCustomer(Customer* customers, int* numCustomers) {
    Customer c;
    c.id = *numCustomers + 1;
    printf("Enter customer name: ");
    scanf(" %[^\n]s", c.name);
    printf("Enter customer address: ");
    scanf(" %[^\n]s", c.address);
    printf("Enter customer phone number: ");
    scanf(" %[^\n]s", c.phone);
    customers[*numCustomers] = c;
    (*numCustomers)++;
}

void displayCustomers(Customer* customers, int numCustomers) {
    printf("Customer ID\tCustomer Name\tCustomer Address\tCustomer Phone\n");
    for (int i = 0; i < numCustomers; i++) {
        printf("%d\t\t%s\t\t%s\t\t%s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
    }
}

void searchCustomer(Customer* customers, int numCustomers) {
    char name[50];
    printf("Enter customer name to search: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            printf("Customer ID\tCustomer Name\tCustomer Address\tCustomer Phone\n");
            printf("%d\t\t%s\t\t%s\t\t%s\n", customers[i].id, customers[i].name, customers[i].address, customers[i].phone);
            return;
        }
    }
    printf("Customer not found.\n");
}

void deleteCustomer(Customer* customers, int* numCustomers) {
    int id;
    printf("Enter customer ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *numCustomers; i++) {
        if (customers[i].id == id) {
            for (int j = i; j < (*numCustomers)-1; j++) {
                customers[j] = customers[j+1];
            }
            (*numCustomers)--;
            printf("Customer with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Customer not found.\n");
}