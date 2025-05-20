//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 10000

// Function to remove all the extra whitespaces from a string
char *remove_extra_spaces(char *str)
{
    int i, j;
    for (i = 0, j = 0; str[i]; ++i) {
        if (!(isspace(str[i]) && (i == 0 || isspace(str[i - 1])))) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return str;
}

// Main function to format the HTML code
int main()
{
    char code[MAX_CHARACTERS];

    // Read the input HTML code and remove extra whitespaces
    scanf("%[^\n]s", code);
    remove_extra_spaces(code);

    int num_tabs = 0, i;
    char current_char, prev_char = '\0';

    // Iterate through the code and add tabs and newlines where required
    for (i = 0; i < strlen(code); i++) {
        current_char = code[i];
        if (current_char == '<') {
            if (prev_char == '>' && num_tabs > 0) {
                printf("\n");
            }
            for (int j = 0; j < num_tabs; j++) {
                printf("\t");
            }
            num_tabs++;
        }
        printf("%c", current_char);
        if (current_char == '>') {
            printf("\n");
            num_tabs--;
        }
        prev_char = current_char;
    }

    return 0;
}