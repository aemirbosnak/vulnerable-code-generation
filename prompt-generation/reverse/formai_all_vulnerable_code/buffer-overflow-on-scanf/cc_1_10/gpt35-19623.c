//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000
#define MAX_CUSTOMERS 1000

// Structure for storing medicine details
struct Medicine{
    char name[50];
    int quantity;
    float price;
};

// Structure for storing customer details
struct Customer{
    char name[50];
    int age;
    char address[100];
};

// Global Variables
struct Medicine medicines[MAX_MEDICINES];
struct Customer customers[MAX_CUSTOMERS];
int numMedicines = 0;
int numCustomers = 0;

// Function to add a new medicine
void addMedicine(){
    char name[50];
    int quantity;
    float price;
    printf("Enter name of the medicine: ");
    scanf("%s", name);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &quantity);
    printf("Enter price of the medicine: ");
    scanf("%f", &price);
    strcpy(medicines[numMedicines].name, name);
    medicines[numMedicines].quantity = quantity;
    medicines[numMedicines].price = price;
    numMedicines++;
    printf("\nMedicine added successfully!\n");
}

// Function to display all medicines in the store
void displayMedicines(){
    printf("\n----------------------------------------------------------\n");
    printf("Name\t\tQuantity\tPrice\n");
    printf("----------------------------------------------------------\n");
    for(int i=0; i<numMedicines; i++){
        printf("%s\t\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("----------------------------------------------------------\n");
}

// Function to add a new customer
void addCustomer(){
    char name[50];
    int age;
    char address[100];
    printf("Enter name of the customer: ");
    scanf("%s", name);
    printf("Enter age of the customer: ");
    scanf("%d", &age);
    printf("Enter address of the customer: ");
    scanf("%s", address);
    strcpy(customers[numCustomers].name, name);
    customers[numCustomers].age = age;
    strcpy(customers[numCustomers].address, address);
    numCustomers++;
    printf("\nCustomer added successfully!\n");
}

// Function to display all customers in the store
void displayCustomers(){
    printf("\n----------------------------------------------------------\n");
    printf("Name\t\tAge\tAddress\n");
    printf("----------------------------------------------------------\n");
    for(int i=0; i<numCustomers; i++){
        printf("%s\t\t%d\t%s\n", customers[i].name, customers[i].age, customers[i].address);
    }
    printf("----------------------------------------------------------\n");
}

// Function to sell medicine to a customer
void sellMedicine(){
    char name[50];
    int quantity;
    printf("Enter name of the medicine: ");
    scanf("%s", name);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &quantity);
    int index = -1;
    for(int i=0; i<numMedicines; i++){
        if(strcmp(medicines[i].name, name) == 0){
            medicines[i].quantity -= quantity;
            printf("\nMedicine sold successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

int main(){
    int choice;
    while(1){
        printf("\n\n------------------- Medical Store Management ----------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Add Customer\n");
        printf("4. Display Customers\n");
        printf("5. Sell Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addMedicine();
                break;

            case 2:
                displayMedicines();
                break;

            case 3:
                addCustomer();
                break;

            case 4:
                displayCustomers();
                break;

            case 5:
                sellMedicine();
                break;

            case 6:
                printf("\nThank you for using this software!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}