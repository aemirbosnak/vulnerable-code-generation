//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Appointment //structure to hold appointment details
{
    char name[50];
    int day, month, year, hour, minute;
};

int main()
{
    bool exit = false; //loop control variable
    struct Appointment schedule[10]; //array of structures to hold maximum 10 appointments
    int count = 0; //counter variable

    while(exit == false) //start of while loop
    {
        int choice; //variable to hold user choice
        printf("\n Welcome to Appointment Scheduler!\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) //switch case statement
        {
            case 1:
                printf("\n Add Appointment\n");
                if(count == 10) //check if maximum number of appointments has been reached
                {
                    printf("Maximum number of appointments reached! Cannot add more.\n");
                }
                else
                {
                    printf("Enter name: ");
                    scanf("%s", schedule[count].name);
                    printf("Enter date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d", &schedule[count].day, &schedule[count].month, &schedule[count].year);
                    printf("Enter time (hh:mm): ");
                    scanf("%d:%d", &schedule[count].hour, &schedule[count].minute);
                    printf("\n Appointment added successfully!\n");
                    count++; //increase counter variable after adding an appointment
                }
                break;

            case 2:
                printf("\n View Appointments\n");
                if(count == 0) //check if no appointments have been added yet
                {
                    printf("No appointments added yet!\n");
                }
                else
                {
                    printf("Name\t\tDate\t\tTime\n"); //display header row
                    printf("----\t\t----\t\t----\n");

                    for(int i=0; i<count; i++) //loop through appointments and display details
                    {
                        printf("%s\t\t%d/%d/%d\t\t%d:%d\n", schedule[i].name, schedule[i].day, schedule[i].month, schedule[i].year, schedule[i].hour, schedule[i].minute);
                    }
                }
                break;

            case 3:
                printf("\n Program Exiting.\n");
                exit = true; //set exit loop control variable to true
                break;

            default:
                printf("\n Invalid Choice!\n"); //display error message for invalid choice
        }
    }

    return 0;
}