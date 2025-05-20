//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *keys;
    int keys_size;
    int *values;
    int values_size;
} Map;

void map_init(Map *map, int size) {
    map->keys = (int *)malloc(size * sizeof(int));
    map->values = (int *)malloc(size * sizeof(int));
    map->keys_size = 0;
    map->values_size = 0;
}

void map_put(Map *map, int key, int value) {
    if (map->keys_size >= map->values_size) {
        map->keys_size *= 2;
        map->values_size *= 2;
        map->keys = (int *)realloc(map->keys, map->keys_size * sizeof(int));
        map->values = (int *)realloc(map->values, map->values_size * sizeof(int));
    }
    map->keys[map->keys_size++] = key;
    map->values[map->values_size++] = value;
}

int map_get(Map *map, int key) {
    for (int i = 0; i < map->keys_size; i++) {
        if (map->keys[i] == key) {
            return map->values[i];
        }
    }
    return -1;
}

void map_destroy(Map *map) {
    free(map->keys);
    free(map->values);
}

int *map_keys(Map *map, int *size) {
    *size = map->keys_size;
    return map->keys;
}

int *map_values(Map *map, int *size) {
    *size = map->values_size;
    return map->values;
}

int main() {
    srand(time(NULL));

    Map map;
    map_init(&map, 10);

    for (int i = 0; i < 100; i++) {
        int key = rand() % 100;
        int value = rand() % 100;
        map_put(&map, key, value);
    }

    int *keys = map_keys(&map, NULL);
    int *values = map_values(&map, NULL);

    for (int i = 0; i < map.keys_size; i++) {
        printf("%d -> %d\n", keys[i], values[i]);
    }

    map_destroy(&map);

    return 0;
}