//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define MAX_STRING_COUNT 100

char strings[MAX_STRING_COUNT][MAX_STRING_LENGTH];
int string_count = 0;

void add_string(char* str) {
    if (string_count >= MAX_STRING_COUNT) {
        printf("Error: Maximum number of strings reached.\n");
        return;
    }
    strcpy(strings[string_count], str);
    string_count++;
}

void remove_string(int index) {
    if (index < 0 || index >= string_count) {
        printf("Error: Invalid string index.\n");
        return;
    }
    for (int i = index; i < string_count - 1; i++) {
        strcpy(strings[i], strings[i + 1]);
    }
    string_count--;
}

void print_strings() {
    for (int i = 0; i < string_count; i++) {
        printf("%s\n", strings[i]);
    }
}

int main() {
    add_string("Hello, world!");
    add_string("How are you?");
    print_strings();

    remove_string(0);
    print_strings();

    char input[MAX_STRING_LENGTH];
    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        add_string(input);
        print_strings();
    }

    return 0;
}