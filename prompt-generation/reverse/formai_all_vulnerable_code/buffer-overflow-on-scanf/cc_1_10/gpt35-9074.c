//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>

char* findChar(char *str, char c) {
    if (*str == c) {
        return str;
    }
    if (*str == '\0') {
        return NULL;
    }
    return findChar(str + 1, c);
}

void replaceChar(char *str, char c1, char c2) {
    if (*str == c1) {
        *str = c2;
    }
    if (*str == '\0') {
        return;
    }
    replaceChar(str + 1, c1, c2);
}

int countChars(char *str, int count) {
    if (*str == '\0') {
        return count;
    }
    countChars(str + 1, ++count);
}

int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // Find character
    char c;
    printf("Enter a character to find: ");
    scanf("%c", &c);
    char *p = findChar(s, c);
    if (p == NULL) {
        printf("Character not found.\n");
    }
    else {
        printf("Character found at position %ld.\n", p - s + 1);
    }

    // Replace character
    char c1, c2;
    printf("Enter a character to replace: ");
    scanf(" %c", &c1);
    printf("Enter a new character: ");
    scanf(" %c", &c2);
    replaceChar(s, c1, c2);
    printf("New string: %s", s);

    // Count characters
    int count = countChars(s, 0);
    printf("Number of characters: %d\n", count);

    return 0;
}