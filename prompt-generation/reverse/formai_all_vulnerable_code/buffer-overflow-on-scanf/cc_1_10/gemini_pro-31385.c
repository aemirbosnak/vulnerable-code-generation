//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an appointment
typedef struct {
    char name[50];
    char description[100];
    int start_time;
    int end_time;
} Appointment;

// Function to compare two appointments based on their start time
int compare_appointments(const void *a, const void *b) {
    Appointment *appt1 = (Appointment *)a;
    Appointment *appt2 = (Appointment *)b;
    return appt1->start_time - appt2->start_time;
}

// Function to schedule an appointment
int schedule_appointment(Appointment *appts, int num_appts, Appointment new_appt) {
    // Check for conflicts
    for (int i = 0; i < num_appts; i++) {
        if (new_appt.start_time < appts[i].end_time && new_appt.end_time > appts[i].start_time) {
            printf("Conflict: New appointment overlaps with existing appointment %s\n", appts[i].name);
            return -1;
        }
    }

    // Add the new appointment to the array
    appts[num_appts] = new_appt;

    // Sort the appointments by start time
    qsort(appts, num_appts + 1, sizeof(Appointment), compare_appointments);

    return 0;
}

// Function to print the appointments
void print_appointments(Appointment *appts, int num_appts) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s: %s, %d-%d\n", appts[i].name, appts[i].description, appts[i].start_time, appts[i].end_time);
    }
}

// Main function
int main() {
    // Initialize the array of appointments
    Appointment appts[10];

    // Get the number of appointments
    int num_appts;
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appts);

    // Get the details of each appointment
    for (int i = 0; i < num_appts; i++) {
        printf("Enter the name of appointment %d: ", i + 1);
        scanf(" %s", appts[i].name);
        printf("Enter the description of appointment %d: ", i + 1);
        scanf(" %s", appts[i].description);
        printf("Enter the start time of appointment %d: ", i + 1);
        scanf(" %d", &appts[i].start_time);
        printf("Enter the end time of appointment %d: ", i + 1);
        scanf(" %d", &appts[i].end_time);
    }

    // Schedule the appointments
    for (int i = 0; i < num_appts; i++) {
        int result = schedule_appointment(appts, i, appts[i]);
        if (result == -1) {
            printf("Error: Appointment %s could not be scheduled due to a conflict.\n", appts[i].name);
        }
    }

    // Print the appointments
    print_appointments(appts, num_appts);

    return 0;
}