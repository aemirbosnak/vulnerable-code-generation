//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char c, *text, line[80], *lines[50];
    int i, j, n, m, line_length, max_line_length, text_length;

    printf("Enter a C text: ");
    fgets(text, 80, stdin);
    text_length = strlen(text);
    n = 0;
    while (isspace(text[n])) {
        n++;
    }
    for (i = 0; i < text_length; i++) {
        if (isalpha(text[i]) || isdigit(text[i])) {
            lines[n] = &text[i];
            n++;
        }
    }
    lines[n] = NULL;

    max_line_length = 0;
    for (i = 0; lines[i]; i++) {
        line_length = strlen(lines[i]);
        if (line_length > max_line_length) {
            max_line_length = line_length;
        }
    }

    printf("Enter the number of lines to be displayed: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        for (j = 0; j < max_line_length; j++) {
            printf(" ");
        }
        printf("_");
        printf("\n");
        for (j = 0; j < max_line_length; j++) {
            printf("-");
        }
        printf("\n");
        for (j = 0; lines[i]; j++) {
            if (j % 4 == 0) {
                printf(" ");
            }
            printf("%c", lines[i][j]);
        }
        printf("\n");
        for (j = 0; j < max_line_length; j++) {
            printf("-");
        }
        printf("\n");
    }

    return 0;
}