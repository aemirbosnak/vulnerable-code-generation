//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int main(int argc, char *argv[]) {
    //Check if the number of arguments provided is correct
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return -1;
    }

    //Open the log file for reading
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file %s\n", argv[1]);
        return -1;
    }

    //Initialize variables to store log data
    char line[MAX_LINE_LEN];
    char date[MAX_LINE_LEN];
    int num_requests = 0;
    int num_errors = 0;
    int num_warnings = 0;
    int num_infos = 0;

    //Read log file line-by-line
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        //Check if the line contains a date in the format dd/MM/yyyy
        if (sscanf(line, "%s", date) == 1 && strlen(date) == 10 && date[2] == '/' && date[5] == '/') {
            //Get the log level from the line
            char *log_level = strtok(line, " ");
            if (log_level != NULL) {
                if (strcmp(log_level, "ERROR") == 0) {
                    num_errors++;
                } else if (strcmp(log_level, "WARNING") == 0) {
                    num_warnings++;
                } else if (strcmp(log_level, "INFO") == 0) {
                    num_infos++;
                }
            }
            num_requests++; //Increment the number of requests
        }
    }

    //Close the log file
    fclose(log_file);

    //Print the log analysis results
    printf("Log file %s analysis:\n\n", argv[1]);
    printf("Total requests: %d\n", num_requests);
    printf("Errors: %d\n", num_errors);
    printf("Warnings: %d\n", num_warnings);
    printf("Infos: %d\n", num_infos);

    return 0;
}