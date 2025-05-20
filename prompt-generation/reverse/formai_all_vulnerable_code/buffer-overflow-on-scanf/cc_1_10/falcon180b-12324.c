//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t date_time;
};

struct appointment* create_appointment(char* name, char* phone, char* email, time_t date_time) {
    struct appointment* appointment = (struct appointment*)malloc(sizeof(struct appointment));
    strncpy(appointment->name, name, MAX_NAME_LENGTH);
    strncpy(appointment->phone, phone, MAX_PHONE_LENGTH);
    strncpy(appointment->email, email, MAX_EMAIL_LENGTH);
    appointment->date_time = date_time;
    return appointment;
}

void print_appointment(struct appointment* appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Phone: %s\n", appointment->phone);
    printf("Email: %s\n", appointment->email);
    printf("Date and Time: %s", ctime(&appointment->date_time));
}

int compare_appointments(const void* a, const void* b) {
    struct appointment* appointment1 = *((struct appointment**)a);
    struct appointment* appointment2 = *((struct appointment**)b);

    if (appointment1->date_time < appointment2->date_time) {
        return -1;
    } else if (appointment1->date_time > appointment2->date_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments = 0;
    struct appointment* appointments[MAX_APPOINTMENTS];

    printf("Welcome to the Retro C Appointment Scheduler!\n");
    printf("How many appointments would you like to schedule? (Maximum %d)\n", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", appointments[i]->name);
        printf("Phone: ");
        scanf("%s", appointments[i]->phone);
        printf("Email: ");
        scanf("%s", appointments[i]->email);
        printf("Date and Time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i]->date_time);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment*), compare_appointments);

    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}