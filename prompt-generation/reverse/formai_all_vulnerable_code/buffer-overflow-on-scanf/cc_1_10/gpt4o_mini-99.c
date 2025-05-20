//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define LOGFILE "/var/log/sysadmin_activity.log"
#define MAX_BUFFER 256

void log_activity(const char *message) {
    FILE *log_fp = fopen(LOGFILE, "a");
    if (!log_fp) {
        perror("Unable to open log file");
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    fprintf(log_fp, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec, message);
    fclose(log_fp);
}

void get_user_info(const char *username) {
    struct passwd *pw = getpwnam(username);
    if (pw == NULL) {
        printf("User %s not found.\n", username);
        return;
    }

    printf("User Information for %s:\n", username);
    printf("UID: %d\n", pw->pw_uid);
    printf("GID: %d\n", pw->pw_gid);
    printf("Home Directory: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);
}

void change_password(const char *username) {
    char new_password[MAX_BUFFER];

    printf("Enter new password for %s: ", username);
    if (fgets(new_password, sizeof(new_password), stdin) == NULL) {
        perror("Error reading password");
        return;
    }
    
    // Remove newline character
    new_password[strcspn(new_password, "\n")] = 0;

    // Change password using system command (requires sudo privileges)
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "echo '%s:%s' | sudo chpasswd", username, new_password);
    
    if (system(command) == -1) {
        perror("Failed to change password");
        return;
    }

    char log_message[MAX_BUFFER];
    snprintf(log_message, sizeof(log_message), "Changed password for user %s", username);
    log_activity(log_message);
    printf("Password changed successfully for %s.\n", username);
}

void list_users() {
    printf("User List:\n");
    
    FILE *fp = fopen("/etc/passwd", "r");
    if (fp == NULL) {
        perror("Unable to open /etc/passwd");
        return;
    }

    char line[MAX_BUFFER];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *username = strtok(line, ":");
        printf("%s\n", username);
    }

    fclose(fp);
}

int main() {
    int choice;
    char username[MAX_BUFFER];

    while (1) {
        printf("\nSystem Administration Menu:\n");
        printf("1. Get user information\n");
        printf("2. Change user password\n");
        printf("3. List all users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear stdin
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                get_user_info(username);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                change_password(username);
                break;
            case 3:
                list_users();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}