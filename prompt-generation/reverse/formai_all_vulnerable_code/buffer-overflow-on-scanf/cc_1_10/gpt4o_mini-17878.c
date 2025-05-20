//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BOOT_OPTIONS 5
#define MAX_STRING_LENGTH 50

typedef struct {
    char name[MAX_STRING_LENGTH];
    int priority;
} BootOption;

int compareBootOptions(const void *a, const void *b) {
    BootOption *optionA = (BootOption *)a;
    BootOption *optionB = (BootOption *)b;
    return optionB->priority - optionA->priority; // Descending order
}

void loadBootOptions(BootOption *options, int *count) {
    // Let's assume boot options are hardcoded for the example
    strcpy(options[0].name, "Ubuntu");
    options[0].priority = 10;
    
    strcpy(options[1].name, "Windows 10");
    options[1].priority = 5;

    strcpy(options[2].name, "Fedora");
    options[2].priority = 7;

    strcpy(options[3].name, "Arch Linux");
    options[3].priority = 6;

    strcpy(options[4].name, "Mint");
    options[4].priority = 8;

    *count = 5; // Total count of boot options
}

void displayBootMenu(BootOption *options, int count) {
    printf("Boot Options:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Priority: %d)\n", i + 1, options[i].name, options[i].priority);
    }
}

void optimizeBootOrder(BootOption *options, int count) {
    qsort(options, count, sizeof(BootOption), compareBootOptions);
}

void saveBootOrder(BootOption *options, int count) {
    FILE *file = fopen("bootorder.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %d\n", options[i].name, options[i].priority);
        }
        fclose(file);
        printf("Boot order saved to bootorder.txt\n");
    } else {
        perror("Failed to save boot order");
    }
}

void bootOptionSelected(const BootOption *option) {
    printf("Booting into %s...\n", option->name);
    sleep(2); // Simulated boot time
    printf("%s has been successfully booted!\n", option->name);
}

int main() {
    BootOption options[MAX_BOOT_OPTIONS];
    int count;

    printf("Boot Optimizer V1.0\n");
    printf("====================\n");

    loadBootOptions(options, &count);
    optimizeBootOrder(options, count);
    displayBootMenu(options, count);

    int selected;
    printf("Select your boot option (1-%d): ", count);
    scanf("%d", &selected);
    if (selected < 1 || selected > count) {
        printf("Invalid selection. Exiting...\n");
        return 1;
    }

    bootOptionSelected(&options[selected - 1]);
    saveBootOrder(options, count);

    return 0;
}