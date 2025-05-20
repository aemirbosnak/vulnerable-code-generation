//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 100

void printResults(int *result_array, int size);
void analyzeLog(char *filename);

int main()
{
    char filename[MAX_LINE_LENGTH];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    analyzeLog(filename);

    return 0;
}

// Function to print the results
void printResults(int *result_array, int size) {
    printf("----Results----\n");
    printf("Total number of requests: %d\n", result_array[0]);
    printf("Number of successful requests: %d\n", result_array[1]);
    printf("Number of failed requests: %d\n", result_array[2]);
}

// Function to analyze the log file
void analyzeLog(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int counts_array[3] = {0, 0, 0}; // To store the total number of requests, successful requests and failed requests respectively

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *token;

        // Count the total number of requests
        counts_array[0]++;

        // Check for successful and failed requests
        // Successful requests contain "200 OK"
        // Failed requests contain "404" or "500" or "503"
        token = strtok(line, " ");
        if(strncmp(token, "200", 3) == 0) {
            counts_array[1]++;
        } else if(strncmp(token, "404", 3) == 0 || strncmp(token, "500", 3) == 0 || strncmp(token, "503", 3) == 0) {
            counts_array[2]++;
        }
    }

    // Print the results
    printResults(counts_array, 3);
    
    // Close the file
    fclose(fp);
}