//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Struct for an appointment
typedef struct {
    int hour;
    int minute;
    int day;
    int month;
    int year;
    char description[100];
} Appointment;

// Struct for a scheduled day
typedef struct {
    int day;
    int month;
    int year;
    int total_appointments;
    Appointment appointments[MAX_APPOINTMENTS];
} ScheduledDay;

// Function to print the scheduled appointments for a day
void printAppointments(ScheduledDay day) {
    printf("Appointments for %d/%d/%d:\n", day.day, day.month, day.year);
    for(int i=0; i<day.total_appointments; i++) {
        printf("%02d:%02d - %s\n", day.appointments[i].hour, day.appointments[i].minute,
               day.appointments[i].description);
    }
    printf("\n");
}

// Function to check if an appointment already exists on a day at a given time
int checkIfAppointmentExists(ScheduledDay day, int hour, int minute) {
    for(int i=0; i<day.total_appointments; i++) {
        if(day.appointments[i].hour == hour && day.appointments[i].minute == minute) {
            return 1;
        }
    }
    return 0;
}

// Function to schedule a new appointment on a day
void scheduleAppointment(ScheduledDay *day) {
    Appointment newAppointment;
    printf("Enter time for new appointment (hh:mm): ");
    scanf("%d:%d", &newAppointment.hour, &newAppointment.minute);
    
    // Check if appointment time is valid
    if(newAppointment.hour < 0 || newAppointment.hour > 23 ||
       newAppointment.minute < 0 || newAppointment.minute > 59) {
        printf("Invalid appointment time entered.\n");
        return;
    }
    
    // Check if appointment time already exists
    if(checkIfAppointmentExists(*day, newAppointment.hour, newAppointment.minute)) {
        printf("An appointment already exists at that time.\n");
        return;
    }
    
    printf("Enter appointment description: ");
    scanf(" %[^\n]", newAppointment.description);
    
    // Add new appointment to day's appointments
    day->appointments[day->total_appointments] = newAppointment;
    day->total_appointments++;
    
    printf("Appointment added successfully.\n\n");
}

int main() {
    // Get current date
    time_t t = time(NULL);
    struct tm currentTime = *localtime(&t);
    
    // Create scheduled day for current date
    ScheduledDay today = {
        .day = currentTime.tm_mday,
        .month = currentTime.tm_mon + 1,
        .year = currentTime.tm_year + 1900,
        .total_appointments = 0
    };
    
    // Main menu loop
    while(1) {
        printf("Scheduled appointments for today:\n");
        printAppointments(today);
        
        printf("What would you like to do?\n");
        printf("1. Schedule a new appointment\n");
        printf("2. Exit program\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                scheduleAppointment(&today);
                break;
            }
            case 2: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    
    return 0;
}