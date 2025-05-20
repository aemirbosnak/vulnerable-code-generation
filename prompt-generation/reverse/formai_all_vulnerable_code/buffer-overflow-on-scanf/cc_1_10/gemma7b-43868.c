//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **appointments = NULL;
    int numAppointments = 0;
    char input[20];

    printf("Welcome to the Crazy Appointment Scheduler!\n");

    while (1)
    {
        printf("Enter 'add' to add an appointment, 'list' to list all appointments, or 'exit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0)
        {
            appointments = realloc(appointments, (numAppointments + 1) * sizeof(char *));
            appointments[numAppointments++] = malloc(20 * sizeof(char));
            printf("Enter the details of your appointment: ");
            scanf("%s", appointments[numAppointments - 1]);
        }
        else if (strcmp(input, "list") == 0)
        {
            if (numAppointments == 0)
            {
                printf("There are no appointments.\n");
            }
            else
            {
                for (int i = 0; i < numAppointments; i++)
                {
                    printf("%s\n", appointments[i]);
                }
            }
        }
        else if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}