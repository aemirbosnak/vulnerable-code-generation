//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_LOG_SIZE 256
#define MAX_COMMAND_SIZE 1024
#define CONFIG_FILE "sysadmin_config.txt"

typedef struct {
    char log_file[MAX_LOG_SIZE];
    int max_log_size;
    int timeout;
} Config;

// Function prototypes
void load_config(Config *config);
void log_message(const char *message, const Config *config);
void signal_handler(int signal);
void execute_command(const char *command);
void display_menu(const Config *config);
void handle_input(const Config *config);

// Main program
int main() {
    Config config;

    // Load configuration
    load_config(&config);
    signal(SIGINT, signal_handler);

    printf("System Administration Utility\n");
    printf("==============================\n");

    while (1) {
        display_menu(&config);
        handle_input(&config);
    }

    return 0;
}

// Load configuration from a file
void load_config(Config *config) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "log_file=%s\n", config->log_file);
    fscanf(file, "max_log_size=%d\n", &(config->max_log_size));
    fscanf(file, "timeout=%d\n", &(config->timeout));

    fclose(file);
}

// Log messages to the log file
void log_message(const char *message, const Config *config) {
    FILE *log_file = fopen(config->log_file, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "%s\n", message);
    fclose(log_file);
}

// Signal handler for graceful shutdown
void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nExiting gracefully...\n");
        exit(0);
    }
}

// Execute system commands
void execute_command(const char *command) {
    int result = system(command);
    if (result == -1) {
        perror("Error executing command");
    }
}

// Display the menu to the user
void display_menu(const Config *config) {
    printf("\nChoose an option:\n");
    printf("1. Show current directory\n");
    printf("2. List files\n");
    printf("3. Check disk usage\n");
    printf("4. Execute custom command\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

// Handle user input
void handle_input(const Config *config) {
    int choice;
    char command[MAX_COMMAND_SIZE];

    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
        log_message("Showing current directory.", config);
        execute_command("pwd");
        break;

    case 2:
        log_message("Listing files.", config);
        execute_command("ls -l");
        break;

    case 3:
        log_message("Checking disk usage.", config);
        execute_command("df -h");
        break;

    case 4:
        printf("Enter your command: ");
        getchar(); // consume newline
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline
        log_message("Executing custom command.", config);
        execute_command(command);
        break;

    case 5:
        log_message("Exiting program.", config);
        printf("Exiting...\n");
        exit(0);
        break;

    default:
        printf("Invalid choice, please try again.\n");
        break;
    }
}