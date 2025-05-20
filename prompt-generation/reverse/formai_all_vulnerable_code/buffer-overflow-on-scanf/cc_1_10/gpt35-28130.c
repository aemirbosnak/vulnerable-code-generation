//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
//This is a C event logger program that logs system events with timestamps

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This is the main function
int main()
{
    //Declare variables
    int menu_choice;
    char log_entry[100];
    char filename[20];    
    FILE *logfile;

    //Get the filename for the log file
    printf("Enter the filename for the log file: ");
    scanf("%s", filename);

    //Create the log file
    if((logfile = fopen(filename, "w")) == NULL)
    {
        printf("Error creating log file! Exiting program...");
        exit(1);
    }

    //Display the menu and get user input
    do
    {
        printf("\n*** System Event Logger ***\n");
        printf("1. Add event log entry\n");
        printf("2. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice)
        {
            case 1:
                //Get the log entry from the user
                printf("\nEnter log entry: ");
                scanf("%s", log_entry);

                //Get the current time
                time_t current_time = time(NULL);
                struct tm *time_info = localtime(&current_time);
                char time_string[9];
                strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

                //Print the log entry and timestamp to the log file
                fprintf(logfile, "[%s] %s\n", time_string, log_entry);
                printf("Log entry added!\n");
                break;

            case 2:
                //Close the log file and exit the program
                printf("\nExiting program...\n");
                fclose(logfile);
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(menu_choice != 2);

    return 0;
}