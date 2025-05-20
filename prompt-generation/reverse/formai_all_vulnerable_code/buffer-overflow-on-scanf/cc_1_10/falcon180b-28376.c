//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char date[11];
    char time[9];
};

void add_appointment(struct appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void display_appointments(struct appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s - %s\n", appointments[i].name, appointments[i].phone, appointments[i].date, appointments[i].time);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nDo you want to add an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_appointment(appointments, num_appointments);
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    display_appointments(appointments, num_appointments);

    return 0;
}