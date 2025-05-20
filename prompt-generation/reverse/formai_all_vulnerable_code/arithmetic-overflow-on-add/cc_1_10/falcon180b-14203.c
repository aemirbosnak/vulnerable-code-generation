//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the current date and time
void display_time(struct tm *time_info) {
    printf("Current date and time: %s", asctime(time_info));
}

// Function to travel back in time by n seconds
void travel_back_in_time(int n) {
    time_t now = time(NULL);
    time_t back_in_time = now - n;
    struct tm *time_info = localtime(&back_in_time);
    display_time(time_info);
}

// Function to travel forward in time by n seconds
void travel_forward_in_time(int n) {
    time_t now = time(NULL);
    time_t forward_in_time = now + n;
    struct tm *time_info = localtime(&forward_in_time);
    display_time(time_info);
}

int main() {
    int choice, seconds;

    // Loop until the user chooses to exit
    while(1) {
        printf("\nTime Travel Simulator\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Validate the user's choice
        switch(choice) {
            case 1:
                printf("Enter the number of seconds to travel back in time: ");
                scanf("%d", &seconds);
                travel_back_in_time(seconds);
                break;

            case 2:
                printf("Enter the number of seconds to travel forward in time: ");
                scanf("%d", &seconds);
                travel_forward_in_time(seconds);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}