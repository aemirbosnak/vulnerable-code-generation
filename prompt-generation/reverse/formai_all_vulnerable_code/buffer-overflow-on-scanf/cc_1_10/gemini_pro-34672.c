//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This function sanitizes a string by removing all non-alphanumeric characters.
 *
 * @param str The string to sanitize.
 */
void sanitize_string(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

/*
 * This function validates a string by ensuring that it contains only alphanumeric characters.
 *
 * @param str The string to validate.
 * @return True if the string is valid, false otherwise.
 */
int validate_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    sanitize_string(str);

    if (validate_string(str)) {
        printf("The sanitized string is: %s\n", str);
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}