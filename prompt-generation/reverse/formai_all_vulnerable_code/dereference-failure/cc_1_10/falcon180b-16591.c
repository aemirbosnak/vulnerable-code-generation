//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char *name;
    char *phone;
    char *email;
    int date;
    int time;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment *appointments = malloc(MAX_APPOINTMENTS * sizeof(Appointment));

    char input[MAX_APPOINTMENT_LENGTH];
    while (fgets(input, MAX_APPOINTMENT_LENGTH, stdin)!= NULL) {
        char *name = strtok(input, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, ",");
        int date = atoi(strtok(NULL, ","));
        int time = atoi(strtok(NULL, ","));

        if (num_appointments >= MAX_APPOINTMENTS) {
            printf("Error: too many appointments!\n");
            exit(1);
        }

        appointments[num_appointments].name = strdup(name);
        appointments[num_appointments].phone = strdup(phone);
        appointments[num_appointments].email = strdup(email);
        appointments[num_appointments].date = date;
        appointments[num_appointments].time = time;

        num_appointments++;
    }

    printf("Number of appointments: %d\n", num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Email: %s\n", appointments[i].email);
        printf("Date: %d\n", appointments[i].date);
        printf("Time: %d\n\n", appointments[i].time);
    }

    free(appointments);
    return 0;
}