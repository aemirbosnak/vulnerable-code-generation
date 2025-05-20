//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void romantic_intro() {
    printf("In the quiet corners of the night, as stars whisper their secrets, \n");
    printf("Let us embark on a journey to explore the intimate embrace of memory.\n\n");
}

void display_ram_usage() {
    FILE *file;
    long total_memory, free_memory;
    char buffer[256];

    file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Could not open /proc/meminfo");
        return;
    }

    // Read total and free memory
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            break;
        }
    }
    fclose(file);

    // Calculate used memory
    long used_memory = total_memory - free_memory;

    // Romantic output of memory usage
    printf("Oh beloved RAM, how you gracefully carry the weight of our tasks.\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Let us cherish these values as we dance through the realms of computation.\n\n");
}

void romantic_wait(int seconds) {
    printf("As we breathe in this moment, let us wait, lingering in the sweetness of time...\n");
    for (int i = seconds; i > 0; i--) {
        printf("Waiting for %d seconds...\n", i);
        sleep(1);
    }
    printf("Ah, time flies like a whispered promise...\n\n");
}

int main() {
    romantic_intro();
    
    while (1) {
        display_ram_usage();
        romantic_wait(5);
    }

    return 0;
}