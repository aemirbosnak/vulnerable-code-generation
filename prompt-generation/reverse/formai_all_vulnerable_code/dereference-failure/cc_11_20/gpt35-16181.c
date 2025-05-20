//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    // Set the name of the system's process directory
    const char* process_dir = "/proc/";

    // Set the maximum length of the process ID
    const unsigned int MAX_PID_LENGTH = 10;

    // Set the max directory entry length
    const unsigned int MAX_DIRENT_LENGTH = 256;

    DIR* dir;
    struct dirent* direntry;

    // Open the process directory
    if ((dir = opendir(process_dir)) == NULL) {
        perror("Error opening directory\n");
        exit(EXIT_FAILURE);
    }

    // Read the entries of the directory
    while ((direntry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and the name is numerical
        if (direntry->d_type == DT_DIR) {
            const char* pid = direntry->d_name;

            // Validate that the name is numerical
            for (int i = 0; i < strlen(pid); i++) {
                if (pid[i] < '0' || pid[i] > '9') {
                    pid = NULL;
                    break;
                }
            }

            // If it is numerical, print the information about the process
            if (pid != NULL) {
                // Set the max file path length
                const unsigned int MAX_FILE_PATH_LENGTH = strlen(process_dir) + strlen(pid) + MAX_PID_LENGTH;

                // Set the file paths for the data we will retrieve
                char stat_filepath[MAX_FILE_PATH_LENGTH];
                char cmdline_filepath[MAX_FILE_PATH_LENGTH];

                // Build the file paths using the process id
                sprintf(stat_filepath, "%s%s/stat", process_dir, pid);
                sprintf(cmdline_filepath, "%s%s/cmdline", process_dir, pid);

                // Open the stat file for reading
                FILE* stat_file = fopen(stat_filepath, "r");
                if (stat_file == NULL) {
                    continue;
                }

                // Read the stat file and extract the information we want
                char* line = NULL;
                size_t len = 0;

                getline(&line, &len, stat_file);
                char* token = strtok(line, " ");
                int column = 0;
                char* pid_str;
                char* comm_str;

                // Iterate through space separated string
                while (token != NULL) {
                    if (column == 0) {
                        // Extract process ID
                        pid_str = token;
                    } else if (column == 1) {
                        // Extract the command string
                        comm_str = token+1; // skip first character (open parenthesis)
                        comm_str[strlen(comm_str)-1] = 0; // remove last character (close parenthesis)
                        break;
                    }

                    // Move to the next token
                    token = strtok(NULL, " ");
                    column++;
                }

                // Close the stat file
                fclose(stat_file);

                // Open the command line file for reading
                FILE* cmdline_file = fopen(cmdline_filepath, "r");
                if (cmdline_file == NULL) {
                    continue;
                }

                // Read the command line and print the information
                char cmdline[256] = "";
                fgets(cmdline, 256, cmdline_file);
                fclose(cmdline_file);

                printf("%-10s%-50s%-50s\n", pid_str, comm_str, cmdline);
            }
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}