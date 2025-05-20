//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // declare a character array to store string

    printf("Enter a string:\n"); 
    scanf("%[^\n]", str); // take input string from the user until a newline is encountered

    int len = strlen(str); // find the length of the string using strlen() function
    printf("The length of the string is: %d\n", len);

    // Reverse the string:
    int i;
    char reversed_str[100]; // declare a new character array to store the reversed string

    for (i = 0; i < len; i++) {
        reversed_str[i] = str[len-i-1]; // reverse the string by copying characters in reverse order
    }
    reversed_str[len] = '\0'; // add null terminator to the end of the reversed string

    printf("The reversed string is: %s\n", reversed_str);

    // Count the number of vowels in the string:
    int vowel_count = 0;
    char vowels[] = "aeiouAEIOU"; // declare an array of vowels to check against

    for (i = 0; i < len; i++) {
        char current_char = str[i];
        char *p = strchr(vowels, current_char); // find the first occurrence of the current character in the vowels array
        if (p != NULL) { // if a match is found, increment vowel_count
            vowel_count++;
        }
    }

    printf("The number of vowels in the string is: %d\n", vowel_count);

    // Remove all occurrences of a specific character from the string:
    char remove_char;
    printf("Enter a character to remove from the string:\n");
    scanf(" %c", &remove_char); // take input of the character to remove from the user

    int removed_count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == remove_char) { // if the current character matches the character to be removed, skip it
            removed_count++;
            continue;
        }
        str[i-removed_count] = str[i]; // otherwise, shift the current character left by the number of removed characters
    }
    str[len-removed_count] = '\0'; // add null terminator to the end of the modified string

    printf("The string with character '%c' removed is: %s\n", remove_char, str);

    return 0;
}