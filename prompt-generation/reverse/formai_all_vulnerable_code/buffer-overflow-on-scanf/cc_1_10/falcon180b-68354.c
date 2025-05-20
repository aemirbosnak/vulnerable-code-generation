//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

appointment create_appointment(char* name, time_t start_time, time_t end_time) {
    appointment appt;
    strncpy(appt.name, name, MAX_APPOINTMENT_LENGTH);
    appt.start_time = start_time;
    appt.end_time = end_time;
    return appt;
}

void print_appointment(appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Start Time: %s\n", ctime(&appt.start_time));
    printf("End Time: %s\n", ctime(&appt.end_time));
    printf("\n");
}

int compare_appointments(const void* a, const void* b) {
    appointment* appt1 = (appointment*)a;
    appointment* appt2 = (appointment*)b;

    time_t diff = difftime(appt2->start_time, appt1->start_time);

    if(diff < 0)
        return 1;
    else if(diff > 0)
        return -1;
    else
        return 0;
}

int main() {
    int num_appointments;
    appointment* appointments;

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    appointments = malloc(num_appointments * sizeof(appointment));

    for(int i=0; i<num_appointments; i++) {
        char name[MAX_APPOINTMENT_LENGTH];
        time_t start_time, end_time;

        printf("Enter appointment #%d details:\n", i+1);
        printf("Name: ");
        scanf("%s", name);

        printf("Start Time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&start_time));

        printf("End Time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&end_time));

        appointments[i] = create_appointment(name, start_time, end_time);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    printf("Sorted Appointments:\n");
    for(int i=0; i<num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    free(appointments);
    return 0;
}