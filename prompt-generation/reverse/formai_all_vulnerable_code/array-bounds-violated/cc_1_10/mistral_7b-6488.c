//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to reverse the given string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if two strings are anagrams of each other
int areAnagrams(char *str1, char *str2) {
    int count[256] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2)
        return 0;

    for (int i = 0; i < len1; ++i) {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    for (int i = 0; i < 256; ++i) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    char str1[MAX_LEN] = "";
    char str2[MAX_LEN] = "";

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Check if the two strings are reverses of each other
    if (strlen(str1) != strlen(str2)) {
        printf("Strings are not reverse pairs.\n");
    } else {
        reverseString(str1);
        reverseString(str2);

        if (strcmp(str1, str2) == 0)
            printf("Strings are reverse pairs.\n");
        else
            printf("Strings are not reverse pairs.\n");
    }

    // Check if the two strings are anagrams of each other
    if (areAnagrams(str1, str2))
        printf("Strings are anagrams.\n");
    else
        printf("Strings are not anagrams.\n");

    return 0;
}