//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    char *data;
    int size;
} string;

void init_string(string *s) {
    s->data = (char*)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
    s->data[0] = '\0';
}

void append_char(string *s, char c) {
    if (s->size >= MAX_SIZE - 1) {
        printf("Error: String is full.\n");
        return;
    }
    s->data[s->size++] = c;
    s->data[s->size] = '\0';
}

void print_string(const string *s) {
    printf("%s", s->data);
}

int main() {
    char input[MAX_SIZE];
    string s;
    init_string(&s);

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    int i = 0;
    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            append_char(&s, toupper(input[i]));
        }
        i++;
    }

    printf("Modified string: ");
    print_string(&s);

    free(s.data);
    return 0;
}