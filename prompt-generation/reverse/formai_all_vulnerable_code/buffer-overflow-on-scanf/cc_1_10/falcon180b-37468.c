//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int date;
    int time;
} appointment;

int main() {
    int choice, i;
    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    appointment schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &schedule[num_appointments].date, &schedule[num_appointments].date + 1, &schedule[num_appointments].date + 2);
                printf("Enter time (hh:mm): ");
                scanf("%d:%d", &schedule[num_appointments].time, &schedule[num_appointments].time + 1);
                num_appointments++;
                break;
            case 2:
                printf("Enter appointment number to delete: ");
                scanf("%d", &i);
                if(i >= 0 && i < num_appointments) {
                    for(int j = i; j < num_appointments - 1; j++) {
                        schedule[j] = schedule[j + 1];
                    }
                    num_appointments--;
                }
                break;
            case 3:
                printf("Appointments:\n");
                for(int i = 0; i < num_appointments; i++) {
                    printf("%s (%d/%d/%d %d:%d)\n", schedule[i].name, schedule[i].date, schedule[i].date + 1, schedule[i].date + 2, schedule[i].time, schedule[i].time + 1);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}