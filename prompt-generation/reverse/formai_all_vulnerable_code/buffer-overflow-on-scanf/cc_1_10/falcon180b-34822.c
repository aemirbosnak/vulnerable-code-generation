//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 50

typedef struct {
    time_t timestamp;
    int location;
} TimeTravelRecord;

int main(int argc, char *argv[]) {
    TimeTravelRecord travels[MAX_TIME_TRAVELS];
    int num_travels = 0;
    int choice;
    char input_buffer[100];

    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to any time between 1900 and 2100.\n");
    printf("Enter 'travel' to go to a random year, or enter a specific year.\n");

    while (num_travels < MAX_TIME_TRAVELS) {
        printf("Enter your choice: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        choice = atoi(input_buffer);

        if (choice == 1) {
            int year;
            printf("Enter the year you want to travel to: ");
            scanf("%d", &year);

            if (year >= 1900 && year <= 2100) {
                travels[num_travels].timestamp = mktime(&(struct tm){ 0, 0, 0, 1, 0, year - 1900 });
                travels[num_travels].location = year;
                num_travels++;
            } else {
                printf("Invalid year.\n");
            }
        } else if (choice == 2) {
            if (num_travels > 0) {
                int location = travels[num_travels - 1].location;
                printf("You are currently in the year %d.\n", location);
            } else {
                printf("You haven't traveled anywhere yet.\n");
            }
        } else if (choice == 3) {
            if (num_travels > 0) {
                int location = travels[num_travels - 1].location;
                printf("You traveled to the year %d.\n", location);
            } else {
                printf("You haven't traveled anywhere yet.\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}