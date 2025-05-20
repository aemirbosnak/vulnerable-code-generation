//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_APPOINTMENT_LENGTH 50

struct Appointment {
    char name[MAX_APPOINTMENT_LENGTH];
    int start;
    int end;
};

void print_schedule(struct Appointment appointments[MAX_APPOINTMENTS]) {
    for (int i = 0; i < MAX_APPOINTMENTS; ++i) {
        if (appointments[i].start != 0) {
            printf("%s: %d:%d - %d:%d\n", appointments[i].name,
                   appointments[i].start / 60, appointments[i].start % 60,
                   appointments[i].end / 60, appointments[i].end % 60);
        }
    }
}

int find_empty_slot(struct Appointment appointments[MAX_APPOINTMENTS], int len) {
    for (int i = 0; i < MAX_APPOINTMENTS; ++i) {
        if (appointments[i].start == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    struct Appointment schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char command[MAX_APPOINTMENT_LENGTH];

    while (1) {
        printf("> ");
        fgets(command, MAX_APPOINTMENT_LENGTH, stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "quit") == 0) {
            break;
        }

        sscanf(command, "%s %s %d %d", schedule[num_appointments].name,
               schedule[num_appointments].name + strlen(schedule[num_appointments].name) - 1,
               &schedule[num_appointments].start, &schedule[num_appointments].end);

        int slot = find_empty_slot(schedule, num_appointments);

        if (slot == -1) {
            printf("Error: Schedule is full.\n");
            continue;
        }

        schedule[num_appointments].start = schedule[num_appointments].start * 60;
        schedule[num_appointments].end = schedule[num_appointments].end * 60;

        if (schedule[num_appointments].end < schedule[num_appointments].start) {
            printf("Error: Invalid appointment length.\n");
            continue;
        }

        num_appointments++;
    }

    print_schedule(schedule);

    return 0;
}