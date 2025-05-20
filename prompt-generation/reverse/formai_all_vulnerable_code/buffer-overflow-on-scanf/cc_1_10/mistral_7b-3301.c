//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define APPT_NAME_LEN 50
#define APPT_TIME_LEN 10

struct Appointment {
    char name[APPT_NAME_LEN];
    struct tm time;
};

typedef struct Appointment Appointment;

void print_cyberpunk_banner() {
    printf("\x1b[1;31m-----------------------------------------------------\n");
    printf("\x1b[1;31m|             Cyberpunk Appointment Scheduler           |\n");
    printf("\x1b[1;31m|-----------------------------------------------------|\n");
}

void print_menu() {
    printf("\x1b[1;33m[1] Add Appointment\n");
    printf("\x1b[1;33m[2] Delete Appointment\n");
    printf("\x1b[1;33m[3] List Appointments\n");
    printf("\x1b[1;33m[4] Exit\n");
}

void add_appointment(Appointment appointments[], int *num_appointments, char *name, int hour, int minute) {
    if (*num_appointments >= MAX_APPOINTMENTS) {
        printf("\x1b[1;31mError: Maximum number of appointments reached!\n");
        return;
    }

    strcpy(appointments[*num_appointments].name, name);
    appointments[*num_appointments].time.tm_hour = hour;
    appointments[*num_appointments].time.tm_min = minute;
    appointments[*num_appointments].time.tm_sec = 0;
    appointments[*num_appointments].time.tm_isdst = -1;

    (*num_appointments)++;
}

void delete_appointment(Appointment appointments[], int *num_appointments, char *name) {
    int i;

    for (i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            memmove(&appointments[i], &appointments[i + 1], sizeof(Appointment) * (*num_appointments - i - 1));
            (*num_appointments)--;
            break;
        }
    }
}

void list_appointments(Appointment appointments[], int num_appointments) {
    int i;

    printf("\x1b[1;35mListing Appointments:\n");

    for (i = 0; i < num_appointments; i++) {
        printf("\x1b[1;32m%s: ", appointments[i].name);
        printf("\x1b[1;36m%02d:%02d\n", appointments[i].time.tm_hour, appointments[i].time.tm_min);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char name[APPT_NAME_LEN];
    int hour, minute;
    int choice;

    print_cyberpunk_banner();

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\x1b[1;34mEnter appointment name: ");
                scanf("%s", name);
                printf("\x1b[1;34mEnter hour: ");
                scanf("%d", &hour);
                printf("\x1b[1;34mEnter minute: ");
                scanf("%d", &minute);
                add_appointment(appointments, &num_appointments, name, hour, minute);
                break;
            case 2:
                printf("\x1b[1;34mEnter appointment name to delete: ");
                scanf("%s", name);
                delete_appointment(appointments, &num_appointments, name);
                break;
            case 3:
                list_appointments(appointments, num_appointments);
                break;
            case 4:
                printf("\x1b[1;31mExiting...\n");
                exit(0);
            default:
                printf("\x1b[1;31mInvalid choice!\n");
        }
    }

    return 0;
}