#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *text, *summary, c;
    int length = 0, words = 0, i;

    printf("Enter text: ");
    text = gets(NULL);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n')
            words++;
    }

    summary = (char *)malloc((words + 1) * sizeof(char));
    words = 0;

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            if (words > 0)
                summary[words] = ' ';
        } else {
            summary[words] = text[i];
            words++;
        }
    }

    printf("Summary: ");
    for (i = 0; summary[i] != '\0'; i++)
        putchar(summary[i]);

    free(text);
    free(summary);

    return 0;
}
