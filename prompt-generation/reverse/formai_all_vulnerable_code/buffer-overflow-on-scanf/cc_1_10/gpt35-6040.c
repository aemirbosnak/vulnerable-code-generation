//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Appointment
// struct to store appointment details
{
    char name[30];
    int age;
    char gender[10];
    char date[15];
};

void createAppointment(struct Appointment app[], int num)
// function to create an appointment
{
    printf("Enter your name: ");
    scanf("%s", app[num].name);
    printf("Enter your age: ");
    scanf("%d", &app[num].age);
    printf("Enter your gender: ");
    scanf("%s", app[num].gender);
    printf("Enter the date you want the appointment (dd/mm/yyyy format): ");
    scanf("%s", app[num].date);
    printf("\nAppointment created!\n\n");
}

void viewAppointments(struct Appointment app[], int num)
// function to view all appointments
{
    if(num == 0)
    {
        printf("No appointments yet.\n\n");
        return;
    }
    printf("Current appointments:\n");
    for(int i = 0; i < num; i++)
    {
        printf("\nAppointment %d:\n", i+1);
        printf("Name: %s\n", app[i].name);
        printf("Age: %d\n", app[i].age);
        printf("Gender: %s\n", app[i].gender);
        printf("Date: %s\n", app[i].date);
        printf("\n");
    }
}

int main()
{
    struct Appointment appointments[50];
    int numAppointments = 0;
    int choice;

    printf("Welcome to the Appointment Scheduler!\n\n");

    do
    {
        printf("MENU:\n");
        printf("1) Create a new appointment\n");
        printf("2) View all appointments\n");
        printf("3) Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
            case 1:
                createAppointment(appointments, numAppointments);
                numAppointments++;
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 3);

    return 0;
}