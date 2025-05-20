#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void searchReplace(char *str, const char *search, const char *replace) {
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
    char text[1024], search[100], replace[100];
    printf("Enter text: ");
    gets(text);
    printf("Enter search string: ");
    gets(search);
    printf("Enter replace string: ");
    gets(replace);
    searchReplace(text, search, replace);
    printf("Modified text: %s\n", text);
    return 0;
}
