//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[MAX_NAME_LENGTH];
    time_t now = time(NULL);
    time_t start_time, end_time;

    printf("Welcome to the Shocked Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", input);

    // Check if user has an existing appointment
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, input) == 0) {
            printf("You already have an appointment at %s.\n", ctime(&appointments[i].start_time));
            return 0;
        }
    }

    // Schedule a new appointment
    printf("When would you like your appointment? (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", input);
    if (strptime(input, "%Y-%m-%d %H:%M:%S", &start_time)!= NULL) {
        printf("How long will your appointment be? (HH:MM:SS): ");
        scanf("%s", input);
        if (strptime(input, "%H:%M:%S", &end_time)!= NULL) {
            if (difftime(end_time, start_time) > 0) {
                if (num_appointments < MAX_APPOINTMENTS) {
                    strcpy(appointments[num_appointments].name, input);
                    appointments[num_appointments].start_time = start_time;
                    appointments[num_appointments].end_time = end_time;
                    num_appointments++;
                    printf("Your appointment has been scheduled for %s.\n", ctime(&start_time));
                } else {
                    printf("Sorry, we are fully booked.\n");
                }
            } else {
                printf("Invalid appointment duration.\n");
            }
        } else {
            printf("Invalid appointment duration.\n");
        }
    } else {
        printf("Invalid appointment date and/or time.\n");
    }

    return 0;
}