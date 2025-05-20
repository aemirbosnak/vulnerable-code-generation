//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50
#define MAX_CLIENTS 50
#define MAX_CLIENT_NAME_LENGTH 50

typedef struct {
    char name[MAX_CLIENT_NAME_LENGTH];
    int id;
} Client;

typedef struct {
    time_t start_time;
    time_t end_time;
    char description[MAX_APPOINTMENT_LENGTH];
    int client_id;
} Appointment;

Client clients[MAX_CLIENTS];
Appointment appointments[MAX_APPOINTMENTS];
int num_clients = 0;
int num_appointments = 0;

void add_client(char* name, int id) {
    strcpy(clients[num_clients].name, name);
    clients[num_clients].id = id;
    num_clients++;
}

int find_client_id(char* name) {
    for (int i = 0; i < num_clients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            return clients[i].id;
        }
    }
    return -1;
}

void add_appointment(time_t start_time, time_t end_time, char* description, int client_id) {
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].client_id = client_id;
    num_appointments++;
}

void print_appointments(time_t current_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].start_time <= current_time && appointments[i].end_time >= current_time) {
            printf("%.19s - %.19s | %s | Client %d\n", ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].description, appointments[i].client_id);
        }
    }
}

int main() {
    add_client("John Doe", 1);
    add_client("Jane Smith", 2);
    add_appointment(time(NULL) + 3600, time(NULL) + 7200, "Meeting", 1);
    add_appointment(time(NULL) + 1800, time(NULL) + 3600, "Lunch", 2);

    while (TRUE) {
        time_t current_time = time(NULL);
        print_appointments(current_time);
        sleep(60);
    }

    return 0;
}