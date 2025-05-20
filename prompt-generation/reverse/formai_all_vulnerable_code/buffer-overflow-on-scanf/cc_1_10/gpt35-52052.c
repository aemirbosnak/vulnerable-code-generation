//FormAI DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <string.h>

// function to count number of vowels in a given string
int countVowels(char str[]) {
    int count = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        char ch = str[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            count++;
        }
    }
    return count;
}

// function to replace a given character with another in a string
void replaceChar(char str[], char oldChar, char newChar) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from input
    
    // counting vowels
    int numVowels = countVowels(input);
    printf("Number of vowels in the string: %d\n", numVowels);
    
    // replacing characters
    char oldChar, newChar;
    printf("Enter a character to replace: ");
    scanf("%c", &oldChar);
    printf("Enter a character to replace with: ");
    getchar(); // to discard the newline character left in the input buffer
    scanf("%c", &newChar);
    replaceChar(input, oldChar, newChar);
    printf("New string after replacement: %s\n", input);
    
    return 0;
}