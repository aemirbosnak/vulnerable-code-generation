//FormAI DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event_log.txt"

int main()
{
    FILE *file_ptr;
    time_t current_time;

    printf("Wow! You won't believe what just happened! We're logging events!\n");

    // Open the event log file for writing
    file_ptr = fopen(EVENT_LOG_FILE, "w");

    if(file_ptr == NULL) 
    {
        perror("Oh no! Couldn't open the event log file.");
        exit(EXIT_FAILURE);
    }

    // Get the current time and write the start event to the log file
    time(&current_time);
    fprintf(file_ptr, "The event logger program was launched at %s", ctime(&current_time));

    // Perform some fake events and write them to the log file
    int i;
    for(i = 0; i < 5; i++)
    {
        int event_code = rand() % 100;
        char* message;

        switch(event_code)
        {
            case 0:
                message = "A hacker attempted to breach system security.";
                break;

            case 1:
                message = "A new user account was created.";
                break;

            case 2:
                message = "A software update was installed successfully.";
                break;

            case 3:
                message = "A hardware component failed.";
                break;

            case 4:
                message = "A backup was scheduled and completed successfully.";
                break;

            default:
                message = "An unknown event occurred.";
                break;
        }

        time(&current_time);
        fprintf(file_ptr, "[%s] %s\n", ctime(&current_time), message);
        printf("Event %d logged!\n", i+1);

        // Wait a random delay before logging the next event
        int delay = (rand() % 5) + 1;
        printf("Waiting %d seconds...\n", delay);
        clock_t start_time = clock();
        while((clock() - start_time) < (delay * CLOCKS_PER_SEC));
    }

    // Write the stop event to the log file and close it
    time(&current_time);
    fprintf(file_ptr, "The event logger program ended at %s", ctime(&current_time));
    fclose(file_ptr);

    printf("Logging complete! Check out %s for all the juicy details!\n", EVENT_LOG_FILE);
    return EXIT_SUCCESS;
}