//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Appointment {
    char patient_name[50];
    char doctor_name[50];
    char date[15];
    char time[10];
} Appointment;

int main() {
    int choice, n=0, i;
    Appointment *ap;

    printf("Welcome to Appointment Scheduler\n");

    while(choice != 4) {
        printf("\nChoose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit\n");

        scanf("%d", &choice);
        switch(choice) {
            case 1:
                ap = realloc(ap, (n+1)*sizeof(Appointment));
                printf("\nEnter patient name: ");
                scanf("%s", ap[n].patient_name);
                printf("Enter doctor name: ");
                scanf("%s", ap[n].doctor_name);
                printf("Enter date: ");
                scanf("%s", ap[n].date);
                printf("Enter time: ");
                scanf("%s", ap[n].time);
                printf("Appointment added successfully!\n");
                n++;
                break;

            case 2:
                if (n == 0) {
                    printf("\nNo appointments found!\n");
                    break;
                }
                printf("\nList of all appointments\n");
                for(i=0; i<n; i++) {
                    printf("%d. %s - %s, on %s at %s\n", i+1, ap[i].patient_name, ap[i].doctor_name, ap[i].date, ap[i].time);
                }
                break;

            case 3:
                if (n == 0) {
                    printf("\nNo appointments found!\n");
                    break;
                }
                printf("\nEnter the number of the appointment to delete: ");
                scanf("%d", &i);
                if (i>n || i<1) {
                    printf("\nInvalid appointment number!\n");
                    break;
                }
                for (; i<n; i++) {
                    ap[i-1] = ap[i];
                }
                n--;
                printf("Appointment deleted successfully!\n");
                break;

            case 4:
                printf("Thank you for using Appointment Scheduler!\n");
                break;

            default:
                printf("Invalid input! Please try again.\n");
        }
    }

    free(ap);
    return 0;
}