//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[20];
    char time[20];
    char date[20];
} Appointment;

int main() {
    time_t t;
    struct tm *tm;
    Appointment appointments[MAX_Appointments];
    int i = 0;

    // Initialize the appointments array
    for (i = 0; i < MAX_Appointments; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].time[0] = '\0';
        appointments[i].date[0] = '\0';
    }

    // Get the current time and date
    time(&t);
    tm = localtime(&t);

    // Create a new appointment
    printf("Enter your name: ");
    scanf("%s", appointments[i].name);

    printf("Enter the time (HH:MM): ");
    scanf("%s", appointments[i].time);

    printf("Enter the date (DD/MM/YY): ");
    scanf("%s", appointments[i].date);

    // Increment the index for the next appointment
    i++;

    // Print the appointment details
    printf("Your appointment has been scheduled:\n");
    printf("Name: %s\n", appointments[i - 1].name);
    printf("Time: %s\n", appointments[i - 1].time);
    printf("Date: %s\n", appointments[i - 1].date);

    return 0;
}