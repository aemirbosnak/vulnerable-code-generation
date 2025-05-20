//Falcon-180B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *data;
    int size;
} String;

void init_string(String *str) {
    str->data = NULL;
    str->size = 0;
}

void append_string(String *str, const char *new_data) {
    int new_size = str->size + strlen(new_data) + 1;
    if (new_size > MAX_SIZE) {
        printf("Error: String is too long.\n");
        return;
    }
    char *new_data_copy = malloc(new_size * sizeof(char));
    if (new_data_copy == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    strcpy(new_data_copy, str->data);
    strcpy(new_data_copy + str->size, new_data);
    free(str->data);
    str->data = new_data_copy;
    str->size += strlen(new_data);
}

void print_string(const String *str) {
    printf("%s", str->data);
}

int main() {
    String str;
    init_string(&str);

    append_string(&str, "Hello, ");
    append_string(&str, "world!");

    print_string(&str);

    free(str.data);

    return 0;
}