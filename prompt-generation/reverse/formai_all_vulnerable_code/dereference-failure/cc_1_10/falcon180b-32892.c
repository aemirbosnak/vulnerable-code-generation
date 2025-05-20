//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_char(String *s, char c) {
    s->data = (char *)realloc(s->data, s->size + 2);
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print_string(String s) {
    printf("%s", s.data);
}

int main() {
    String input, pattern;

    init_string(&input);
    init_string(&pattern);

    printf("Enter a string: ");
    scanf("%s", input.data);

    printf("Enter a pattern to search for: ");
    scanf("%s", pattern.data);

    int index = 0;
    while (index <= input.size - pattern.size) {
        if (strcmp(input.data + index, pattern.data) == 0) {
            printf("Pattern found at position %d\n", index);
        }
        index++;
    }

    free(input.data);
    free(pattern.data);

    return 0;
}