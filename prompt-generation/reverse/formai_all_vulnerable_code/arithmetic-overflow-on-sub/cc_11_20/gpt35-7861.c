//FormAI DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Check if the program has been given at least one command line argument
    if (argc < 2) {
        printf("Please pass the path of a log file as a command line argument.\n");
        return 1;
    }
    
    FILE *log_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Open the log file
    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Could not open log file.\n");
        return 1;
    }
    
    char *ip_addresses[100];
    int ip_count[100] = { 0 };
    int unique_ips = 0;
    int total_lines = 0;
    
    while ((read = getline(&line, &len, log_file)) != -1) {
        // Remove trailing newline character from the line
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
        }
        
        // Extract the ip address from the log line
        char *ip = strtok(line, " ");
        if (ip) {
            // Check if this is a new ip address
            int i;
            for (i = 0; i < unique_ips; i++) {
                if (strcmp(ip_addresses[i], ip) == 0) {
                    break;
                }
            }
            // If it is a new ip address, add it to the array and increment unique_ips
            if (i == unique_ips) {
                ip_addresses[unique_ips] = malloc(strlen(ip) + 1);
                strcpy(ip_addresses[unique_ips], ip);
                unique_ips++;
            }
            // Increment the count for this ip address
            ip_count[i]++;
            total_lines++;
        }
    }
    
    // Calculate the percentage of each ip address
    float ip_percentage[100];
    for (int i = 0; i < unique_ips; i++) {
        ip_percentage[i] = (float)ip_count[i] / total_lines * 100;
    }
    
    // Sort the ip addresses by count in descending order
    for (int i = 0; i < unique_ips-1; i++) {
        for (int j = 0; j < unique_ips-i-1; j++) {
            if (ip_count[j] < ip_count[j+1]) {
                // Swap the ip addresses
                char *temp_str = ip_addresses[j];
                ip_addresses[j] = ip_addresses[j+1];
                ip_addresses[j+1] = temp_str;
                // Swap the counts
                int temp_int = ip_count[j];
                ip_count[j] = ip_count[j+1];
                ip_count[j+1] = temp_int;
                // Swap the percentages
                float temp_float = ip_percentage[j];
                ip_percentage[j] = ip_percentage[j+1];
                ip_percentage[j+1] = temp_float;
            }
        }
    }
    
    // Print the analysis results
    printf("Total lines: %d\n", total_lines);
    
    printf("Unique ip addresses: %d\n", unique_ips);
    for (int i = 0; i < unique_ips; i++) {
        printf("%s: %d hits (%.2f%%)\n", ip_addresses[i], ip_count[i], ip_percentage[i]);
    }
    
    // Clean up allocated memory and close the log file
    for (int i = 0; i < unique_ips; i++) {
        free(ip_addresses[i]);
    }
    fclose(log_file);
    if (line) {
        free(line);
    }
    
    return 0;
}