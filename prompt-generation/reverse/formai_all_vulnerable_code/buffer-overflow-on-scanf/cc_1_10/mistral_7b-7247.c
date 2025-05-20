//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void str_toLowerCase(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

void print_char_array(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int areAnagrams(char *str1, char *str2) {
    int char_count[26] = {0};
    int len1 = strlen(str1), len2 = strlen(str2);

    if (len1 != len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        int index = tolower(str1[i]) - 'a';
        char_count[index]++;
    }

    for (int i = 0; i < len2; i++) {
        int index = tolower(str2[i]) - 'a';
        char_count[index]--;

        if (char_count[index] < 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);
    str_toLowerCase(str1);

    printf("Enter the second string: ");
    scanf("%s", str2);
    str_toLowerCase(str2);

    if (areAnagrams(str1, str2)) {
        printf("The given strings are anagrams.\n");

        printf("First string characters in alphabetical order:\n");
        print_char_array(str1, strlen(str1));

        printf("Second string characters in alphabetical order:\n");
        print_char_array(str2, strlen(str2));
    } else {
        printf("The given strings are not anagrams.\n");
    }

    return 0;
}