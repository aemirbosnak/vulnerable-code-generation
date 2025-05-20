//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BOOT_ENTRIES 100
#define NAME_LENGTH 50
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[NAME_LENGTH];
    int loadTime;  // Load time in milliseconds
} BootEntry;

void delay(int milliseconds) {
    usleep(milliseconds * 1000); // usleep takes microseconds
}

void loadBootEntries(BootEntry *entries, int *count) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d", entries[*count].name, &entries[*count].loadTime) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void optimizeBootEntries(BootEntry *entries, int count) {
    printf("\n--- Optimizing Boot Process ---\n");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (entries[j].loadTime > entries[j + 1].loadTime) {
                BootEntry temp = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = temp;
            }
        }
    }

    printf("\n--- Optimized Boot Order ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d ms\n", entries[i].name, entries[i].loadTime);
    }
}

void executeBootEntries(BootEntry *entries, int count) {
    printf("\n--- Booting Your System ---\n");
    for (int i = 0; i < count; i++) {
        printf("Loading %s...\n", entries[i].name);
        delay(entries[i].loadTime);
        printf("%s loaded in %d ms!\n", entries[i].name, entries[i].loadTime);
    }
    printf("\n--- Boot Complete! Enjoy your journey! ---\n");
}

int main() {
    BootEntry entries[MAX_BOOT_ENTRIES];
    int count = 0;

    printf("Welcome to the Enchanted Boot Optimizer!\n");
    loadBootEntries(entries, &count);
    
    optimizeBootEntries(entries, count);
    
    executeBootEntries(entries, count);
    
    return 0;
}