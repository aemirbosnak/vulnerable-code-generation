//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1000

int main() {

    printf("Welcome to the Log Analysis Program!\n");
    printf("Let's analyze your log files!\n\n");

    char log_file_name[50];
    printf("Please enter the name of your log file: ");
    scanf("%s", log_file_name);

    FILE *log_file_ptr;
    log_file_ptr = fopen(log_file_name, "r");

    if (log_file_ptr == NULL) {
        printf("Oops! Couldn't open the log file!\n");
        return 1;
    }

    char current_log_line[MAX_LOG_LENGTH];
    int total_log_lines = 0;
    int error_log_count = 0;
    int warning_log_count = 0;
    int info_log_count = 0;

    while (fgets(current_log_line, MAX_LOG_LENGTH, log_file_ptr) != NULL) {
        total_log_lines++;
        if (strstr(current_log_line, "ERROR") != NULL) {
            error_log_count++;
        } else if (strstr(current_log_line, "WARNING") != NULL) {
            warning_log_count++;
        } else if (strstr(current_log_line, "INFO") != NULL) {
            info_log_count++;
        }
    }

    printf("\n********** Log Analysis Report **********\n");
    printf("Total log lines: %d\n", total_log_lines);
    printf("ERROR logs count: %d\n", error_log_count);
    printf("WARNING logs count: %d\n", warning_log_count);
    printf("INFO logs count: %d\n", info_log_count);

    if (error_log_count > warning_log_count && error_log_count > info_log_count) {
        printf("Looks like there are too many errors in your log file. You might want to check it!\n");
    } else if (warning_log_count > error_log_count && warning_log_count > info_log_count) {
        printf("Looks like there are too many warnings in your log file. You might want to check it!\n");
    } else {
        printf("Looks like your log file is in good shape! Keep up the good work!\n");
    }

    fclose(log_file_ptr);

    printf("\nThank you for using the Log Analysis Program!\n");

    return 0;
}