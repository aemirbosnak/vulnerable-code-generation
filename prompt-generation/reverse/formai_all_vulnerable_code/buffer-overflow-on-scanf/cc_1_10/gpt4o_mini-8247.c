//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 10
#define MAX_LENGTH 100
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char username[MAX_LENGTH];
    int boot_speed;
    int verbose_logging;
} UserSettings;

void saveBootConfig(UserSettings* users, int user_count);
void loadBootConfig(UserSettings* users, int* user_count);
void optimizeBootSettings(UserSettings* user);
void displaySettings(UserSettings* user);

int main() {
    UserSettings users[MAX_USERS];
    int user_count = 0;
    int choice;

    // Load existing user settings
    loadBootConfig(users, &user_count);

    while (1) {
        printf("Boot Optimizer Menu:\n");
        printf("1. Add User\n");
        printf("2. Optimize Boot Settings\n");
        printf("3. Display User Settings\n");
        printf("4. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (user_count < MAX_USERS) {
                    printf("Enter username: ");
                    scanf("%s", users[user_count].username);
                    users[user_count].boot_speed = 0; // default settings
                    users[user_count].verbose_logging = 0;
                    user_count++;
                } else {
                    printf("Maximum user limit reached!\n");
                }
                break;
            case 2:
                for (int i = 0; i < user_count; i++) {
                    printf("Optimizing for %s...\n", users[i].username);
                    optimizeBootSettings(&users[i]);
                }
                break;
            case 3:
                for (int i = 0; i < user_count; i++) {
                    displaySettings(&users[i]);
                }
                break;
            case 4:
                saveBootConfig(users, user_count);
                printf("Settings saved. Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void optimizeBootSettings(UserSettings* user) {
    user->boot_speed = 1; // Assume optimization improves boot speed
    user->verbose_logging = 0; // Disable verbose logging for a quicker boot

    printf("Optimized boot settings for %s: \n", user->username);
    printf("- Boot Speed: %d (optimized)\n", user->boot_speed);
    printf("- Verbose Logging: %d (disabled)\n", user->verbose_logging);
}

void displaySettings(UserSettings* user) {
    printf("User: %s\n", user->username);
    printf("Boot Speed Optimization: %d\n", user->boot_speed);
    printf("Verbose Logging: %d\n", user->verbose_logging);
    printf("-----------------------------\n");
}

void saveBootConfig(UserSettings* users, int user_count) {
    FILE* file = fopen(CONFIG_FILE, "w");
    if (file == NULL) {
        perror("Unable to open config file for writing");
        return;
    }
    
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %d %d\n", users[i].username, users[i].boot_speed, users[i].verbose_logging);
    }
    
    fclose(file);
}

void loadBootConfig(UserSettings* users, int* user_count) {
    FILE* file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        return; // No existing config, function exits early
    }
    
    while (fscanf(file, "%s %d %d", users[*user_count].username, 
                         &users[*user_count].boot_speed, 
                         &users[*user_count].verbose_logging) != EOF) {
        (*user_count)++;
        if (*user_count >= MAX_USERS) break; // Prevent overflow
    }

    fclose(file);
}