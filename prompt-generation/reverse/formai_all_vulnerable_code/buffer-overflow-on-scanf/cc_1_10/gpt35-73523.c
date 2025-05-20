//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

int main() {
    // initializing time variables
    time_t current_time;
    struct tm *loc_time;

    // getting current time
    current_time = time(NULL);
    loc_time = localtime(&current_time);

    // setting variable for light status
    int light_status = 0;

    // greeting message
    printf("Welcome to Smart Home Light Control!\n");

    // loop for user input
    while (1) {
        // displaying menu options
        printf("\nPlease select an option:\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Check light status\n");
        printf("4. Quit\n");

        // taking user input
        int option;
        printf("Enter option number: ");
        scanf("%d", &option);

        // handling user input
        switch (option) {
            case 1:
                if (light_status == 0) {
                    light_status = 1;
                    printf("\nLight turned on!\n");
                    printf("Time: %d:%d\n", loc_time->tm_hour, loc_time->tm_min);
                } else {
                    printf("\nLight is already on!\n");
                }
                break;
            case 2:
                if (light_status == 1) {
                    light_status = 0;
                    printf("\nLight turned off!\n");
                    printf("Time: %d:%d\n", loc_time->tm_hour, loc_time->tm_min);
                } else {
                    printf("\nLight is already off!\n");
                }
                break;
            case 3:
                if (light_status == 1) {
                    printf("\nLight is currently on.\n");
                } else {
                    printf("\nLight is currently off.\n");
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }
}