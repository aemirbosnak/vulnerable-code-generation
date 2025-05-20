//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINES 1000

// Define the structure for the log line
typedef struct log_line {
    char timestamp[20];
    char username[20];
    char action[50];
} log_line;

// Function to parse a log line
log_line parse_log_line(char* line) {
    log_line l;
    sscanf(line, "[%s] %s %s", l.timestamp, l.username, l.action);
    return l;
}

int main(int argc, char** argv) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Define some random names for generating sample data
    char* names[10] = {"Neo", "Trinity", "Morpheus", "Cypher", "Mouse", "Switch", "Tank", "Dozer", "Agent Smith", "The Oracle"};
    
    // Define some sample actions for generating sample data
    char* actions[5] = {"logged in", "logged out", "created a new file", "deleted a file", "modified a file"};

    // Generate some sample log data
    FILE* log_file = fopen("sample_log.txt", "w");
    if (log_file != NULL) {
        for (int i = 0; i < MAX_LOG_LINES; i++) {
            int name_index = rand() % 10;
            int action_index = rand() % 5;
            char timestamp[20];
            time_t now = time(NULL);
            strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
            fprintf(log_file, "[%s] %s %s\n", timestamp, names[name_index], actions[action_index]);
        }
        fclose(log_file);
    }

    // Read the log file and parse the log lines
    log_line log_lines[MAX_LOG_LINES];
    int num_lines = 0;
    log_file = fopen("sample_log.txt", "r");
    if (log_file != NULL) {
        char line[100];
        while (fgets(line, 100, log_file) != NULL) {
            log_lines[num_lines++] = parse_log_line(line);
        }
        fclose(log_file);
    }

    // Print some statistics based on the log data
    printf("Number of log lines read: %d\n", num_lines);

    int num_logins = 0;
    int num_logouts = 0;
    int num_file_creations = 0;
    int num_file_deletions = 0;
    int num_file_modifications = 0;
    
    for (int i = 0; i < num_lines; i++) {
        if (strcmp(log_lines[i].action, "logged in") == 0) {
            num_logins++;
        } else if (strcmp(log_lines[i].action, "logged out") == 0) {
            num_logouts++;
        } else if (strcmp(log_lines[i].action, "created a new file") == 0) {
            num_file_creations++;
        } else if (strcmp(log_lines[i].action, "deleted a file") == 0) {
            num_file_deletions++;
        } else if (strcmp(log_lines[i].action, "modified a file") == 0) {
            num_file_modifications++;
        }
    }
    
    printf("Number of logins: %d\n", num_logins);
    printf("Number of logouts: %d\n", num_logouts);
    printf("Number of file creations: %d\n", num_file_creations);
    printf("Number of file deletions: %d\n", num_file_deletions);
    printf("Number of file modifications: %d\n", num_file_modifications);
    
    return 0;
}