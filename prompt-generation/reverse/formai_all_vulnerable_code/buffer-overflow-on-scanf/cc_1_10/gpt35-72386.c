//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert size into human-readable format
void formatSize(float size, char *output)
{
    int i = 0;
    char units[] = "BKMGT";
    while (size > 1024)
    {
        size /= 1024;
        i++;
    }
    sprintf(output, "%.2f %cB", size, units[i]);
}

int main()
{
    // get the path to the directory
    char path[256];
    printf("Enter the path to the directory: ");
    scanf("%s", path);
    getchar();

    // run the command to get the disk usage
    char command[512];
    sprintf(command, "du -hd 1 %s", path);

    // open the pipe to read the output
    FILE *pipe = popen(command, "r");
    if (!pipe)
    {
        printf("Error: Failed to open pipe\n");
        return 1;
    }

    // iterate over the output to get the disk usage for each file
    char line[256];
    while (fgets(line, 256, pipe))
    {
        char *ptr = strchr(line, '\t');
        if (!ptr)
            continue;
        float size = atof(ptr);
        ptr[0] = '\0';
        char output[32];
        formatSize(size, output);
        printf("%-20s %s\n", line, output);
    }

    // close the pipe
    pclose(pipe);
    return 0;
}