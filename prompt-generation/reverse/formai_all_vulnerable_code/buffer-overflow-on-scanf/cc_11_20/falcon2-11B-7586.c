//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct appointment
{
    char name[50];
    int start_time;
    int end_time;
};

struct appointment appointments[10];

int main()
{
    int n = 0;
    int choice;
    struct appointment temp_appointment;

    do
    {
        printf("\nEnter 1 to add an appointment\n");
        printf("Enter 2 to display the appointments\n");
        printf("Enter 3 to delete an appointment\n");
        printf("Enter 4 to update an appointment\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter details of the appointment:\n");
            scanf("%s %d %d", appointments[n].name, &appointments[n].start_time, &appointments[n].end_time);
            n++;
            break;

        case 2:
            for(int i = 0; i < n; i++)
            {
                printf("\n%s: %d - %d\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
            }
            break;

        case 3:
            printf("\nEnter the name of the appointment to be deleted: ");
            scanf("%s", appointments[n].name);
            for(int i = 0; i < n; i++)
            {
                if(strcmp(appointments[i].name, appointments[n].name) == 0)
                {
                    for(int j = i; j < n-1; j++)
                    {
                        appointments[j] = appointments[j+1];
                    }
                    n--;
                    break;
                }
            }
            break;

        case 4:
            printf("\nEnter the name of the appointment to be updated: ");
            scanf("%s", appointments[n].name);
            printf("\nEnter new start time: ");
            scanf("%d", &appointments[n].start_time);
            printf("\nEnter new end time: ");
            scanf("%d", &appointments[n].end_time);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.");
        }
    } while(choice!= 5);

    return 0;
}