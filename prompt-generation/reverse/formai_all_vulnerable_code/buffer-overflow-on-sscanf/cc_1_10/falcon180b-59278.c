//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} ConfigItem;

int compare_config_items(const void *a, const void *b) {
    return strcmp(*(ConfigItem **)a, *(ConfigItem **)b);
}

int load_config(const char *filename, ConfigItem **config, int *size) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open config file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    ConfigItem *items = NULL;
    int num_items = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *key, *value;
        if (sscanf(line, "%s=%s", &key, &value)!= 2) {
            fprintf(stderr, "Error: Invalid config line '%s'\n", line);
            continue;
        }

        ConfigItem *item = malloc(sizeof(ConfigItem));
        item->key = strdup(key);
        item->value = strdup(value);
        items = realloc(items, sizeof(ConfigItem) * ++num_items);
        items[num_items - 1] = *item;
    }

    qsort(items, num_items, sizeof(ConfigItem), compare_config_items);
    *config = items;
    *size = num_items;

    fclose(fp);
    return 0;
}

int main() {
    ConfigItem *config = NULL;
    int num_config_items = 0;

    if (load_config("config.txt", &config, &num_config_items)) {
        return 1;
    }

    for (int i = 0; i < num_config_items; i++) {
        printf("%s = %s\n", config[i].key, config[i].value);
    }

    return 0;
}