//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment_t;

void add_appointment(appointment_t* appointments, int num_appointments, char* name, char* description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(appointment_t* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (%s - %s)\n", appointments[i].name, appointments[i].description, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

void remove_appointment(appointment_t* appointments, int num_appointments, int index) {
    if (index >= num_appointments) {
        printf("Error: Invalid appointment index.\n");
        return;
    }

    num_appointments--;
    for (int i = index; i < num_appointments; i++) {
        appointments[i] = appointments[i+1];
    }
}

int main() {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time, end_time;

    while (1) {
        printf("1. Add appointment\n2. Print appointments\n3. Remove appointment\n4. Exit\n");
        scanf("%d", &num_appointments);

        switch (num_appointments) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&start_time));
            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&end_time));

            add_appointment(appointments, num_appointments, name, description, start_time, end_time);
            break;

        case 2:
            print_appointments(appointments, num_appointments);
            break;

        case 3:
            printf("Enter appointment index to remove: ");
            scanf("%d", &num_appointments);

            remove_appointment(appointments, num_appointments, num_appointments-1);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}