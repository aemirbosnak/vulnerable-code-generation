//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20
#define MAX_TIME_LENGTH 8

typedef struct {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

bool is_valid_time(const char* time) {
    if (strlen(time) != 5) {
        return false;
    }
    for (int i = 0; i < strlen(time); i++) {
        if (i == 2) {
            if (time[i] != ':') {
                return false;
            }
        } else {
            if (!isdigit(time[i])) {
                return false;
            }
        }
    }
    int hour = atoi(strtok(strdup(time), ":"));
    int minute = atoi(strtok(NULL, ":"));
    if (hour < 0 || hour > 23) {
        return false;
    }
    if (minute < 0 || minute > 59) {
        return false;
    }
    return true;
}

void add_appointment(Appointment* appointments, int* num_appointments) {
    if (*num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full.\n");
        return;
    }
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[*num_appointments].name);
    clear_input_buffer();
    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", appointments[*num_appointments].time);
    clear_input_buffer();
    if (!is_valid_time(appointments[*num_appointments].time)) {
        printf("Sorry, that is not a valid time.\n");
        return;
    }
    (*num_appointments)++;
    printf("Appointment added to the schedule.\n");
}

void cancel_appointment(Appointment* appointments, int* num_appointments) {
    printf("Enter the name of the appointment to cancel: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    clear_input_buffer();
    bool appointment_found = false;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            appointment_found = true;
            for (int j = i + 1; j < *num_appointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            (*num_appointments)--;
            printf("Appointment cancelled.\n");
            break;
        }
    }
    if (!appointment_found) {
        printf("Appointment not found.\n");
    }
}

void print_schedule(const Appointment* appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("The schedule is empty.\n");
        return;
    }
    printf("%-20s %s\n", "Name", "Time");
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %s\n", appointments[i].name, appointments[i].time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char command;
    do {
        printf("Enter a command (A)dd, (C)ancel, (P)rint, (Q)uit: ");
        scanf("%c", &command);
        clear_input_buffer();
        switch (toupper(command)) {
            case 'A':
                add_appointment(appointments, &num_appointments);
                break;
            case 'C':
                cancel_appointment(appointments, &num_appointments);
                break;
            case 'P':
                print_schedule(appointments, num_appointments);
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Sorry, that is not a valid command.\n");
        }
    } while (toupper(command) != 'Q');
    return 0;
}