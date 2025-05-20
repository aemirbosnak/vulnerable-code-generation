//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

#define MB 1048576

void print_usage(double usage)
{
    if (usage >= 90)
    {
        printf("WARNING: Your disk usage is at %.2f%%. Free up some space immediately!\n", usage);
    }
    else if (usage >= 75)
    {
        printf("Your disk usage is at %.2f%%. Consider freeing up some space.\n", usage);
    }
    else
    {
        printf("Your disk usage is at %.2f%%. You have plenty of free space.\n", usage);
    }
}

void print_stats(char *path, double total_space, double used_space, double free_space)
{
    printf("\nDisk space statistics for %s:\n", path);
    printf("Total space: %.2f MB\n", total_space / MB);
    printf("Used space: %.2f MB\n", used_space / MB);
    printf("Free space: %.2f MB\n", free_space / MB);
    double usage = (used_space / total_space) * 100;
    print_usage(usage);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    char *path = argv[1];
    struct statvfs stats;
    if (statvfs(path, &stats) != 0)
    {
        perror("Error getting disk space information");
        return 1;
    }
    double total_space = (double)stats.f_blocks * (double)stats.f_frsize;
    double free_space = (double)stats.f_bfree * (double)stats.f_frsize;
    double used_space = total_space - free_space;
    print_stats(path, total_space, used_space, free_space);
    return 0;
}