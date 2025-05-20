//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

// Define the maximum possible number of processes
#define MAX_PROCESSES 65536

// Define the maximum length of the process command line
#define MAX_COMMAND_LINE_LENGTH 4096

// Define the path of the "/proc" directory
#define PROC_DIRECTORY "/proc"

// Define the name of the executable process viewer file
#define EXECUTABLE_NAME "myprocviewer"

// Define the process struct
typedef struct {
    int pid;
    char command[MAX_COMMAND_LINE_LENGTH];
} process_t;

// Main function
int main(int argc, char **argv) {

    // Define a process array
    process_t *proc_array;

    // Allocate memory for the process array
    proc_array = (process_t *) malloc(MAX_PROCESSES * sizeof(process_t));

    // Define a pointer to the process directory
    DIR *proc_dir;

    // Open the process directory
    proc_dir = opendir(PROC_DIRECTORY);

    // Check if the process directory was opened successfully
    if (proc_dir == NULL) {
        printf("Error: Could not open the process directory (%s).\n", PROC_DIRECTORY);
        return -1;
    }

    // Define a pointer to the current directory entry
    struct dirent *dir_entry;

    // Define a counter for the number of processes in the process array
    int num_processes = 0;

    // Iterate over each directory entry in the process directory
    while ((dir_entry = readdir(proc_dir)) != NULL) {

        // Check if the current entry is a directory
        if (dir_entry->d_type == DT_DIR) {

            // Convert the directory name to an integer
            int pid = atoi(dir_entry->d_name);

            // Check if the conversion was successful
            if (pid > 0) {

                // Define a pointer to the current process command line file
                char command_file_path[MAX_COMMAND_LINE_LENGTH];
                sprintf(command_file_path, "%s/%d/cmdline", PROC_DIRECTORY, pid);
                FILE *command_file = fopen(command_file_path, "r");

                // Check if the command line file was opened successfully
                if (command_file != NULL) {

                    // Read the command line of the process
                    char command_line[MAX_COMMAND_LINE_LENGTH];
                    fgets(command_line, MAX_COMMAND_LINE_LENGTH, command_file);

                    // Close the command line file
                    fclose(command_file);

                    // Remove the trailing newline character from the command line
                    command_line[strcspn(command_line, "\n")] = '\0';

                    // Copy the process information into the process array
                    proc_array[num_processes].pid = pid;
                    strcpy(proc_array[num_processes].command, command_line);

                    // Increment the number of processes in the process array
                    num_processes++;
                }
            }
        }
    }

    // Close the process directory
    closedir(proc_dir);

    // Sort the process array by process ID
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (proc_array[i].pid > proc_array[j].pid) {
                process_t temp = proc_array[i];
                proc_array[i] = proc_array[j];
                proc_array[j] = temp;
            }
        }
    }

    // Print the process table header
    printf("%-10s %-s\n", "PID", "COMMAND");

    // Print a separator line between the header and the process table
    for (int i = 0; i < 80; i++) {
        putchar('-');
    }
    putchar('\n');

    // Print the process table
    for (int i = 0; i < num_processes; i++) {
        printf("%-10d %-s\n", proc_array[i].pid, proc_array[i].command);
    }

    // Free the memory allocated for the process array
    free(proc_array);

    return 0;
}