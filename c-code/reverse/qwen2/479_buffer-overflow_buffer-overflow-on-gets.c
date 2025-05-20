#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

void replaceWord(char *text, const char *search, const char *replace) {
    char buffer[MAX_LEN];
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
    strcpy(text, buffer);
}

int main() {
    char text[MAX_LEN], search[MAX_LEN], replace[MAX_LEN];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter search word: ");
    scanf("%s", search);

    printf("Enter replacement word: ");
    scanf("%s", replace);

    replaceWord(text, search, replace);

    printf("Modified text: %s\n", text);

    return 0;
}
