//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

void init(String *s) {
    s->size = 0;
    s->data[0] = '\0';
}

void append(String *s, char c) {
    if (s->size >= MAX_SIZE - 1) {
        printf("Error: String is full.\n");
        exit(1);
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print(String s) {
    printf("%s", s.data);
}

int main() {
    String input, pattern;
    init(&input);
    init(&pattern);

    printf("Enter the input string: ");
    scanf("%s", input.data);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern.data);

    int index = 0;
    while (index <= input.size - pattern.size) {
        int match = 1;
        for (int i = 0; i < pattern.size; i++) {
            if (input.data[index + i]!= pattern.data[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("Pattern found at position %d.\n", index);
        }
        index++;
    }

    return 0;
}