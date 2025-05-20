//FormAI DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char originalString[100], modifiedString[100];
    int length, i, j, k, l;

    printf("Enter the string: ");
    scanf("%s", originalString);

    length = strlen(originalString);

    printf("The character count is: %d\n", length);

    // reverse the string
    j = length - 1;
    for (i = 0; i < length; i++) {
        modifiedString[i] = originalString[j];
        j--;
    }
    modifiedString[i] = '\0';

    printf("The reversed string is: %s\n", modifiedString);

    // remove whitespaces
    j = 0;
    for (i = 0; i < length; i++) {
        if (originalString[i] != ' ') {
            modifiedString[j] = originalString[i];
            j++;
        }
    }
    modifiedString[j] = '\0';

    printf("The string without spaces is: %s\n", modifiedString);

    // convert to uppercase
    for (i = 0; i < length; i++) {
        modifiedString[i] = toupper(originalString[i]);
    }
    modifiedString[i] = '\0';

    printf("The uppercase string is: %s\n", modifiedString);

    // replace a character
    char searchChar, replaceChar;

    printf("Enter the character to be replaced: ");
    scanf(" %c", &searchChar);

    printf("Enter the character to replace with: ");
    scanf(" %c", &replaceChar);

    for (i = 0; i < length; i++) {
        if (originalString[i] == searchChar) {
            modifiedString[i] = replaceChar;
        }
        else {
            modifiedString[i] = originalString[i];
        }
    }
    modifiedString[i] = '\0';

    printf("The replaced string is: %s\n", modifiedString);

    // count vowels and consonants
    int vowels = 0, consonants = 0;
    char c;

    for (i = 0; i < length; i++) {
        c = toupper(originalString[i]);
        if ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) {
            vowels++;
        }
        else if ((c >= 'A') && (c <= 'z')) {
            consonants++;
        }
    }

    printf("The number of vowels is: %d\n", vowels);
    printf("The number of consonants is: %d\n", consonants);

    // find substring
    char substring[100];

    printf("Enter the substring to find: ");
    scanf("%s", substring);

    int subLength = strlen(substring), found = 0;

    for (i = 0; i <= length - subLength; i++) {
        for (j = i; j < i + subLength; j++) {
            if (originalString[j] != substring[j - i]) {
                break;
            }
        }
        if (j == i + subLength) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Substring %s found at position %d\n", substring, i);
    }
    else {
        printf("Substring %s not found\n", substring);
    }

    // remove duplicates
    j = 0;
    for (i = 0; i < length; i++) {
        for (k = 0; k < i; k++) {
            if (originalString[i] == originalString[k]) {
                break;
            }
        }
        if (k == i) {
            modifiedString[j] = originalString[i];
            j++;
        }
    }
    modifiedString[j] = '\0';

    printf("The string without duplicates is: %s\n", modifiedString);

    return 0;
}