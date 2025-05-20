//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of a word in a sentence
int count_word_frequency(char *sentence, char *word) {
    int count = 0;
    char *token;
    char *delim = " ";
    token = strtok(sentence, delim);
    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, delim);
    }
    return count;
}

// Function to read a log file and count the frequency of HTTP status codes
void analyze_log_file(FILE *log_file) {
    char line[1024];
    char *response_code;
    int status_code;
    int total_requests = 0;
    int total_responses = 0;

    // Initialize the frequency count for each HTTP status code
    int status_code_count[11] = {0};

    while (fgets(line, sizeof(line), log_file)!= NULL) {
        total_requests++;
        response_code = strstr(line, " ");
        response_code += 9;
        status_code = atoi(response_code);
        status_code_count[status_code / 100]++;
        total_responses++;
    }

    // Calculate the percentage of each HTTP status code
    for (int i = 0; i < 11; i++) {
        status_code_count[i] = (int) ((double) status_code_count[i] / total_responses * 100);
    }

    // Print the results
    printf("Total requests: %d\n", total_requests);
    printf("Total responses: %d\n", total_responses);
    printf("HTTP status code frequency:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%dxx: %d (%d%%)\n", i, status_code_count[i], status_code_count[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char log_file_path[1024];
    printf("Enter the path to the log file: ");
    scanf("%s", log_file_path);
    log_file = fopen(log_file_path, "r");
    if (log_file == NULL) {
        printf("Error: could not open log file\n");
        return 1;
    }
    analyze_log_file(log_file);
    fclose(log_file);
    return 0;
}