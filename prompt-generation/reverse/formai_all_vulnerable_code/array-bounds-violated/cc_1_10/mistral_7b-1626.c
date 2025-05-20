//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to check if a given character is alphabet
int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to reverse a given string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if two strings are anagrams of each other
int are_anagrams(char *str1, char *str2) {
    int count[26] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;

    for (int i = 0; i < len1; ++i) {
        if (is_alpha(str1[i]))
            count[str1[i] - 'a']++;
    }

    for (int i = 0; i < len2; ++i) {
        if (is_alpha(str2[i])) {
            if (--count[str2[i] - 'a'] < 0)
                return 0;
        }
    }

    return 1;
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strlen(str1) - 1] = '\0';

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strlen(str2) - 1] = '\0';

    reverse_string(str1);

    if (are_anagrams(str1, str2))
        printf("Anagrams!\n");
    else
        printf("Not Anagrams!\n");

    return 0;
}