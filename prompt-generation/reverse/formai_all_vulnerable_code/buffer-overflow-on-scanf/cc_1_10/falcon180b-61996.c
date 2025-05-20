//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];
    char result[MAX_LENGTH];

    // Get user input for string1
    printf("Enter string 1: ");
    scanf("%s", string1);

    // Get user input for string2
    printf("Enter string 2: ");
    scanf("%s", string2);

    // Concatenate string1 and string2
    strcat(string1, string2);
    printf("Concatenated string: %s\n", string1);

    // Copy string1 to result
    strcpy(result, string1);
    printf("Copied string: %s\n", result);

    // Reverse string1
    int length = strlen(string1);
    for (int i = 0; i < length / 2; i++) {
        char temp = string1[i];
        string1[i] = string1[length - i - 1];
        string1[length - i - 1] = temp;
    }
    printf("Reversed string: %s\n", string1);

    // Convert string1 to uppercase
    for (int i = 0; i < strlen(string1); i++) {
        string1[i] = toupper(string1[i]);
    }
    printf("Uppercase string: %s\n", string1);

    // Convert string1 to lowercase
    for (int i = 0; i < strlen(string1); i++) {
        string1[i] = tolower(string1[i]);
    }
    printf("Lowercase string: %s\n", string1);

    // Remove all whitespace from string1
    char *ptr = string1;
    while (*ptr!= '\0') {
        if (!isspace(*ptr)) {
            string1[0] = *ptr;
            string1[1] = '\0';
            ptr++;
        } else {
            ptr++;
        }
    }
    printf("String without whitespace: %s\n", string1);

    return 0;
}