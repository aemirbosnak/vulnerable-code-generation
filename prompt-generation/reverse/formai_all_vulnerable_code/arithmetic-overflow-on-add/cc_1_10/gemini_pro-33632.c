//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment data structure
typedef struct Appointment {
    int id;
    char *desc;
    time_t start;
    time_t end;
} Appointment;

// Function to create a new appointment
Appointment *new_appointment(int id, char *desc, time_t start, time_t end) {
    Appointment *appt = malloc(sizeof(Appointment));
    appt->id = id;
    appt->desc = desc;
    appt->start = start;
    appt->end = end;
    return appt;
}

// Function to print an appointment
void print_appointment(Appointment *appt) {
    printf("Appointment ID: %d\n", appt->id);
    printf("Description: %s\n", appt->desc);
    printf("Start time: %s", ctime(&appt->start));
    printf("End time: %s", ctime(&appt->end));
}

// Function to compare two appointments by start time
int compare_appointments(Appointment *a, Appointment *b) {
    return a->start - b->start;
}

// Function to schedule an appointment
void schedule_appointment(Appointment **appts, int *num_appts, Appointment *appt) {
    // Check for overlapping appointments
    for (int i = 0; i < *num_appts; i++) {
        if (appt->start >= appts[i]->start && appt->start <= appts[i]->end) {
            printf("Error: Appointment overlaps with existing appointment.\n");
            return;
        }
        if (appt->end >= appts[i]->start && appt->end <= appts[i]->end) {
            printf("Error: Appointment overlaps with existing appointment.\n");
            return;
        }
    }

    // Add the new appointment to the array
    appts[*num_appts] = appt;
    (*num_appts)++;

    // Sort the appointments by start time
    qsort(appts, *num_appts, sizeof(Appointment *), (int (*)(const void *, const void *))compare_appointments);

    printf("Appointment scheduled successfully.\n");
}

// Function to cancel an appointment
void cancel_appointment(Appointment **appts, int *num_appts, int id) {
    // Find the appointment by ID
    int index = -1;
    for (int i = 0; i < *num_appts; i++) {
        if (appts[i]->id == id) {
            index = i;
            break;
        }
    }

    // If the appointment was not found, print an error message
    if (index == -1) {
        printf("Error: Appointment not found.\n");
        return;
    }

    // Remove the appointment from the array
    for (int i = index; i < *num_appts - 1; i++) {
        appts[i] = appts[i + 1];
    }
    (*num_appts)--;

    printf("Appointment canceled successfully.\n");
}

// Function to print all appointments
void print_appointments(Appointment **appts, int num_appts) {
    if (num_appts == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        print_appointment(appts[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appts[100];
    int num_appts = 0;

    // Schedule some appointments
    schedule_appointment(appts, &num_appts, new_appointment(1, "Doctor's appointment", time(NULL) + 3600, time(NULL) + 7200));
    schedule_appointment(appts, &num_appts, new_appointment(2, "Meeting with boss", time(NULL) + 10800, time(NULL) + 14400));
    schedule_appointment(appts, &num_appts, new_appointment(3, "Lunch with friend", time(NULL) + 18000, time(NULL) + 21600));

    // Print the appointments
    print_appointments(appts, num_appts);

    // Cancel an appointment
    cancel_appointment(appts, &num_appts, 2);

    // Print the appointments after canceling
    print_appointments(appts, num_appts);

    return 0;
}