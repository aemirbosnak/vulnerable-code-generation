//FormAI DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[100];
    int len1, len2, len3;

    // Get three strings as input
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    printf("Enter the third string: ");
    fgets(str3, sizeof(str3), stdin);

    // Get the lengths of each string
    len1 = strlen(str1) - 1; // Removing the newline character
    len2 = strlen(str2) - 1;
    len3 = strlen(str3) - 1;

    // Combine the first two strings
    strcat(str1, str2);

    // Reverse the third string
    for (int i = 0; i < len3/2; i++) {
        char temp = str3[i];
        str3[i] = str3[len3-i-1];
        str3[len3-i-1] = temp;
    }

    // Count the number of vowels in the first string
    int vowel_count = 0;
    for (int i = 0; i < len1; i++) {
        char ch = str1[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowel_count++;
        }
    }

    // Replace all instances of the second string in the first string with the third string
    int index = 0;
    while ((index = strstr(str1, str2) - str1) != -1) {
        // Copy the first part of the string
        char first_part[100];
        strncpy(first_part, str1, index);

        // Copy the second part of the string
        char second_part[100];
        strncpy(second_part, str1 + index + len2, len1 - index - len2 + 1);

        // Combine the first part, third string, and second part
        strcpy(str1, first_part);
        strcat(str1, str3);
        strcat(str1, second_part);

        len1 = strlen(str1);
    }

    // Display the final string and the vowel count
    printf("Final string: %s\n", str1);
    printf("Number of vowels in first string: %d\n", vowel_count);

    return 0;
}