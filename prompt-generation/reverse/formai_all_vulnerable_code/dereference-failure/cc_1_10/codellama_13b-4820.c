//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
// Lightweight C Appointment Scheduler Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char *name;
    char *date;
    char *time;
    char *type;
};

struct appointment *create_appointment(char *name, char *date, char *time, char *type) {
    struct appointment *appointment = (struct appointment *)malloc(sizeof(struct appointment));
    appointment->name = strdup(name);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->type = strdup(type);
    return appointment;
}

void print_appointment(struct appointment *appointment) {
    printf("Appointment: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("Type: %s\n", appointment->type);
}

void free_appointment(struct appointment *appointment) {
    free(appointment->name);
    free(appointment->date);
    free(appointment->time);
    free(appointment->type);
    free(appointment);
}

int main() {
    struct appointment *appointment1 = create_appointment("John", "2022-03-10", "10:00", "Meeting");
    struct appointment *appointment2 = create_appointment("Jane", "2022-03-11", "11:00", "Appointment");
    struct appointment *appointment3 = create_appointment("John", "2022-03-12", "12:00", "Meeting");

    print_appointment(appointment1);
    print_appointment(appointment2);
    print_appointment(appointment3);

    free_appointment(appointment1);
    free_appointment(appointment2);
    free_appointment(appointment3);

    return 0;
}