//FormAI DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> // For time() function 

/* Structure of a Log Entry */
struct LogEntry{
    char event_type[20]; 
    char event_description[50]; 
    char timestamp[25];
    int event_id; 
}; 

int main(){
    int event_counter = 1; // Keeps count of number of events
    char input; // Char variable to take input from user
    struct LogEntry temp; // Temporary Log Entry for each event 
    FILE *fptr; // File pointer for opening and writing to file 
 
    time_t t = time(NULL); // Get current time
    struct tm tm = *localtime(&t); // Convert time to standard struct format
    printf("Welcome to Example C System Event Logger Program.\nCurrent Date & Time: %02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  
    /* Open file for writing */
    fptr = fopen("log.txt", "w");
    if (fptr == NULL){
        printf("Could not open file to write!\n");
        exit(1);
    }
  
    printf("\nInstruction: Enter 'e' to log an event and 'q' to quit program.\n");
  
    while(1){
        printf("\nEnter your choice: ");
        scanf(" %c", &input);
        if(input == 'e' || input == 'E'){
            printf("Enter event type (Max 20 characters): ");
            scanf(" %s", &temp.event_type);
  
            printf("Enter event description (Max 50 characters): ");
            scanf(" %s", &temp.event_description);
        
            /* Get current time and store in Log */
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            sprintf(temp.timestamp, "%02d-%02d-%04d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            
            temp.event_id = event_counter; // Set event ID
            event_counter++; // Increment event counter
          
            /* Write log entry to file */
            fprintf(fptr, "%d %s %s %s\n", temp.event_id, temp.timestamp, temp.event_type, temp.event_description);
            printf("Event Logged Successfully.\n");
        }
        else if(input == 'q' || input == 'Q'){
            printf("Quitting Program.\n");
            break;
        }
        else{
            printf("Invalid input. Please try again.\n");
        }
    }
  
    fclose(fptr); // Close file 
    return 0; 
}