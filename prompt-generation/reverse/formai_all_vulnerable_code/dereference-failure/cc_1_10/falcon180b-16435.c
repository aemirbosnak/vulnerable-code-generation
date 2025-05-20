//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char *key;
    char *value;
} Config;

Config *config_load(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: failed to open %s\n", filename);
        exit(1);
    }

    Config *config = malloc(sizeof(Config));
    config->key = malloc(MAX_KEY_LEN);
    config->value = malloc(MAX_VALUE_LEN);

    while (fgets(config->key, MAX_KEY_LEN, fp)!= NULL) {
        char *pos = strchr(config->key, '=');
        if (pos == NULL) {
            fprintf(stderr, "Error: invalid line in %s\n", filename);
            exit(1);
        }
        *pos = '\0';
        pos++;
        strcpy(config->value, pos);
    }

    fclose(fp);
    return config;
}

void config_free(Config *config) {
    free(config->key);
    free(config->value);
    free(config);
}

void config_print(const Config *config) {
    printf("Key: %s\nValue: %s\n", config->key, config->value);
}

int main() {
    Config *config = config_load("config.txt");
    config_print(config);
    config_free(config);

    return 0;
}