//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_CMD 256

void get_machine_info();
void list_directory_contents(const char *directory);
void display_user_info();
void display_system_uptime();
void read_file(const char *file_path);
void execute_command(const char *command);
void print_current_time();

int main() {
    char command[MAX_CMD];
    char file_to_read[MAX_PATH];

    // Print welcome message
    printf("Welcome to the System Administration Tool!\n");
    printf("===========================================\n");
    
    // Get and display machine info
    get_machine_info();

    // Display current user info
    display_user_info();

    // Display system uptime
    display_system_uptime();

    // Print current time
    print_current_time();

    // List contents of the current directory
    list_directory_contents(".");

    // Offer to read a file
    printf("\nEnter the full path of a file to read (or type 'exit' to quit): ");
    scanf("%s", file_to_read);
    while (strcmp(file_to_read, "exit") != 0) {
        read_file(file_to_read);
        printf("\nEnter another file path (or type 'exit' to quit): ");
        scanf("%s", file_to_read);
    }

    // Execute a custom command
    printf("\nPlease enter a shell command to execute (or type 'exit' to finish): ");
    fgets(command, MAX_CMD, stdin); // Flush the buffer
    fgets(command, MAX_CMD, stdin);
    while (strcmp(command, "exit\n") != 0) {
        execute_command(command);
        printf("\nPlease enter another shell command to execute (or type 'exit' to finish): ");
        fgets(command, MAX_CMD, stdin);
    }

    printf("Goodbye!\n");
    return 0;
}

void get_machine_info() {
    char hostname[MAX_PATH];
    gethostname(hostname, sizeof(hostname));

    // Getting OS and Kernel Version
    FILE *fp = popen("uname -a", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    char os_info[MAX_PATH];
    fgets(os_info, sizeof(os_info), fp);
    pclose(fp);

    printf("\nMachine Info:\n");
    printf("Hostname: %s\n", hostname);
    printf("OS and Kernel Version: %s", os_info);
}

void list_directory_contents(const char *directory) {
    struct stat path_stat;
    if (stat(directory, &path_stat) == -1) {
        perror("stat");
        return;
    }

    if (S_ISDIR(path_stat.st_mode)) {
        printf("\nContents of directory '%s':\n", directory);
        FILE *fp = popen("ls -l", "r");
        if (fp == NULL) {
            perror("Failed to run command");
            return;
        }

        char line[256];
        while (fgets(line, sizeof(line), fp) != NULL) {
            printf("%s", line);
        }
        pclose(fp);
    } else {
        printf("Provided path is not a directory.\n");
    }
}

void display_user_info() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("\nUser Info:\n");
        printf("Username: %s\n", pw->pw_name);
        printf("Home Directory: %s\n", pw->pw_dir);
    } else {
        perror("Failed to get user info");
    }
}

void display_system_uptime() {
    FILE *fp = fopen("/proc/uptime", "r");
    if (fp == NULL) {
        perror("Failed to open uptime file");
        return;
    }

    double uptime;
    fscanf(fp, "%lf", &uptime);
    fclose(fp);

    int days = uptime / 86400;
    uptime -= days * 86400;
    int hours = uptime / 3600;
    uptime -= hours * 3600;
    int minutes = uptime / 60;

    printf("\nSystem Uptime: %d days %d hours %d minutes\n", days, hours, minutes);
}

void read_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file) {
        char line[256];
        printf("\nContents of '%s':\n", file_path);
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        perror("Failed to read file");
    }
}

void execute_command(const char *command) {
    printf("\nExecuting command: %s\n", command);
    int status = system(command);
    if (status == -1) {
        perror("Failed to execute command");
    } else {
        printf("Command executed with status: %d\n", WEXITSTATUS(status));
    }
}

void print_current_time() {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    printf("\nCurrent Time: %s", time_str);
}