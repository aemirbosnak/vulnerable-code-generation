//FormAI DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = (char*) malloc(sizeof(char));
    printf("Enter a string: ");
    scanf("%[^\n]", str); // read until newline
    getchar(); // consume newline character
    
    int len = strlen(str);
    printf("String length: %d\n", len);
    
    char* vowel_str = (char*) malloc((len+1)*sizeof(char)); // +1 for null character
    int vowel_count = 0;
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowel_str[vowel_count++] = c;
        }
    }
    vowel_str[vowel_count] = '\0';
    printf("String with only vowels: %s\n", vowel_str);
    
    char* rev_str = (char*) malloc((len+1)*sizeof(char)); // +1 for null character
    int rev_count = 0;
    for (int i = len-1; i >= 0; i--) {
        rev_str[rev_count++] = str[i];
    }
    rev_str[rev_count] = '\0';
    printf("Reversed string: %s\n", rev_str);
    
    int palin = 1;
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len-1-i]) {
            palin = 0;
            break;
        }
    }
    if (palin) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    
    free(str);
    free(vowel_str);
    free(rev_str);
    return 0;
}