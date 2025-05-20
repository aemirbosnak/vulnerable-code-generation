//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Creating a file pointer
    FILE *fp;
    
    // Get current date/time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Create filename with date/time in the format: "syslog_YYYY-MM-DD_HH-MM-SS.log"
    char filename[50];
    sprintf(filename, "syslog_%04d-%02d-%02d_%02d-%02d-%02d.log", 
            t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    
    // Open the file in append mode
    fp = fopen(filename, "a");
    
    // Check if file was opened successfully
    if(fp == NULL){
        printf("Failed to open %s", filename);
        exit(1);
    }
    
    // Display message to user
    printf("System event logging started.\n");
    
    // Log system event - program started
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] Program started.\n", 
            t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    
    // Wait for user input to log system event
    char input[50];
    printf("Press any key to generate a system event.\n");
    scanf("%s", input);
    
    // Log system event - user input received
    fprintf(fp, "[%04d-%02d-%02d %02d:%02d:%02d] User input received: %s\n", 
            t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, input);
    
    // Close the file pointer
    fclose(fp);
    
    // Display message to user
    printf("System event logging complete.\n");
    
    // Exit the program
    return 0;
}