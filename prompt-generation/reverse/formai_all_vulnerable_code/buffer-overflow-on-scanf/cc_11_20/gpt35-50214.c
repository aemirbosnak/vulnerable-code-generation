//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h> // inclide standard input output header file
#include <stdlib.h> // include library to use system() function

int main()
{
    int day, time; // variables to store day and time
    char name[20]; // variable to store name

    printf("Welcome to Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", name); // read name from user

    printf("\nHi %s,\n", name);
    printf("Please select a day for your appointment:\n");

    printf("1. Monday\n");
    printf("2. Tuesday\n");
    printf("3. Wednesday\n");
    printf("4. Thursday\n");
    printf("5. Friday\n");

    scanf("%d", &day); // read day from user

    if(day < 1 || day > 5) // check if day is in range or not
    {
        printf("Invalid day! Please select a valid day.\n");
        return 0; // exit program
    }

    printf("\nPlease select a time for your appointment:\n");

    printf("1. 9AM\n");
    printf("2. 10AM\n");
    printf("3. 11AM\n");
    printf("4. 12PM\n");
    printf("5. 1PM\n");

    scanf("%d", &time); // read time from user

    if(time < 1 || time > 5) // check if time is in range or not
    {
        printf("Invalid time! Please select a valid time.\n");
        return 0; // exit program
    }

    printf("\nAppointment scheduled successfully on ");

    switch(day) // display selected day
    {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
    }

    printf(" at ");

    switch(time) // display selected time
    {
        case 1:
            printf("9AM");
            break;
        case 2:
            printf("10AM");
            break;
        case 3:
            printf("11AM");
            break;
        case 4:
            printf("12PM");
            break;
        case 5:
            printf("1PM");
            break;
    }

    printf("\n\nThank you for using Appointment Scheduler!\n\n");

    system("pause"); // pause execution

    return 0; // exit program
}