//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number (max %d characters): ", MAX_PHONE_LENGTH - 1);
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);

    appointments[num_appointments].appointment_time = time(NULL);
}

void print_appointments(appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    printf("Welcome to the appointment scheduler!\n");

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nWhat would you like to do?\n1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                num_appointments++;
                break;
            case 2:
                print_appointments(appointments, num_appointments);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}