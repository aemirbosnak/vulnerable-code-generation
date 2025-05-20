#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void searchAndReplace(char *text, const char *searchWord, const char *replaceWord) {
    char buffer[1024];
    int pos = 0;
    while (*text) {
        if (strncmp(text, searchWord, strlen(searchWord)) == 0) {
            strcpy(buffer + pos, replaceWord);
            pos += strlen(replaceWord);
            text += strlen(searchWord);
        } else {
            buffer[pos++] = *text++;
        }
    }
    buffer[pos] = '\0';
    printf("Modified Text: %s\n", buffer);
}

int main() {
    char text[1024];
    char searchWord[100], replaceWord[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the word to search: ");
    scanf("%s", searchWord);

    printf("Enter the word to replace: ");
    scanf("%s", replaceWord);

    searchAndReplace(text, searchWord, replaceWord);

    return 0;
}
