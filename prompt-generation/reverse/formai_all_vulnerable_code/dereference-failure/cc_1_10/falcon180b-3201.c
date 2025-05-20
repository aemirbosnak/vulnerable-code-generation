//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 512

typedef struct {
    char *key;
    char *value;
} ConfigPair;

typedef struct {
    ConfigPair *pairs;
    int num_pairs;
} Config;

int load_config_file(const char *filename, Config *config) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open config file '%s'\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    char *key = NULL;
    char *value = NULL;
    int num_pairs = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int line_len = strlen(line);
        if (line_len == 0 || line[0] == '#' || line[0] == '\n') {
            continue;
        }

        char *trimmed_line = line + strspn(line, " \t");
        if (trimmed_line == line) {
            continue;
        }

        char *eq_pos = strchr(trimmed_line, '=');
        if (eq_pos == NULL) {
            printf("Error: invalid line in config file: '%s'\n", line);
            continue;
        }

        *eq_pos = '\0';
        key = strdup(trimmed_line);
        value = strdup(eq_pos + 1);

        ConfigPair pair = {key, value};
        config->pairs = realloc(config->pairs, sizeof(ConfigPair) * ++num_pairs);
        config->pairs[num_pairs - 1] = pair;
    }

    fclose(fp);

    config->num_pairs = num_pairs;
    return 0;
}

void free_config(Config *config) {
    for (int i = 0; i < config->num_pairs; i++) {
        free(config->pairs[i].key);
        free(config->pairs[i].value);
    }
    free(config->pairs);
}

int main() {
    Config config = {NULL, 0};

    if (load_config_file("config.txt", &config)!= 0) {
        return 1;
    }

    printf("Loaded config file with %d pairs:\n", config.num_pairs);
    for (int i = 0; i < config.num_pairs; i++) {
        printf("%s = %s\n", config.pairs[i].key, config.pairs[i].value);
    }

    free_config(&config);
    return 0;
}