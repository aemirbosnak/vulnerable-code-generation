//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/sysinfo.h>

void print_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return;
    }

    long total_memory = info.totalram;
    long free_memory = info.freeram;
    long used_memory = total_memory - free_memory;

    printf("Total RAM: %ld MB\n", total_memory / (1024 * 1024));
    printf("Used RAM: %ld MB\n", used_memory / (1024 * 1024));
    printf("Free RAM: %ld MB\n", free_memory / (1024 * 1024));
    printf("RAM Usage: %.2f%%\n", ((double)used_memory / (double)total_memory) * 100);
}

void display_usage_instructions() {
    printf("\nMemory Usage Monitor\n");
    printf("Commands:\n");
    printf("  m - Display memory usage\n");
    printf("  q - Quit the program\n");
}

int main() {
    char command;

    while (1) {
        display_usage_instructions();
        printf("Enter command: ");
        command = tolower(getchar());
        getchar();  // To consume the newline character after input

        switch (command) {
            case 'm':
                print_memory_usage();
                break;
            case 'q':
                printf("Exiting the Memory Usage Monitor.\n");
                return 0;
            default:
                printf("Unknown command. Please enter 'm' or 'q'.\n");
                break;
        }
    }

    return 0;
}