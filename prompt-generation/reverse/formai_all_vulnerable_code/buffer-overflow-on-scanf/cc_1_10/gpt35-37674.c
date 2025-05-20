//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
#define MIN_AMOUNT 50

//Structure to hold customers data
struct Customer
{
    int id;
    char name[30];
    float amountSpent;
};

//Initialization of global variables
int totalCustomers = 0;
struct Customer customers[MAX];

//Function to add a new customer
void addCustomer()
{
    if(totalCustomers == MAX)
    {
        printf("\nSorry! The cafe has reached its maximum capacity.");
        return;
    }
    
    struct Customer newCustomer;
    printf("\nEnter the details of the new customer: ");
    printf("\nID: ");
    scanf("%d", &newCustomer.id);
    printf("Name: ");
    scanf("%s", newCustomer.name);
    printf("Amount spent: ");
    scanf("%f", &newCustomer.amountSpent);
    
    customers[totalCustomers] = newCustomer;
    totalCustomers++;
    
    printf("\nCustomer added successfully!\n");
}

//Function to print the list of all customers and their details
void printCustomers()
{
    if(totalCustomers == 0)
    {
        printf("\nNo customers added yet.\n");
        return;
    }
    
    printf("\n%-10s%-20s%-20s", "ID", "Name", "Amount spent");
    for(int i=0; i<totalCustomers; i++)
    {
        printf("\n%-10d%-20s%-20.2f", customers[i].id, customers[i].name, customers[i].amountSpent);
    }
    printf("\n");
}

//Function to calculate loyalty points of a customer
int calculatePoints(float amount)
{
    return amount/MIN_AMOUNT;
}

//Function to display loyalty points of a customer
void displayPoints()
{
    if(totalCustomers == 0)
    {
        printf("\nNo customers added yet.\n");
        return;
    }
    
    int id;
    printf("\nEnter the ID of the customer: ");
    scanf("%d", &id);
    
    int index = -1;
    for(int i=0; i<totalCustomers; i++)
    {
        if(customers[i].id == id)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
    {
        printf("\nNo customer found with ID %d.\n", id);
        return;
    }
    
    int points = calculatePoints(customers[index].amountSpent);
    printf("\nThe customer has earned %d points so far.\n", points);
}

//Function to delete a customer
void deleteCustomer()
{
    if(totalCustomers == 0)
    {
        printf("\nNo customers added yet.\n");
        return;
    }
    
    int id;
    printf("\nEnter the ID of the customer to be deleted: ");
    scanf("%d", &id);
    
    int index = -1;
    for(int i=0; i<totalCustomers; i++)
    {
        if(customers[i].id == id)
        {
            index = i;
            break;
        }
    }
    
    if(index == -1)
    {
        printf("\nNo customer found with ID %d.\n", id);
        return;
    }
    
    for(int i=index; i<totalCustomers-1; i++)
    {
        customers[i] = customers[i+1];
    }
    
    totalCustomers--;
    printf("\nCustomer with ID %d has been deleted successfully!\n", id);
}

//Main function
int main()
{
    printf("Welcome to the Cafe Billing System!");

    int choice;

    do
    {
        printf("\n\nMenu:\n");
        printf("1. Add a new customer\n");
        printf("2. Print list of all customers\n");
        printf("3. Display loyalty points of a customer\n");
        printf("4. Delete a customer\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addCustomer();
                break;

            case 2:
                printCustomers();
                break;

            case 3:
                displayPoints();
                break;

            case 4:
                deleteCustomer();
                break;

            case 5:
                printf("\nThank you for using Cafe Billing System!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice!=5);

    return 0;
}