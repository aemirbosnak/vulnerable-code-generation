//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    int id;
    time_t start_time;
    time_t end_time;
    char status;
    contact client;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    num_appointments++;
    appointments[num_appointments-1].id = num_appointments;
    appointments[num_appointments-1].status = 'A';
    printf("Enter start time (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", appointments[num_appointments-1].start_time);
    printf("Enter end time (yyyy-mm-dd hh:mm:ss): ");
    scanf("%s", appointments[num_appointments-1].end_time);
    printf("Enter client name: ");
    scanf("%s", appointments[num_appointments-1].client.name);
    printf("Enter client phone number: ");
    scanf("%s", appointments[num_appointments-1].client.phone);
    printf("Enter client email: ");
    scanf("%s", appointments[num_appointments-1].client.email);
}

void view_appointments() {
    printf("ID\tStart Time\tEnd Time\tStatus\tClient Name\tClient Phone\tClient Email\n");
    for (int i=0; i<num_appointments; i++) {
        printf("%d\t%s\t%s\t%c\t%s\t%s\t%s\n", appointments[i].id, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].status, appointments[i].client.name, appointments[i].client.phone, appointments[i].client.email);
    }
}

void cancel_appointment() {
    printf("Enter appointment ID to cancel: ");
    int id;
    scanf("%d", &id);
    for (int i=0; i<num_appointments; i++) {
        if (appointments[i].id == id) {
            printf("Appointment %d cancelled.\n", id);
            appointments[i].status = 'C';
        }
    }
}

int main() {
    system("clear");
    printf("Welcome to the Appointment Scheduler\n");
    int choice = 0;
    while (choice!= 4) {
        printf("\n1. Add appointment\n2. View appointments\n3. Cancel appointment\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}