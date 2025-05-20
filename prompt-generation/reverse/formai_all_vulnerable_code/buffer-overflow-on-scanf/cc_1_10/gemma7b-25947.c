//Gemma-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    // Define a structure to store customer information
    struct customer
    {
        char name[50];
        int age;
        float income;
        char occupation[50];
    } customer_data[MAX];

    // Initialize the customer data
    for (int i = 0; i < MAX; i++)
    {
        customer_data[i].name[0] = '\0';
        customer_data[i].age = 0;
        customer_data[i].income = 0.0f;
        customer_data[i].occupation[0] = '\0';
    }

    // Get the customer data from the user
    printf("Enter the customer's name: ");
    scanf("%s", customer_data[0].name);

    printf("Enter the customer's age: ");
    scanf("%d", &customer_data[0].age);

    printf("Enter the customer's income: ");
    scanf("%f", &customer_data[0].income);

    printf("Enter the customer's occupation: ");
    scanf("%s", customer_data[0].occupation);

    // Print the customer data
    printf("Name: %s", customer_data[0].name);

    printf("Age: %d", customer_data[0].age);

    printf("Income: %.2f", customer_data[0].income);

    printf("Occupation: %s", customer_data[0].occupation);

    return 0;
}