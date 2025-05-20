//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_OF_USERS 100
#define MAX_NUM_OF_APPOINTMENTS 100

typedef struct {
    char name[50];
    char email[100];
    int phone;
} User;

typedef struct {
    int user_id;
    char appointment_type[50];
    time_t appointment_time;
    char notes[200];
} Appointment;

User users[MAX_NUM_OF_USERS];
Appointment appointments[MAX_NUM_OF_APPOINTMENTS];
int num_of_users = 0;
int num_of_appointments = 0;

void add_user() {
    printf("Enter the name of the user: ");
    scanf("%s", users[num_of_users].name);
    printf("Enter the email of the user: ");
    scanf("%s", users[num_of_users].email);
    printf("Enter the phone number of the user: ");
    scanf("%d", &users[num_of_users].phone);
    num_of_users++;
}

void add_appointment() {
    printf("Enter the user ID of the user: ");
    scanf("%d", &appointments[num_of_appointments].user_id);
    printf("Enter the appointment type: ");
    scanf("%s", appointments[num_of_appointments].appointment_type);
    printf("Enter the appointment time (Format: YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_of_appointments].appointment_time);
    printf("Enter the notes: ");
    scanf("%s", appointments[num_of_appointments].notes);
    num_of_appointments++;
}

void view_appointments() {
    printf("User ID | Appointment Type | Appointment Time | Notes\n");
    for (int i = 0; i < num_of_appointments; i++) {
        printf("%d | %s | %s | %s\n", appointments[i].user_id, appointments[i].appointment_type, ctime(&appointments[i].appointment_time), appointments[i].notes);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while (1) {
        printf("1. Add User\n2. Add Appointment\n3. View Appointments\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                add_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}