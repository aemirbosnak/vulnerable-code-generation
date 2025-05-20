//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000
#define CONFIG_FILE "config.txt"

typedef struct {
    char keyword[MAX_LINE_LENGTH];
    int threshold;
} ConfigLine;

int read_config(ConfigLine config[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    file = fopen(CONFIG_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open config file \"%s\".\n", CONFIG_FILE);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d", config[num_lines].keyword, &config[num_lines].threshold);
        num_lines++;
    }

    fclose(file);

    return num_lines;
}

int main(int argc, char *argv[]) {
    ConfigLine config[MAX_LINES];
    int num_lines = read_config(config);
    char line[MAX_LINE_LENGTH];
    int count[MAX_LINES] = {0};
    int i, j;

    while (fgets(line, sizeof(line), stdin)) {
        for (i = 0; i < num_lines; i++) {
            if (strstr(line, config[i].keyword)) {
                count[i]++;
                if (count[i] >= config[i].threshold) {
                    printf("Intrusion detected: %s\n", config[i].keyword);
                    for (j = 0; j < num_lines; j++) {
                        count[j] = 0;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}