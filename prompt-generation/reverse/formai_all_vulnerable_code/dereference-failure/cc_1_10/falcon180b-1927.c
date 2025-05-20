//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    char *value;
    struct json_object *next;
} json_object;

typedef struct {
    json_object *head;
} json_array;

json_object *create_object(char *key, char *value) {
    json_object *obj = (json_object *) malloc(sizeof(json_object));
    obj->key = key;
    obj->value = value;
    obj->next = NULL;
    return obj;
}

void add_object(json_object *head, char *key, char *value) {
    json_object *obj = head;
    while (obj->next!= NULL) {
        obj = obj->next;
    }
    obj->next = create_object(key, value);
}

json_array *create_array() {
    json_array *arr = (json_array *) malloc(sizeof(json_array));
    arr->head = NULL;
    return arr;
}

void add_array(json_array *arr, char *value) {
    json_object *obj = create_object("", value);
    if (arr->head == NULL) {
        arr->head = obj;
    } else {
        json_object *tail = arr->head;
        while (tail->next!= NULL) {
            tail = tail->next;
        }
        tail->next = obj;
    }
}

int main() {
    char input[MAX_SIZE];
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    json_array *json = create_array();

    printf("Enter JSON data:\n");
    fgets(input, MAX_SIZE, stdin);

    char *ptr = input;
    while (*ptr!= '\0') {
        if (*ptr == '{') {
            ptr++;
            while (*ptr!= '}' && *ptr!= '\0') {
                if (isalpha(*ptr)) {
                    strncpy(key, ptr, MAX_SIZE);
                    key[strcspn(key, ":")] = '\0';
                    ptr += strlen(key) + 1;
                } else if (*ptr == '\"') {
                    ptr++;
                    strncpy(value, ptr, MAX_SIZE);
                    value[strcspn(value, "\"")] = '\0';
                    ptr += strlen(value) + 2;
                    add_object(json->head, key, value);
                } else {
                    printf("Invalid JSON format.\n");
                    exit(1);
                }
            }
            ptr++;
        } else if (*ptr == '[') {
            ptr++;
            while (*ptr!= ']' && *ptr!= '\0') {
                if (isalpha(*ptr)) {
                    strncpy(key, ptr, MAX_SIZE);
                    key[strcspn(key, ":")] = '\0';
                    ptr += strlen(key) + 1;
                } else if (*ptr == '\"') {
                    ptr++;
                    strncpy(value, ptr, MAX_SIZE);
                    value[strcspn(value, "\"")] = '\0';
                    ptr += strlen(value) + 2;
                    add_array(json, value);
                } else {
                    printf("Invalid JSON format.\n");
                    exit(1);
                }
            }
            ptr++;
        } else {
            ptr++;
        }
    }

    printf("JSON data parsed successfully!\n");
    return 0;
}