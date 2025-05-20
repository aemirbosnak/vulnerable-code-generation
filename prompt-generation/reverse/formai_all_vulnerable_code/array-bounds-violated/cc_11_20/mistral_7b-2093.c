//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int len = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove all whitespaces
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j - 1] = str[j];
            }
            len--;
            i--;
        }
    }

    // Convert all lowercase characters to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    // Search for the substring "HELLO" and replace it with "WORLD"
    char search[] = "HELLO";
    int pos = strstr(str, search) - str;

    if (pos != -1) {
        for (int i = pos; str[i] != '\0'; i++) {
            if (i + 5 < strlen(str) && str[i] == search[0] && str[i+1] == search[1] && str[i+2] == search[2] && str[i+3] == search[3] && str[i+4] == search[4]) {
                for (int j = i; j < strlen(str) + 5; j++) {
                    if (j < strlen(str) + 5 && j >= i) {
                        str[j] = str[j + 5];
                    }
                }
                strncpy(str + i, "WORLD", 5);
                len += 5;
            }
        }
    }

    // Append the string "!"
    str[len] = '!';
    str[len + 1] = '\0';

    printf("Final String: %s\n", str);

    return 0;
}