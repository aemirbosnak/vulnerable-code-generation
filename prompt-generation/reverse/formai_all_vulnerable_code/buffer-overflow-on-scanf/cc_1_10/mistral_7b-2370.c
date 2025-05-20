//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 10
#define MAX_CHAR 256
#define MAX_WORDS 10000

// Structure to store strings and their lengths
typedef struct {
    char str[MAX_CHAR];
    int len;
} string;

// Function to count the number of occurrences of a character in a string
int count_char(char str[], char c) {
    int count = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }

    return count;
}

int main() {
    int i, j, k;
    int num_strings;
    int num_chars;
    char char_to_find;
    string strings[MAX_STRINGS];

    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    printf("Enter the number of characters to find: ");
    scanf("%d", &num_chars);

    printf("Enter the strings:\n");

    for (i = 0; i < num_strings; i++) {
        scanf("%s", strings[i].str);
        strings[i].len = strlen(strings[i].str);
    }

    printf("Enter the character to find: ");
    scanf(" %c", &char_to_find);

    int count[num_strings];

    for (i = 0; i < num_strings; i++) {
        count[i] = count_char(strings[i].str, char_to_find);
    }

    printf("\nCharacter '%c' count in each string:\n", char_to_find);

    for (i = 0; i < num_strings; i++) {
        printf("String %d: %s, Count = %d\n", i + 1, strings[i].str, count[i]);
    }

    return 0;
}