//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void reverse(char *str) {
    int len = strlen(str);
    char temp[MAX_SIZE];

    strcpy(temp, str);

    for (int i = 0; i < len; i++) {
        str[i] = temp[len - i - 1];
    }
}

void capitalize(char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

void removeSpaces(char *str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        if (isspace(str[i])) {
            str[i] = '\0';
        }
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    reverse(str);
    printf("Reversed string: %s\n", str);

    capitalize(str);
    printf("Capitalized string: %s\n", str);

    removeSpaces(str);
    printf("String with spaces removed: %s\n", str);

    return 0;
}