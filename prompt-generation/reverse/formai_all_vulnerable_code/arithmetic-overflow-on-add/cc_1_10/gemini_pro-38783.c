//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 250

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    char description[MAX_DESCRIPTION_LENGTH+1];
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

void remove_appointment(int index) {
    if (index < 0 || index >= num_appointments) {
        printf("Error: Invalid index.\n");
        return;
    }
    for (int i = index; i < num_appointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    num_appointments--;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s (%s)\n", i+1, appointments[i].name, appointments[i].description);
        printf("    Start: %s\n", ctime(&appointments[i].start_time));
        printf("    End: %s\n", ctime(&appointments[i].end_time));
    }
}

int main() {
    // Start by adding some appointments.
    add_appointment("Doctor's appointment", "Annual checkup", time(NULL)+3600, time(NULL)+7200);
    add_appointment("Meeting with boss", "Discuss project", time(NULL)+86400, time(NULL)+90000);
    add_appointment("Dinner with friends", "Celebrate birthday", time(NULL)+172800, time(NULL)+180000);

    // Print the appointments.
    printf("Current appointments:\n");
    print_appointments();

    // Add a new appointment.
    char name[MAX_NAME_LENGTH+1];
    char description[MAX_DESCRIPTION_LENGTH+1];
    time_t start_time;
    time_t end_time;
    printf("Enter the name of the new appointment: ");
    scanf("%s", name);
    printf("Enter the description of the new appointment: ");
    scanf(" %[^\n]s", description);
    printf("Enter the start time of the new appointment (YYYY-MM-DD HH:MM): ");
    scanf(" %d-%d-%d %d:%d", &start_time, &end_time);
    add_appointment(name, description, start_time, end_time);

    // Print the appointments again.
    printf("Updated appointments:\n");
    print_appointments();

    // Remove an appointment.
    int index;
    printf("Enter the index of the appointment to remove: ");
    scanf("%d", &index);
    remove_appointment(index);

    // Print the appointments again.
    printf("Updated appointments:\n");
    print_appointments();

    return 0;
}