//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void reverse_string(char* str) {
    int len = strlen(str);
    char* reverse_str = malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        reverse_str[i++] = str[j];
    }
    reverse_str[i] = '\0';
    printf("Reversed string: %s\n", reverse_str);
    free(reverse_str);
}

void count_vowels(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }
    printf("Number of vowels in the string: %d\n", count);
}

void replace_char(char* str, char old_char, char new_char) {
    int len = strlen(str);
    char* new_str = malloc(len + 1);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (str[j] == old_char) {
            new_str[i++] = new_char;
        } else {
            new_str[i++] = str[j];
        }
    }
    new_str[i] = '\0';
    printf("New string: %s\n", new_str);
    free(new_str);
}

int main() {
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character
    printf("Original string: %s\n", str);

    reverse_string(str);
    count_vowels(str);
    replace_char(str, 'a', 'x');

    return 0;
}