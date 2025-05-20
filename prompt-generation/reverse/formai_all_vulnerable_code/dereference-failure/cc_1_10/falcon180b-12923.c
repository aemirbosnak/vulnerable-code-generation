//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
} appointment;

int main() {
    int num_appointments;
    appointment *appointments;
    char choice;
    time_t current_time;
    
    do {
        time(&current_time);
        printf("Current time: %s\n", ctime(&current_time));
        
        printf("Enter number of appointments (0-100): ");
        scanf("%d", &num_appointments);
        
        if (num_appointments > 0 && num_appointments <= MAX_APPOINTMENTS) {
            appointments = (appointment *)malloc(num_appointments * sizeof(appointment));
            
            for (int i = 0; i < num_appointments; i++) {
                printf("Enter name for appointment %d: ", i+1);
                scanf("%s", appointments[i].name);
                
                printf("Enter phone number for appointment %d: ", i+1);
                scanf("%s", appointments[i].phone_number);
                
                printf("Enter email for appointment %d: ", i+1);
                scanf("%s", appointments[i].email);
                
                printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[i].appointment_time);
            }
            
            printf("Appointments scheduled:\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("Name: %s\nPhone number: %s\nEmail: %s\nAppointment time: %s\n", appointments[i].name, appointments[i].phone_number, appointments[i].email, ctime(&appointments[i].appointment_time));
            }
        } else {
            printf("Invalid number of appointments.\n");
        }
        
        printf("Do you want to schedule more appointments? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    free(appointments);
    
    return 0;
}