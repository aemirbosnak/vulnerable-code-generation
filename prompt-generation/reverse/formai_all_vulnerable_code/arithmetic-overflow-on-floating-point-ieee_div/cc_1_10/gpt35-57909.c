//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_CONFIG_SIZE 100
#define DEFAULT_UPDATE_INTERVAL 1 // in seconds
#define DEFAULT_THRESHOLD 80 // in percent
#define MAX_LINE_SIZE 128

typedef struct {
    int update_interval;
    int threshold;
} Config;

void read_config(Config *config);
void print_usage(int percent);

int main() {
    Config config;
    read_config(&config);
    printf("Monitoring C RAM usage every %d seconds. Threshold set to %d%%.\n", config.update_interval, config.threshold);
    struct sysinfo info;
    unsigned long long total_ram;
    unsigned long long free_ram;
    while (1) {
        if (sysinfo(&info) != 0) {
            printf("Error while retrieving system info.\n");
            break;
        }
        total_ram = info.totalram * info.mem_unit;
        free_ram = info.freeram * info.mem_unit;
        int usage_percent = (int)((total_ram - free_ram) * 100.0 / total_ram);
        if (usage_percent >= config.threshold) {
            printf("RAM usage exceeded %d%%.\n", config.threshold);
            print_usage(usage_percent);
            break;
        }
        print_usage(usage_percent);
        sleep(config.update_interval);
    }
    return 0;
}

void read_config(Config *config) {
    FILE *fp;
    char file_path[] = "/etc/c_ram_usage_monitor.cfg";
    char line[MAX_LINE_SIZE];
    char param[MAX_LINE_SIZE];
    char value[MAX_LINE_SIZE];
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Could not find config file at %s. Using default values for update interval and threshold.\n", file_path);
        config->update_interval = DEFAULT_UPDATE_INTERVAL;
        config->threshold = DEFAULT_THRESHOLD;
        return;
    }
    int line_count = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        line_count++;
        if (line[0] == '#' || line[0] == '\n') { // skip comments and empty lines
            continue;
        }
        if (sscanf(line, "%s %s", param, value) != 2) {
            printf("Error while parsing config file at %s, line %d.\n", file_path, line_count);
            fclose(fp);
            exit(1);
        }
        if (strcmp(param, "update_interval") == 0) {
            config->update_interval = atoi(value);
        } else if (strcmp(param, "threshold") == 0) {
            config->threshold = atoi(value);
        } else {
            printf("Unknown parameter in config file at %s, line %d.\n", file_path, line_count);
            fclose(fp);
            exit(1);
        }
    }
    fclose(fp);
}

void print_usage(int percent) {
    int i;
    printf("C RAM usage: [%s", "|");
    for (i = 0; i < (percent / 2); i++) {
        printf("=");
    }
    for (i = (percent / 2); i < 50; i++) {
        printf(" ");
    }
    printf("|] %d%%\n", percent);
}