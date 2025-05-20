//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
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
} Appointment;

void add_appointment(Appointment* appointments, int* num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[*num_appointments].phone);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[*num_appointments].appointment_time);
    (*num_appointments)++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Name\tPhone\tAppointment Time\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                print_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}