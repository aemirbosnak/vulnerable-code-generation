//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int size;
} String;

#define INITIAL_SIZE 16

void string_init(String* str) {
    str->data = (char*)malloc(INITIAL_SIZE * sizeof(char));
    str->size = 0;
    str->data[0] = '\0';
}

void string_append(String* str, char c) {
    int new_size = str->size + 1;
    if (new_size >= str->data[0]) {
        char* temp = (char*)realloc(str->data, new_size * sizeof(char));
        if (temp == NULL) {
            printf("Failed to reallocate memory\n");
            exit(1);
        }
        str->data = temp;
        str->data[0] = new_size;
    }
    str->data[str->size] = c;
    str->size++;
    str->data[str->size] = '\0';
}

void string_free(String* str) {
    free(str->data);
}

int main() {
    String s;
    string_init(&s);
    string_append(&s, 'H');
    string_append(&s, 'e');
    string_append(&s, 'l');
    string_append(&s, 'l');
    string_append(&s, 'o');
    string_append(&s, '!');
    printf("%s\n", s.data);
    string_free(&s);
    return 0;
}