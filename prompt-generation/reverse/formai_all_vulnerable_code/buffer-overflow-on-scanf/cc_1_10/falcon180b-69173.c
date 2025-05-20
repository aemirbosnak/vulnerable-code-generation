//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int duration;
} appointment;

void print_appointment(appointment* a) {
    printf("Name: %s\n", a->name);
    printf("Phone: %s\n", a->phone);
    printf("Appointment Time: %s\n", ctime(&a->appointment_time));
    printf("Duration: %d minutes\n", a->duration);
}

int main() {
    appointment* appointments = malloc(MAX_APPOINTMENTS * sizeof(appointment));
    int num_appointments = 0;
    char input[100];

    while(1) {
        printf("Enter command (a/d/p/q): ");
        scanf("%s", input);

        if(strcmp(input, "a") == 0) {
            if(num_appointments >= MAX_APPOINTMENTS) {
                printf("Sorry, no more appointments available.\n");
            } else {
                printf("Enter name: ");
                scanf("%s", appointments[num_appointments].name);
                printf("Enter phone number: ");
                scanf("%s", appointments[num_appointments].phone);
                printf("Enter appointment time (yyyy-mm-dd hh:mm:ss): ");
                scanf("%s", input);
                appointments[num_appointments].appointment_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);
                printf("Enter duration in minutes: ");
                scanf("%d", &appointments[num_appointments].duration);
                num_appointments++;
            }
        } else if(strcmp(input, "d") == 0) {
            if(num_appointments == 0) {
                printf("No appointments to display.\n");
            } else {
                for(int i=0; i<num_appointments; i++) {
                    print_appointment(&appointments[i]);
                }
            }
        } else if(strcmp(input, "p") == 0) {
            if(num_appointments == 0) {
                printf("No appointments to print.\n");
            } else {
                for(int i=0; i<num_appointments; i++) {
                    print_appointment(&appointments[i]);
                }
            }
        } else if(strcmp(input, "q") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    free(appointments);
    return 0;
}