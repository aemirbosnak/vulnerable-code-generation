//Falcon-180B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *content;
    int size;
} String;

String *string_create(const char *content) {
    String *string = (String *)malloc(sizeof(String));

    if (string == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return NULL;
    }

    string->content = strdup(content);
    string->size = strlen(content);

    return string;
}

int string_resize(String *string, int new_size) {
    char *new_content = (char *)realloc(string->content, new_size + 1);

    if (new_content == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return -1;
    }

    string->content = new_content;
    string->size = new_size;

    return 0;
}

void string_destroy(String *string) {
    free(string->content);
    free(string);
}

int main() {
    String *string = string_create("Hello, world!");

    printf("Original string: %s\n", string->content);

    string_resize(string, 20);
    string->content[string->size - 1] = '\0';
    printf("Resized string: %s\n", string->content);

    string_destroy(string);

    return 0;
}