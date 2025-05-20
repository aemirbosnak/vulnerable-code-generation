//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to display menu options
void display_menu()
{
    printf("\n1. Add Patient Details\n2. View Patient Details\n3. Update Patient Details\n4. Delete Patient Details\n5. Exit\n");
}

// Function to add patient details
void add_patient()
{
    char name[50];
    int age, gender;

    printf("\nEnter patient's name: ");
    scanf("%s", name);

    printf("Enter patient's age: ");
    scanf("%d", &age);

    printf("Enter patient's gender: ");
    scanf("%d", &gender);

    printf("\nPatient details added successfully!\n");
}

// Function to view patient details
void view_patient()
{
    char name[50];

    printf("\nEnter patient's name: ");
    scanf("%s", name);

    printf("Patient details: %s\n", name);
}

// Function to update patient details
void update_patient()
{
    char name[50];
    int age, gender;

    printf("\nEnter patient's name: ");
    scanf("%s", name);

    printf("Enter patient's age: ");
    scanf("%d", &age);

    printf("Enter patient's gender: ");
    scanf("%d", &gender);

    printf("\nPatient details updated successfully!\n");
}

// Function to delete patient details
void delete_patient()
{
    char name[50];

    printf("\nEnter patient's name: ");
    scanf("%s", name);

    printf("Patient details deleted successfully!\n");
}

int main()
{
    char choice;

    while (1)
    {
        display_menu();

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                add_patient();
                break;
            case '2':
                view_patient();
                break;
            case '3':
                update_patient();
                break;
            case '4':
                delete_patient();
                break;
            case '5':
                printf("\nExiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again!\n");
                break;
        }
    }
    return 0;
}