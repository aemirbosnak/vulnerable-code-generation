//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i, j;
    printf("Enter a sentence in the Alien Language: ");
    scanf("%[^\n]s", input);

    char output[strlen(input) + 1];

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        char c = input[i];
        if (c == 'a') {
            output[j] = 'z';
        } else if (c == 'b') {
            output[j] = 'y';
        } else if (c == 'c') {
            output[j] = 'x';
        } else if (c == 'd') {
            output[j] = 'w';
        } else if (c == 'e') {
            output[j] = 'v';
        } else if (c == 'f') {
            output[j] = 'u';
        } else if (c == 'g') {
            output[j] = 't';
        } else if (c == 'h') {
            output[j] = 's';
        } else if (c == 'i') {
            output[j] = 'r';
        } else if (c == 'j') {
            output[j] = 'q';
        } else if (c == 'k') {
            output[j] = 'p';
        } else if (c == 'l') {
            output[j] = 'o';
        } else if (c == 'm') {
            output[j] = 'n';
        } else if (c == 'n') {
            output[j] = 'm';
        } else if (c == 'o') {
            output[j] = 'l';
        } else if (c == 'p') {
            output[j] = 'k';
        } else if (c == 'q') {
            output[j] = 'j';
        } else if (c == 'r') {
            output[j] = 'i';
        } else if (c == 's') {
            output[j] = 'h';
        } else if (c == 't') {
            output[j] = 'g';
        } else if (c == 'u') {
            output[j] = 'f';
        } else if (c == 'v') {
            output[j] = 'e';
        } else if (c == 'w') {
            output[j] = 'd';
        } else if (c == 'x') {
            output[j] = 'c';
        } else if (c == 'y') {
            output[j] = 'b';
        } else if (c == 'z') {
            output[j] = 'a';
        } else {
            output[j] = c;
        }
    }

    output[j] = '\0';

    printf("The sentence translated to English is: %s\n", output);

    return 0;
}