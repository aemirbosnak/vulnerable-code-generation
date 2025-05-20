//FormAI DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random timestamp
char* generate_timestamp()
{
    char* timestamp = malloc(sizeof(char)*20);
    time_t t = time(NULL);
    struct tm* current_time = localtime(&t);
    sprintf(timestamp, "%04d-%02d-%02d %02d:%02d:%02d", (current_time->tm_year)+1900,
            (current_time->tm_mon)+1, current_time->tm_mday, current_time->tm_hour,
            current_time->tm_min, current_time->tm_sec);
    return timestamp;
}

int main()
{
    FILE *fp;
    fp = fopen("event_log.txt", "a"); // Opening file in append mode
    
    if(fp==NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }
    
    printf("Welcome to the C System event logger!\n");
    char* event_type;
    char* event_description;
    char* timestamp;
    
    // Loop to take user input
    while(1)
    {
        printf("Enter event type (Maximum length 20 characters): ");
        event_type = malloc(sizeof(char)*20);
        gets(event_type);
        
        printf("Enter event description (Maximum length 50 characters): ");
        event_description = malloc(sizeof(char)*50);
        gets(event_description);
        
        // Generating timestamp
        timestamp = generate_timestamp();
        
        // Writing to file
        fprintf(fp, "[%s] Event Type: %s\tEvent Description: %s\n", timestamp, event_type, event_description);
        printf("Event logged successfully!\n");
        
        // Freeing memory
        free(event_type);
        free(event_description);
        free(timestamp);
        
        char choice;
        printf("Do you want to log another event? (Y/N): ");
        scanf(" %c", &choice);
        
        if(choice=='N' || choice=='n')
        {
            printf("Thank you for using the C System event logger! Exiting...\n");
            break;
        }
    }
    
    // Closing file
    fclose(fp);
    
    return 0;
}