//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    int status; // 0 = available, 1 = booked
} appointment;

void print_appointments(appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s %s %s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].status? "Booked" : "Available");
    }
}

int main() {
    appointment* appointments = NULL;
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", appointments[num_appointments].name);

        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", appointments[num_appointments].date);

        printf("Enter time (HH:MM): ");
        scanf("%s", appointments[num_appointments].time);

        int status;
        do {
            printf("Enter status (0 = available, 1 = booked): ");
            scanf("%d", &status);
        } while (status < 0 || status > 1);

        appointments[num_appointments].status = status;
        num_appointments++;
    }

    print_appointments(appointments, num_appointments);

    return 0;
}