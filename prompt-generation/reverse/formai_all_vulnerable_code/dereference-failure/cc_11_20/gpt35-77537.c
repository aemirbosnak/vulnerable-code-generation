//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct json_object_t {
    char* key;
    char* value;
    bool is_string;
    struct json_object_t* next;
} json_object;

json_object* parse_json(char* json_string) {
    char* p = json_string;
    json_object *head = NULL, *tail = NULL;
    while (*p) {
        if (*p == '{') {
            p++;
            json_object* obj = malloc(sizeof(json_object));
            obj->key = NULL;
            obj->value = NULL;
            obj->is_string = false;
            obj->next = NULL;
            if (!head) {
                head = obj;
                tail = obj;
            } else {
                tail->next = obj;
                tail = obj;
            }
            continue;
        } else if (*p == '}') {
            p++;
            if (tail) tail->next = NULL;
            continue;
        } else if (*p == '"') {
            p++;
            char* key = p;
            while (*p && *p != '"') p++;
            char* value = NULL;
            if (*p == '"') {
                *p = '\0';
                p++;
                while (*p != ':' && *p) p++;
                p++;
                while (*p == ' ' || *p == '\t' || *p == '\n') p++;
                if (*p == '"') {
                    value = p + 1;
                    *p = '\0';
                    while (*p && *p != '"') p++;
                    if (*p == '"') {
                        *p = '\0';
                        p++;
                    }
                } else {
                    value = p;
                    while (*p != ',' && *p && *p != '}') p++;
                    if (*p == ',' || *p == '}') {
                        *p = '\0';
                        p++;
                    }
                }
            }
            if (tail && key && value) {
                tail->key = strdup(key);
                tail->value = strdup(value);
                tail->is_string = (value[0] == '"');
            }
            continue;
        } else {
            p++;
        }
    }
    return head;
}

void print_json(json_object* obj) {
    while (obj) {
        if (obj->key) {
            printf("%s: ", obj->key);
        }
        if (obj->value) {
            if (obj->is_string) {
                printf("%s\n", obj->value);
            } else {
                printf("%d\n", atoi(obj->value));
            }
        } else {
            printf("{\n");
            print_json(obj->next);
        }
        obj = obj->next;
    }
}

int main() {
    char* json_string = "{\"name\": \"John Doe\", \"age\": 30, \"address\": {\"street\": \"1234 Main St\", \"state\": \"CA\", \"zip\": \"90001\"}}";
    json_object* obj = parse_json(json_string);
    print_json(obj);
    return 0;
}