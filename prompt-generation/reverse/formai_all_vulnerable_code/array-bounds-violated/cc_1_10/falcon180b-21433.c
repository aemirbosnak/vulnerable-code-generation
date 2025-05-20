//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 1000
#define MAX_INPUT_LENGTH 1000

char pattern[MAX_PATTERN_LENGTH];
char input[MAX_INPUT_LENGTH];

void generate_pattern(int length)
{
    int i;
    for (i = 0; i < length; i++) {
        pattern[i] = 'a' + rand() % 26;
    }
    pattern[length] = '\0';
}

int main()
{
    int length, i;

    printf("Enter the length of the pattern: ");
    scanf("%d", &length);

    generate_pattern(length);

    printf("The pattern is: %s\n", pattern);

    printf("Enter the input string: ");
    scanf("%s", input);

    int input_length = strlen(input);
    int pattern_length = strlen(pattern);

    if (input_length < pattern_length) {
        printf("Input string is too short\n");
        return 0;
    }

    int j = 0;
    for (i = 0; i < input_length; i++) {
        if (tolower(input[i]) == tolower(pattern[j])) {
            j++;
            if (j == pattern_length) {
                printf("Pattern found in input string\n");
                return 0;
            }
        } else {
            j = 0;
        }
    }

    printf("Pattern not found in input string\n");

    return 0;
}