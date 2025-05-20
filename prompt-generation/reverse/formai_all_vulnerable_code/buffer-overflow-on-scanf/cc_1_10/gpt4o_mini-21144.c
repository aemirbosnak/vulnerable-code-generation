//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_APPOINTMENTS 20
#define MAX_TITLE_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date;
} Appointment;

typedef struct {
    char username[20];
    Appointment appointments[MAX_APPOINTMENTS];
    int appointment_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void create_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum users reached. Cannot create more users.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", users[user_count].username);
    users[user_count].appointment_count = 0;
    user_count++;
    printf("User created successfully!\n");
}

void add_appointment(User* user) {
    if (user->appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached for %s.\n", user->username);
        return;
    }
    Appointment *appt = &user->appointments[user->appointment_count];
    printf("Enter appointment title: ");
    scanf("%s", appt->title);
    printf("Enter appointment description: ");
    scanf("%s", appt->description);
    printf("Enter appointment date (YYYY-MM-DD): ");
    char date_string[11];
    scanf("%s", date_string);
    strptime(date_string, "%Y-%m-%d", &appt->date);
    user->appointment_count++;
    printf("Appointment added successfully!\n");
}

void view_appointments(User* user) {
    if (user->appointment_count == 0) {
        printf("No appointments for %s.\n", user->username);
        return;
    }
    printf("Appointments for %s:\n", user->username);
    for (int i = 0; i < user->appointment_count; i++) {
        Appointment *appt = &user->appointments[i];
        printf("%d. %s - %s on %04d-%02d-%02d\n", i + 1,
               appt->title, appt->description,
               appt->date.tm_year + 1900, appt->date.tm_mon + 1,
               appt->date.tm_mday);
    }
}

User* find_user(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void user_menu(User* user) {
    int choice;
    do {
        printf("\n--- Appointment Menu for %s ---\n", user->username);
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_appointment(user);
                break;
            case 2:
                view_appointments(user);
                break;
            case 3:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    int main_choice;
    
    do {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Create User\n");
        printf("2. Login User\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &main_choice);
        
        switch (main_choice) {
            case 1:
                create_user();
                break;
            case 2: {
                char username[20];
                printf("Enter username for login: ");
                scanf("%s", username);
                User* user = find_user(username);
                if (user) {
                    user_menu(user);
                } else {
                    printf("User not found. Please create an account first.\n");
                }
                break;
            }
            case 3:
                printf("Exiting the scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (main_choice != 3);
    
    return 0;
}