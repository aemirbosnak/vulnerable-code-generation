//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum appointment slots per day
#define MAX_APPTS_PER_DAY 10

// Define maximum length for appointment description
#define MAX_APPT_DESCRIPTION_LENGTH 50

// Define the time range for appointments
#define START_TIME 8
#define END_TIME 18

// Define appointment structure
typedef struct {
    int day;
    int time;
    char description[MAX_APPT_DESCRIPTION_LENGTH];
} appointment;

// Define function to print appointment details
void print_appt(appointment *appt) {
    printf("Appointment on Day %d at %d:00\n", appt->day, appt->time);
    printf("Description: %s\n", appt->description);
}

int main() {
    // Define variables to store appointment information
    int day, time;
    char description[MAX_APPT_DESCRIPTION_LENGTH];

    // Define array to store appointments
    appointment appts[MAX_APPTS_PER_DAY * 7];

    // Define variables for loop indexing
    int i;
    int j = 0;

    // Prompt user for appointment information
    printf("Welcome to the appointment scheduler!\n");
    printf("Please enter the day (1-7): ");
    scanf("%d", &day);
    printf("Please enter the time (8-18): ");
    scanf("%d", &time);
    printf("Please enter a brief description of the appointment: ");
    fflush(stdin);
    fgets(description, MAX_APPT_DESCRIPTION_LENGTH, stdin);

    // Check if input values are within range
    if (day < 1 || day > 7 || time < START_TIME || time > END_TIME) {
        printf("Invalid input! Please enter a day between 1 and 7 and a time between 8 and 18.\n");
        return 1;
    }

    // Check if appointment slot is available
    for (i = 0; i < MAX_APPTS_PER_DAY * 7; i++) {
        if (appts[i].day == day && appts[i].time == time) {
            printf("Appointment slot not available. Please select a different time.\n");
            return 1;
        }
    }

    // Save appointment in array
    appts[j].day = day;
    appts[j].time = time;
    strcpy(appts[j].description, description);

    // Print appointment details
    printf("Appointment scheduled successfully!\n");
    print_appt(&appts[j]);

    return 0;
}