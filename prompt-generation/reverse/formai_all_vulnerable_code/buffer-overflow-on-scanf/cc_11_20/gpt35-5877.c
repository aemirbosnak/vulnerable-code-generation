//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <string.h>

struct appointment {
    char name[50];
    char contact[20];
    char date[20];
    char time[10];
};

int main() {
    int choice, i, j, k;
    struct appointment schedule[50];
    int n = 0;
    printf("Welcome to the appointment scheduler program!\n\n");

    do {
        printf("Select an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointment schedule\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", schedule[n].name);
                printf("Enter your contact number: ");
                scanf("%s", schedule[n].contact);
                printf("\nAvailable dates: \n");
                printf("1. 11/10/2021\n");
                printf("2. 12/10/2021\n");
                printf("\nEnter your choice: ");
                scanf("%d", &i);
                switch (i) {
                    case 1:
                        strcpy(schedule[n].date, "11/10/2021");
                        break;
                    case 2:
                        strcpy(schedule[n].date, "12/10/2021");
                        break;
                    default:
                        printf("Please enter a valid option.\n");
                        continue;
                }
                printf("\nAvailable times for %s: \n", schedule[n].date);
                printf("1. 10:00 AM\n");
                printf("2. 2:00 PM\n");
                printf("\nEnter your choice: ");
                scanf("%d", &j);
                switch (j) {
                    case 1:
                        strcpy(schedule[n].time, "10:00 AM");
                        break;
                    case 2:
                        strcpy(schedule[n].time, "2:00 PM");
                        break;
                    default:
                        printf("Please enter a valid option.\n");
                        continue;
                }
                printf("\nAppointment confirmed! %s, your appointment is scheduled on %s at %s.\n\n", schedule[n].name, schedule[n].date, schedule[n].time);
                n++;
                break;
            case 2:
                if (n == 0) {
                    printf("No appointments scheduled.\n");
                    break;
                }
                printf("Appointment schedule:\n");
                printf("Name\tContact\tDate\tTime\n");
                for (k = 0; k < n; k++) {
                    printf("%s\t%s\t%s\t%s\n", schedule[k].name, schedule[k].contact, schedule[k].date, schedule[k].time);
                }
                break;
            case 3:
                printf("Thank you for using the appointment scheduler program!\n");
                break;
            default:
                printf("Please enter a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}