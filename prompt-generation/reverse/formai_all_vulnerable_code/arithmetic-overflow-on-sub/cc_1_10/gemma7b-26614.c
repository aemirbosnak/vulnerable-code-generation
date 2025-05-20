//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int free_space_kb, total_space_kb, used_space_kb;
    char *mount_point;

    // Get the mount point of the C disk
    mount_point = "/dev/sda";

    // Get the free space on the C disk in KB
    free_space_kb = get_free_space(mount_point);

    // Get the total space on the C disk in KB
    total_space_kb = get_total_space(mount_point);

    // Calculate the used space on the C disk in KB
    used_space_kb = total_space_kb - free_space_kb;

    // Print the results
    printf("C Disk Space Analyzer\n");
    printf("-------------------------\n");
    printf("Mount Point: %s\n", mount_point);
    printf("Total Space: %d KB\n", total_space_kb);
    printf("Free Space: %d KB\n", free_space_kb);
    printf("Used Space: %d KB\n", used_space_kb);
    printf("-------------------------\n");

    return 0;
}

int get_free_space(char *mount_point)
{
    int free_space_kb;
    FILE *fp;
    char command[256];

    sprintf(command, "df -h %s | awk 'NR==2'", mount_point);
    fp = popen(command, "r");
    fscanf(fp, "%d KB", &free_space_kb);
    pclose(fp);

    return free_space_kb;
}

int get_total_space(char *mount_point)
{
    int total_space_kb;
    FILE *fp;
    char command[256];

    sprintf(command, "df -h %s | awk 'NR==1'", mount_point);
    fp = popen(command, "r");
    fscanf(fp, "%d KB", &total_space_kb);
    pclose(fp);

    return total_space_kb;
}