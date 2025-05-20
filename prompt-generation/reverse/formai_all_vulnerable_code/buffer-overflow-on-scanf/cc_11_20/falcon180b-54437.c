//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000];
    int len, i, j, k;
    char ch;
    char *p;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    len = strlen(str);

    // Count the number of vowels in the string
    int vowel_count = 0;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel_count++;
            }
        }
    }
    printf("Number of vowels in the string: %d\n", vowel_count);

    // Reverse the string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
    printf("Reversed string: %s\n", str);

    // Replace all occurrences of a character with another character
    char old_ch, new_ch;
    printf("Enter the character to replace: ");
    scanf("%c", &old_ch);
    printf("Enter the new character: ");
    scanf("%c", &new_ch);
    for (i = 0; i < len; i++) {
        if (str[i] == old_ch) {
            str[i] = new_ch;
        }
    }
    printf("String after replacement: %s\n", str);

    // Convert the string to uppercase
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    printf("String in uppercase: %s\n", str);

    // Remove all whitespace characters from the string
    p = strtok(str, " ");
    while (p!= NULL) {
        printf("%s ", p);
        p = strtok(NULL, " ");
    }

    // Count the number of words in the string
    int word_count = 0;
    for (i = 0; i < len; i++) {
        if (isspace(str[i])) {
            word_count++;
        }
    }
    printf("Number of words in the string: %d\n", word_count);

    return 0;
}