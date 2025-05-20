//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_USER_NAME 50
#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 100

typedef struct {
    char name[MAX_USER_NAME];
    int num_log_entries;
    struct {
        time_t timestamp;
        char activity[MAX_LOG_ENTRY_LENGTH];
    } log_entries[MAX_LOG_ENTRIES];
} User;

void init_user(User *user) {
    user->num_log_entries = 0;
}

int add_log_entry(User *user, const char *activity) {
    if (user->num_log_entries >= MAX_LOG_ENTRIES) {
        printf("Error: cannot add more than %d log entries.\n", MAX_LOG_ENTRIES);
        return -1;
    }

    strncpy(user->log_entries[user->num_log_entries].activity, activity, MAX_LOG_ENTRY_LENGTH);
    user->log_entries[user->num_log_entries].timestamp = time(NULL);
    user->num_log_entries++;

    return 0;
}

void print_log_entries(const User *user) {
    printf("Log entries for %s:\n", user->name);
    for (int i = 0; i < user->num_log_entries; i++) {
        printf("%s - %s\n", ctime(&user->log_entries[i].timestamp), user->log_entries[i].activity);
    }
}

int main() {
    User user;
    init_user(&user);

    char name[MAX_USER_NAME];
    printf("Enter your name (up to %d characters): ", MAX_USER_NAME);
    scanf("%s", name);
    strncpy(user.name, name, MAX_USER_NAME);

    int choice;
    while (1) {
        printf("\nFitness Tracker\n");
        printf("1. Add log entry\n");
        printf("2. View log entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char activity[MAX_LOG_ENTRY_LENGTH];
                printf("Enter activity (up to %d characters): ", MAX_LOG_ENTRY_LENGTH);
                scanf("%s", activity);
                add_log_entry(&user, activity);
                break;
            }
            case 2: {
                print_log_entries(&user);
                break;
            }
            case 3: {
                printf("Goodbye, %s!\n", user.name);
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}