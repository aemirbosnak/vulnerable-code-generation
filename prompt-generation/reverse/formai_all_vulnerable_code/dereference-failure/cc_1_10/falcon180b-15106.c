//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *str) {
    str->data = (char *) malloc(MAX_SIZE);
    str->size = 0;
}

void append_string(String *str, const char *data) {
    if (str->size + strlen(data) >= MAX_SIZE) {
        printf("Error: String is too long\n");
        return;
    }
    strcat(str->data, data);
    str->size += strlen(data);
}

void free_string(String *str) {
    free(str->data);
}

int main() {
    String str1, str2;
    init_string(&str1);
    init_string(&str2);

    char input[MAX_SIZE];
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (input[0] == '>') {
            char *data = strtok(input, " ");
            if (data == NULL) {
                printf("Error: Invalid input\n");
                continue;
            }
            data += 1;
            append_string(&str1, data);
        } else if (input[0] == '<') {
            char *data = strtok(input, " ");
            if (data == NULL) {
                printf("Error: Invalid input\n");
                continue;
            }
            data += 1;
            append_string(&str2, data);
        }
    }

    printf("String 1: %s\n", str1.data);
    printf("String 2: %s\n", str2.data);

    free_string(&str1);
    free_string(&str2);

    return 0;
}