//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    time_t appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter email: ");
    scanf("%s", appointments[num_appointments].email);

    printf("Enter appointment time (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", appointments[num_appointments].appointment_time);
}

void display_appointments(appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment time: %s\n\n", appointments[i].appointment_time);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            add_appointment(appointments, num_appointments);
            num_appointments++;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printf("Appointments:\n");
    display_appointments(appointments, num_appointments);

    return 0;
}