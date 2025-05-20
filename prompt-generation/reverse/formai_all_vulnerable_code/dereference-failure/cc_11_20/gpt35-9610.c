//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 64
#define MAX_VAL_LEN 128
#define BUF_SIZE 512

typedef enum { START, KEY, COLON, VALUE, COMMA, ERROR } parser_state;

typedef struct {
    char key[MAX_KEY_LEN + 1];
    char value[MAX_VAL_LEN + 1];
} json_keyval;

typedef struct {
    int size;
    json_keyval *keyvals;
} json_obj;

json_obj *parse_json(char *json_str) {
    json_obj *obj = NULL;
    json_keyval *keyvals = NULL;
    char buf[BUF_SIZE];
    char key_buf[MAX_KEY_LEN + 1];
    char val_buf[MAX_VAL_LEN + 1];
    int buf_i = 0;
    int key_i = 0;
    int val_i = 0;
    int i = 0;
    parser_state state = START;

    while (json_str[i] != '\0') {
        switch (state) {
            case START:
                if (isspace(json_str[i])) {
                    break;
                }
                if (json_str[i] != '{') {
                    state = ERROR;
                    break;
                }
                obj = malloc(sizeof(json_obj));
                obj->size = 0;
                keyvals = malloc(sizeof(json_keyval) * BUF_SIZE);
                state = KEY;
                break;

            case KEY:
                if (isspace(json_str[i])) {
                    break;
                }
                if (json_str[i] == '}') {
                    state = ERROR;
                    break;
                }
                if (json_str[i] == '\"') {
                    state = COLON;
                    break;
                }
                if (key_i == MAX_KEY_LEN) {
                    state = ERROR;
                    break;
                }
                key_buf[key_i] = json_str[i];
                key_i++;
                break;

            case COLON:
                if (json_str[i] != ':') {
                    state = ERROR;
                    break;
                }
                state = VALUE;
                break;

            case VALUE:
                if (isspace(json_str[i])) {
                    break;
                }
                if (json_str[i] == '\"') {
                    state = COMMA;
                    break;
                }
                if (val_i == MAX_VAL_LEN) {
                    state = ERROR;
                    break;
                }
                val_buf[val_i] = json_str[i];
                val_i++;
                break;

            case COMMA:
                if (isspace(json_str[i])) {
                    break;
                }
                if (json_str[i] == '}') {
                    keyvals[obj->size].key[key_i] = '\0';
                    keyvals[obj->size].value[val_i] = '\0';
                    memcpy(keyvals[obj->size].key, key_buf, key_i + 1);
                    memcpy(keyvals[obj->size].value, val_buf, val_i + 1);
                    obj->size++;
                    obj->keyvals = keyvals;
                    state = START;
                    break;
                }
                if (json_str[i] != ',') {
                    state = ERROR;
                    break;
                }
                keyvals[obj->size].key[key_i] = '\0';
                keyvals[obj->size].value[val_i] = '\0';
                memcpy(keyvals[obj->size].key, key_buf, key_i + 1);
                memcpy(keyvals[obj->size].value, val_buf, val_i + 1);
                key_i = 0;
                val_i = 0;
                obj->size++;
                state = KEY;
                break;

            default:
                printf("ERROR\n");
                return NULL;
        }
        i++;
    }

    return obj;
}

int main() {
    char *json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_obj *obj = parse_json(json_str);
    if (obj == NULL) {
        printf("Failed to parse JSON!\n");
        return 1;
    }
    for (int i = 0; i < obj->size; i++) {
        printf("%s: %s\n", obj->keyvals[i].key, obj->keyvals[i].value);
    }
    return 0;
}