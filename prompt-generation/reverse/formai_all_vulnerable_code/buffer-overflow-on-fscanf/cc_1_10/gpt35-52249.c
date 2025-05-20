//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void printHeader();

int main()
{
    printHeader();
    DIR *dirp;
    struct dirent *dir;
    char path[256];
    FILE *file;
    const char *key = "VmSize:";
    char line[512], pid[12], pname[256], vmsize[32];
    dirp = opendir("/proc/");

    if (dirp == NULL)
    {
        printf("Error opening directory");
        exit(1);
    }

    while ((dir = readdir(dirp)) != NULL)
    {
        if (isdigit(*dir->d_name))
        {
            sprintf(path, "/proc/%s/stat", dir->d_name);
            file = fopen(path, "r");
            if (file == NULL)
                continue;

            fscanf(file, "%s ", pid);
            fscanf(file, "%s ", pname);
            fgets(line, 512, file);

            while (fgets(line, 512, file))
            {
                if (strstr(line, key) != NULL)
                {
                    sscanf(line, "%*s %s", vmsize);
                    printf("%-10s%-20s%-10s\n", pid, pname, vmsize);
                    break;
                }
            }

            fclose(file);
        }
    }

    closedir(dirp);
    return 0;
}

void printHeader(){
    printf("%-10s%-20s%-10s\n", "PID", "NAME", "VM SIZE");
}