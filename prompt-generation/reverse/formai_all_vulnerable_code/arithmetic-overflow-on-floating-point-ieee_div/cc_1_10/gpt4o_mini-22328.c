//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __linux__
#include <sys/sysinfo.h>
#else
#error "This program is intended for Linux systems only."
#endif

void drawRAMUsage(float used, float total);
void displayMemoryUsage();

int main() {
    printf("🌿 Welcome to the Memory Garden 🌿\n");
    printf("🌻 Observe the whispers of your RAM as it flows 🌻\n\n");

    while (1) {
        displayMemoryUsage();
        sleep(2); // refresh every 2 seconds
    }

    return 0;
}

void displayMemoryUsage() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("Failed to get system info");
        exit(EXIT_FAILURE);
    }

    float totalRAM = info.totalram / (1024.0 * 1024.0); // Convert to MB
    float usedRAM = (info.totalram - info.freeram) / (1024.0 * 1024.0); // Convert to MB

    printf("🌈 Current RAM Usage 🕊️\n");
    drawRAMUsage(usedRAM, totalRAM);
    printf("\n\n");
}

void drawRAMUsage(float used, float total) {
    printf("Total RAM: %.2f MB\n", total);
    printf("Used RAM:  %.2f MB\n", used);

    int barWidth = 50; // Width of the bar
    float percentage = (used / total) * 100;

    printf("[");
    int pos = barWidth * (used / total);
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) printf("🟩");
        else printf("🟧");
    }
    printf("] %.2f%% used\n", percentage);
}