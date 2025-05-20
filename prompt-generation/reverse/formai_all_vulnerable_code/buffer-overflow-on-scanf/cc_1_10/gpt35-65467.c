//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random numbers */
int random_num(int lower, int upper)
{
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}

/* Function to display the current date and time */
void display_time()
{
    time_t current_time;
    char* c_time_string;

    /* Obtain current time */
    current_time = time(NULL);

    /* Convert to local time format */
    c_time_string = ctime(&current_time);

    /* Display the current time */
    printf("[%s] ", c_time_string);
}

int main()
{
    /* Initialize variables */
    int event_id, server_id;
    char event_type[20];
    char server_name[20];
    int severity;
    int num_events;

    /* Seed random number generator */
    srand(time(0));

    /* Display welcome message */
    printf("Welcome to the C System Event Logger\n");

    /* Prompt user for input */
    printf("How many events do you want to log? ");
    scanf("%d", &num_events);

    /* Loop through and generate event logs */
    for (int i = 1; i <= num_events; i++)
    {
        /* Generate random event ID and server ID */
        event_id = random_num(100000, 999999);
        server_id = random_num(1, 10);

        /* Generate random event type */
        switch (random_num(1, 5))
        {
            case 1:
                strcpy(event_type, "INFO");
                break;

            case 2:
                strcpy(event_type, "WARNING");
                break;

            case 3:
                strcpy(event_type, "ERROR");
                break;

            case 4:
                strcpy(event_type, "CRITICAL");
                break;

            case 5:
                strcpy(event_type, "ALERT");
                break;
        }

        /* Generate random server name */
        switch (server_id)
        {
            case 1:
                strcpy(server_name, "webserver1");
                break;

            case 2:
                strcpy(server_name, "webserver2");
                break;

            case 3:
                strcpy(server_name, "database1");
                break;

            case 4:
                strcpy(server_name, "database2");
                break;

            case 5:
                strcpy(server_name, "appserver1");
                break;

            case 6:
                strcpy(server_name, "appserver2");
                break;

            case 7:
                strcpy(server_name, "mailserver");
                break;

            case 8:
                strcpy(server_name, "fileserver");
                break;

            case 9:
                strcpy(server_name, "backupserver");
                break;

            case 10:
                strcpy(server_name, "monitoringserver");
                break;
        }

        /* Generate random severity level */
        severity = random_num(1, 10);

        /* Display event log */
        display_time();
        printf("[EVENT %d] [%s] [SERVER: %s] [SEVERITY %d]\n", event_id, event_type, server_name, severity);
    }

    /* Display exit message */
    printf("Thank you for using the C System Event Logger\n");

    return 0;
}