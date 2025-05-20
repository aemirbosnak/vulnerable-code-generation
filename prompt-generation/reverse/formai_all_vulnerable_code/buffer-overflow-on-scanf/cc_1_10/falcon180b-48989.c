//Falcon-180B DATASET v1.0 Category: Data mining ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

struct customer
{
    int id;
    char name[50];
    int age;
    int gender;
    int income;
};

void create_customer_database(struct customer customer[], int n)
{
    FILE *fp;
    fp = fopen("customer_database.txt", "w");

    fprintf(fp, "Customer ID\tName\tAge\tGender\tIncome\n");

    for(int i=0; i<n; i++)
    {
        fprintf(fp, "%d\t%s\t%d\t%d\t%d\n", customer[i].id, customer[i].name, customer[i].age, customer[i].gender, customer[i].income);
    }

    fclose(fp);
}

void read_customer_database(struct customer customer[], int n)
{
    FILE *fp;
    fp = fopen("customer_database.txt", "r");

    for(int i=0; i<n; i++)
    {
        fscanf(fp, "%d\t%s\t%d\t%d\t%d", &customer[i].id, customer[i].name, &customer[i].age, &customer[i].gender, &customer[i].income);
    }

    fclose(fp);
}

void display_customer_database(struct customer customer[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Customer ID: %d\n", customer[i].id);
        printf("Name: %s\n", customer[i].name);
        printf("Age: %d\n", customer[i].age);
        printf("Gender: %d\n", customer[i].gender);
        printf("Income: %d\n\n", customer[i].income);
    }
}

int main()
{
    int n;
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    struct customer customer[n];

    printf("Enter customer details:\n");

    for(int i=0; i<n; i++)
    {
        printf("Customer ID: ");
        scanf("%d", &customer[i].id);

        printf("Name: ");
        scanf("%s", customer[i].name);

        printf("Age: ");
        scanf("%d", &customer[i].age);

        printf("Gender (0 for Male, 1 for Female): ");
        scanf("%d", &customer[i].gender);

        printf("Income: ");
        scanf("%d", &customer[i].income);
    }

    create_customer_database(customer, n);

    printf("Customer database created successfully!\n");

    read_customer_database(customer, n);

    printf("Customer database read successfully!\n");

    display_customer_database(customer, n);

    return 0;
}