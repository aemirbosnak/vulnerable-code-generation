//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int size;
} Config;

Config *config_create() {
    Config *config = malloc(sizeof(Config));
    config->pairs = NULL;
    config->size = 0;
    return config;
}

void config_destroy(Config *config) {
    for (int i = 0; i < config->size; i++) {
        free(config->pairs[i].key);
        free(config->pairs[i].value);
    }
    free(config->pairs);
    free(config);
}

void config_add(Config *config, char *key, char *value) {
    KeyValuePair *pair = malloc(sizeof(KeyValuePair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    config->pairs = realloc(config->pairs, sizeof(KeyValuePair) * (config->size + 1));
    config->pairs[config->size] = *pair;
    config->size++;
}

char *config_get(Config *config, char *key) {
    for (int i = 0; i < config->size; i++) {
        if (strcmp(config->pairs[i].key, key) == 0) {
            return config->pairs[i].value;
        }
    }
    return NULL;
}

int main() {
    Config *config = config_create();
    config_add(config, "name", "John Doe");
    config_add(config, "age", "30");
    char *name = config_get(config, "name");
    char *age = config_get(config, "age");
    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    config_destroy(config);
    return 0;
}