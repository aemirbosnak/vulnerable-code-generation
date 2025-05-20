//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t appointment_time;
    int duration;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char* name, time_t appointment_time, int duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("I'm sorry, but I can't schedule any more appointments right now.\n");
        return;
    }
    
    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].duration = duration;
    
    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("I'm sorry, but I don't have any appointments scheduled right now.\n");
    } else {
        printf("Upcoming appointments:\n");
        for (int i = 0; i < num_appointments; i++) {
            char appointment_time_string[100];
            strftime(appointment_time_string, 100, "%Y-%m-%d %H:%M:%S", localtime(&appointments[i].appointment_time));
            printf("%s - %s (%d minutes)\n", appointments[i].name, appointment_time_string, appointments[i].duration);
        }
    }
}

int main() {
    srand(time(NULL));
    
    add_appointment("My Love", time(NULL) + rand() % 86400, 60);
    add_appointment("My Sweetheart", time(NULL) + rand() % 86400, 120);
    add_appointment("My Darling", time(NULL) + rand() % 86400, 180);
    
    print_appointments();
    
    return 0;
}