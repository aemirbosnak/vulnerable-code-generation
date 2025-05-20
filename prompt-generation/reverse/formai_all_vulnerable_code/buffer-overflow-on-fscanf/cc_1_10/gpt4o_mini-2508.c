//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[30];
    int value;
} BootParameter;

void loadConfig(BootParameter *params, int *count) {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (*count < MAX_ENTRIES && fscanf(file, "%s %d", params[*count].name, &params[*count].value) != EOF) {
        (*count)++;
    }
    fclose(file);
}

void saveConfig(BootParameter *params, int count) {
    FILE *file = fopen(CONFIG_FILE, "w");
    if (!file) {
        perror("Could not open config file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", params[i].name, params[i].value);
    }
    fclose(file);
}

void displayConfig(BootParameter *params, int count) {
    printf("Current Boot Configuration:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", params[i].name, params[i].value);
    }
}

void optimizeParameter(BootParameter *param) {
    if (param->value > 1) {
        param->value--;
        printf("Optimized %s to %d\n", param->name, param->value);
    } else {
        printf("%s is already optimized at %d\n", param->name, param->value);
    }
}

void logOptimization(const char *paramName, int oldVal, int newVal) {
    FILE *logFile = fopen("boot_optimization_log.txt", "a");
    if (!logFile) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }
    
    time_t now = time(NULL);
    fprintf(logFile, "[%s] %s: %d -> %d\n", ctime(&now), paramName, oldVal, newVal);
    fclose(logFile);
}

void optimizeBoot(BootParameter *params, int count) {
    for (int i = 0; i < count; i++) {
        int oldVal = params[i].value;
        optimizeParameter(&params[i]);
        logOptimization(params[i].name, oldVal, params[i].value);
    }
}

int main() {
    BootParameter params[MAX_ENTRIES];
    int count;

    loadConfig(params, &count);
    displayConfig(params, count);
    optimizeBoot(params, count);
    saveConfig(params, count);

    printf("\nOptimized boot configuration saved.\n");
    return 0;
}