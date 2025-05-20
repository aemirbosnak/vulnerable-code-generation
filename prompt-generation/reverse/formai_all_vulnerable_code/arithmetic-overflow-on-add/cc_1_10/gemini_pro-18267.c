//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Calendar structure
typedef struct Calendar {
    Appointment **appointments;
    int num_appointments;
    int max_appointments;
} Calendar;

// Create a new calendar
Calendar *create_calendar() {
    Calendar *calendar = malloc(sizeof(Calendar));
    calendar->appointments = NULL;
    calendar->num_appointments = 0;
    calendar->max_appointments = 10;
    return calendar;
}

// Add an appointment to the calendar
void add_appointment(Calendar *calendar, Appointment *appointment) {
    // Reallocate the appointments array if necessary
    if (calendar->num_appointments == calendar->max_appointments) {
        calendar->appointments = realloc(calendar->appointments, sizeof(Appointment *) * (calendar->max_appointments *= 2));
    }

    // Add the appointment to the array
    calendar->appointments[calendar->num_appointments++] = appointment;
}

// Print the calendar
void print_calendar(Calendar *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        Appointment *appointment = calendar->appointments[i];
        printf("%s: %s - %s\n", appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
    }
}

// Free the calendar
void free_calendar(Calendar *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        free(calendar->appointments[i]->description);
        free(calendar->appointments[i]);
    }
    free(calendar->appointments);
    free(calendar);
}

// Main function
int main() {
    // Create a new calendar
    Calendar *calendar = create_calendar();

    // Add some appointments to the calendar
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->description = "Doctor's appointment";
    appointment1->start_time = time(NULL) + 3600;
    appointment1->end_time = time(NULL) + 4200;
    add_appointment(calendar, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->description = "Meeting with boss";
    appointment2->start_time = time(NULL) + 7200;
    appointment2->end_time = time(NULL) + 8400;
    add_appointment(calendar, appointment2);

    // Print the calendar
    print_calendar(calendar);

    // Free the calendar
    free_calendar(calendar);

    return 0;
}