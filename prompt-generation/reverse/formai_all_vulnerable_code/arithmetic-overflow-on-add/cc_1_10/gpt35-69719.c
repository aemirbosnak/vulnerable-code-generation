//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    void *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int count;
} JSONObject;

void freeObject(JSONObject *object);
int parseValue(char *json, int index, void **value);
int parseKeyValuePair(char *json, int index, KeyValuePair *pair);
int parseObject(char *json, int index, JSONObject *object);
char *readFile(const char *filename);

int main() {
    char *json = readFile("example.json");
    JSONObject object;
    object.count = 0;
    object.pairs = NULL;
    parseObject(json, 0, &object);
    freeObject(&object);
    free(json);
    return 0;
}

void freeObject(JSONObject *object) {
    for (int i = 0; i < object->count; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
}

int parseValue(char *json, int index, void **value) {
    // implementation here
}

int parseKeyValuePair(char *json, int index, KeyValuePair *pair) {
    // implementation here
}

int parseObject(char *json, int index, JSONObject *object) {
    while (json[index] != '}') {
        KeyValuePair pair;
        index = parseKeyValuePair(json, index, &pair);
        object->count++;
        object->pairs = realloc(object->pairs, sizeof(KeyValuePair) * object->count);
        object->pairs[object->count-1] = pair;
        if (json[index] == ',') {
            index++;
        } else if (json[index] == '}') {
            break;
        }
    }
    return index;
}

char *readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = malloc(size);
    fread(content, 1, size, file);
    fclose(file);
    return content;
}