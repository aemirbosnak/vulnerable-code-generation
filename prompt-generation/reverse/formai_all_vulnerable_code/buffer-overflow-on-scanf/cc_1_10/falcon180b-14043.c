//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
}

void display_appointments(Appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            add_appointment(appointments, num_appointments);
            num_appointments++;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    display_appointments(appointments, num_appointments);

    return 0;
}