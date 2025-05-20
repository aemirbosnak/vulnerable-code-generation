#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 256

void sanitize_string(char *str) {
    int i = 0;
    for (; str[i] != '\0'; ++i) {
        if (!isalnum(str[i]) && str[i] != '_' && str[i] != '-' && str[i] != ' ') {
            str[i] = '_';
        }
    }
}

void get_safe_input(char *prompt, char *buffer, size_t buffer_size) {
    char input[MAX_INPUT_LENGTH];
    printf("%s", prompt);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_string(input);
    strncpy(buffer, input, buffer_size);
    buffer[buffer_size - 1] = '\0';
}

int main() {
    char name[MAX_INPUT_LENGTH];
    int age;
    char weapon[MAX_INPUT_LENGTH];

    get_safe_input("Enter your name: ", name, sizeof(name));
    get_safe_input("Enter your age: ", (char *)&age, sizeof(age));
    get_safe_input("Enter your weapon: ", weapon, sizeof(weapon));

    printf("Welcome, %s, the valiant %s, aged %d.\n", name, weapon, age);

    return 0;
}
