//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50 // maximum number of records in the database

struct Record // typedef struct used to store data fields
{
    int id;
    char name[50];
    int age;
    char gender;
    float salary;
};

struct Record database[MAX_RECORDS]; // array of structures

void addRecord(int id, char name[], int age, char gender, float salary)
{
    static int recordCount = 0; // static variable to keep count of records

    if (recordCount < MAX_RECORDS) // check if database is full
    {
        database[recordCount].id = id;
        strcpy(database[recordCount].name, name);
        database[recordCount].age = age;
        database[recordCount].gender = gender;
        database[recordCount].salary = salary;

        recordCount++; // increment record count
        printf("\nRecord added successfully!");
    }
    else
    {
        printf("\nThe database is full and cannot add more records!");
    }
}

void searchRecord(char name[])
{
    int i, flag = 0;

    for (i = 0; i < MAX_RECORDS; i++)
    {
        if (strcmp(database[i].name, name) == 0) // if name matches
        {
            printf("\n Record found!");
            printf("\n ID: %d", database[i].id);
            printf("\n Name: %s", database[i].name);
            printf("\n Age: %d", database[i].age);
            printf("\n Gender: %c", database[i].gender);
            printf("\n Salary: %.2f", database[i].salary);

            flag = 1; // set flag to indicate record found
            break;
        }
    }

    if (flag == 0) // if record not found
    {
        printf("\nRecord not found!");
    }
}

int main()
{
    int choice, id, age;
    char name[50], gender;
    float salary;

    printf("Welcome to the Database Simulation Program!");

    do
    {
        printf("\n\nPlease select an option:");
        printf("\n1. Add a record");
        printf("\n2. Search for a record");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter ID: ");
            scanf("%d", &id);
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("\nEnter age: ");
            scanf("%d", &age);
            printf("\nEnter gender (M/F): ");
            scanf(" %c", &gender);
            printf("\nEnter salary: ");
            scanf("%f", &salary);

            addRecord(id, name, age, gender, salary); // call addRecord function
            break;

        case 2:
            printf("\nEnter name to search: ");
            scanf("%s", name);

            searchRecord(name); // call searchRecord function
            break;

        case 3:
            printf("\nThank you for using the program! Goodbye!");
            exit(0); // terminate program

        default:
            printf("\nInvalid choice! Please select again.");
            break;
        }
    } while (choice != 3); // continue until user selects exit

    return 0;
}