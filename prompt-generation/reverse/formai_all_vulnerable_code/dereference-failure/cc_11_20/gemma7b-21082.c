//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JsonNode *object;
        struct JsonNode **array;
    } data;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;
    int state = 0;

    while (jsonStr[i] != '\0') {
        switch (state) {
            case 0:
                if (jsonStr[i] == '{') {
                    tail = malloc(sizeof(JsonNode));
                    tail->type = 'o';
                    tail->data.object = NULL;
                    tail->next = NULL;
                    if (head == NULL) {
                        head = tail;
                    } else {
                        tail->next = head;
                        head = tail;
                    }
                    state = 1;
                } else if (jsonStr[i] == '[') {
                    tail = malloc(sizeof(JsonNode));
                    tail->type = 'a';
                    tail->data.array = NULL;
                    tail->next = NULL;
                    if (head == NULL) {
                        head = tail;
                    } else {
                        tail->next = head;
                        head = tail;
                    }
                    state = 2;
                } else if (jsonStr[i] == '"') {
                    tail = malloc(sizeof(JsonNode));
                    tail->type = 's';
                    tail->data.string = malloc(MAX_BUFFER_SIZE);
                    memcpy(tail->data.string, jsonStr + i + 1, MAX_BUFFER_SIZE - 1);
                    tail->next = NULL;
                    if (head == NULL) {
                        head = tail;
                    } else {
                        tail->next = head;
                        head = tail;
                    }
                    state = 3;
                } else if (jsonStr[i] == ',') {
                    state = 0;
                } else if (jsonStr[i] == '}') {
                    state = 4;
                } else if (jsonStr[i] == ']') {
                    state = 5;
                }
                break;
            case 1:
                if (jsonStr[i] == '"') {
                    state = 3;
                } else if (jsonStr[i] == ',') {
                    state = 0;
                } else if (jsonStr[i] == '}') {
                    state = 4;
                }
                break;
            case 2:
                if (jsonStr[i] == '"') {
                    state = 3;
                } else if (jsonStr[i] == ',') {
                    state = 0;
                } else if (jsonStr[i] == ']') {
                    state = 5;
                }
                break;
            case 3:
                if (jsonStr[i] == ',') {
                    state = 0;
                } else if (jsonStr[i] == '}') {
                    state = 4;
                } else if (jsonStr[i] == ']') {
                    state = 5;
                }
                break;
            case 4:
                state = 0;
                break;
            case 5:
                state = 0;
                break;
        }
        i++;
    }

    free(buffer);
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonStr);
    return 0;
}