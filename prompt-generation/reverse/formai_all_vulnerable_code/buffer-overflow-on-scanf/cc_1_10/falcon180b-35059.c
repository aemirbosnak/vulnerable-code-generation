//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

void init_string(String* str) {
    str->size = 0;
    str->data[0] = '\0';
}

void append_char(String* str, char c) {
    if (str->size >= MAX_SIZE - 1) {
        printf("Error: String is too long.\n");
        exit(1);
    }
    str->data[str->size++] = c;
    str->data[str->size] = '\0';
}

void print_string(const String* str) {
    printf("%s", str->data);
}

int main() {
    String input_string;
    init_string(&input_string);

    char c;
    while ((c = getchar())!= '\n') {
        append_char(&input_string, c);
    }

    char search_char;
    printf("Enter a character to search for: ");
    scanf("%c", &search_char);

    int index = -1;
    for (int i = 0; i < input_string.size; i++) {
        if (input_string.data[i] == search_char) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Character not found.\n");
    } else {
        printf("Character found at position %d.\n", index);
    }

    return 0;
}