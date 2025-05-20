//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, char* name, char* description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].description, description, MAX_DESCRIPTION_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start Time: %s\n", ctime(&appointments[i].start_time));
        printf("End Time: %s\n", ctime(&appointments[i].end_time));
        printf("\n");
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "Meeting with Boss", "Discuss project progress", time(NULL) + 3600, time(NULL) + 7200);
    add_appointment(appointments, num_appointments, "Lunch with Team", "Discuss new ideas", time(NULL) + 14400, time(NULL) + 18000);

    print_appointments(appointments, num_appointments);

    return 0;
}