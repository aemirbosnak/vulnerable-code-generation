//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* data;
    int size;
} String;

void string_init(String* str) {
    str->data = NULL;
    str->size = 0;
}

void string_destroy(String* str) {
    free(str->data);
    str->data = NULL;
    str->size = 0;
}

void string_append(String* str, const char* data) {
    int new_size = str->size + strlen(data) + 1;
    char* new_data = realloc(str->data, new_size);
    if (new_data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    str->data = new_data;
    strcpy(str->data + str->size, data);
    str->size += strlen(data);
}

void string_print(const String* str) {
    printf("%s", str->data);
}

int main() {
    String str;
    string_init(&str);

    for (int i = 0; i < 1000000; ++i) {
        char* data = malloc(10);
        sprintf(data, "%d", i);
        string_append(&str, data);
        free(data);
    }

    string_print(&str);

    string_destroy(&str);

    return 0;
}