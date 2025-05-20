//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

// Function to translate given string to Alien language
void translateToAlienLanguage(char str[]) {
    
    // Array of vowels in English language
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int len = strlen(str);
    
    // Loop through all the characters in given string
    for (int i = 0; i < len; i++) {
        
        // If character is a consonant, replace it with 'z'
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
            str[i] = 'z';
        }
        
        // If character is a vowel, replace it with its corresponding alien language vowel
        else {
            switch (str[i]) {
                case 'a':
                    str[i] = 'x';
                    break;
                case 'e':
                    str[i] = 'y';
                    break;
                case 'i':
                    str[i] = 'w';
                    break;
                case 'o':
                    str[i] = 'v';
                    break;
                case 'u':
                    str[i] = 'u';
                    break;
                default:
                    break;
            }
        }
    }
    
    // Print translated string
    printf("Translated string: %s\n", str);
}

int main() {
    char str[100];
    printf("Enter string to translate to Alien language: ");
    scanf("%[^\n]s", str);
    translateToAlienLanguage(str);
    return 0;
}