//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0, j = 0, k = 0, cpu_usage = 0, total_usage = 0;
    FILE* file_ptr = NULL;

    // Open a file to write data
    file_ptr = fopen("cpu_usage.txt", "w");

    // Loop for 5 minutes
    for (i = 0; i < 5; i++)
    {
        // Calculate the CPU usage
        cpu_usage = get_cpu_usage();

        // Write the CPU usage to the file
        fprintf(file_ptr, "%d\n", cpu_usage);

        // Increment the total usage
        total_usage += cpu_usage;

        // Sleep for 1 minute
        sleep(1);
    }

    // Close the file
    fclose(file_ptr);

    // Print the total usage
    printf("Total CPU usage: %d\n", total_usage);

    return 0;
}

int get_cpu_usage()
{
    char command[MAX_BUFFER_SIZE];
    FILE* pipe_ptr = NULL;
    int output = 0;

    // Create a command to get the CPU usage
    sprintf(command, "top -b -n 1 | awk 'NR == 2' | awk '{ print $2 }'");

    // Open a pipe to the command
    pipe_ptr = popen(command, "r");

    // Read the output of the command
    fscanf(pipe_ptr, "%d", &output);

    // Close the pipe
    pclose(pipe_ptr);

    // Return the CPU usage
    return output;
}