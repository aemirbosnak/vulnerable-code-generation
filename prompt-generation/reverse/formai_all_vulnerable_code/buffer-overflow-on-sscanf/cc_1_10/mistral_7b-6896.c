//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_VARS 10
#define MAX_VALUE 256

char *envp[MAX_VARS];
char config_file[MAX_LINE];
char line[MAX_LINE];
char var_name[MAX_VALUE];
char var_value[MAX_VALUE];

int main(int argc, char **argv) {
    int fd;
    int i = 0;

    // Check if a configuration file is provided as an argument
    if (argc > 1) {
        strcpy(config_file, argv[1]);
    } else {
        fprintf(stderr, "Usage: %s <configuration_file>\n", argv[0]);
        exit(1);
    }

    // Open the configuration file
    fd = open(config_file, O_RDONLY);
    if (fd < 0) {
        perror("Error opening configuration file");
        exit(1);
    }

    // Read the configuration file line by line
    while (fgets(line, MAX_LINE, fd) != NULL) {
        // Parse each line into variable name and value
        sscanf(line, "%s=%s", var_name, var_value);

        // Set environment variable
        if ((envp[i] = malloc(strlen(var_name) + strlen(var_value) + 2)) == NULL) {
            perror("Error allocating memory for environment variable");
            exit(1);
        }
        strcpy(envp[i], var_name);
        strcat(envp[i], "=");
        strcat(envp[i], var_value);

        i++;

        // Limit the number of environment variables
        if (i >= MAX_VARS) {
            fprintf(stderr, "Too many variables in configuration file\n");
            exit(1);
        }
    }

    // Close the configuration file
    close(fd);

    // Start the background process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(1);
    } else if (pid > 0) {
        printf("Started background process with PID %d\n", pid);
    } else {
        // Child process
        execvp("./my_program", &argv[1]);
        perror("Error executing my_program");
        exit(1);
    }

    // Free environment variables and exit parent process
    for (int j = 0; j <= i; j++) {
        free(envp[j]);
    }

    return 0;
}