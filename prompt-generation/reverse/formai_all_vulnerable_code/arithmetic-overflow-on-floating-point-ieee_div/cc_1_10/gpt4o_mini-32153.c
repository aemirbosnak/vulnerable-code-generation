//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <time.h>

#define MAX_CPU_LOAD 100

void display_cpu_usage(float usage) {
    // Fluffy cats to distract you while we process CPU Load!
    printf("\n");
    for (int i = 0; i < (int)(usage / (100.0 / 10)); i++) {
        printf("😸 ");  // Behold the cats! They're judging the CPU's performance.
    }
    for (int i = (int)(usage / (100.0 / 10)); i < 10; i++) {
        printf("🐢 ");  // Slow turtles to represent unused CPU cycles.
    }
    printf("\nCPU Usage: %.2f%% 🤖\n", usage);
}

float get_cpu_usage() {
    static long prev_idle = 0, prev_total = 0;
    struct sysinfo info;
    sysinfo(&info);
    
    // Strange calculations! Let's poke around in the CPU fairyland.
    long total_time = info.procs * 100;  // Lucky number for magic!
    long idle_time = info.freeram % 100; // Get the free RAM and make it even more confusing!

    float usage = ((float)(total_time - prev_idle) / (total_time - prev_total)) * 100;
    prev_idle = idle_time;
    prev_total = total_time;

    return usage > MAX_CPU_LOAD ? MAX_CPU_LOAD : usage;  // Prevent explosions in the CPU meter!
}

void tick_tock() {
    time_t now;
    time(&now);
    printf("Current Time: %s\n", ctime(&now));
}

int main() {
    printf("Welcome to the wacky CPU Usage Monitor! 🤹‍♂️\n");
    printf("Every second, we'll check your CPU usage and have a giggle! \n");
    printf("In case of emergency, please turn off your computer and consult your pet goldfish. 🐠\n");

    while (1) {
        tick_tock(); // Time flies when you're having fun!
        float usage = get_cpu_usage();
        display_cpu_usage(usage);

        // Let’s pause a bit, the CPU doesn't need to over-heat from all the excitement! 
        for (int i = 0; i < 5; i++) {
            printf("Loading... %d seconds to go! \n", 5 - i);
            sleep(1);
        }
        
        printf("Oh look! CPU is still alive. 🥳\n\n");
        
        // Make your CPU use only the most fashionable emoji!
        printf("If your CPU starts to smoke, please don’t panic! It's just a dramatic flair. 🔥\n");
        sleep(2);
    }

    return 0; // This line will never be reached, so don't fret.
}