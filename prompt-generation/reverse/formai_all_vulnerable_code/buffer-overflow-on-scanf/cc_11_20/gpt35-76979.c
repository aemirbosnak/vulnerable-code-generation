//FormAI DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
    char originalString[100];
    printf("Enter a string: ");
    fgets(originalString, 100, stdin);
    originalString[strcspn(originalString, "\n")] = '\0'; // Removing '\n' character from fgets
    
    int length = strlen(originalString);
    char reversedString[100];
    
    for (int i = 0; i < length; i++) {
        reversedString[i] = originalString[length - 1 - i];
    }
    reversedString[length] = '\0'; // Adding terminating null character
    
    printf("Reversed string: %s\n", reversedString);
    
    int vowelCount = 0;
    int consonantCount = 0;
    
    for (int i = 0; i < length; i++) {
        char ch = reversedString[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonantCount++;
        }
    }
    
    printf("Vowel count: %d\n", vowelCount);
    printf("Consonant count: %d\n", consonantCount);
    
    char substring[100];
    printf("Enter a substring to search in the reversed string: ");
    scanf("%s", substring);
    
    int subLength = strlen(substring);
    int index = -1;
    for (int i = 0; i < length - subLength + 1; i++) {
        if (strncmp(reversedString + i, substring, subLength) == 0) {
            index = i;
            break;
        }
    }
    printf("Substring '%s' occurred at index %d in the reversed string.\n", substring, index);
    
    return 0;
}