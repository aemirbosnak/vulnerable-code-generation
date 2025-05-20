//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void displayMemoryUsage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        printf("Oops! I couldn't read any memory information. Are we out of memory? 😱\n");
        return;
    }

    char line[256];
    long total_memory = 0;
    long free_memory = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            // Got total memory
        }
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            // Got free memory
        }
    }
    
    fclose(file);    

    long used_memory = total_memory - free_memory;

    printf("🔍 Memory Usage Report! 🔍\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("\n");

    if (used_memory < total_memory * 0.25) {
        printf("🎉 Congrats! You are using less than 25%% of your RAM!\n");
    } else if (used_memory < total_memory * 0.5) {
        printf("😐 You are in the comfortable zone! Using 25%% to 50%% of RAM.\n");
    } else if (used_memory < total_memory * 0.75) {
        printf("😳 Caution! You're using 50%% to 75%% of your RAM. It's getting a bit cozy!\n");
    } else {
        printf("🔥 Warning! You're using more than 75%% of your RAM! Time to close some tabs!\n");
    }
}

void pokeTheSquid() {
    printf("🐙 Poke the squid! Just for fun...\n");
    for (int i = 0; i < 5; i++) {
        printf("Poke %d! 🐙\n", i + 1);
        sleep(1);
    }
    printf("Squid is now awake! What a strange creature!\n\n");
}

int main() {
    while (1) {
        printf("⌛ Checking RAM usage...\n");
        displayMemoryUsage();
        pokeTheSquid();

        printf("⏱️ I will check again in 5 seconds...\n");
        sleep(5);
    }
    
    return 0;
}