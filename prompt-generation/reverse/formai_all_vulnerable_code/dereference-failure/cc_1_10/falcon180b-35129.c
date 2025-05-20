//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    // Remove leading/trailing white spaces
    char *trimmed = str;
    while (isspace(*trimmed)) {
        trimmed++;
    }
    int len = strlen(trimmed);
    while (isspace(trimmed[len - 1])) {
        trimmed[--len] = '\0';
    }

    // Reverse the string
    char reverse[MAX_LEN];
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = trimmed[i];
        trimmed[i] = trimmed[j];
        trimmed[j] = temp;
        i++;
        j--;
    }

    // Capitalize the first letter of each word
    int start = 0, end = 0;
    while (end < len) {
        if (isspace(trimmed[end])) {
            trimmed[end] = '\0';
            for (int k = start; k < end; k++) {
                trimmed[k] = toupper(trimmed[k]);
            }
            start = end + 1;
        }
        end++;
    }

    // Print the manipulated string
    printf("Original string: %s\n", str);
    printf("Trimmed string: %s\n", trimmed);
    printf("Reversed string: %s\n", reverse);
    printf("Capitalized string: %s\n", trimmed);

    return 0;
}