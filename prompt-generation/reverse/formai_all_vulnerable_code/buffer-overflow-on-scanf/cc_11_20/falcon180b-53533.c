//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    char choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. List appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(num_appointments == MAX_APPOINTMENTS)
                    printf("Sorry, maximum number of appointments reached.\n");
                else {
                    printf("Enter name: ");
                    scanf(" %s", appointments[num_appointments].name);
                    printf("Enter email: ");
                    scanf(" %s", appointments[num_appointments].email);
                    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
                    scanf(" %s", appointments[num_appointments].appointment_time);
                    num_appointments++;
                    printf("Appointment added successfully.\n");
                }
                break;
            case '2':
                if(num_appointments == 0)
                    printf("No appointments to remove.\n");
                else {
                    int index;
                    printf("Enter index of appointment to remove: ");
                    scanf(" %d", &index);
                    if(index >= 0 && index < num_appointments) {
                        num_appointments--;
                        printf("Appointment removed successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case '3':
                if(num_appointments == 0)
                    printf("No appointments to list.\n");
                else {
                    printf("List of appointments:\n");
                    for(int i=0; i<num_appointments; i++) {
                        printf("%s (%s) - %s\n", appointments[i].name, appointments[i].email, ctime(&appointments[i].appointment_time));
                    }
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}