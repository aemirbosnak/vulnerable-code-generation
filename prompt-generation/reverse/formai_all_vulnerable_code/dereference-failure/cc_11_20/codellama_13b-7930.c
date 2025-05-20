//Code Llama-13B DATASET v1.0 Category: Text processing ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[100];
    int text_len;
    char *p;

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text_len = strlen(text);

    // Remove whitespace characters from the beginning and end of the string
    p = text;
    while (*p == ' ' || *p == '\t' || *p == '\n') {
        p++;
    }
    text_len -= (p - text);
    memmove(text, p, text_len);
    p = text + text_len - 1;
    while (*p == ' ' || *p == '\t' || *p == '\n') {
        p--;
    }
    text_len = p - text + 1;
    text[text_len] = '\0';

    // Capitalize the first letter of the first word
    p = text;
    while (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\0') {
        *p = toupper(*p);
        p++;
    }

    // Convert the remaining words to lowercase
    while (*p != '\0') {
        while (*p == ' ' || *p == '\t' || *p == '\n') {
            p++;
        }
        while (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\0') {
            *p = tolower(*p);
            p++;
        }
    }

    // Print the modified text
    printf("Modified text: %s\n", text);

    return 0;
}