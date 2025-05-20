//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 10

// Struct for holding appointment data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

// Function for displaying all appointments in the schedule
void displaySchedule(Appointment schedule[]) {
    printf("Here is the current schedule:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (schedule[i].name[0] != '\0') {
            printf("%d:%02d - %s\n", schedule[i].hour, schedule[i].minute, schedule[i].name);
        }
    }
    printf("\n");
}

// Function for adding an appointment to the schedule
void addAppointment(Appointment schedule[], char inputName[], int inputHour, int inputMinute) {
    int openIndex = -1;
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (schedule[i].name[0] == '\0' && openIndex == -1) {
            openIndex = i;
        }
        if (strcmp(schedule[i].name, inputName) == 0 &&
            schedule[i].hour == inputHour &&
            schedule[i].minute == inputMinute) {
            printf("There is already an appointment for that time and name.\n\n");
            return;
        }
    }
    if (openIndex == -1) {
        printf("Sorry, the schedule is full right now. Try again later.\n\n");
        return;
    }
    strcpy(schedule[openIndex].name, inputName);
    schedule[openIndex].hour = inputHour;
    schedule[openIndex].minute = inputMinute;
    printf("Appointment added successfully.\n\n");
}

int main() {
    Appointment schedule[MAX_APPOINTMENTS];
    memset(schedule, 0, sizeof(Appointment) * MAX_APPOINTMENTS);
    bool running = true;
    while (running) {
        printf("Enter a command (add, display, quit): ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char inputName[MAX_NAME_LENGTH];
            int inputHour, inputMinute;
            printf("Enter the name for the appointment: ");
            scanf("%s", inputName);
            printf("Enter the hour for the appointment: ");
            scanf("%d", &inputHour);
            printf("Enter the minute for the appointment: ");
            scanf("%d", &inputMinute);
            addAppointment(schedule, inputName, inputHour, inputMinute);
        } else if (strcmp(input, "display") == 0) {
            displaySchedule(schedule);
        } else if (strcmp(input, "quit") == 0) {
            printf("Quitting now. Goodbye!\n");
            running = false;
        }
    }
    return 0;
}