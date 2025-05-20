//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_CUSTOMERS 50

struct medicine
{
    char name[50];
    int price;
    int quantity;
} medicines[MAX_MEDICINES];

struct customer
{
    char name[50];
    int age;
    char gender;
    char address[100];
    char phone[11];
    int basket[MAX_MEDICINES];
    int basketQuantity[MAX_MEDICINES];
    int totalCost;
    int itemsBought;
} customers[MAX_CUSTOMERS];

int numMedicines = 0;
int numCustomers = 0;

void addMedicine()
{
    if(numMedicines == MAX_MEDICINES)
    {
        printf("\nMedicines are full.");
        return;
    }

    printf("\nEnter medicine name: ");
    fflush(stdin);
    gets(medicines[numMedicines].name);

    printf("\nEnter medicine price: ");
    scanf("%d", &medicines[numMedicines].price);

    printf("\nEnter medicine quantity: ");
    scanf("%d", &medicines[numMedicines].quantity);

    numMedicines++;
}

void showMedicines()
{
    printf("\nMedicine\tPrice\tQuantity\n");

    for(int i=0;i<numMedicines;i++)
    {
        printf("%s\t\t%d\t%d\n", medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void addCustomer()
{
    if(numCustomers == MAX_CUSTOMERS)
    {
        printf("\nCustomers are full.");
        return;
    }

    printf("\nEnter customer name: ");
    fflush(stdin);
    gets(customers[numCustomers].name);

    printf("\nEnter customer age: ");
    scanf("%d", &customers[numCustomers].age);

    printf("\nEnter customer gender (M/F): ");
    fflush(stdin);
    scanf("%c", &customers[numCustomers].gender);

    printf("\nEnter customer address: ");
    fflush(stdin);
    gets(customers[numCustomers].address);

    printf("\nEnter customer phone number: ");
    fflush(stdin);
    gets(customers[numCustomers].phone);

    printf("\nCustomer added successfully.");

    numCustomers++;
}

void showCustomers()
{
    printf("\nName\tAge\tGender\tPhone\n");

    for(int i=0;i<numCustomers;i++)
    {
        printf("%s\t%d\t%c\t%s\n", customers[i].name, customers[i].age, customers[i].gender, customers[i].phone);
    }
}

void addBasket(int customerIndex)
{
    int medicineIndex, quantity;
    char cont = 'Y';

    while(cont == 'Y' || cont == 'y')
    {
        printf("\nEnter medicine index: ");
        scanf("%d", &medicineIndex);

        printf("\nEnter quantity: ");
        scanf("%d", &quantity);

        if(quantity > medicines[medicineIndex].quantity)
        {
            printf("\nRequested quantity is not available. Stock available: %d", medicines[medicineIndex].quantity);
            continue;
        }

        customers[customerIndex].basket[customers[customerIndex].itemsBought] = medicineIndex;
        customers[customerIndex].basketQuantity[customers[customerIndex].itemsBought] = quantity;
        customers[customerIndex].totalCost += medicines[medicineIndex].price * quantity;
        medicines[medicineIndex].quantity -= quantity;
        customers[customerIndex].itemsBought++;

        printf("\nDo you want to add more medicines? (Y/N): ");
        fflush(stdin);
        scanf("%c", &cont);
    }
}

void checkout(int customerIndex)
{
    printf("\nItems\tQuantity\tPrice\tTotal\n");

    for(int i=0;i<customers[customerIndex].itemsBought;i++)
    {
        int medicineIndex = customers[customerIndex].basket[i];
        int medicineQuantity = customers[customerIndex].basketQuantity[i];
        int cost = medicines[medicineIndex].price * medicineQuantity;
        printf("%s\t%d\t\t%d\t%d\n", medicines[medicineIndex].name, medicineQuantity, medicines[medicineIndex].price, cost);
    }

    printf("\nTotal cost: %d", customers[customerIndex].totalCost);

    printf("\nThank you for shopping.");
}

int main()
{
    int choice, customerIndex;

    do
    {
        printf("\n1. Add Medicine\n2. Show Medicines\n3. Add Customer\n4. Show Customers\n5. Add Basket\n6. Checkout\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                showMedicines();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                showCustomers();
                break;
            case 5:
                printf("\nEnter customer index: ");
                scanf("%d", &customerIndex);
                addBasket(customerIndex);
                break;
            case 6:
                printf("\nEnter customer index: ");
                scanf("%d", &customerIndex);
                checkout(customerIndex);
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice.");
                break;
        }
    } while (1);

    return 0;
}