//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int start_hour;
    int end_hour;
};

struct appointment appointment_list[MAX_APPOINTMENTS];
int number_of_appointments = 0;

void add_appointment(struct appointment app) {
    if (number_of_appointments < MAX_APPOINTMENTS) {
        appointment_list[number_of_appointments++] = app;
        printf("Appointment added for %s on day %d from %d:00 to %d:00\n", app.name, app.day, app.start_hour, app.end_hour);
    } else {
        printf("Maximum number of appointments reached!\n");
    }
}

void print_appointments() {
    if (number_of_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("Scheduled Appointments:\n");
        for (int i = 0; i < number_of_appointments; i++) {
            printf("%d. %s on day %d from %d:00 to %d:00\n", i+1, appointment_list[i].name, appointment_list[i].day, appointment_list[i].start_hour, appointment_list[i].end_hour);
        }
    }
}

int main() {
    while (1) {
        char action[10];
        printf("\nWhat would you like to do (add/print/exit)? ");
        scanf("%s", action);

        if(strcmp(action, "add") == 0) {
            struct appointment app;
            printf("\nEnter Name: ");
            scanf("%s", app.name);
            printf("Enter Day: ");
            scanf("%d", &app.day);
            printf("Enter Start Hour: ");
            scanf("%d", &app.start_hour);
            printf("Enter End Hour: ");
            scanf("%d", &app.end_hour);
            add_appointment(app);
        } else if (strcmp(action, "print") == 0) {
            print_appointments();
        } else if (strcmp(action, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option!\n");
        }
    }
    return 0;
}