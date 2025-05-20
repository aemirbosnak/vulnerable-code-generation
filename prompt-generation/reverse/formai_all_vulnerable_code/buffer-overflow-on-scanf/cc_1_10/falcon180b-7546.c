//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure for an appointment
typedef struct {
    char name[50];
    int date;
    int time;
} appointment;

// Function to compare two appointments based on their date and time
int compareAppointments(const void* a, const void* b) {
    appointment* app1 = (appointment*)a;
    appointment* app2 = (appointment*)b;

    if (app1->date == app2->date) {
        return app1->time - app2->time;
    } else {
        return app1->date - app2->date;
    }
}

// Function to print the schedule for a given day
void printSchedule(appointment schedule[], int day) {
    printf("Schedule for %d:\n", day);
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (schedule[i].date == day) {
            printf("%s at %d\n", schedule[i].name, schedule[i].time);
        }
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the appointment schedule
    appointment schedule[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Prompt the user for the number of appointments they want to schedule
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &numAppointments);

    // Loop through each appointment and prompt the user for the details
    for (int i = 0; i < numAppointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", schedule[i].name);

        printf("Enter the date for appointment %d (dd/mm/yyyy): ", i+1);
        scanf("%d/%d/%d", &schedule[i].date, &schedule[i].date, &schedule[i].date);

        printf("Enter the time for appointment %d (hh:mm): ", i+1);
        scanf("%d:%d", &schedule[i].time, &schedule[i].time);
    }

    // Sort the appointment schedule by date and time
    qsort(schedule, numAppointments, sizeof(appointment), compareAppointments);

    // Print the appointment schedule for each day
    for (int day = 1; day <= 31; day++) {
        printSchedule(schedule, day);
    }

    return 0;
}