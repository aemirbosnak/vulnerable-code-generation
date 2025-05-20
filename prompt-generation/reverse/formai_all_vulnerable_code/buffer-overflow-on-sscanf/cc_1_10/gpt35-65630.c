//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(void) {
    char buffer[MAX_SIZE];
    char cmd[MAX_SIZE];
    int size = 0;
    int total_mem = 0;
    int free_mem = 0;
    int used_mem = 0;
    float usage = 0.0;

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while(1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
        // Copy the command into the buffer
        sprintf(cmd, "free -b | grep Mem | awk '{print $2\" \"$3\" \"$4}'");
        // Open the command for reading
        fp = popen(cmd, "r");
        if(fp == NULL) {
            printf("failed to execute the command\n");
        }
        // Read the output a line at a time
        while((read = getline(&line, &len, fp)) != -1) {
            //printf("%s", line);
            // Get the used memory
            sscanf(line, "%d %d %d", &total_mem, &used_mem, &free_mem);
            //printf("%d %d %d\n", total_mem, used_mem, free_mem);
        }

        // Calculate the usage percentage
        usage = used_mem * 100.0 / total_mem;
        // Clean up
        pclose(fp);
        if(line) {
            free(line);
        }

        // Clear the screen
        system("clear");
        printf("==================================================\n");
        printf("|                                                |\n");
        printf("|            C RAM Usage Monitor Example         |\n");
        printf("|                                                |\n");
        printf("==================================================\n");
        printf("\nTotal Memory: %d\n", total_mem);
        printf("Used Memory: %d\n", used_mem);
        printf("Free Memory: %d\n", free_mem);
        printf("Usage: %.2f%%\n", usage);

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}