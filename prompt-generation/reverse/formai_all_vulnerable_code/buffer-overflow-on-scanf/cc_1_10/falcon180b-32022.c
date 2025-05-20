//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_APPOINTMENTS 1000

typedef struct {
    char name[50];
    int id;
    int num_appointments;
    int *appointment_times;
} User;

typedef struct {
    int hour;
    int minute;
} AppointmentTime;

User users[MAX_USERS];
AppointmentTime appointments[MAX_APPOINTMENTS];
int num_users = 0;
int num_appointments = 0;

void add_user() {
    printf("Enter name: ");
    scanf("%s", users[num_users].name);
    users[num_users].id = num_users + 1;
    users[num_users].num_appointments = 0;
    users[num_users].appointment_times = NULL;
    num_users++;
}

void schedule_appointment(int user_id) {
    printf("Enter appointment time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].hour, &appointments[num_appointments].minute);
    num_appointments++;
}

void view_schedule(int user_id) {
    printf("Schedule for %s (%d):\n", users[user_id - 1].name, user_id);
    for (int i = 0; i < users[user_id - 1].num_appointments; i++) {
        printf("%d:%02d - ", appointments[users[user_id - 1].appointment_times[i]].hour, appointments[users[user_id - 1].appointment_times[i]].minute);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Cyberpunk Appointment Scheduler\n");
        printf("1. Add user\n");
        printf("2. Schedule appointment\n");
        printf("3. View schedule\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                printf("Enter user ID: ");
                int user_id = rand() % MAX_USERS + 1;
                schedule_appointment(user_id);
                break;
            case 3:
                printf("Enter user ID: ");
                int view_user_id = rand() % MAX_USERS + 1;
                view_schedule(view_user_id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}