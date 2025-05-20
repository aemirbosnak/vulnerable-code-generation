//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *reverse_string(char *str) {
    int len = strlen(str);
    char *rev_str = malloc(len + 1);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev_str[j] = tolower(str[i]);
    }

    return rev_str;
}

char *remove_whitespace(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (!isspace(str[i])) {
            new_str[j++] = tolower(str[i]);
        }
    }

    new_str[j] = '\0';

    return new_str;
}

char *replace_vowel(char *str) {
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            new_str[j++] = '*';
        } else {
            new_str[j++] = tolower(str[i]);
        }
    }

    new_str[j] = '\0';

    return new_str;
}

int main() {
    char input_str[100];

    printf("Enter a string: ");
    scanf("%s", input_str);

    char *rev_str = reverse_string(input_str);
    printf("Reversed string: %s\n", rev_str);

    char *new_str = remove_whitespace(input_str);
    printf("String without whitespace: %s\n", new_str);

    char *vowel_str = replace_vowel(input_str);
    printf("String with vowels replaced by asterisks: %s\n", vowel_str);

    free(rev_str);
    free(new_str);
    free(vowel_str);

    return 0;
}