//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BLOCK_SIZE 4096

int main()
{
    int total_blocks = 0;
    int free_blocks = 0;
    char disk_path[] = "/path/to/your/disk";

    // Calculate the total number of blocks on the disk
    struct stat stat_buf;
    stat(disk_path, &stat_buf);
    total_blocks = (stat_buf.st_size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    // Calculate the number of free blocks on the disk
    FILE *fp = fopen(disk_path, "r");
    if (fp)
    {
        char block[BLOCK_SIZE];
        while (fread(block, BLOCK_SIZE, 1, fp) == 1)
        {
            int is_free = 1;
            for (int i = 0; i < BLOCK_SIZE; i++)
            {
                if (block[i] != 0)
                {
                    is_free = 0;
                    break;
                }
            }

            if (is_free)
            {
                free_blocks++;
            }
        }

        fclose(fp);
    }

    // Print the results
    printf("Total blocks: %d\n", total_blocks);
    printf("Free blocks: %d\n", free_blocks);
    printf("Free space: %.2f%%", (free_blocks * 100.0) / total_blocks);

    return 0;
}