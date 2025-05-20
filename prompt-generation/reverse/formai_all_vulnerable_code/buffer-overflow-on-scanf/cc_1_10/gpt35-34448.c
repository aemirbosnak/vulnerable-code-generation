//FormAI DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Open the log file for writing
    FILE *log_file;
    log_file = fopen("event_log.txt", "w");

    // Make sure the file opened successfully
    if (log_file == NULL) {
        printf("Oops! Something went wrong and we couldn't open the log file. Please try again later!");
        exit(1);
    }

    // Welcome message
    printf("Hi there! Let's log some happy events!\n");

    // Get the user's name
    char name[20];
    printf("What's your name, friend? ");
    scanf("%s", name);

    // Greet the user by name
    printf("Hi, %s! Let's get started.\n", name);

    // Keep logging events until the user is finished
    char event[100];
    int continue_logging = 1;
    while (continue_logging) {

        // Get the current time
        time_t current_time;
        time(&current_time);

        // Ask the user what happened
        printf("What happy event would you like to log? ");
        scanf(" %[^\n]", event);

        // Log the event to the file
        fprintf(log_file, "[%s] %s logged the happy event: %s\n", ctime(&current_time), name, event);

        // Ask the user if they want to log another event
        char answer[3];
        printf("Would you like to log another happy event? (Y/N) ");
        scanf("%s", answer);

        // Check the user's answer
        if (answer[0] == 'N' || answer[0] == 'n') {
            continue_logging = 0;
        }
    }

    // Close the log file
    fclose(log_file);

    // Thank the user and exit the program
    printf("Thanks for logging your happy events with us, %s! Have a great day!\n", name);
    return 0;
}