//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

void add_appointment(appointment *appointments, int num_appointments) {
    printf("Enter name for appointment (%d/%d): ", num_appointments + 1, MAX_APPOINTMENTS);
    scanf("%s", appointments[num_appointments].name);

    printf("Enter date for appointment (%s) (dd/mm/yyyy): ", appointments[num_appointments].name);
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time for appointment (%s) (hh:mm): ", appointments[num_appointments].name);
    scanf("%s", appointments[num_appointments].time);
}

void display_appointments(appointment *appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s - %s - %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nEnter 'a' to add an appointment or 'd' to display appointments: ");
        char choice = toupper(getchar());

        if (choice == 'A') {
            add_appointment(appointments, num_appointments);
            num_appointments++;
        } else if (choice == 'D') {
            display_appointments(appointments, num_appointments);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}