//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LEN 50
#define DESC_LEN 150

typedef struct {
    char title[TITLE_LEN];
    char description[DESC_LEN];
    struct tm time;  // structure to hold appointment time
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_menu() {
    printf("\n============================\n");
    printf("  Neon City Appointment Scheduler  \n");
    printf("============================\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
    printf("============================\n");
    printf("Choose your action: ");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot schedule more appointments. Limit reached!\n");
        return;
    }

    Appointment new_appointment;
    printf("Enter appointment title: ");
    getchar(); // to consume newline
    fgets(new_appointment.title, TITLE_LEN, stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Enter appointment description: ");
    fgets(new_appointment.description, DESC_LEN, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; 

    printf("Enter date and time (YYYY-MM-DD HH:MM): ");
    int year, month, day, hour, minute;
    scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);
    
    new_appointment.time.tm_year = year - 1900;
    new_appointment.time.tm_mon = month - 1;
    new_appointment.time.tm_mday = day;
    new_appointment.time.tm_hour = hour;
    new_appointment.time.tm_min = minute;
    new_appointment.time.tm_sec = 0;
    new_appointment.time.tm_isdst = -1; // Not considering daylight saving time

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added: %s at %04d-%02d-%02d %02d:%02d\n", 
           new_appointment.title, year, month, day, hour, minute);
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled in this neon dystopia!\n");
        return;
    }

    printf("Scheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        Appointment a = appointments[i];
        printf("%d. %s - %s on %04d-%02d-%02d at %02d:%02d\n", 
               i + 1, a.title, a.description, 
               a.time.tm_year + 1900, a.time.tm_mon + 1, 
               a.time.tm_mday, a.time.tm_hour, a.time.tm_min);
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Shutting down Neon City Scheduler. Until next time...\n");
                exit(0);
            default:
                printf("Invalid choice! Choose again, cyber traveler.\n");
        }
    }

    return 0;
}