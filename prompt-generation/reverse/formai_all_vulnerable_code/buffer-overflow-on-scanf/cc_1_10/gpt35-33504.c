//FormAI DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(void) {
    DIR *dir;
    struct dirent *ent;
    char path[100];
    char cmd[200];
    FILE *fp;

    printf("---------------------------------------\n");
    printf("--------C SYSTEM PROCESS VIEWER--------\n");
    printf("---------------------------------------\n");

    printf("Enter the path to check processes (ex: /proc):\n");
    scanf("%s", path);

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory\n");
        exit(EXIT_FAILURE);
    }

    printf("PID    |    Process Name             |   Memory Usage\n");
    printf("-----------------------------------------------------\n");

    while ((ent = readdir(dir)) != NULL) {

        // Check if entry is a directory
        if (ent->d_type == DT_DIR) {

            // Check if entry name is a number (PID) and not "." or ".." 
            if (atoi(ent->d_name) != 0 && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {

                printf("%-6s | ", ent->d_name);

                // Obtain process name
                sprintf(cmd, "cat /proc/%s/status | grep Name | awk '{print $2}'", ent->d_name);
                fp = popen(cmd, "r");
                fgets(path, sizeof(path)-1, fp);
                pclose(fp);
                path[strlen(path)-1] = '\0'; // remove newline character

                printf("%-25s | ", path);

                // Obtain memory usage
                sprintf(cmd, "cat /proc/%s/status | grep VmRSS | awk '{print $2}'", ent->d_name);
                fp = popen(cmd, "r");
                fgets(path, sizeof(path)-1, fp);
                pclose(fp);
                path[strlen(path)-1] = '\0'; // remove newline character

                printf("%-10s\n", path);
                
            }
        }
    }

    printf("-----------------------------------------------------\n");
    closedir(dir);

    return 0;
}