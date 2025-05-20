//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

// Struct for storing appointment details
struct appointment {
    char name[50];
    int time; // in 24-hr format
    int duration; // in minutes
};

// Array of appointment slots with default availability
bool availability[8][12] = {
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true},
    {true, true, true, true, true, true, true, true, true, true, true, true}
};

// Function to check availability for a given time range
bool check_availability(int day, int start_time, int end_time) {
    for (int i = start_time; i < end_time; i++) {
        if (!availability[day][i]) {
            return false;
        }
    }
    return true;
}

// Function to book an appointment at a given time range
void book_appointment(int day, int start_time, int end_time, struct appointment appt) {
    for (int i = start_time; i < end_time; i++) {
        availability[day][i] = false;
    }
    printf("Appointment booked on %d-%02d-%02d from %d:00 to %d:00 for %s\n",
           2022, 1, day+1, start_time, end_time, appt.name);
}

int main() {
    printf("*** Welcome to Appointment Scheduler ***\n\n");

    // Example appointments
    struct appointment appt1 = {"John Doe", 9, 60};
    struct appointment appt2 = {"Jane Smith", 13, 120};

    // Check availability and book appointments
    if (check_availability(0, 9, 10)) {
        book_appointment(0, 9, 10, appt1);
    } else {
        printf("Sorry, the selected time slot is not available\n");
    }

    if (check_availability(0, 13, 15)) {
        book_appointment(0, 13, 15, appt2);
    } else {
        printf("Sorry, the selected time slot is not available\n");
    }

    return 0;
}