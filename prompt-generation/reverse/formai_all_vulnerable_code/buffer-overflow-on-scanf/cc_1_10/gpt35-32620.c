//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    Time startTime;
    Time endTime;
} AppointmentTime;

typedef struct {
    char name[50];
    AppointmentTime time;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments;
} Schedule;

void inputTime(Time *t);
void printTime(Time t);
bool compareTime(Time t1, Time t2);
bool isTimeAvailable(Time startTime, Time endTime, Schedule *schedule);
void addAppointment(Appointment appt, Schedule *schedule);
void printSchedule(Schedule schedule);
void deleteAppointment(char *name, Schedule *schedule);

int main() {
    Schedule schedule;
    schedule.numAppointments = 0;
    int input;

    do {
        printf("\n\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Schedule\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                Appointment appt;
                printf("\nAdd Appointment\n");
                printf("Enter your name: ");
                scanf("%s", appt.name);
                printf("Enter start time:\n");
                inputTime(&appt.time.startTime);
                printf("Enter end time:\n");
                inputTime(&appt.time.endTime);
                if (isTimeAvailable(appt.time.startTime, appt.time.endTime, &schedule)) {
                    addAppointment(appt, &schedule);
                    printf("\nAppointment added successfully.\n");
                } else {
                    printf("\nThis time slot is not available.\n");
                }
                break;
            }
            case 2: {
                printf("\nView Schedule\n");
                printSchedule(schedule);
                break;
            }
            case 3: {
                printf("\nDelete Appointment\n");
                char name[50];
                printf("Enter your name: ");
                scanf("%s", name);
                deleteAppointment(name, &schedule);
                break;
            }
            case 4: {
                printf("\nExiting Appointment Scheduler.\n");
                break;
            }
            default: {
                printf("\nInvalid input. Please try again.\n");
                break;
            }
        }
    } while (input != 4);

    return 0;
}

void inputTime(Time *t) {
    printf("Hour (0-23): ");
    scanf("%d", &t->hour);
    printf("Minute (0-59): ");
    scanf("%d", &t->minute);
}

void printTime(Time t) {
    printf("%02d:%02d", t.hour, t.minute);
}

bool compareTime(Time t1, Time t2) {
    if (t1.hour == t2.hour && t1.minute == t2.minute) {
        return true;
    } else {
        return false;
    }
}

bool isTimeAvailable(Time startTime, Time endTime, Schedule *schedule) {
    for (int i = 0; i < schedule->numAppointments; i++) {
        if (compareTime(startTime, schedule->appointments[i].time.startTime)
            || (compareTime(endTime, schedule->appointments[i].time.endTime))
            || (startTime.hour < schedule->appointments[i].time.endTime.hour
            && startTime.minute < schedule->appointments[i].time.endTime.minute
            && endTime.hour > schedule->appointments[i].time.startTime.hour
            && endTime.minute > schedule->appointments[i].time.startTime.minute)) {
            return false; // Not available
        }
    }
    return true;
}

void addAppointment(Appointment appt, Schedule *schedule) {
    schedule->appointments[schedule->numAppointments] = appt;
    schedule->numAppointments++;
}

void printSchedule(Schedule schedule) {
    if (schedule.numAppointments == 0) {
        printf("\nNo appointments currently scheduled.\n");
    } else {
        printf("\nScheduled Appointments:\n");
        for (int i = 0; i < schedule.numAppointments; i++) {
            printf("Name: %s\n", schedule.appointments[i].name);
            printf("Start Time: ");
            printTime(schedule.appointments[i].time.startTime);
            printf("\n");
            printf("End Time: ");
            printTime(schedule.appointments[i].time.endTime);
            printf("\n\n");
        }
    }
}

void deleteAppointment(char *name, Schedule *schedule) {
    bool found = false;
    for (int i = 0; i < schedule->numAppointments; i++) {
        if (strcmp(schedule->appointments[i].name, name) == 0) {
            found = true;
            for (int j = i; j < schedule->numAppointments - 1; j++) {
                schedule->appointments[j] = schedule->appointments[j + 1];
            }
            schedule->numAppointments--;
            printf("\nAppointment deleted successfully.\n");
        }
    }
    if (!found) {
        printf("\nNo appointment found with name '%s'\n", name);
    }
}