//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void to_alien_language(char str[]);
void from_alien_language(char str[]);

int main() {
    char str[MAX_LEN];      
    int choice;

    printf("Enter 1 to translate to Alien Language or 2 to translate from Alien Language: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter a string to be translated to Alien Language: ");
        scanf("%s", str);
        to_alien_language(str);
    } else if(choice == 2) {
        printf("Enter a string in Alien Language to be translated to English: ");
        scanf("%s", str);
        from_alien_language(str);
    } else {
        printf("Invalid choice!");
    }

    return 0;
}

void to_alien_language(char str[]) {

    int len = strlen(str);

    // loop through every character in the input string
    for(int i = 0; i < len; i++) {

        // check if the character is a vowel
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            // if yes, replace it with the next consonant in the alphabet loop
            if(str[i] == 'a') {
                str[i] = 'b';
            } else if(str[i] == 'e') {
                str[i] = 'f';
            } else if(str[i] == 'i') {
                str[i] = 'j';
            } else if(str[i] == 'o') {
                str[i] = 'p';
            } else if(str[i] == 'u') {
                str[i] = 'v';
            }
        }
    }

    // print the translated string in Alien Language
    printf("The string in Alien Language is: %s", str);
}

void from_alien_language(char str[]) {

    int len = strlen(str);

    // loop through every character in the input string
    for(int i = 0; i < len; i++) {

        // check if the character is a consonant
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
            // if yes, replace it with the previous vowel in the alphabet loop
            if(str[i] == 'b') {
                str[i] = 'a';
            } else if(str[i] == 'c') {
                str[i] = 'a';
            } else if(str[i] == 'd') {
                str[i] = 'e';
            } else if(str[i] == 'f') {
                str[i] = 'e';
            } else if(str[i] == 'g') {
                str[i] = 'i';
            } else if(str[i] == 'h') {
                str[i] = 'i';
            } else if(str[i] == 'j') {
                str[i] = 'o';
            } else if(str[i] == 'k') {
                str[i] = 'o';
            } else if(str[i] == 'l') {
                str[i] = 'u';
            } else if(str[i] == 'm') {
                str[i] = 'u';
            } else if(str[i] == 'n') {
                str[i] = 'a';
            } else if(str[i] == 'p') {
                str[i] = 'e';
            } else if(str[i] == 'q') {
                str[i] = 'i';
            } else if(str[i] == 'r') {
                str[i] = 'o';
            } else if(str[i] == 's') {
                str[i] = 'u';
            } else if(str[i] == 't') {
                str[i] = 'a';
            } else if(str[i] == 'v') {
                str[i] = 'e';
            } else if(str[i] == 'w') {
                str[i] = 'i';
            } else if(str[i] == 'x') {
                str[i] = 'o';
            } else if(str[i] == 'y') {
                str[i] = 'u';
            } else if(str[i] == 'z') {
                str[i] = 'a';
            }
        }
    }

    // print the translated string in English
    printf("The string in English is: %s", str);
}