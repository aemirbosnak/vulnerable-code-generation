//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PING_COUNT 4
#define BUFFER_SIZE 256

void execute_ping(const char *target) {
    // Construct the ping command with necessary parameters
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c %d %s", PING_COUNT, target);

    // Execute the ping command
    int status = system(command);
    if (status == -1) {
        perror("Failure executing ping command");
    }
}

void parse_ping_output(const char *target) {
    // Execute the ping command and redirect output to a temporary file
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c %d %s > temp_ping_output.txt 2>&1", PING_COUNT, target);
    
    // Execute the command
    int status = system(command);
    if (status == -1) {
        perror("Failure executing ping command");
        return;
    }

    // Open the temporary output file to read results
    FILE *file = fopen("temp_ping_output.txt", "r");
    if (file == NULL) {
        perror("Error opening temp ping output file");
        return;
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        // Print only relevant lines from the ping output
        if (strstr(line, "time=") != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);

    // Clean up the temporary file
    remove("temp_ping_output.txt");
}

int main() {
    char target[BUFFER_SIZE];
    
    printf("Enter the target IP address or domain to ping: ");
    scanf("%s", target);
    
    while (1) {
        printf("\nPinging %s...\n", target);
        parse_ping_output(target);
        
        printf("\nPress Ctrl+C to stop monitoring or wait for the next ping.\n");
        sleep(5); // Delay before the next ping
    }
    
    return 0;
}