//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments, char* name, int year, int month, int day, int hour, int minute) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strcpy(appointments[numAppointments].name, name);
    appointments[numAppointments].year = year;
    appointments[numAppointments].month = month;
    appointments[numAppointments].day = day;
    appointments[numAppointments].hour = hour;
    appointments[numAppointments].minute = minute;

    numAppointments++;
}

void printAppointment(Appointment appointment) {
    printf("%s - %04d-%02d-%02d %02d:%02d\n", appointment.name, appointment.year, appointment.month, appointment.day, appointment.hour, appointment.minute);
}

void printAppointments(Appointment* appointments, int numAppointments) {
    printf("Upcoming Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
    }
}

int main() {
    time_t now;
    struct tm* currentTime;

    time(&now);
    currentTime = localtime(&now);

    int year = currentTime->tm_year + 1900;
    int month = currentTime->tm_mon + 1;
    int day = currentTime->tm_mday;
    int hour = currentTime->tm_hour;
    int minute = currentTime->tm_min;

    printf("Current date and time: %04d-%02d-%02d %02d:%02d\n", year, month, day, hour, minute);

    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    addAppointment(appointments, numAppointments, "Meeting with Boss", 2021, 12, 15, 10, 0);
    addAppointment(appointments, numAppointments, "Doctor's Appointment", 2021, 12, 20, 14, 30);

    printAppointments(appointments, numAppointments);

    return 0;
}