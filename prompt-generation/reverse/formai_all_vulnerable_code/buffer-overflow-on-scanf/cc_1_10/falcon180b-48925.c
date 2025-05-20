//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TIME 24*60

struct appointment {
    char name[50];
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
};

void add_appointment(struct appointment appointments[], int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter start time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].start_hour, &appointments[num_appointments].start_min);

    printf("Enter end time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].end_hour, &appointments[num_appointments].end_min);

    num_appointments++;
}

void print_appointments(struct appointment appointments[], int num_appointments) {
    printf("Name\tStart Time\tEnd Time\n");
    for(int i=0; i<num_appointments; i++) {
        printf("%s\t%02d:%02d\t%02d:%02d\n", appointments[i].name, appointments[i].start_hour, appointments[i].start_min, appointments[i].end_hour, appointments[i].end_min);
    }
}

void schedule_appointments(struct appointment appointments[], int num_appointments) {
    int current_time = 0;
    while(current_time < MAX_TIME) {
        for(int i=0; i<num_appointments; i++) {
            if(current_time >= appointments[i].start_hour*60+appointments[i].start_min && current_time < appointments[i].end_hour*60+appointments[i].end_min) {
                printf("%s is scheduled from %02d:%02d to %02d:%02d\n", appointments[i].name, appointments[i].start_hour, appointments[i].start_min, appointments[i].end_hour, appointments[i].end_min);
            }
        }
        current_time++;
        sleep(1);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments);
    add_appointment(appointments, num_appointments);
    add_appointment(appointments, num_appointments);

    print_appointments(appointments, num_appointments);

    schedule_appointments(appointments, num_appointments);

    return 0;
}