//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/* Function that returns the process name given the process id */
char* process_name(int pid)
{
    char *name = malloc(sizeof(char) * 1024);

    sprintf(name, "/proc/%d/cmdline", pid);
    FILE *file = fopen(name, "r");

    if (file != NULL) {
        fgets(name, 1024, file);
        fclose(file);

        char *pos = strstr(name, "\0");
        while (pos > name && isspace(*--pos));
        *++pos = '\0';
    }

    return name;
}

/* Function that returns the current memory usage given the process id */
long int memory_usage(int pid)
{
    char *name = malloc(sizeof(char) * 1024);

    sprintf(name, "/proc/%d/statm", pid);
    FILE *file = fopen(name, "r");

    long int usage = 0;

    if (file != NULL) {
        fscanf(file, "%ld %ld", &usage, &usage);
        fclose(file);
    }

    free(name);

    return usage * sysconf(_SC_PAGESIZE);
}

/* Function to display the process information */
void display_process_info(int pid)
{
    printf("---------------------------------\n");
    printf("Process ID: %d\n", pid);
    printf("Process Name: %s\n", process_name(pid));
    printf("Memory Usage: %ld bytes\n", memory_usage(pid));
    printf("---------------------------------\n");
}

/* Main function */
int main(int argc, char *argv[])
{
    printf("Welcome to the hilarious process viewer!\n");

    DIR *directory = opendir("/proc");
    struct dirent *entry;

    while ((entry = readdir(directory))) {
        if (isdigit(*entry->d_name)) {
            int pid = atoi(entry->d_name);
            display_process_info(pid);
        }
    }

    printf("We hope you enjoyed the show! Exiting...\n");

    closedir(directory);

    return 0;
}