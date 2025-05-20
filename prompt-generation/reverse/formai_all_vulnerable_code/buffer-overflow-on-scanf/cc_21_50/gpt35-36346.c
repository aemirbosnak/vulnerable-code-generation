//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("Sorted string: %s\n", str);

    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for (i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowels++;
        } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            consonants++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else {
            spaces++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    printf("Enter a character to search: ");
    fflush(stdin);
    char searchChar = getchar();

    int charIndex = -1;

    for (i = 0; i < len; i++) {
        if (str[i] == searchChar) {
            charIndex = i;
            break;
        }
    }

    if (charIndex == -1) {
        printf("%c not found in the string.\n", searchChar);
    } else {
        printf("%c found at index %d.\n", searchChar, charIndex);
    }

    int start, end;
    printf("Enter the start and end index of the substring to extract: ");
    scanf("%d %d", &start, &end);

    if (start < 0 || end >= len || start > end) {
        printf("Invalid indices.\n");
    } else {
        char extractedSubStr[100];
        j = 0;
        for (i = start; i <= end; i++) {
            extractedSubStr[j++] = str[i]; 
        }
        extractedSubStr[j] = '\0';
        printf("Extracted substring: %s\n", extractedSubStr);
    }

    return 0;
}