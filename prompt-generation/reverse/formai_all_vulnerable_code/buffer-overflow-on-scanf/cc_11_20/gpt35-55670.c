//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment {
    char date[20];
    char time[20];
    char name[50];
    char contact[20];
    char purpose[100];
};

int main() {
    int selection;
    struct appointment obj[10];
    int count = 0;

    while (1)
    {
        printf("Welcome to the appointment scheduler!\n");
        printf("1. Book appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel booking\n");
        printf("4. Exit\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            if (count < 10) {
                printf("\nPlease provide the following information to schedule an appointment:\n");
                printf("Enter the date in dd/mm/yyyy format: ");
                scanf("%s", &obj[count].date);
                printf("Enter the time in hh:mm format: ");
                scanf("%s", &obj[count].time);
                printf("Enter your name: ");
                scanf("%s", &obj[count].name);
                printf("Enter your contact number: ");
                scanf("%s", &obj[count].contact);
                printf("Enter the purpose of the appointment: ");
                scanf("%s", &obj[count].purpose);
                count++;
                printf("\nAppointment booked successfully!\n");
            }
            else {
                printf("\nSorry! Appointment slots are full.\n");
            }
            break;

        case 2:
            printf("\nHere are the list of appointments:\n");

            for (int i = 0; i < count; i++) {
                printf("\nAppointment %d:\n", i + 1);
                printf("Date: %s\n", obj[i].date);
                printf("Time: %s\n", obj[i].time);
                printf("Name: %s\n", obj[i].name);
                printf("Contact: %s\n", obj[i].contact);
                printf("Purpose: %s\n", obj[i].purpose);
            }
            break;

        case 3:
            if (count == 0) {
                printf("\nNo appointments to cancel.\n");
            }
            else {
                printf("\nEnter the index of the appointment to be cancelled: ");
                int index;
                scanf("%d", &index);

                if (index < 1 || index > count) {
                    printf("\nInvalid appointment index.\n");
                }
                else {
                    for (int i = index; i < count; i++) {
                        strcpy(obj[i - 1].date, obj[i].date);
                        strcpy(obj[i - 1].time, obj[i].time);
                        strcpy(obj[i - 1].name, obj[i].name);
                        strcpy(obj[i - 1].contact, obj[i].contact);
                        strcpy(obj[i - 1].purpose, obj[i].purpose);
                    }
                    count--;
                    printf("\nAppointment cancelled successfully!\n");
                }
            }
            break;

        case 4:
            printf("\nThank you for using the appointment scheduler. Goodbye!\n");
            exit(0);
            break;

        default:
            printf("\nInvalid selection. Please select again!\n");
            break;
        }
    }

    return 0;
}