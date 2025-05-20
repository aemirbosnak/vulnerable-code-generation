//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define SHAPESHIFT_INTERVAL 10 // in seconds

int main()
{
    int shapeshift_count = 0;
    struct sysinfo sys_info;
    long long total_ram;

    sysinfo(&sys_info);
    total_ram = (long long)sys_info.totalram * sys_info.mem_unit;

    printf("Starting C RAM usage monitor...\n");
    printf("Total RAM: %lld bytes\n", total_ram);

    while (1)
    {
        // Get system RAM usage
        sysinfo(&sys_info);
        long long free_ram = (long long)sys_info.freeram * sys_info.mem_unit;
        long long used_ram = total_ram - free_ram;

        // Shapeshift display style
        switch (shapeshift_count)
        {
            case 0:
                printf("      ^      \n");
                printf("    / | \\    \n");
                printf("   /  |  \\   \n");
                printf("  /___|___\\  \n");
                printf("     / \\     \n");
                printf("    /   \\    \n");
                printf("   /     \\   \n");
                printf("\n");
                break;
            case 1:
                printf("     ^ ^     \n");
                printf("    / | \\    \n");
                printf("   /  |  \\   \n");
                printf("  /___|___\\  \n");
                printf("     / \\     \n");
                printf("    /   \\    \n");
                printf("   /     \\   \n");
                printf("\n");
                break;
            case 2:
                printf("     ^ ^     \n");
                printf("    / | \\    \n");
                printf("   /  |  \\   \n");
                printf("  /___|___\\  \n");
                printf("     / \\     \n");
                printf("    /   \\    \n");
                printf("   /     \\   \n");
                printf("     | |     \n");
                break;
            case 3:
                printf("     ^ ^     \n");
                printf("    / | \\    \n");
                printf("   /  |  \\   \n");
                printf("  /___|___\\  \n");
                printf("     / \\     \n");
                printf("    /   \\    \n");
                printf("   /     \\   \n");
                printf("     | |     \n");
                printf("     | |     \n");
                break;
            default:
                shapeshift_count = 0;
        }

        printf("RAM Usage: %lld bytes\n\n", used_ram);

        // Increment shapeshift counter
        shapeshift_count++;

        // Pause for SHAPESHIFT_INTERVAL seconds
        sleep(SHAPESHIFT_INTERVAL);
    }

    return 0;
}