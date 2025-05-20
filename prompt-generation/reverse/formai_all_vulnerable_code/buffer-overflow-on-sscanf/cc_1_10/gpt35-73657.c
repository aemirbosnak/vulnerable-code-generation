//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

appointment appointments[MAX_APPOINTMENTS];

int num_appointments = 0;

void add_appointment(char* name, int year, int month, int day, int hour, int minute) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Cannot add appointment, maximum appointments reached.\n");
        return;
    }
    appointment new_appt;
    strncpy(new_appt.name, name, MAX_NAME_LENGTH);
    new_appt.name[MAX_NAME_LENGTH-1] = '\0';
    new_appt.year = year;
    new_appt.month = month;
    new_appt.day = day;
    new_appt.hour = hour;
    new_appt.minute = minute;
    appointments[num_appointments] = new_appt;
    num_appointments++;
    printf("Appointment added for %s on %d/%d/%d at %d:%02d.\n", name, day, month, year, hour, minute);
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        appointment appt = appointments[i];
        printf("%s: %d/%d/%d at %d:%02d\n", appt.name, appt.day, appt.month, appt.year, appt.hour, appt.minute);
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler.\n");
    printf("Type 'quit' to exit or 'help' for a list of commands.\n");

    while(true) {
        char input[MAX_NAME_LENGTH];
        printf("> ");
        fgets(input, MAX_NAME_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "quit") == 0) {
            printf("Exiting.\n");
            break;
        } else if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  add <name> <year> <month> <day> <hour> <minute>\n");
            printf("  list\n");
            printf("  help\n");
            printf("  quit\n");
        } else if (strncmp(input, "add", 3) == 0) {
            char name[MAX_NAME_LENGTH];
            int year, month, day, hour, minute;
            if (sscanf(input, "add %s %d %d %d %d %d", name, &year, &month, &day, &hour, &minute) == 6) {
                add_appointment(name, year, month, day, hour, minute);
            } else {
                printf("Invalid add command. Please enter in the format: 'add <name> <year> <month> <day> <hour> <minute>'.\n");
            }
        } else if (strcmp(input, "list") == 0) {
            print_appointments();
        } else {
            printf("Unknown command. Type 'help' for a list of valid commands.\n");
        }
    }

    return 0;
}