//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    char date[10];
    char time[10];
};

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while(1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_appointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, maximum number of appointments reached.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", appointments[num_appointments].name);
                    printf("Enter date (DD/MM/YYYY): ");
                    scanf("%s", appointments[num_appointments].date);
                    printf("Enter time (HH:MM): ");
                    scanf("%s", appointments[num_appointments].time);
                    num_appointments++;
                }
                break;
            case 2:
                if(num_appointments == 0) {
                    printf("No appointments found.\n");
                } else {
                    printf("\nAppointments:\n");
                    for(int i = 0; i < num_appointments; i++) {
                        printf("%s - %s %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
                    }
                }
                break;
            case 3:
                if(num_appointments == 0) {
                    printf("No appointments found.\n");
                } else {
                    printf("\nEnter name to delete: ");
                    scanf("%s", appointments[num_appointments-1].name);
                    num_appointments--;
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}