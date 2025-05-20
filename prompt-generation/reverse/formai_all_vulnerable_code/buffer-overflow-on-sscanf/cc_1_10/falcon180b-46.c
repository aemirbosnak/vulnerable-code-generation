//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RAM_MAX 1000 // Maximum number of RAM entries to store

typedef struct {
    char process_name[50];
    int pid;
    int ram_usage;
    time_t timestamp;
} RAM_entry;

RAM_entry ram_table[RAM_MAX];
int num_entries = 0;

void init_table() {
    memset(ram_table, 0, sizeof(ram_table));
    num_entries = 0;
}

int add_entry(char* process_name, int pid, int ram_usage) {
    if (num_entries >= RAM_MAX) {
        return -1;
    }

    strncpy(ram_table[num_entries].process_name, process_name, 50);
    ram_table[num_entries].pid = pid;
    ram_table[num_entries].ram_usage = ram_usage;
    ram_table[num_entries].timestamp = time(NULL);

    num_entries++;

    return 0;
}

void print_table() {
    printf("Process Name\tPID\tRAM Usage (KB)\tTimestamp\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\t%d\t%s\n", ram_table[i].process_name, ram_table[i].pid, ram_table[i].ram_usage, ctime(&ram_table[i].timestamp));
    }
}

int main() {
    init_table();

    while (1) {
        system("ps aux --sort=-rss | head -n 11 > ps_output.txt");

        FILE* file = fopen("ps_output.txt", "r");
        if (file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        char line[100];
        while (fgets(line, sizeof(line), file)!= NULL) {
            char process_name[50];
            int pid;
            int ram_usage;

            sscanf(line, "%s\t%d\t%d\t%s", process_name, &pid, &ram_usage, NULL);

            add_entry(process_name, pid, ram_usage);
        }

        fclose(file);
        remove("ps_output.txt");

        sleep(5); // Update every 5 seconds
    }

    return 0;
}