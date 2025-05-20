//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <string.h>

// function prototype
void surrealAppointmentScheduler();

// global variables
char name[50];
char date[20];
char time[10];
char location[50];

int main()
{
    printf("Welcome to the Surrealist Appointment Scheduler!\n\n");
    surrealAppointmentScheduler();
    return 0;
}

void surrealAppointmentScheduler()
{
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nGreetings, %s. You have entered the fantastical world of the Surrealist Appointment Scheduler!\n", name);

    printf("\nWhat kind of surreal appointment would you like to schedule?\n");
    printf("1. A meeting with a talking cat\n");
    printf("2. A consultation with a wise owl\n");
    printf("3. A dance party with a group of unicorns\n");
    printf("4. A picnic with a giant mushroom\n");
    printf("5. Something entirely different!\n\n");
    printf("Enter your choice: ");
    int appointmentChoice;
    scanf("%d", &appointmentChoice);

    switch(appointmentChoice)
    {
        case 1:
            printf("\nMeow! You have chosen to schedule a meeting with a talking cat.\n");
            break;
        case 2:
            printf("\nHoot! You have chosen to schedule a consultation with a wise owl.\n");
            break;
        case 3:
            printf("\nNeigh! You have chosen to schedule a dance party with a group of unicorns.\n");
            break;
        case 4:
            printf("\nYum! You have chosen to schedule a picnic with a giant mushroom.\n");
            break;
        default:
            printf("\nHow strange! You have chosen to schedule something entirely different.\n");
            break;
    }

    printf("\nWhen would you like to have your surreal appointment? (format: MM/DD/YYYY): ");
    scanf("%s", date);
    printf("\nWhat time do you want your surreal appointment? (format: HH:MM AM/PM): ");
    scanf("%s", time);
    printf("\nWhere would you like your surreal appointment to take place? ");
    //(via teleportation, time travel, or dreamland)
    scanf("%s", location);

    printf("\nFantastic! Here are the details of your surreal appointment:\n");
    printf("Appointment Type: %d\n", appointmentChoice);
    printf("Name: %s\n", name);
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Location: %s\n", location);
}