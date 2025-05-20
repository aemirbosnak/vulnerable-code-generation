//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DURATION 120 // 2 hours

// Struct to hold appointment details
typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;
} Appointment;

// Function to compare appointment start times
int compare_start_times(const void *a, const void *b) {
    const Appointment *appointment_a = (const Appointment *)a;
    const Appointment *appointment_b = (const Appointment *)b;

    return difftime(appointment_a->start_time, appointment_b->start_time);
}

// Function to print appointments in a human-readable format
void print_appointments(Appointment appointments[], int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (%d minutes)\n", appointments[i].name, ctime(&appointments[i].start_time), appointments[i].duration);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize appointments array
    Appointment appointments[MAX_APPOINTMENTS];
    memset(appointments, 0, sizeof(appointments));

    // Add some sample appointments
    strcpy(appointments[0].name, "Meeting with John");
    appointments[0].start_time = time(NULL) + (rand() % 3600); // Random start time between now and 1 hour from now
    appointments[0].duration = rand() % MAX_DURATION + 1;

    strcpy(appointments[1].name, "Lunch with Jane");
    appointments[1].start_time = time(NULL) + (rand() % 3600);
    appointments[1].duration = rand() % MAX_DURATION + 1;

    int num_appointments = 2;

    // Sort appointments by start time
    qsort(appointments, num_appointments, sizeof(Appointment), compare_start_times);

    // Print appointments
    print_appointments(appointments, num_appointments);

    return 0;
}