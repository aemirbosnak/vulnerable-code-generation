//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
// Dennis Ritchie style C Appointment Scheduler example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct appointment {
    char name[50];
    char description[50];
    time_t start_time;
    time_t end_time;
};

int main() {
    struct appointment appointments[5];
    int num_appointments = 0;

    // Initialize appointment 1
    strcpy(appointments[0].name, "John Doe");
    strcpy(appointments[0].description, "Meeting with client");
    appointments[0].start_time = time(NULL);
    appointments[0].end_time = appointments[0].start_time + 1 * 60 * 60;

    // Initialize appointment 2
    strcpy(appointments[1].name, "Jane Doe");
    strcpy(appointments[1].description, "Meeting with client");
    appointments[1].start_time = time(NULL);
    appointments[1].end_time = appointments[1].start_time + 2 * 60 * 60;

    // Initialize appointment 3
    strcpy(appointments[2].name, "Bob Smith");
    strcpy(appointments[2].description, "Meeting with client");
    appointments[2].start_time = time(NULL);
    appointments[2].end_time = appointments[2].start_time + 3 * 60 * 60;

    // Initialize appointment 4
    strcpy(appointments[3].name, "Alice Johnson");
    strcpy(appointments[3].description, "Meeting with client");
    appointments[3].start_time = time(NULL);
    appointments[3].end_time = appointments[3].start_time + 4 * 60 * 60;

    // Initialize appointment 5
    strcpy(appointments[4].name, "John Doe");
    strcpy(appointments[4].description, "Meeting with client");
    appointments[4].start_time = time(NULL);
    appointments[4].end_time = appointments[4].start_time + 5 * 60 * 60;

    // Print appointments
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start Time: %s\n", ctime(&appointments[i].start_time));
        printf("End Time: %s\n", ctime(&appointments[i].end_time));
        printf("\n");
    }

    return 0;
}