//FormAI DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Welcome to the Curious Log Analyzer!\n\n");

    // Ask user for log file name
    char file_name[50];
    printf("Please enter the name of the log file you would like to analyze: ");
    scanf("%s", file_name);
    printf("\n");

    // Open file for reading
    FILE *log_file = fopen(file_name, "r");
    if(log_file == NULL){
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    // Count total number of log entries in the file
    int num_entries = 0;
    char line[200];
    while(fgets(line, 200, log_file)){
        num_entries++;
    }

    // Display total number of log entries
    printf("Total number of log entries: %d\n\n", num_entries);

    // Reset file pointer to beginning of file
    fseek(log_file, 0, SEEK_SET);

    // Initialize arrays to store unique IP addresses and their count
    char ip_addresses[num_entries][20];
    int count[num_entries];
    int num_unique_ips = 0;

    // Loop through log entries and count unique IP addresses
    while(fgets(line, 200, log_file)){
        // Extract IP address from log entry
        char *ip = strtok(line, " ");
        ip = strtok(NULL, " ");

        // Check if IP address is already in array
        int already_exists = 0;
        for(int i=0; i<num_unique_ips; i++){
            if(strcmp(ip_addresses[i], ip) == 0){
                count[i]++;
                already_exists = 1;
                break;
            }
        }

        // Add IP address to array if it doesn't already exist
        if(!already_exists){
            strcpy(ip_addresses[num_unique_ips], ip);
            count[num_unique_ips] = 1;
            num_unique_ips++;
        }
    }

    // Display unique IP addresses and their count
    printf("Unique IP addresses in log file and their count:\n");
    for(int i=0; i<num_unique_ips; i++){
        printf("%s: %d\n", ip_addresses[i], count[i]);
    }
    printf("\n");

    // Find entry with longest response time
    int max_time = 0;
    char max_time_line[200];
    fseek(log_file, 0, SEEK_SET);
    while(fgets(line, 200, log_file)){
        // Extract response time from log entry
        char *time_str = strtok(line, " ");
        for(int i=0; i<6; i++){
            time_str = strtok(NULL, " ");
        }
        int time = atoi(time_str);

        // Update max time if necessary
        if(time > max_time){
            max_time = time;
            strcpy(max_time_line, line);
        }
    }

    // Display entry with longest response time
    printf("Log entry with longest response time:\n%s\n", max_time_line);

    // Close file and exit program
    fclose(log_file);
    return 0;
}