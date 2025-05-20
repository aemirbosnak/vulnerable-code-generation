//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char phone[15];
    char date[10];
    char time[9];
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);
}

void print_appointments(appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s - %s\n", appointments[i].name, appointments[i].phone, appointments[i].date, appointments[i].time);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Add appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_appointment(appointments, num_appointments);
            num_appointments++;
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid input\n");
        }
    }

    printf("Appointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}