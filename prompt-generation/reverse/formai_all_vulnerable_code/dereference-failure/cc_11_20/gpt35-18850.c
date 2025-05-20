//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <string.h>

// define function to convert C Alien Language to English
char* cAlienToEnglish(char* cAlien) {
    char* english = "";
    int len = strlen(cAlien);
    
    // loop through each character of C Alien Language
    for (int i = 0; i < len; i++) {
        int asciiVal = (int) cAlien[i];
        
        // if character is lowercase vowel
        if (asciiVal == 97 || asciiVal == 101 || asciiVal == 105 || asciiVal == 111 || asciiVal == 117) {
            strcat(english, "a");
        }
        // if character is uppercase vowel
        else if (asciiVal == 65 || asciiVal == 69 || asciiVal == 73 || asciiVal == 79 || asciiVal == 85) {
            strcat(english, "A");
        }
        // if character is lowercase consonant
        else if (asciiVal >= 98 && asciiVal <= 122 && asciiVal != 101 && asciiVal != 105 && asciiVal != 111 && asciiVal != 117) {
            strcat(english, "b");
        }
        // if character is uppercase consonant
        else if (asciiVal >= 66 && asciiVal <= 90 && asciiVal != 69 && asciiVal != 73 && asciiVal != 79 && asciiVal != 85) {
            strcat(english, "B");
        }
        // if character is number
        else if (asciiVal >= 48 && asciiVal <= 57) {
            strcat(english, "C");
        }
        // if character is special character
        else {
            strcat(english, "D");
        }
    }
    
    return english;
}

int main() {
    char cAlien[] = "Eennniiiiieeee";
    
    // convert C Alien Language to English
    char* english = cAlienToEnglish(cAlien);
    
    printf("C Alien Language: %s\n", cAlien);
    printf("English: %s\n", english);
    
    return 0;
}