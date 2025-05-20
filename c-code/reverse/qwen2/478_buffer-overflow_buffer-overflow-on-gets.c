#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void replaceString(char *str, const char *search, const char *replace) {
    char buffer[1024];
    int pos = 0;
    while (*str) {
        if (strncmp(str, search, strlen(search)) == 0) {
            strcpy(buffer + pos, replace);
            pos += strlen(replace);
            str += strlen(search);
        } else {
            buffer[pos++] = *str++;
        }
    }
    buffer[pos] = '\0';
    strcpy(str, buffer);
}

int main() {
    char input[1024], search[100], replace[100];
    printf("Enter string: ");
    gets(input); // Note: Using gets() for simplicity; consider using fgets() in real applications
    printf("Enter search string: ");
    gets(search);
    printf("Enter replace string: ");
    gets(replace);
    replaceString(input, search, replace);
    printf("Result: %s\n", input);
    return 0;
}
