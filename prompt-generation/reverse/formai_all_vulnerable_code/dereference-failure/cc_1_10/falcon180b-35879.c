//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INITIAL_SIZE 100

typedef struct {
    char *data;
    size_t capacity;
    size_t size;
} String;

void init_string(String *s) {
    s->data = (char*)malloc(INITIAL_SIZE * sizeof(char));
    s->capacity = INITIAL_SIZE;
    s->size = 0;
    s->data[0] = '\0';
}

void free_string(String *s) {
    free(s->data);
    s->data = NULL;
    s->capacity = 0;
    s->size = 0;
}

void string_append(String *s, const char *str) {
    size_t new_size = s->size + strlen(str) + 1;
    if (new_size > s->capacity) {
        s->capacity *= 2;
        s->data = (char*)realloc(s->data, s->capacity * sizeof(char));
    }
    strcat(s->data, str);
    s->size = new_size;
}

int main() {
    String input_string = {NULL, 0, 0};
    String reversed_string = {NULL, 0, 0};
    char ch;
    int i = 0;

    // Initialize input string
    init_string(&input_string);

    // Get input from user
    printf("Enter a string: ");
    while ((ch = getchar())!= '\n') {
        string_append(&input_string, &ch);
    }

    // Reverse the input string
    for (i = input_string.size - 1; i >= 0; i--) {
        string_append(&reversed_string, &input_string.data[i]);
    }

    // Print the reversed string
    printf("Reversed string: %s\n", reversed_string.data);

    // Free memory
    free_string(&input_string);
    free_string(&reversed_string);

    return 0;
}