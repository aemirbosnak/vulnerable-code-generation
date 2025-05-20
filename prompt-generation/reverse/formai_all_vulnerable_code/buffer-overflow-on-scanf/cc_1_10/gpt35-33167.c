//FormAI DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *directory;
    struct dirent *dir_entry;
    char path[50] = "/proc/";
    int pid;
    char status_file[30] = "/status";
    char line[100];

    printf("\n~~~ Love Process Viewer ~~~\n\n");

    printf("My love, please input the Process ID that you want to view: ");
    scanf("%d", &pid);

    sprintf(path + strlen(path), "%d", pid);
    strcat(path, status_file);

    // Open the file
    FILE *status = fopen(path, "r");

    if (status == NULL)
    {
        printf("Oops! Something went wrong. Maybe the process does not exist.\n");
        return 1;
    }

    // Print the header of our viewer
    printf("My love, below are the details for the process with ID %d:\n\n", pid);

    // Read the status file line by line
    while (fgets(line, 100, status))
    {
        if (strstr(line, "Name"))
        {
            printf("Process Name: %s", line + 6);
        }
        else if (strstr(line, "State"))
        {
            printf("Process State: %s", line + 7);
        }
        else if (strstr(line, "PPid"))
        {
            printf("Parent Process ID: %s", line + 6);
        }
        else if (strstr(line, "Uid"))
        {
            printf("User ID: %s", line + 5);
        }
    }

    printf("\nLove, I hope you enjoyed seeing the process details!\n\n");

    // Close the file and directory
    fclose(status);
    closedir(directory);

    return EXIT_SUCCESS;
}