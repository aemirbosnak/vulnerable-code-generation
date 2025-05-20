//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
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
        printf("%s - %s\n", ctime(&appointments[i].start_time), appointments[i].description);
    }
}

int main() {
    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);

    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (1) {
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter appointment description: ");
        scanf("%s", description);

        time_t start_time = mktime(time_info) + 60 * 60; // one hour from now
        time_t end_time = start_time + 60 * 60; // one hour duration

        add_appointment(appointments, num_appointments, name, description, start_time, end_time);

        print_appointments(appointments, num_appointments);

        printf("\nPress enter to add another appointment or type 'exit' to quit.\n");
        char input[MAX_NAME_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}