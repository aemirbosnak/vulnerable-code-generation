//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char result[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Concatenate two strings
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    // Copy one string to another
    strcpy(result, str1);
    printf("Copied string: %s\n", result);

    // Compare two strings
    int result_compare = strcmp(str1, str2);
    if (result_compare == 0) {
        printf("Strings are equal.\n");
    } else if (result_compare < 0) {
        printf("String 1 is less than string 2.\n");
    } else {
        printf("String 1 is greater than string 2.\n");
    }

    // Reverse a string
    char reverse_str[100];
    strcpy(reverse_str, str1);
    int len = strlen(reverse_str);
    for (int i = len - 1; i >= 0; i--) {
        reverse_str[i] = reverse_str[len - i - 1];
    }
    printf("Reversed string: %s\n", reverse_str);

    // Replace a substring in a string
    char replace_str[100];
    printf("Enter substring to replace: ");
    scanf("%s", replace_str);
    printf("Enter replacement string: ");
    scanf("%s", str2);
    int replace_len = strlen(replace_str);
    int replace_count = 0;
    char* pos = strstr(str1, replace_str);
    while (pos!= NULL) {
        strcpy(pos, str2);
        pos += strlen(str2);
        replace_count++;
        pos = strstr(pos, replace_str);
    }
    printf("Replaced string: %s\n", str1);
    printf("Number of replacements: %d\n", replace_count);

    return 0;
}