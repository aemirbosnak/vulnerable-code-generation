//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[30];
    int age;
} Patient;

typedef struct {
    int id;
    char description[100];
    Patient patient;
    Date date;
    char time[10];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void display_menu() {
    printf("\nAppointment Scheduler");
    printf("\n1. Schedule an appointment");
    printf("\n2. View all appointments");
    printf("\n3. Cancel an appointment");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

void schedule_appointment() {
    if(num_appointments >= MAX_APPOINTMENTS) {
        printf("\nMaximum appointments reached!\n");
        return;
    }
    
    Appointment new_appointment;
    printf("\nEnter Appointment Details:");
    printf("\nPatient Name: ");
    scanf("%s", new_appointment.patient.name);
    printf("Patient Age: ");
    scanf("%d", &new_appointment.patient.age);
    printf("Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &new_appointment.date.day, &new_appointment.date.month, &new_appointment.date.year);
    printf("Time (HH:MM): ");
    scanf("%s", new_appointment.time);
    printf("Description: ");
    getchar();
    fgets(new_appointment.description, 100, stdin);
    
    new_appointment.id = num_appointments + 1;
    appointments[num_appointments] = new_appointment;
    num_appointments++;
    
    printf("\nAppointment scheduled successfully!\n");
}

void view_appointments() {
    if(num_appointments == 0) {
        printf("\nNo appointments scheduled!\n");
        return;
    }
    
    printf("\nList of Appointments:");
    printf("\nID  | Patient Name | Patient Age | Date       | Time   | Description");
    printf("\n--------------------------------------------------------------------\n");
    
    for(int i = 0; i < num_appointments; i++) {
        printf("%-4d| %-12s | %-11d | %02d/%02d/%04d | %-6s | %s", appointments[i].id, appointments[i].patient.name, appointments[i].patient.age, appointments[i].date.day, appointments[i].date.month, appointments[i].date.year, appointments[i].time, appointments[i].description);
    }
    
    printf("\n");
}

void cancel_appointment() {
    if(num_appointments == 0) {
        printf("\nNo appointments scheduled!\n");
        return;
    }
    
    int id;
    printf("\nEnter appointment ID to cancel: ");
    scanf("%d", &id);
    
    int found = 0;
    for(int i = 0; i < num_appointments; i++) {
        if(appointments[i].id == id) {
            found = 1;
            for(int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            num_appointments--;
            
            printf("\nAppointment cancelled!\n");
            break;
        }
    }
    
    if(!found) {
        printf("\nInvalid appointment ID!\n");
    }
}

int main() {
    int choice;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice != 4);
    
    return 0;
}