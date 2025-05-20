//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 100

typedef enum {
    OBJ_START,
    KEY,
    VAL,
    OBJ_END
} token_t;

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} entry_t;

typedef struct {
    entry_t entries[MAX_KEY_LEN];
    int count;
} object_t;

object_t parse(char *json) {
    object_t obj;
    char *ptr = json;
    int idx = 0;
    token_t token = OBJ_START;
    while (*ptr != '\0') {
        switch (token) {
            case OBJ_START:
                if (*ptr == '{') {
                    token = KEY;
                }
                break;
            case KEY:
                if (*ptr == '"') {
                    ptr++;
                    idx = 0;
                    while (*ptr != '"' && idx < MAX_KEY_LEN) {
                        obj.entries[obj.count].key[idx] = *ptr;
                        idx++;
                        ptr++;
                    }
                    obj.entries[obj.count].key[idx] = '\0';
                    token = VAL;
                }
                break;
            case VAL:
                if (*ptr == ':') {
                    ptr++;
                    idx = 0;
                    while (*ptr != ',' && *ptr != '}' && idx < MAX_VAL_LEN) {
                        obj.entries[obj.count].value[idx] = *ptr;
                        idx++;
                        ptr++;
                    }
                    obj.entries[obj.count].value[idx] = '\0';
                    token = (ptr == '}' ? OBJ_END : KEY);
                    obj.count++;
                }
                break;
            case OBJ_END:
                if (*ptr == '}') {
                    return obj;
                }
                break;
        }
        ptr++;
    }
    return obj;
}

int main() {
    char *json = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    object_t obj = parse(json);
    printf("Number of entries: %d\n", obj.count);
    for (int i = 0; i < obj.count; i++) {
        printf("%s: %s\n", obj.entries[i].key, obj.entries[i].value);
    }
    return 0;
}