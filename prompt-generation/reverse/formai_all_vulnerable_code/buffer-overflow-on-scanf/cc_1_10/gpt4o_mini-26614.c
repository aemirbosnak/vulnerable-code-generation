//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
#include <signal.h>

#define LOG_FILE "/var/log/sys_admin_log.txt"

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Log file opening failed");
        exit(EXIT_FAILURE);
    }
    time_t now = time(NULL);
    fprintf(log_file, "%s - %s\n", ctime(&now), event);
    fclose(log_file);
}

void check_disk_space() {
    FILE *fp = popen("df -h", "r");
    if (fp == NULL) {
        log_event("Failed to run df command");
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void check_memory_usage() {
    FILE *fp = popen("free -h", "r");
    if (fp == NULL) {
        log_event("Failed to run free command");
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void display_uptime() {
    FILE *fp = fopen("/proc/uptime", "r");
    if (fp == NULL) {
        log_event("Failed to read uptime");
        return;
    }
    double uptime;
    fscanf(fp, "%lf", &uptime);
    fclose(fp);
    printf("System Uptime: %.2f seconds\n", uptime);
}

void kill_process_by_name(const char *process_name) {
    char command[256];
    sprintf(command, "pkill -f %s", process_name);
    int status = system(command);
    if (status == -1) {
        log_event("Failed to kill process");
    } else {
        char log_message[256];
        sprintf(log_message, "Killed process: %s", process_name);
        log_event(log_message);
    }
}

void signal_handler(int signal) {
    switch (signal) {
        case SIGINT:
            log_event("Received SIGINT, shutting down gracefully.");
            exit(EXIT_SUCCESS);
        case SIGTERM:
            log_event("Received SIGTERM, shutting down.");
            exit(EXIT_SUCCESS);
        default:
            break;
    }
}

void display_user_info() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("User Name: %s\n", pw->pw_name);
        printf("User ID: %d\n", pw->pw_uid);
        printf("User Home: %s\n", pw->pw_dir);
    } else {
        log_event("Failed to get user information");
    }
}

void display_menu() {
    printf("\n--- System Administration Menu ---\n");
    printf("1. Check Disk Space\n");
    printf("2. Check Memory Usage\n");
    printf("3. Display Uptime\n");
    printf("4. Kill a Process\n");
    printf("5. Display User Information\n");
    printf("6. Exit\n");
    printf("---------------------------------\n");
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    while (1) {
        display_menu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Checking Disk Space...\n");
                check_disk_space();
                log_event("Checked disk space.");
                break;
            case 2:
                printf("Checking Memory Usage...\n");
                check_memory_usage();
                log_event("Checked memory usage.");
                break;
            case 3:
                printf("Displaying System Uptime...\n");
                display_uptime();
                log_event("Displayed uptime.");
                break;
            case 4: {
                char process_name[100];
                printf("Enter process name to kill: ");
                scanf("%s", process_name);
                kill_process_by_name(process_name);
                break;
            }
            case 5:
                printf("Displaying User Information...\n");
                display_user_info();
                log_event("Displayed user information.");
                break;
            case 6:
                log_event("Exiting the program.");
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}