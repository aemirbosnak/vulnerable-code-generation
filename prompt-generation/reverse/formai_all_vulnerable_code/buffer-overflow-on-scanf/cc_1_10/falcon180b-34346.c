//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t date;
    int duration;
};

void print_appointment(struct appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Phone: %s\n", appt.phone);
    printf("Date: %s\n", ctime(&appt.date));
    printf("Duration: %d minutes\n", appt.duration);
}

int compare_appointments(const void *a, const void *b) {
    struct appointment *appt1 = (struct appointment *)a;
    struct appointment *appt2 = (struct appointment *)b;

    if (appt1->date < appt2->date) {
        return -1;
    } else if (appt1->date > appt2->date) {
        return 1;
    } else {
        return 0;
    }
}

void schedule_appointment(struct appointment *appt) {
    int choice;

    printf("Enter appointment details:\n");
    printf("Name: ");
    scanf("%s", appt->name);
    printf("Phone: ");
    scanf("%s", appt->phone);
    printf("Date (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appt->date);
    printf("Duration in minutes: ");
    scanf("%d", &appt->duration);
}

int main() {
    int num_appointments, i;
    struct appointment appts[MAX_APPOINTMENTS];

    printf("Welcome to the appointment scheduler!\n");

    srand(time(NULL));
    num_appointments = rand() % MAX_APPOINTMENTS + 1;

    for (i = 0; i < num_appointments; i++) {
        schedule_appointment(&appts[i]);
    }

    qsort(appts, num_appointments, sizeof(struct appointment), compare_appointments);

    printf("Appointments scheduled:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(appts[i]);
    }

    return 0;
}