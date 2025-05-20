//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_LIMIT 100
#define MAX_MEDICINE 50
#define MAX_CUSTOMERS 50

//Defining structures for Medicine and Customer
typedef struct {
    char name[MAX_LIMIT];
    int quantity;
    float price;
} medicine;

typedef struct {
    char name[MAX_LIMIT];
    char address[MAX_LIMIT];
    float billAmount;
    int medicineBought[MAX_MEDICINE];
} customer;

//Defining global variables
int totalMedicine = 0;
int totalCustomers = 0;
medicine medicineList[MAX_MEDICINE];
customer customerList[MAX_CUSTOMERS];

//Function to add medicine to the system
void addMedicine() {
    printf("\nEnter the medicine name: ");
    scanf("%s", medicineList[totalMedicine].name);
    printf("Enter the quantity of medicine: ");
    scanf("%d", &medicineList[totalMedicine].quantity);
    printf("Enter the price of medicine: ");
    scanf("%f", &medicineList[totalMedicine].price);
    totalMedicine++;
    printf("\nMedicine added successfully!\n");
}

//Function to view all the medicines in the system
void viewAllMedicines() {
    printf("\nName\tQuantity\tPrice\n");
    for(int i=0;i<totalMedicine;i++) {
        printf("%s\t%d\t%.2f\n",medicineList[i].name,medicineList[i].quantity,medicineList[i].price);
    }
}

//Function to add customer to the system
void addCustomer() {
    printf("\nEnter the customer name: ");
    scanf("%s", customerList[totalCustomers].name);
    printf("Enter the customer address: ");
    scanf("%s", customerList[totalCustomers].address);
    totalCustomers++;
    printf("\nCustomer added successfully!\n");
}

//Function to purchase medicine by the customer
void purchaseMedicine() {
    int customerId, medicineId, quantity;
    float amount;
    printf("\nEnter the customer id: ");
    scanf("%d", &customerId);
    printf("Enter the medicine id: ");
    scanf("%d", &medicineId);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    //Checking if medicine is available in stock
    if(medicineList[medicineId].quantity>=quantity) {
        amount = quantity*medicineList[medicineId].price;
        if(amount>=customerList[customerId].billAmount) {
            customerList[customerId].medicineBought[medicineId]+=quantity;
            customerList[customerId].billAmount+=amount;
            medicineList[medicineId].quantity-=quantity;
            printf("\nMedicine purchased successfully!\n");
        }
        else {
            printf("\nYou do not have enough funds to buy this medicine!\n");
        }
    }
    else {
        printf("\nThis medicine is out of stock!\n");
    }
}

//Function to view all the customers
void viewAllCustomers() {
    printf("\nName\tAddress\tBill Amount\n");
    for(int i=0;i<totalCustomers;i++) {
        printf("%s\t%s\t%.2f\n",customerList[i].name,customerList[i].address,customerList[i].billAmount);
    }
}

//Function to generate a bill for a customer
void generateBill() {
    int customerId;
    float discount = 0;
    time_t now;
    time(&now);
    printf("\nEnter the customer id: ");
    scanf("%d", &customerId);
    printf("Date and Time: %s", ctime(&now));
    printf("Customer Name: %s\n",customerList[customerId].name);
    printf("Customer Address: %s\n",customerList[customerId].address);
    printf("Bill Amount: Rs. %.2f\n",customerList[customerId].billAmount);
    printf("\nMedicines Purchased:\n");
    printf("Name\t\tQuantity\tPrice\n");
    for(int i=0;i<totalMedicine;i++) {
        if(customerList[customerId].medicineBought[i]>0) {
            printf("%s\t\t%d\t\t%.2f\n",medicineList[i].name,customerList[customerId].medicineBought[i],medicineList[i].price);
        }
    }
    if(customerList[customerId].billAmount>=10000) {
        discount = customerList[customerId].billAmount*0.1;
        printf("\nDiscount Applied: Rs. %.2f\n",discount);
    }
    printf("\nTotal Amount to be Paid: Rs. %.2f\n",customerList[customerId].billAmount-discount);
}

//Main function
int main() {
    int choice;
    printf("\t\t\tCyberpunk Medical Store Management System\n");
    printf("\t\t\t=========================================\n");
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add Medicine\n");
        printf("2. View All Medicines\n");
        printf("3. Add Customer\n");
        printf("4. Purchase Medicine\n");
        printf("5. View All Customers\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewAllMedicines();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                purchaseMedicine();
                break;
            case 5:
                viewAllCustomers();
                break;
            case 6:
                generateBill();
                break;
            case 7:
                printf("\nThank you for using the Cyberpunk Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}