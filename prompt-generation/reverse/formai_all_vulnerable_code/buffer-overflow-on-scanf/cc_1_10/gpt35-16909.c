//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int hour;
    int minute;
}Time;

typedef struct{
    char name[20];
    Time time;
}Appointment;

Appointment scheduler[10];
int num_appointments = 0;

// Asynchronous function that retrieves current time
void get_current_time(Time *current_time){
    time_t now;
    struct tm *ts;

    now = time(NULL);
    ts = localtime(&now);

    current_time->hour = ts->tm_hour;
    current_time->minute = ts->tm_min;
}

// Function to add an appointment to the scheduler
void add_appointment(){
    Appointment new_appt;

    printf("\nEnter the name of the appointment: ");
    scanf("%s", new_appt.name);

    printf("\nEnter the hour (in 24-hour format) of the appointment: ");
    scanf("%d", &new_appt.time.hour);

    printf("\nEnter the minute of the appointment: ");
    scanf("%d", &new_appt.time.minute);

    scheduler[num_appointments] = new_appt;
    num_appointments++;

    printf("\nAppointment added successfully!");
}

// Asynchronous function that prints the appointments scheduled for the day
void print_appointments(){
    printf("\nScheduled Appointments:");
    for(int i = 0; i < num_appointments; i++){
        printf("\n %d:%02d - %s", scheduler[i].time.hour, scheduler[i].time.minute, scheduler[i].name);
    }
}

// Asynchronous function that checks if there are any upcoming appointments
void check_appointments(){
    Time current_time;

    // Get the current time
    get_current_time(&current_time);

    // Check if there are any upcoming appointments within the next hour
    printf("\nChecking for upcoming appointments...");

    for(int i = 0; i < num_appointments; i++){
        if(scheduler[i].time.hour == current_time.hour){
            if(scheduler[i].time.minute >= current_time.minute && scheduler[i].time.minute < current_time.minute + 60){
                printf("\nUpcoming Appointment: %s at %d:%02d", scheduler[i].name, scheduler[i].time.hour, scheduler[i].time.minute);
            }
        }
        else if(scheduler[i].time.hour == current_time.hour + 1){
            if(scheduler[i].time.minute < current_time.minute + 60 - 60){
                printf("\nUpcoming Appointment: %s at %d:%02d", scheduler[i].name, scheduler[i].time.hour, scheduler[i].time.minute);
            }
        }
    }
}

// Asynchronous function that starts the program
void start_program(){
    while(1){
        int choice;
        printf("\n\n***********************************");
        printf("\n********** APPOINTMENT ***********");
        printf("\n***********   SCHEDULER  ************");
        printf("\n***********************************\n");
        printf("\n[1] Add an appointment");
        printf("\n[2] View all appointments");
        printf("\n[3] Check for upcoming appointments");
        printf("\n[4] Exit the program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                check_appointments();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}

// Asynchronous main function
int main(){
    start_program();

    return 0;
}