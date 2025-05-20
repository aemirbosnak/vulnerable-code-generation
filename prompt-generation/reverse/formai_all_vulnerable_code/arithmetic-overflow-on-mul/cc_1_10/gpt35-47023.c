//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define FUTURISTIC " \xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\x94\x80\xE2\x95\x90\xE2\xA0\xB9"
#define RAM_BAR "\xE2\x96\x8C"

int main()
{
    struct sysinfo info;
    long int total_ram, free_ram, used_ram;

    while (true)
    {
        sysinfo(&info);
        total_ram = (long int)info.totalram * (long int)info.mem_unit;
        free_ram = (long int)info.freeram * (long)info.mem_unit;
        used_ram = total_ram - free_ram;

        system("clear");

        printf(FUTURISTIC "\n");
        printf("\xE2\xA0\xA4 Total RAM: %ldMB\n", total_ram / 1024 / 1024);
        printf("\xE2\xA0\xA4 Used RAM: %ldMB\n", used_ram / 1024 / 1024);
        printf("\xE2\xA0\xA4 Free RAM: %ldMB\n", free_ram / 1024 / 1024);

        int used_percentage = (int)(used_ram * 100 / total_ram);
        printf("\n\n\t [ ");
        for (int i = 0; i < 50; i++)
        {
            if (i < used_percentage / 2)
            {
                printf(RAM_BAR);
            }
            else
            {
                printf(" ");
            }
        }
        printf(" ]  %d%%\n", used_percentage);

        printf(FUTURISTIC "\n");

        sleep(1);
    }

    return 0;
}