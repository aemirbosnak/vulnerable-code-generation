//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct appointment {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment *appointments, int num_appointments, char *name, char *email, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].email, email, MAX_EMAIL_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

void print_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s)\n%s - %s\n\n", appointments[i].name, appointments[i].email, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH] = "";
    char email[MAX_EMAIL_LENGTH] = "";
    time_t start_time, end_time;

    while (1) {
        printf("\nEnter name: ");
        scanf("%s", name);

        printf("Enter email: ");
        scanf("%s", email);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&start_time));

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&end_time));

        add_appointment(appointments, num_appointments, name, email, start_time, end_time);
    }

    return 0;
}