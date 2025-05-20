//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPT 10
#define APPT_LEN 50

typedef struct {
    char name[APPT_LEN];
    int start, end;
} Appointment;

Appointment schedule[MAX_APPT];
int num_appts = 0;

void print_schedule() {
    printf("\nSherlock's Appointment Schedule:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s: %d:%02d - %d:%02d\n", schedule[i].name,
                schedule[i].start / 60, schedule[i].start % 60,
                schedule[i].end / 60, schedule[i].end % 60);
    }
}

int add_appointment(char *name, int start, int end) {
    if (num_appts >= MAX_APPT) {
        fprintf(stderr, "Error: Schedule is full.\n");
        return -1;
    }

    strcpy(schedule[num_appts].name, name);
    schedule[num_appts].start = start;
    schedule[num_appts].end = end;

    num_appts++;
    return 0;
}

int main(int argc, char **argv) {
    int min, hour, meridiem;
    char name[APPT_LEN];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <name> <start_time> <end_time>\n", argv[0]);
        return 1;
    }

    sscanf(argv[2], "%d:%d%s", &hour, &min, &meridiem);
    int start = hour * 60 + min;

    sscanf(argv[3], "%d:%d%s", &hour, &min, &meridiem);
    int end = hour * 60 + min;

    add_appointment(argv[1], start, end);
    print_schedule();

    return 0;
}