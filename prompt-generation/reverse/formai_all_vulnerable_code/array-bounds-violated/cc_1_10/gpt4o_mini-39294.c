//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_USERS 100
#define LOG_FILE "system_log.txt"

struct User {
    char username[50];
    char password[50];
    time_t last_login;
};

struct User users[MAX_USERS];
int user_count = 0;

void log_event(const char *event) {
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("Unable to open log file");
        return;
    }
    time_t now = time(NULL);
    fprintf(fp, "[%s] %s\n", ctime(&now), event);
    fclose(fp);
}

void init_users() {
    FILE *file = fopen("users.dat", "r");
    if (file == NULL) {
        perror("Could not open users file");
        return;
    }

    while (fscanf(file, "%49s %49s", users[user_count].username, users[user_count].password) != EOF) {
        users[user_count].last_login = 0;
        user_count++;
    }
    fclose(file);
}

int authenticate(const char *username, const char *password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return i; // return index of the user
        }
    }
    return -1; // user not found
}

void display_user_info(int user_index) {
    printf("User: %s\n", users[user_index].username);
    printf("Last login: %s", ctime(&users[user_index].last_login));
}

void update_login_time(int user_index) {
    users[user_index].last_login = time(NULL);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir("/proc")) == NULL) {
        log_event("Failed to open /proc directory");
        perror("opendir");
        return;
    }

    printf("List of running processes:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                char stat_file[256];
                snprintf(stat_file, sizeof(stat_file), "/proc/%s/stat", entry->d_name);

                FILE *fp = fopen(stat_file, "r");
                if (fp != NULL) {
                    char process_name[50];
                    fscanf(fp, "%*d %s", process_name);
                    fclose(fp);
                    printf("PID: %d, Name: %s\n", pid, process_name);
                }
            }
        }
    }
    closedir(dir);
}

void shutdown_system() {
    log_event("System is shutting down...");
    system("shutdown now");
}

int main() {
    init_users();
    char username[50], password[50];
    printf("Welcome to the Futuristic System Manager!\n");
    
    printf("Please enter your username: ");
    scanf("%49s", username);
    printf("Please enter your password: ");
    scanf("%49s", password);

    int user_index = authenticate(username, password);
    if (user_index == -1) {
        log_event("Failed login attempt");
        printf("Authentication failed!\n");
        return 1;
    }

    log_event("Successful login");
    printf("Login successful!\n");
    display_user_info(user_index);
    update_login_time(user_index);

    char command[20];
    while (1) {
        printf("Enter a command (list, shutdown, exit): ");
        scanf("%19s", command);
        
        if (strcmp(command, "list") == 0) {
            list_processes();
        } else if (strcmp(command, "shutdown") == 0) {
            shutdown_system();
            break;
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
    return 0;
}