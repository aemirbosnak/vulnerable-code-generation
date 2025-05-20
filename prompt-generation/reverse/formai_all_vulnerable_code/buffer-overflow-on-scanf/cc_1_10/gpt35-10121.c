//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Removing the newline character from input

    printf("\nThe original string is: %s", str);

    // Converting string to uppercase
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    printf("\nThe string in uppercase is: %s", str);

    // Converting string to lowercase
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    printf("\nThe string in lowercase is: %s", str);

    // Reversing the string
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    printf("\nThe reversed string is: %s", str);

    // Removing all occurrences of a character from the string
    char removeChar;
    printf("\nEnter a character to remove from the string: ");
    scanf("%c", &removeChar);
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != removeChar) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("\nThe string after removing '%c' is: %s ", removeChar, str);

    return 0;
}