//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
    char *p1, *p2;
    if (!str || *str == '\0') {
        return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
    int count = 0;
    for (; *str; ++str) {
        switch (*str) {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o': case 'O':
            case 'u': case 'U':
                ++count;
        }
    }
    return count;
}

// Function to remove all spaces from a string
char *remove_spaces(char *str) {
    char *p1, *p2;
    for (p1 = p2 = str; *p1; ++p1) {
        if (*p1 != ' ') {
            *p2++ = *p1;
        }
    }
    *p2 = '\0';
    return str;
}

// Function to convert a string to uppercase
char *to_upper(char *str) {
    for (; *str; ++str) {
        *str = toupper(*str);
    }
    return str;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    printf("Reversed string: %s\n", reverse(str));
    printf("Number of vowels: %d\n", count_vowels(str));
    printf("String with no spaces: %s\n", remove_spaces(str));
    printf("String in uppercase: %s\n", to_upper(str));

    return 0;
}