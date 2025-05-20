//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define BLOCK_SIZE 4096

int main()
{
    char path[256];
    struct stat stat_buf;
    long long total_blocks, used_blocks, free_blocks;
    long long total_size, used_size, free_size;
    int i, j;
    FILE *fp;

    printf("Enter the path to the disk: ");
    scanf("%s", path);

    if (stat(path, &stat_buf) != 0)
    {
        perror("Error stat()ing the disk");
        exit(1);
    }

    total_blocks = stat_buf.st_blocks;
    used_blocks = stat_buf.st_size / BLOCK_SIZE;
    free_blocks = total_blocks - used_blocks;

    total_size = total_blocks * BLOCK_SIZE;
    used_size = used_blocks * BLOCK_SIZE;
    free_size = total_size - used_size;

    printf("\nDisk Space Analyzer\n");
    printf("------------------------\n");
    printf("Total Blocks: %lld\n", total_blocks);
    printf("Used Blocks: %lld\n", used_blocks);
    printf("Free Blocks: %lld\n", free_blocks);
    printf("Total Size: %lld MB\n", total_size / 1024 / 1024);
    printf("Used Size: %lld MB\n", used_size / 1024 / 1024);
    printf("Free Size: %lld MB\n", free_size / 1024 / 1024);

    fp = fopen("disk_usage.txt", "w");
    fprintf(fp, "Disk Space Usage\n");
    fprintf(fp, "------------------------\n");
    fprintf(fp, "Total Blocks: %lld\n", total_blocks);
    fprintf(fp, "Used Blocks: %lld\n", used_blocks);
    fprintf(fp, "Free Blocks: %lld\n", free_blocks);
    fprintf(fp, "Total Size: %lld MB\n", total_size / 1024 / 1024);
    fprintf(fp, "Used Size: %lld MB\n", used_size / 1024 / 1024);
    fprintf(fp, "Free Size: %lld MB\n", free_size / 1024 / 1024);

    fclose(fp);

    return 0;
}