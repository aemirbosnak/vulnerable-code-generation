//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int month;
    int day;
    int year;
    int hour;
    int min;
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter email: ");
    scanf("%s", appointments[numAppointments].email);
    printf("Enter month: ");
    scanf("%d", &appointments[numAppointments].month);
    printf("Enter day: ");
    scanf("%d", &appointments[numAppointments].day);
    printf("Enter year: ");
    scanf("%d", &appointments[numAppointments].year);
    printf("Enter hour: ");
    scanf("%d", &appointments[numAppointments].hour);
    printf("Enter minute: ");
    scanf("%d", &appointments[numAppointments].min);
    numAppointments++;
}

void displayAppointments(Appointment* appointments, int numAppointments) {
    printf("Name\tEmail\tDate\tTime\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\t%d-%02d-%02d\t%02d:%02d\n",
               appointments[i].name, appointments[i].email,
               appointments[i].year, appointments[i].month, appointments[i].day,
               appointments[i].hour, appointments[i].min);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    srand(time(NULL));
    for (int i = 0; i < MAX_APPOINTMENTS && numAppointments < MAX_APPOINTMENTS; i++) {
        int randomYear = rand() % 2022 + 2020;
        int randomMonth = rand() % 12 + 1;
        int randomDay = rand() % 28 + 1;
        int randomHour = rand() % 24;
        int randomMin = rand() % 60;

        addAppointment(appointments, numAppointments);
    }

    displayAppointments(appointments, numAppointments);

    return 0;
}