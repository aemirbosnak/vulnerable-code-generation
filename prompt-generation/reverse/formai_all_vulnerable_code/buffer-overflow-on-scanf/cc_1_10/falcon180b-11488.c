//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    time_t appointment_time;
} Appointment;

void add_appointment(Appointment *appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter email: ");
    scanf("%s", appointments[num_appointments].email);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
    struct tm *appt_tm = localtime(&appointments[num_appointments].appointment_time);
    printf("Appointment scheduled for %s", asctime(appt_tm));
}

void view_appointments(Appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\n", appointments[i].name);
        printf("%s\n", appointments[i].phone);
        printf("%s\n", appointments[i].email);
        struct tm *appt_tm = localtime(&appointments[i].appointment_time);
        printf("Appointment scheduled for %s\n\n", asctime(appt_tm));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        int choice;
        printf("1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                num_appointments++;
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}