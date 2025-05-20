//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_URL_LENGTH 256
#define LOG_FILE "uptime_log.txt"
#define PING_COMMAND "curl -o /dev/null -s -w \"%{http_code}\" "

// Function prototypes
void log_result(const char *url, const char *result, double duration);
int execute_ping(const char *url);

int main() {
    char url[MAX_URL_LENGTH];       // Holds the URL to monitor
    int interval;                   // Monitoring interval in seconds

    // Gather user input for URL and interval
    printf("Welcome to Uptime Monitor! \n");
    printf("Enter the URL to monitor (e.g., http://example.com): ");
    scanf("%255s", url);
    printf("Enter the monitoring interval in seconds: ");
    scanf("%d", &interval);

    // Validate user input
    if (strlen(url) == 0 || interval <= 0) {
        fprintf(stderr, "Invalid input! Please provide a valid URL and positive interval.\n");
        return EXIT_FAILURE;
    }

    printf("Monitoring %s every %d seconds...\n", url, interval);

    // Continuous monitoring loop
    while (1) {
        // Record the start time
        clock_t start = clock();

        // Execute the ping
        int status_code = execute_ping(url);

        // Measure the elapsed time
        clock_t end = clock();
        double duration = (double)(end - start) / CLOCKS_PER_SEC;

        // Log the result
        if (status_code >= 200 && status_code < 400) {
            printf("Website is up! Status Code: %d, Response Time: %.2f seconds\n", status_code, duration);
            log_result(url, "UP", duration);
        } else {
            printf("Website is down! Status Code: %d, Response Time: %.2f seconds\n", status_code, duration);
            log_result(url, "DOWN", duration);
        }

        // Sleep for the defined interval
        sleep(interval);
    }

    return EXIT_SUCCESS;
}

// Function to log the results to a file
void log_result(const char *url, const char *result, double duration) {
    // Open the log file in append mode
    int log_fd = open(LOG_FILE, O_CREAT | O_RDWR | O_APPEND, 0644);
    if (log_fd < 0) {
        fprintf(stderr, "Error opening log file!\n");
        return;
    }

    // Get current time for logging
    time_t now = time(NULL);
    char time_str[20];
    struct tm *tm_info;
    tm_info = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    // Prepare the log entry
    char log_entry[512];
    snprintf(log_entry, sizeof(log_entry), "[%s] %s | Status: %s | Duration: %.2f seconds\n", time_str, url, result, duration);

    // Write the log entry to the file
    write(log_fd, log_entry, strlen(log_entry));
    close(log_fd);
}

// Function to execute ping command and fetch HTTP status code
int execute_ping(const char *url) {
    char command[MAX_URL_LENGTH + 50];  // Command to execute
    snprintf(command, sizeof(command), "%s%s", PING_COMMAND, url);  // Formulate command

    // Open a pipe to execute the command
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return -1;
    }

    char result_str[4];  // buffer to hold the result
    fgets(result_str, sizeof(result_str), fp); // Read the output
    pclose(fp);

    // Convert result to integer HTTP status code
    int status_code = atoi(result_str);
    return status_code;
}