//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character from Alien Language to English Alphabet
char convert_char(char c){
    switch(c){
        case 'o': return 'a';
        case '|': return 'b';
        case '*': return 'c';
        case '^': return 'd';
        case '>': return 'e';
        case '#': return 'f';
        case '/': return 'g';
        case '\\': return 'h';
        case '@': return 'i';
        case '+': return 'j';
        case '=': return 'k';
        case '%': return 'l';
        case '_': return 'm';
        case '?': return 'n';
        case '<': return 'o';
        case '~': return 'p';
        case '&': return 'q';
        case '$': return 'r';
        case '!': return 's';
        case '`': return 't';
        case '{': return 'u';
        case '}': return 'v';
        case '[': return 'w';
        case ']': return 'x';
        case ';': return 'y';
        case ':': return 'z';
        default: return c;
    }
}

int main(){
    char alien_language[1000];   // To store Alien Language message
    char english[1000];          // To store English Alphabet message
    int len;                     // To store length of message
    
    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a message in Alien Language: ");
    fgets(alien_language, 1000, stdin);  // Reading Alien Language message from user
    
    len = strlen(alien_language);
    for(int i=0; i<len; i++){
        english[i] = convert_char(tolower(alien_language[i]));  // Converting each character and storing in English Alphabet message
    }
    english[len-1] = '\0';      // Adding null character at the end of string
    
    printf("\nThe original message in Alien Language: %s", alien_language);
    printf("The translated message in English Alphabet: %s", english);
    
    printf("\nThank you for using the Alien Language Translator!\n");
    return 0;
}