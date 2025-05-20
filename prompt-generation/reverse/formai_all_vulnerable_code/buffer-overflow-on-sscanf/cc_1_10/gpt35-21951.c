//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the CPU Usage Monitor!\n");
    while(1)
    {
        system("clear"); // clears the screen for a fresh output

        printf("Checking CPU usage...\n");

        // open the file containing CPU usage information
        FILE *file = fopen("/proc/stat", "r");
        if (file == NULL) 
        {
            printf("Error: unable to open file.\n");
            continue;
        }

        // read and ignore the first line
        char buffer[256];
        fgets(buffer, 256, file);

        // read the second line (the one containing CPU usage info)
        fgets(buffer, 256, file); 
        fclose(file);

        // parse the line to get the CPU usage values
        int user, nice, system, idle, iowait, irq, softirq, steal;
        sscanf(buffer, "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

        // calculate total CPU usage
        int total = user + nice + system + idle + iowait + irq + softirq + steal;

        // calculate percentage of CPU usage by the user
        float percentage = (float)user/total * 100;

        // print the CPU usage value and a funny message to go with it
        printf("CPU usage: %.2f%%\n", percentage);

        if (percentage < 30)
        {
            printf("The CPU looks bored. Maybe give it something to do, like play Minesweeper?\n");
        } 
        else if (percentage < 60)
        {
            printf("The CPU is working hard, but not too hard. It's like a hamster on a wheel.\n");
        } 
        else if (percentage < 90)
        {
            printf("The CPU is starting to sweat. Maybe it needs a break and some Gatorade?\n");
        }
        else
        {
            printf("Stop! Hammer Time! The CPU is going to blow!\n");
        }

        // wait 5 seconds before checking CPU usage again
        sleep(5);
    }
    return 0;
}