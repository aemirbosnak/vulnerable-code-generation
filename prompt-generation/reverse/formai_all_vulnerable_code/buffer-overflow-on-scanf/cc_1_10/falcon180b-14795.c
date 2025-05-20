//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int appointment_duration;
    int reminder_minutes;
    char reminder_type;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter the email of the appointment: ");
    scanf("%s", appointments[num_appointments].email);
    printf("Enter the phone number of the appointment: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
    printf("Enter the appointment duration in minutes: ");
    scanf("%d", &appointments[num_appointments].appointment_duration);
    printf("Enter the reminder time in minutes: ");
    scanf("%d", &appointments[num_appointments].reminder_minutes);
    printf("Enter the reminder type (SMS/Email): ");
    scanf(" %c", &appointments[num_appointments].reminder_type);
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Name\tEmail\tPhone\tAppointment Time\tAppointment Duration\tReminder Time\tReminder Type\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\t%d\t%d\t%c\n", appointments[i].name, appointments[i].email, appointments[i].phone, ctime(&appointments[i].appointment_time), appointments[i].appointment_duration, appointments[i].reminder_minutes, appointments[i].reminder_type);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment, 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_appointment(appointments, num_appointments);
            num_appointments++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    display_appointments(appointments, num_appointments);

    return 0;
}