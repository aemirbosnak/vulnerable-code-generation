//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    time_t start_time;
    time_t end_time;
} appointment;

appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("I'm sorry, my dear Watson, but it seems that my schedule is quite full at the moment.\n");
        return;
    }

    strncpy(schedule[num_appointments].name, name, MAX_NAME_LEN);
    schedule[num_appointments].start_time = start_time;
    schedule[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_schedule() {
    if (num_appointments == 0) {
        printf("It appears that I have no appointments scheduled for today.\n");
        return;
    }

    printf("My schedule for today:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", schedule[i].name, ctime(&schedule[i].start_time), ctime(&schedule[i].end_time));
    }
}

int main() {
    srand(time(NULL));

    add_appointment("Inspector Lestrade", time(NULL) + rand() % 3600, time(NULL) + rand() % 3600 + 60 * 60);
    add_appointment("Mrs. Hudson", time(NULL) + rand() % 3600 + 60 * 60, time(NULL) + rand() % 3600 + 60 * 60 + 60 * 15);

    print_schedule();

    return 0;
}