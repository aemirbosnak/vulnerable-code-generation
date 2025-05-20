//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100000
#define MAX_URL_LENGTH 2048
#define MAX_AGENT_LENGTH 256

typedef struct {
    char ip[16];
    char agent[MAX_AGENT_LENGTH];
    char url[MAX_URL_LENGTH];
    int status_code;
    int bytes_sent;
    int time_taken;
    char timestamp[32];
} LogEntry;

int main(int argc, char *argv[]) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_filename[MAX_URL_LENGTH];
    char output_filename[MAX_URL_LENGTH];
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    int i, j;

    // Get input and output file names from command line arguments
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file %s\n", input_filename);
        return 1;
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file %s\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Read log entries from input file
    while (fscanf(input_file, "%s %s %s %d %d %d [%s]\n", 
                   log_entries[num_entries].ip, log_entries[num_entries].agent, 
                   log_entries[num_entries].url, &log_entries[num_entries].status_code, 
                   &log_entries[num_entries].bytes_sent, &log_entries[num_entries].time_taken, 
                   log_entries[num_entries].timestamp) == 7) {
        num_entries++;
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Maximum number of log entries exceeded\n");
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
    }

    fclose(input_file);

    // Write log entries to output file
    fprintf(output_file, "IP\tAgent\tURL\tStatus Code\tBytes Sent\tTime Taken\n");
    for (i = 0; i < num_entries; i++) {
        fprintf(output_file, "%s\t%s\t%s\t%d\t%d\t%d\n", 
                log_entries[i].ip, log_entries[i].agent, log_entries[i].url, 
                log_entries[i].status_code, log_entries[i].bytes_sent, log_entries[i].time_taken);
    }

    fclose(output_file);

    return 0;
}