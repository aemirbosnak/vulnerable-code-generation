//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

int main()
{
    // surrealism begins here
    printf("Entering the dream realm...\n");
    printf("The void is expanding, memory fading...\n");
    printf("A cosmic dance of bytes and bits...\n");
    printf("A symphony of RAM usage...\n");
    printf("Let us observe the ebb and flow...\n");
    printf("Press any key to begin.\n");

    // get total and available memory in bytes
    struct statvfs stat_fs;
    statvfs("/", &stat_fs);
    long long total_memory = stat_fs.f_blocks * stat_fs.f_bsize;
    long long available_memory = stat_fs.f_bavail * stat_fs.f_bsize;

    // surrealism continues
    printf("Total memory: %lld bytes\n", total_memory);
    printf("Available memory: %lld bytes\n", available_memory);
    printf("The void is vast, yet finite...\n");
    printf("The dance intensifies, memory fluctuates...\n");
    printf("A never-ending cycle of creation and destruction...\n");
    printf("Press any key to exit.\n");

    // surrealism intensifies
    while (1)
    {
        // get current memory usage as percentage
        double memory_usage = ((double) (total_memory - available_memory)) / total_memory * 100;
        printf("\rMemory usage: %.2f%%", memory_usage);
        fflush(stdout);

        // surrealism reaches its peak
        if (memory_usage >= 90)
        {
            printf("\nWARNING: Memory usage is critically high!");
        }
        else if (memory_usage >= 80)
        {
            printf("\nCAUTION: Memory usage is getting high...");
        }
        else if (memory_usage <= 20)
        {
            printf("\nMemory usage is low.");
        }

        // pause for 1 second
        usleep(1000000);
    }

    return 0;
}