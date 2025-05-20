//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLIENTS 100
#define MAX_APPOINTMENTS 1000
#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24

struct Appointment {
    int day;
    int hour;
    int minute;
    int duration;
    int client_id;
};

struct Client {
    char name[50];
    int id;
    int num_appointments;
};

void add_appointment(struct Client* client, struct Appointment* appointment) {
    client->num_appointments++;
    appointment->client_id = client->id;
}

void print_schedule(struct Appointment* schedule, int num_appointments) {
    printf("Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d: ", i+1);
        printf("Day: %d\n", schedule[i].day);
        printf("Hour: %d\n", schedule[i].hour);
        printf("Minute: %d\n", schedule[i].minute);
        printf("Duration: %d minutes\n\n", schedule[i].duration);
    }
}

void generate_appointments(struct Appointment* schedule, int num_appointments) {
    srand(time(NULL));
    for (int i = 0; i < num_appointments; i++) {
        schedule[i].day = rand() % DAYS_IN_WEEK;
        schedule[i].hour = rand() % HOURS_IN_DAY;
        schedule[i].minute = rand() % 60;
        schedule[i].duration = rand() % 60 + 1;
    }
}

int main() {
    struct Client clients[MAX_CLIENTS];
    struct Appointment schedule[MAX_APPOINTMENTS];

    int num_clients = 0;
    int num_appointments = 0;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("How many clients will be using the scheduler? ");
    scanf("%d", &num_clients);

    for (int i = 0; i < num_clients; i++) {
        printf("Enter client name: ");
        scanf("%s", clients[i].name);
        clients[i].id = i+1;
        clients[i].num_appointments = 0;
    }

    printf("How many appointments will be scheduled? ");
    scanf("%d", &num_appointments);

    generate_appointments(schedule, num_appointments);

    printf("Appointments:\n");
    print_schedule(schedule, num_appointments);

    return 0;
}