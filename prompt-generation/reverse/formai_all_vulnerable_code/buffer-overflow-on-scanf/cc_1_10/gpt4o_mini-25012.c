//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 1024

void inputString(char *str, int len) {
    printf("Enter a string (up to %d characters): ", len);
    fgets(str, len, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
}

void executeSurprise(char *str) {
    printf("\nSurprise! Let's begin our string manipulation journey!\n");
    
    // Step 1: Convert to uppercase
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("1. Uppercase: %s\n", str);
    
    // Step 2: Determine length
    int length = strlen(str);
    printf("2. Length of string: %d\n", length);
    
    // Step 3: Reverse the string
    char reversed[MAX_STRING_LEN];
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string
    printf("3. Reversed: %s\n", reversed);
    
    // Step 4: Count vowels and consonants
    int vowels = 0, consonants = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            if (strchr("AEIOU", str[i])) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("4. Vowels: %d, Consonants: %d\n", vowels, consonants);
    
    // Step 5: Find and replace 'A' with '@'
    char replaced[MAX_STRING_LEN];
    for (int i = 0; i < length; i++) {
        replaced[i] = (str[i] == 'A') ? '@' : str[i];
    }
    replaced[length] = '\0';
    printf("5. Replaced 'A' with '@': %s\n", replaced);
    
    // Step 6: Create a substring
    char substring[MAX_STRING_LEN];
    int start, sub_length;
    printf("6. Enter substring start index (0 to %d): ", length - 1);
    scanf("%d", &start);
    printf("Enter substring length: ");
    scanf("%d", &sub_length);
    if (start >= 0 && start + sub_length <= length) {
        strncpy(substring, &str[start], sub_length);
        substring[sub_length] = '\0';
        printf("Substring: %s\n", substring);
    } else {
        printf("Error: Invalid substring range!\n");
    }
    
    // Step 7: Count occurrences of a character
    char charToCount;
    printf("7. Enter a character to count in the original string: ");
    getchar(); // To consume newline left in buffer
    scanf("%c", &charToCount);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == charToCount) {
            count++;
        }
    }
    printf("Occurrences of '%c': %d\n", charToCount, count);
    
    // Step 8: Append another string
    char appendStr[MAX_STRING_LEN];
    printf("8. Enter a string to append: ");
    getchar(); // To consume newline left in buffer
    fgets(appendStr, MAX_STRING_LEN, stdin);
    appendStr[strcspn(appendStr, "\n")] = '\0'; // Remove newline character
    strcat(str, appendStr);
    printf("After appending: %s\n", str);
    
    // Step 9: Split the string by spaces
    printf("9. Splitting the string:\n");
    char *token = strtok(str, " ");
    while (token != NULL) {
        printf(" - %s\n", token);
        token = strtok(NULL, " ");
    }

    // Step 10: Final surprise, let's create a shout version!
    char shout[MAX_STRING_LEN];
    for (int i = 0; str[i]; i++) {
        shout[i] = (islower(str[i])) ? toupper(str[i]) : str[i];
    }
    shout[length] = '\0';
    printf("10. SHOUT VERSION: %s\n", shout);
}

int main() {
    char input[MAX_STRING_LEN];
    
    inputString(input, MAX_STRING_LEN);
    
    executeSurprise(input);
    
    return 0;
}