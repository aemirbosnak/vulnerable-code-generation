//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct appointment {
    char name[100];
    char date[20];
    char time[20];
    int duration;
};

int main() {
    struct appointment appointments[10];
    int n = 10;

    for (int i = 0; i < n; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].date[0] = '\0';
        appointments[i].time[0] = '\0';
        appointments[i].duration = 0;
    }

    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[0].name);

    printf("Enter the date of the appointment: ");
    scanf("%s", appointments[0].date);

    printf("Enter the time of the appointment: ");
    scanf("%s", appointments[0].time);

    appointments[0].duration = 60; // default duration of 1 hour

    for (int i = 1; i < n; i++) {
        printf("Enter the name of the %dth appointment: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the date of the %dth appointment: ", i+1);
        scanf("%s", appointments[i].date);

        printf("Enter the time of the %dth appointment: ", i+1);
        scanf("%s", appointments[i].time);

        appointments[i].duration = 60; // default duration of 1 hour
    }

    printf("Appointments:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s on %s at %s for %dh hours\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
    }

    return 0;
}