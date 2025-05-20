//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_DESCRIPTION_LEN 50
#define MAX_TIME_LEN 8

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char time[MAX_TIME_LEN];
} Appointment;

Appointment appointments[10];
int numAppointments = 0;

int addAppointment(char* name, char* description, char* time) {
    if (numAppointments >= 10) {
        printf("No more appointments can be added.\n");
        return -1;
    }

    strncpy(appointments[numAppointments].name, name, MAX_NAME_LEN);
    strncpy(appointments[numAppointments].description, description, MAX_DESCRIPTION_LEN);
    strncpy(appointments[numAppointments].time, time, MAX_TIME_LEN);

    numAppointments++;
    return 0;
}

int viewAppointments() {
    if (numAppointments == 0) {
        printf("No appointments found.\n");
        return -1;
    }

    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }

    return 0;
}

int deleteAppointment(int index) {
    if (index < 0 || index >= numAppointments) {
        printf("Invalid appointment index.\n");
        return -1;
    }

    for (int i = index; i < numAppointments - 1; i++) {
        strncpy(appointments[i].name, appointments[i + 1].name, MAX_NAME_LEN);
        strncpy(appointments[i].description, appointments[i + 1].description, MAX_DESCRIPTION_LEN);
        strncpy(appointments[i].time, appointments[i + 1].time, MAX_TIME_LEN);
    }

    numAppointments--;
    return 0;
}

int main() {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char time[MAX_TIME_LEN];

    printf("Enter appointment name: ");
    scanf("%s", name);

    printf("Enter appointment description: ");
    scanf("%s", description);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", time);

    addAppointment(name, description, time);

    printf("Appointment added successfully.\n");

    viewAppointments();

    printf("Enter appointment index to delete: ");
    scanf("%d", &index);

    deleteAppointment(index);

    viewAppointments();

    return 0;
}