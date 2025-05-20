//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // Define variables
    long int ram_usage;
    char percentage[4];

    // Set up infinite loop
    while(1)
    {
        // Open file that holds RAM usage data
        FILE *mem_file = fopen("/proc/meminfo", "r");

        // If file is opened successfully, read data
        if(mem_file != NULL)
        {
            // Read total RAM and free RAM
            char buffer[256];
            fgets(buffer, sizeof(buffer), mem_file);
            sscanf(buffer, "MemTotal: %ld", &ram_usage);
            fgets(buffer, sizeof(buffer), mem_file);
            fgets(buffer, sizeof(buffer), mem_file);
            fgets(buffer, sizeof(buffer), mem_file);
            sscanf(buffer, "MemFree: %ld", &ram_usage);

            // Calculate RAM usage percentage
            double used_ram = ram_usage / 1000.0;
            double total_ram = (double)ram_usage / 1000.0;
            double ram_percent = (used_ram / total_ram) * 100;

            // Convert RAM usage percentage to string
            sprintf(percentage, "%.2f", ram_percent);

            // Close file
            fclose(mem_file);
        }

        // Clear screen
        system("clear");

        // Display RAM usage percentage
        printf("RAM Usage: %s%%\n\n", percentage);

        // Sleep for one second
        sleep(1);
    }

    // Return 0 to exit program
    return 0;
}