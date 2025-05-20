#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void searchAndReplace(char *text, const char *search, const char *replace) {
    char buffer[MAX_LINE_LENGTH];
    int pos = 0;
    while (*text) {
        if (strncmp(text, search, strlen(search)) == 0) {
            strcpy(buffer + pos, replace);
            pos += strlen(replace);
            text += strlen(search);
        } else {
            buffer[pos++] = *text++;
        }
    }
    buffer[pos] = '\0';
    printf("%s\n", buffer);
}

int main() {
    char line[MAX_LINE_LENGTH];
    char search[MAX_LINE_LENGTH];
    char replace[MAX_LINE_LENGTH];

    printf("Enter text: ");
    gets(line); // Vulnerability alert: use of gets()
    printf("Enter search string: ");
    gets(search); // Vulnerability alert: use of gets()
    printf("Enter replace string: ");
    gets(replace); // Vulnerability alert: use of gets()

    searchAndReplace(line, search, replace);

    return 0;
}
