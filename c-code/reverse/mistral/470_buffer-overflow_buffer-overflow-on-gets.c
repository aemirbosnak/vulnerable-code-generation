#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void searchAndReplace(char *text, char *search, char *replace, char *output, int *position) {
    int i, j, len_search = strlen(search), len_replace = strlen(replace);
    int found = 0;

    for (i = 0; text[i] != '\0'; i++) {
        for (j = 0; j < len_search && text[i + j] == search[j]; j++, i++) {
            if (j == len_search) {
                found = 1;
                strncpy(output + *position, replace, len_replace);
                *position += len_replace;
                for (; i < strlen(text) && text[i] != '\0'; i++)
                    output[*position++] = text[i];
                text += i - len_search + 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found && *text != '\0')
        strcpy(output + *position, text);
    output[*position] = '\0';
}

int main() {
    char text[100], search[20], replace[20];
    char output[200];
    int position = 0;

    printf("Enter a text: ");
    gets(text);
    printf("Enter the word to search: ");
    gets(search);
    printf("Enter the replacement word: ");
    gets(replace);

    searchAndReplace(text, search, replace, output, &position);
    printf("Modified text: %s\n", output);

    return 0;
}
