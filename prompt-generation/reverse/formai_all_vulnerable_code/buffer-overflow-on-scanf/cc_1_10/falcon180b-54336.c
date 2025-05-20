//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    time_t timestamp;
};

void add_appointment(struct appointment *appointments, int *num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments].name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[*num_appointments].date);

    time_t now = time(NULL);
    strftime(appointments[*num_appointments].date, MAX_DATE_LENGTH, "%Y-%m-%d", localtime(&now));
    appointments[*num_appointments].timestamp = now;

    (*num_appointments)++;
}

void print_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].date);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n");
        printf("2. Print appointments\n");
        printf("3. Exit\n");
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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}