//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void addAppointment(char *name, int day, int time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("No more appointments available.\n");
        return;
    }
    
    Appointment appt = {0};
    strcpy(appt.name, name);
    appt.day = day;
    appt.time = time;
    
    appointments[num_appointments++] = appt;
}

void printAppointments() {
    printf("Appointments:\n");
    printf("------------------------------------------------\n");
    printf("|      Name      |      Day      |      Time     |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("| %14s | %14d | %14d |\n", appointments[i].name, appointments[i].day, appointments[i].time);
    }
}

void searchAppointments(char *name) {
    bool found = false;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("%s's appointment is on day %d at time %d.\n", name, appointments[i].day, appointments[i].time);
            found = true;
        }
    }
    if (!found) {
        printf("No appointment found for %s.\n", name);
    }
}

int main() {
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    int day, time;
    
    while (1) {
        printf("\n\n");
        printf("Appointment Scheduler\n");
        printf("----------------------\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Search for Appointment\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice.\n");
            continue;
        }
        
        if (choice == 1) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter day: ");
            scanf("%d", &day);
            printf("Enter time: ");
            scanf("%d", &time);
            addAppointment(name, day, time);
        } else if (choice == 2) {
            printAppointments();
        } else if (choice == 3) {
            printf("Enter name: ");
            scanf("%s", name);
            searchAppointments(name);
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}