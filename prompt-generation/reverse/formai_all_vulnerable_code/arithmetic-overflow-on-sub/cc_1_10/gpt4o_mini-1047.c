//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_MEMORY_HISTORY 100

typedef struct {
    long total_memory;
    long free_memory;
    long used_memory;
    long cached_memory;
} MemoryUsage;

MemoryUsage mem_history[MAX_MEMORY_HISTORY];
int history_index = 0;

void fetch_memory_usage(MemoryUsage *usage) {
    struct sysinfo info;
    sysinfo(&info);
    usage->total_memory = info.totalram * info.mem_unit;
    usage->free_memory = info.freeram * info.mem_unit;
    usage->used_memory = usage->total_memory - usage->free_memory;
    usage->cached_memory = info.bufferram * info.mem_unit; // also included in free memory in some cases
}

void print_memory_usage(MemoryUsage *usage) {
    printf("Total Memory: %ld bytes\n", usage->total_memory);
    printf("Free Memory: %ld bytes\n", usage->free_memory);
    printf("Used Memory: %ld bytes\n", usage->used_memory);
    printf("Cached Memory: %ld bytes\n", usage->cached_memory);
    printf("---------------------------------------\n");
}

void log_memory_usage(MemoryUsage *usage) {
    if (history_index < MAX_MEMORY_HISTORY) {
        mem_history[history_index] = *usage;
        history_index++;
    } else {
        printf("Memory history buffer is full. Cannot log more data.\n");
    }
}

void display_memory_history() {
    printf("Memory Usage History:\n");
    printf("Index | Total Memory | Free Memory | Used Memory | Cached Memory\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < history_index; i++) {
        printf("%5d | %12ld | %11ld | %11ld | %12ld\n", 
                i, 
                mem_history[i].total_memory, 
                mem_history[i].free_memory, 
                mem_history[i].used_memory, 
                mem_history[i].cached_memory);
    }
}

int main() {
    MemoryUsage current_usage;
    char command[50];

    printf("Memory Usage Monitor\n");
    printf("Type 'history' to view memory usage history, 'exit' to terminate the program.\n");
    
    while (1) {
        fetch_memory_usage(&current_usage);
        print_memory_usage(&current_usage);
        log_memory_usage(&current_usage);
        
        printf("Enter a command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "history") == 0) {
            display_memory_history();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Memory Usage Monitor. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
        
        sleep(1); // Sleep for a second before fetching memory again
    }

    return 0;
}