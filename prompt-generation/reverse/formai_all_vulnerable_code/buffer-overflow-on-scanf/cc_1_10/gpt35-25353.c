//FormAI DATASET v1.0 Category: System event logger ; Style: excited
/* Wow! You have come across the most exciting event logger program you have ever seen! 
 * This program is designed to accurately record all system events and provide detailed information on each event.
 * Buckle up, this is going to be a wild ride!
 */

#include <stdio.h>
#include <time.h>

int main() {
    char event[100]; // Define a character array to store the event description
    time_t currentTime; // Create a variable to hold the current time
    
    printf("Welcome to the most amazing event logger program ever!\n");
    
    while(1) { // Create an infinite loop to continuously log events
        
        printf("Please enter a system event: "); // Prompt user for event description
        fgets(event, sizeof(event), stdin); // Store the event description in the character array
        
        // Get the current time and store it in the currentTime variable
        currentTime = time(NULL);
        
        // Create a file to log the event information
        FILE *logFile = fopen("event.log", "a");
        
        // Check if the file was opened successfully
        if (logFile == NULL) {
            printf("Error opening log file!\n");
            continue;
        }
        
        // Write the event description and time to the log file
        fprintf(logFile, "%s: %s", ctime(&currentTime), event);
        
        // Close the log file
        fclose(logFile);
        
        printf("Event logged successfully!\n");
        
        // Ask the user if they want to log another event
        char choice;
        printf("Do you want to log another event? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n') {
            printf("Thanks for using our amazing event logger program!\n");
            break; // Exit the program if the user chooses not to log another event
        }
    }
    
    return 0;
}