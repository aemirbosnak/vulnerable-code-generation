//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototypes
int json_parse(char* json, char* key, char* value);
void print_key_value(char* key, char* value);

int main() {
    char json[1024];
    char key[256];
    char value[256];

    while (fgets(json, sizeof(json), stdin)) {
        if (json[strlen(json) - 1] == '\n') {
            json[strlen(json) - 1] = '\0';
        }

        int result = json_parse(json, key, value);
        if (result == 0) {
            printf("%s: %s\n", key, value);
            free(key);
            free(value);
        }
    }

    return 0;
}

int json_parse(char* json, char* key, char* value) {
    int start = 0;
    int end = 0;
    int escape_char = 0;
    int quoted = 0;
    int in_string = 0;

    while (json[start]!= '\0') {
        switch (json[start]) {
            case '"':
                quoted =!quoted;
                if (quoted) {
                    end = start + 1;
                    break;
                }
            case '\\':
                escape_char = 1;
            case '[':
                end = start + 1;
                break;
            case ']':
                end = start + 1;
                break;
            case ',':
                end = start + 1;
                break;
            case ':':
                end = start + 1;
                break;
            case '\n':
                end = start + 1;
                break;
            default:
                if (escape_char) {
                    switch (json[start]) {
                        case '\\':
                            escape_char = 0;
                            break;
                        case '"':
                            escape_char = 0;
                            break;
                        default:
                            json[end] = json[start];
                            end++;
                    }
                } else {
                    json[end] = json[start];
                    end++;
                }
                break;
        }

        start++;
    }

    if (end == start) {
        return 0;
    } else {
        return 1;
    }
}

void print_key_value(char* key, char* value) {
    printf("%s: %s\n", key, value);
    free(key);
    free(value);
}