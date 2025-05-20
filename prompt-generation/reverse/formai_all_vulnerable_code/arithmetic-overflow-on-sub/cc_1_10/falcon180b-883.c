//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} ConfigItem;

typedef struct {
    ConfigItem *items;
    int num_items;
} Config;

int config_load(Config *config, const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_SIZE];
    char *key, *value;
    char *ptr;
    int linenum = 0;

    if (file == NULL) {
        printf("Error: could not open %s\n", filename);
        return -1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        linenum++;

        key = strtok_r(line, "=", &ptr);
        if (key == NULL) {
            printf("Error: invalid line %d in %s\n", linenum, filename);
            fclose(file);
            return -1;
        }

        value = strtok_r(NULL, "\n", &ptr);
        if (value == NULL) {
            printf("Error: invalid line %d in %s\n", linenum, filename);
            fclose(file);
            return -1;
        }

        config_add_item(config, key, value);
    }

    fclose(file);
    return 0;
}

int config_add_item(Config *config, const char *key, const char *value) {
    ConfigItem *item = malloc(sizeof(ConfigItem));

    item->key = strdup(key);
    item->value = strdup(value);

    if (config->items == NULL) {
        config->items = item;
        config->num_items = 1;
    } else {
        config->items = realloc(config->items, sizeof(ConfigItem) * (config->num_items + 1));
        config->items[config->num_items - 1] = *item;
        free(item);
        config->num_items++;
    }

    return 0;
}

char *config_get_value(Config *config, const char *key) {
    int i;

    for (i = 0; i < config->num_items; i++) {
        if (strcmp(config->items[i].key, key) == 0) {
            return config->items[i].value;
        }
    }

    return NULL;
}

int main() {
    Config config;

    if (config_load(&config, "config.txt")!= 0) {
        return -1;
    }

    printf("Value for key1: %s\n", config_get_value(&config, "key1"));
    printf("Value for key2: %s\n", config_get_value(&config, "key2"));

    return 0;
}