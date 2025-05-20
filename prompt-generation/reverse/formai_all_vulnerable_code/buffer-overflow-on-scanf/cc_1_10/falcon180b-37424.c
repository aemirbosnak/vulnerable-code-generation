//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

void print_appointment(appointment* a) {
    printf("%s - %s (%s @ %s)\n", a->name, a->description, a->date, a->time);
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[MAX_DESCRIPTION_LENGTH];
    time_t current_time;
    struct tm* time_info;
    char date_buffer[MAX_DATE_LENGTH];
    char time_buffer[MAX_TIME_LENGTH];

    while(1) {
        printf("Enter an appointment (or 'q' to quit):\n");
        scanf("%s", input);

        if(strcmp(input, "q") == 0) {
            break;
        }

        strcpy(appointments[num_appointments].name, "Unknown");
        strcpy(appointments[num_appointments].description, input);
        strcpy(appointments[num_appointments].date, "");
        strcpy(appointments[num_appointments].time, "");

        time(&current_time);
        time_info = localtime(&current_time);

        strftime(date_buffer, MAX_DATE_LENGTH, "%Y-%m-%d", time_info);
        strftime(time_buffer, MAX_TIME_LENGTH, "%H:%M", time_info);

        strcpy(appointments[num_appointments].date, date_buffer);
        strcpy(appointments[num_appointments].time, time_buffer);

        num_appointments++;
    }

    printf("Appointments:\n");
    for(int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}