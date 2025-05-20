//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
/*
 * This is a sample C Log analysis program that demonstrates the use of various statistical functions to extract 
 * meaningful insights from log data. The program reads log files from a directory, parses each log entry and 
 * performs various statistical operations on the log data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dirent.h>

// Define the maximum length of a log entry
#define MAX_LOG_ENTRY_LENGTH 1000

// Function to compute the mean of a log data set
double compute_mean(int* data, int data_size) {
    double sum = 0;
    for(int i=0;i<data_size;i++) {
        sum += data[i];
    }
    return sum / data_size;
}

// Function to compute the median of a log data set
double compute_median(int* data, int data_size) {
    // Sort the data first
    for(int i=0;i<data_size-1;i++) {
        for(int j=0;j<data_size-i-1;j++) {
            if(data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
    
    // If data set size is even
    if(data_size % 2 == 0) {
        int mid_index = data_size / 2;
        return (data[mid_index-1] + data[mid_index]) / 2.0;
    }
    // If data set size is odd
    else {
        int mid_index = floor(data_size / 2);
        return data[mid_index];
    }
}

// Function to compute the standard deviation of a log data set
double compute_stddev(int* data, int data_size) {
    double mean = compute_mean(data, data_size);
    double sum = 0;
    for(int i=0;i<data_size;i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / data_size);
}

int main() {
    // Define the path to the directory containing the log files
    char* log_directory = "/var/log";
    
    // Open the directory for reading
    DIR* dir;
    struct dirent* file;
    dir = opendir(log_directory);
    
    int log_entries_count = 0;
    int log_entries[MAX_LOG_ENTRY_LENGTH];
    
    // Process each log file in the directory
    while((file = readdir(dir)) != NULL) {
        // Open the log file for reading
        char log_file_path[1000];
        snprintf(log_file_path, sizeof log_file_path, "%s/%s", log_directory, file->d_name);
        FILE* log_file = fopen(log_file_path, "r");
        
        // Read each log entry from the log file and process it
        char log_entry[MAX_LOG_ENTRY_LENGTH];
        while(fgets(log_entry, MAX_LOG_ENTRY_LENGTH, log_file)) {
            // Parse the log entry and extract the log data
            // In this example, we assume that the log data is a single integer value
            char* log_data_str = strtok(log_entry, ",");
            int log_data = atoi(log_data_str);
            
            // Add the log data to the log_entries array
            log_entries[log_entries_count++] = log_data;
        }
        
        // Close the log file
        fclose(log_file);
    }
    
    // Compute statistics on the log data
    double mean = compute_mean(log_entries, log_entries_count);
    double median = compute_median(log_entries, log_entries_count);
    double stddev = compute_stddev(log_entries, log_entries_count);
    
    // Print the statistics to the console
    printf("Mean: %lf\n", mean);
    printf("Median: %lf\n", median);
    printf("Standard Deviation: %lf\n", stddev);
    
    return 0;
}