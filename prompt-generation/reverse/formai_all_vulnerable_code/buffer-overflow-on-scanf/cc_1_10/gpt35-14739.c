//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include<stdio.h>

int main(){
    printf("Welcome to our unique C Log Analysis Program\n\n");
    printf("Please enter the path of the log file to be analyzed\n");

    // Reading the file path from the user
    char file_path[1000];
    scanf("%s", file_path);

    FILE *log_file = fopen(file_path, "r"); // opening the log file in read mode
    if(log_file == NULL){
        printf("Error in opening the file. Please check the file path and try again.\n");
        return 0;
    }

    printf("\n");
    printf("--------------------------------------------------------------------------------\n");

    // initializing variables to hold count of different types of log entries
    int info_count = 0;
    int warning_count = 0;
    int error_count = 0;

    // initializing variable to hold maximum and minimum length of log messages
    int max_length = -1;
    int min_length = 1000000;

    // initializing variable to hold total length of all log messages combined
    int total_length = 0;

    // initializing a variable to hold the current line being read from the log file
    char current_line[1000];

    // looping through the log file line by line
    while(fgets(current_line, 1000, log_file)){

        // counting the occurrence of each type of log message
        if(strstr(current_line, "INFO")){
            info_count++;
        }
        else if(strstr(current_line, "WARNING")){
            warning_count++;
        }
        else if(strstr(current_line, "ERROR")){
            error_count++;
        }

        // finding the maximum and minimum length of the log messages
        int current_length = strlen(current_line);
        if(current_length > max_length){
            max_length = current_length;
        }
        if(current_length < min_length){
            min_length = current_length;
        }

        // adding the length of current log message to the total length
        total_length += current_length;
    }

    printf("Log Analysis Results:\n\n");

    // printing the count of different types of log messages
    printf("Number of INFO messages: %d\n", info_count);
    printf("Number of WARNING messages: %d\n", warning_count);
    printf("Number of ERROR messages: %d\n", error_count);

    // printing the maximum, minimum and average length of the log messages
    printf("Maximum length of log messages: %d\n", max_length);
    printf("Minimum length of log messages: %d\n", min_length);
    printf("Average length of log messages: %d\n", total_length/(info_count+warning_count+error_count));

    printf("--------------------------------------------------------------------------------\n");

    // closing the log file
    fclose(log_file);

    return 0;
}