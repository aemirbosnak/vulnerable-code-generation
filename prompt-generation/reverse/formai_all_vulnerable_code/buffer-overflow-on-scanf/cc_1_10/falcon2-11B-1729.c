//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    int start_time;
    int end_time;
};

struct appointment appointments[10];
int num_appointments = 0;

void add_appointment(char* name, int start_time, int end_time) {
    struct appointment new_appointment = {.name = name,.start_time = start_time,.end_time = end_time };
    if (num_appointments < 10) {
        appointments[num_appointments++] = new_appointment;
    } else {
        printf("No more appointments available.\n");
    }
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment: %s\n", appointments[i].name);
        printf("Start Time: %d\n", appointments[i].start_time);
        printf("End Time: %d\n", appointments[i].end_time);
        printf("\n");
    }
}

int main() {
    char name[50];
    int start_time, end_time;

    printf("Enter appointment name:\n");
    scanf("%s", name);

    printf("Enter start time:\n");
    scanf("%d", &start_time);

    printf("Enter end time:\n");
    scanf("%d", &end_time);

    add_appointment(name, start_time, end_time);

    print_appointments();

    return 0;
}