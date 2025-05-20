//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char *reverse_string(char *str) {
    int length = strlen(str);
    char *reverse_str = malloc(MAX_LENGTH);
    if (reverse_str == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    int i = 0;
    for (int j = length - 1; j >= 0; j--) {
        reverse_str[i++] = tolower(str[j]);
    }
    reverse_str[i] = '\0';
    return reverse_str;
}

char *remove_vowels(char *str) {
    int length = strlen(str);
    char *vowel_free_str = malloc(MAX_LENGTH);
    if (vowel_free_str == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (!isalpha(str[j])) {
            vowel_free_str[i++] = str[j];
        }
    }
    vowel_free_str[i] = '\0';
    return vowel_free_str;
}

int main() {
    char input_str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_str);
    char *reverse_str = reverse_string(input_str);
    printf("Reversed string: %s\n", reverse_str);
    char *vowel_free_str = remove_vowels(input_str);
    printf("Vowel-free string: %s\n", vowel_free_str);
    free(reverse_str);
    free(vowel_free_str);
    return 0;
}