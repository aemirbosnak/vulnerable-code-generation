//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
} Appointment;

int main() {
    int num_appointments;
    Appointment appointments[MAX_APPOINTMENTS];

    // Get number of appointments from user
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    // Get appointment details from user
    for (int i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter phone number for appointment %d: ", i+1);
        scanf("%s", appointments[i].phone_number);

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_time);
    }

    // Sort appointments by appointment time
    for (int i = 0; i < num_appointments-1; i++) {
        for (int j = i+1; j < num_appointments; j++) {
            if (difftime(appointments[i].appointment_time, appointments[j].appointment_time) > 0) {
                Appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }

    // Print appointments
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\nPhone Number: %s\nAppointment Time: %s\n\n", appointments[i].name, appointments[i].phone_number, ctime(&appointments[i].appointment_time));
    }

    return 0;
}