//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define THERMAL_ZONE_FILE "/sys/class/thermal/zone0/temp"
#define THERMAL_ZONE_FILE_RW "/sys/class/thermal/zone0/temp"

int main()
{
    FILE *fp;
    int temperature, zone_temp;
    char buffer[256];

    if ((fp = fopen(THERMAL_ZONE_FILE_RW, "r")) == NULL)
    {
        perror("Error opening thermal zone file");
        exit(1);
    }

    while (1)
    {
        sleep(1);

        if (fscanf(fp, "%d", &temperature) != 1)
        {
            perror("Error reading temperature");
            exit(1);
        }

        printf("Current temperature: %d\n", temperature);

        zone_temp = temperature;

        if (zone_temp > 80)
        {
            printf("WARNING: Zone temperature exceeded 80 degrees!\n");
        }

        if (zone_temp < 20)
        {
            printf("WARNING: Zone temperature below 20 degrees!\n");
        }

        snprintf(buffer, 256, "Thermal zone temp: %d", zone_temp);
        write(1, buffer, strlen(buffer) + 1);
    }

    fclose(fp);

    return 0;
}