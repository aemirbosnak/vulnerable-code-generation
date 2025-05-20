//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 255

typedef struct Appointment {
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments. Cannot add new appointment.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start time: %s", ctime(&appointments[i].start_time));
        printf("End time: %s", ctime(&appointments[i].end_time));
    }
}

int main() {
    bool running = true;

    while (running) {
        printf("Welcome to the Appointment Scheduler.\n");
        printf("What would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Print all appointments\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the appointment name: ");
                char name[MAX_NAME_LENGTH + 1];
                scanf(" %[^\n]%*c", name);

                printf("Enter the appointment description: ");
                char description[MAX_DESCRIPTION_LENGTH + 1];
                scanf(" %[^\n]%*c", description);

                printf("Enter the appointment start time (YYYY-MM-DD HH:MM:SS): ");
                char start_time_str[20];
                scanf(" %[^\n]%*c", start_time_str);

                printf("Enter the appointment end time (YYYY-MM-DD HH:MM:SS): ");
                char end_time_str[20];
                scanf(" %[^\n]%*c", end_time_str);

                struct tm start_tm;
                strptime(start_time_str, "%Y-%m-%d %H:%M:%S", &start_tm);
                time_t start_time = mktime(&start_tm);

                struct tm end_tm;
                strptime(end_time_str, "%Y-%m-%d %H:%M:%S", &end_tm);
                time_t end_time = mktime(&end_tm);

                add_appointment(name, description, start_time, end_time);

                printf("Appointment added successfully.\n");
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                running = false;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}