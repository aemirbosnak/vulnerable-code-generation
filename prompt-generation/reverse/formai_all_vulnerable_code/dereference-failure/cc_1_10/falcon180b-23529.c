//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char phone[15];
    char reason[100];
    time_t appointment_time;
} appointment;

appointment create_appointment(char* name, char* phone, char* reason, time_t appointment_time) {
    appointment appt;
    strcpy(appt.name, name);
    strcpy(appt.phone, phone);
    strcpy(appt.reason, reason);
    appt.appointment_time = appointment_time;
    return appt;
}

void display_appointments(appointment* appts, int count) {
    printf("Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s - %s - %s\n", appts[i].name, appts[i].phone, appts[i].reason, ctime(&appts[i].appointment_time));
    }
}

int compare_appointments(const void* a, const void* b) {
    appointment* appt1 = (appointment*)a;
    appointment* appt2 = (appointment*)b;
    return difftime(appt1->appointment_time, appt2->appointment_time);
}

int main() {
    appointment* appts = malloc(MAX_APPOINTMENTS * sizeof(appointment));
    int count = 0;

    while (count < MAX_APPOINTMENTS) {
        char name[50];
        char phone[15];
        char reason[100];
        time_t appointment_time;

        printf("Enter name:\n");
        scanf("%s", name);

        printf("Enter phone:\n");
        scanf("%s", phone);

        printf("Enter reason:\n");
        scanf("%s", reason);

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS):\n");
        scanf("%s", reason);
        appointment_time = strptime(reason, "%Y-%m-%d %H:%M:%S", NULL);

        appts[count] = create_appointment(name, phone, reason, appointment_time);
        count++;
    }

    qsort(appts, count, sizeof(appointment), compare_appointments);
    display_appointments(appts, count);

    free(appts);
    return 0;
}