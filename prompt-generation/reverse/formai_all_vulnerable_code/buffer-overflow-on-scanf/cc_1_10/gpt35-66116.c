//FormAI DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC 32768

int PIDList[MAX_PROC], PIDCount = 0;

void ListProcIds();
void ListProcesses();

int main(int argc, char *argv[])
{
    char choice;

    printf("Welcome to the Process Viewer!\n\n");

    while (1)
    {
        printf("Menu:\n");
        printf("1. List running processes\n");
        printf("2. List process IDs\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                ListProcesses();
                break;

            case '2':
                ListProcIds();
                break;

            case '3':
                printf("\nThank you for using Process Viewer!\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n\n");
        }
    }
    return 0;
}

void ListProcesses()
{
    DIR *dir;
    struct dirent *dirEntry;
    char procPath[128];
    int PID, j = 0;

    printf("\n%-10s %-24s %-10s\n", "PID", "NAME", "STATE");

    dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("Error");
        exit(1);
    }

    while ((dirEntry = readdir(dir)) != NULL)
    {
        if ((strcmp(dirEntry->d_name, ".") == 0) || (strcmp(dirEntry->d_name, "..") == 0))
            continue;

        PID = atoi(dirEntry->d_name);

        if (PID == 0)
            continue;

        sprintf(procPath, "/proc/%d/status", PID);

        FILE *fp = fopen(procPath, "r");

        if (fp)
        {
            char line[256];
            char name[256];
            char state[256];

            while(fgets(line, sizeof(line), fp))
            {
                if (strncmp(line, "Name:", 5) == 0)
                {
                    sscanf(line + 6, "%s", name);
                }

                if (strncmp(line, "State:", 6) == 0)
                {
                    sscanf(line + 7, "%s", state);
                }
            }

            fclose(fp);

            if (strlen(name) > 0 && strlen(state) > 0)
            {
                printf("%-10d %-24s %-10s\n", PID, name, state);
                PIDList[j++] = PID;
            }
        }
    }

    PIDCount = j;

    closedir(dir);
}

void ListProcIds()
{
    if (PIDCount == 0)
    {
        printf("\nNo processes have been listed yet.\n\n");
        return;
    }

    printf("\nProcess IDs:\n");
    for (int i = 0; i < PIDCount; i++)
    {
        printf("%d ", PIDList[i]);
    }

    printf("\n\n");
}