//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 15
#define MAX_TIME_LENGTH 10
#define MAX_NOTES_LENGTH 100

struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char notes[MAX_NOTES_LENGTH];
};

struct appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full. No more appointments can be added.\n");
        return;
    }

    struct appointment new_appt;

    printf("Enter name: ");
    scanf("%s", new_appt.name);

    printf("Enter date (format: MM/DD/YYYY): ");
    scanf("%s", new_appt.date);

    printf("Enter time (format: HH:MM AM/PM): ");
    scanf("%s", new_appt.time);

    printf("Enter notes: ");
    scanf(" %[^\n]", new_appt.notes);

    schedule[num_appointments] = new_appt;
    num_appointments++;

    printf("Appointment added.\n");
}

void view_schedule() {
    if (num_appointments == 0) {
        printf("The schedule is empty.\n");
        return;
    }

    printf("Schedule:\n");
    printf("Name\tDate\t\tTime\tNotes\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", 
            schedule[i].name, schedule[i].date, schedule[i].time, schedule[i].notes);
    }
}

void search_appointment() {
    if (num_appointments == 0) {
        printf("The schedule is empty.\n");
        return;
    }

    char search_term[MAX_NAME_LENGTH];
    bool found = false;

    printf("Enter name to search: ");
    scanf("%s", search_term);

    printf("Search results:\n");
    printf("Name\tDate\t\tTime\tNotes\n");

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(schedule[i].name, search_term) == 0) {
            printf("%s\t%s\t%s\t%s\n", 
                schedule[i].name, schedule[i].date, schedule[i].time, schedule[i].notes);
            found = true;
        }
    }

    if (!found) {
        printf("No appointments found for '%s'.\n", search_term);
    }
}

int main() {
    int choice;

    do {
        printf("Appointment Scheduler\n");
        printf("=====================\n");
        printf("1. Add appointment\n");
        printf("2. View schedule\n");
        printf("3. Search appointment\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_schedule();
                break;
            case 3:
                search_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}