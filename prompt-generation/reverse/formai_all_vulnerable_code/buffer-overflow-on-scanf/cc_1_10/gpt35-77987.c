//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Struct representing an appointment
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char* description;
} Appointment;

// Check if two appointments are conflicting
bool is_conflicting(Appointment a1, Appointment a2) {
    if (a1.year != a2.year || a1.month != a2.month || a1.day != a2.day) {
        return false;
    }

    int a1_hour = a1.hour * 60 + a1.minute;
    int a2_hour = a2.hour * 60 + a2.minute;

    return abs(a1_hour - a2_hour) < 30;
}

// Print out an appointment
void print_appointment(Appointment appt) {
    printf("%02d/%02d/%04d at %02d:%02d - %s\n", appt.day, appt.month, appt.year, appt.hour, appt.minute, appt.description);
}

// Main function
int main() {
    int num_appointments;
    printf("How many appointments do you want to schedule? ");
    scanf("%d", &num_appointments);

    Appointment appts[num_appointments];

    // Get appointment information
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i+1);

        // Date
        printf("Enter the date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &appts[i].day, &appts[i].month, &appts[i].year);

        // Time
        printf("Enter the time (HH:MM): ");
        scanf("%d:%d", &appts[i].hour, &appts[i].minute);

        // Description
        printf("Enter the description: ");
        scanf("%s", appts[i].description);

        // Check for conflicts with existing appointments
        for (int j = 0; j < i; j++) {
            if (is_conflicting(appts[i], appts[j])) {
                printf("Error: Appointment conflicts with existing appointment:\n");
                print_appointment(appts[j]);
                i--;  // Decrease the i index to try again
                break;
            }
        }
    }

    // Print out all the appointments
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appts[i]);
    }

    return 0;
}