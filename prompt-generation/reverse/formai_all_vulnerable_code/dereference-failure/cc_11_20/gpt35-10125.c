//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    //Open the /proc directory to read the process IDs
    if (!(dir = opendir("/proc")))
    {
        perror("Couldn't open the directory\n");
        return 1;
    }

    //Traverse through the directory
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_DIR && atoi(entry->d_name))
        {
            int pid = atoi(entry->d_name);
            char path[50];
            sprintf(path, "/proc/%d/status", pid);
            FILE *fp = fopen(path, "r");
            char line[128];
            char name[30];
            int status;

            //Read the process name and status from the /proc/PID/status file
            while (fgets(line, 128, fp) != NULL)
            {
                if (sscanf(line, "Name: %s", name) == 1)
                {
                    //Print the process name and ID
                    printf("Process name: %s (PID %d)\n", name, pid);
                    break;
                }
                if (sscanf(line, "State: %d", &status) == 1)
                {
                    //Print the state of the process
                    if (status == 0)
                        printf("Status: Running\n");
                    else if (status == 1 || status == 2 || status == 4)
                        printf("Status: Sleeping\n");
                    else
                        printf("Status: Stopped\n");

                    break;
                }
            }

            fclose(fp);
        }
    }

    closedir(dir);
    return 0;
}