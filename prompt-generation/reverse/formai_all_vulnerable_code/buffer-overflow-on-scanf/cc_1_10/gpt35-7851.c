//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* A struct to store the details of the system event */
struct Event {
    int id;
    char type[50];
    char message[100];
    time_t timestamp;
};

/* Function to log the system event */
void logEvent(struct Event *e) {
    FILE *fileptr;
    
    /* Open the log file in append mode */
    fileptr = fopen("system.log", "a");
    
    /* Log the event details */
    fprintf(fileptr, "Event ID: %d\n", e->id);
    fprintf(fileptr, "Event Type: %s\n", e->type);
    fprintf(fileptr, "Event Message: %s\n", e->message);
    fprintf(fileptr, "Timestamp: %s\n", asctime(localtime(&e->timestamp)));
    fprintf(fileptr, "--------------------------------------------------\n");
    
    /* Close the log file */
    fclose(fileptr);
}

/* Main function */
int main() {
    int event_id = 1;
    char event_type[50];
    char event_message[100];
    int choice;
    struct Event event;
    
    printf("**** System Event Logger ****\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Log an event\n");
        printf("2. Exit\n");
        printf("Enter your choice (1/2): ");
        scanf("%d", &choice);
        getchar(); /* To clear the newline character from the buffer */
        
        switch(choice) {
            case 1:
                /* Get the input details of the event */
                printf("\nEnter the event type: ");
                fgets(event_type, sizeof(event_type), stdin);
                printf("Enter the event message: ");
                fgets(event_message, sizeof(event_message), stdin);
                
                /* Set the details of the event */
                event.id = event_id++;
                strcpy(event.type, event_type);
                strcpy(event.message, event_message);
                event.timestamp = time(NULL);
                
                /* Log the event */
                logEvent(&event);
                
                printf("\nEvent logged successfully!\n");
                break;
                
            case 2:
                printf("\nExiting the System Event Logger...\n");
                break;
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 2);
    
    return 0;
}