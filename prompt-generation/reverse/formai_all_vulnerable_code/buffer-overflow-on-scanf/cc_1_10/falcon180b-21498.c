//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

struct event {
    time_t timestamp;
    char description[80];
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char input[80];
    time_t current_time;
    int choice;

    srand(time(NULL));

    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("What would you like to do?\n");
        printf("1. Travel to a specific time\n");
        printf("2. View timeline of events\n");
        printf("3. Add event to timeline\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the target time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", input);
                if(strptime(input, "%Y-%m-%d %H:%M:%S", &current_time)!= NULL) {
                    printf("You have successfully traveled to %s!\n", ctime(&current_time));
                } else {
                    printf("Invalid date/time format.\n");
                }
                break;
            case 2:
                printf("Timeline of events:\n");
                for(int i=0; i<num_events; i++) {
                    printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
                }
                break;
            case 3:
                if(num_events >= MAX_EVENTS) {
                    printf("Timeline is full. Cannot add more events.\n");
                } else {
                    printf("Enter the event description (max 80 characters): ");
                    scanf("%s", events[num_events].description);
                    time(&events[num_events].timestamp);
                    num_events++;
                    printf("Event added successfully!\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}