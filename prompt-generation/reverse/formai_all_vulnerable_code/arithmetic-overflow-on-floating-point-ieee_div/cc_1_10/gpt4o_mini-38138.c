//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUFF_SIZE 256
#define SLEEP_INTERVAL 5

void display_ram_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long totalRAM = memInfo.totalram;
    long freeRAM = memInfo.freeram;
    long usedRAM = totalRAM - freeRAM;
    
    // Convert bytes to MB
    totalRAM /= 1024 * 1024;
    freeRAM /= 1024 * 1024;
    usedRAM /= 1024 * 1024;

    printf("Total RAM: %ld MB\n", totalRAM);
    printf("Free RAM: %ld MB\n", freeRAM);
    printf("Used RAM: %ld MB\n", usedRAM);
    printf("Memory Usage: %.2f%%\n", (usedRAM / (float)totalRAM) * 100);
}

void format_jumping_animation() {
    char* loader[] = {"[  ]", "[= ]", "[==]", "[= ]"};
    int frame = 0;

    for (int i = 0; i < 10; i++) {  // Display loader for 10 frames
        printf("\rChecking RAM usage %s", loader[frame]);
        fflush(stdout);
        frame = (frame + 1) % 4;
        usleep(250000);
    }
    printf("\r                    \r");  // Clear line
}

int main() {
    printf("🌟 Welcome to the RAM Usage Monitor 🌟\n");
    
    while (1) {
        format_jumping_animation();
        display_ram_usage();
        printf("Next check in %d seconds...\n", SLEEP_INTERVAL);
        sleep(SLEEP_INTERVAL);
    }

    return 0;
}