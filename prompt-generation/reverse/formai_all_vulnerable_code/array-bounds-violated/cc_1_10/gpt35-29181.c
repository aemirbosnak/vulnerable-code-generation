//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], str3[100];
    int len1, len2, len3;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    len1 = strlen(str1);
    if (str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';
    }

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    len2 = strlen(str2);
    if (str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
    }

    // Concatenating two strings
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);

    // Copying a string
    strcpy(str3, str1);
    printf("Copied String: %s\n", str3);

    // Reversing a string
    len3 = strlen(str3);
    for (int i = 0; i < len3 / 2; i++) {
        char temp = str3[i];
        str3[i] = str3[len3 - i - 1];
        str3[len3 - i - 1] = temp;
    }
    printf("Reversed String: %s\n", str3);

    // Finding a substring in a string
    char *substr = strstr(str1, str2);
    if (substr) {
        printf("Substring Found: %s\n", substr);
    } else {
        printf("No Substring Found\n");
    }

    // Converting a string to uppercase
    len3 = strlen(str3);
    for (int i = 0; i < len3; i++) {
        if (str3[i] >= 'a' && str3[i] <= 'z') {
            str3[i] = str3[i] - ('a' - 'A');
        }
    }
    printf("Uppercase String: %s\n", str3);

    return 0;
}