//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment *appointments, int *num_appointments) {
    char name[MAX_NAME_LENGTH];
    time_t start_time, end_time;

    printf("Enter name: ");
    scanf("%s", name);
    strcpy(appointments[*num_appointments].name, name);

    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);
    appointments[*num_appointments].start_time = start_time;

    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);
    appointments[*num_appointments].end_time = end_time;

    (*num_appointments)++;
}

void print_appointments(appointment *appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, &num_appointments);

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Do you want to add another appointment? (y/n): ");
        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, "y") == 0) {
            add_appointment(appointments, &num_appointments);
        } else {
            break;
        }
    }

    print_appointments(appointments, num_appointments);

    return 0;
}