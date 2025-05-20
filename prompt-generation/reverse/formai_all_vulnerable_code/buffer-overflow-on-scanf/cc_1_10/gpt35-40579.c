//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <string.h>

// Structure to hold the mapping of characters to Alien Language
typedef struct {
    char alien_char;
    char human_char[10];
} alien_map;

// Mapping of characters to Alien Language
alien_map map[] = {
    {'A', "NAR"},
    {'B', "ZIN"},
    {'C', "LOP"},
    {'D', "KEL"},
    {'E', "SOP"},
    {'F', "TAR"},
    {'G', "JIT"},
    {'H', "BAN"},
    {'I', "RIP"},
    {'J', "KOX"},
    {'K', "HEX"},
    {'L', "ZEP"},
    {'M', "DAZ"},
    {'N', "FEN"},
    {'O', "GUB"},
    {'P', "LIX"},
    {'Q', "VAX"},
    {'R', "RED"},
    {'S', "WOK"},
    {'T', "YIK"},
    {'U', "POY"},
    {'V', "MEK"},
    {'W', "GEQ"},
    {'X', "JAB"},
    {'Y', "XIR"},
    {'Z', "MUD"}
};

// Function to translate a string from Human Language to Alien Language
void to_alien_language(char human_text[]) {
    int len = strlen(human_text);
    for(int i=0; i<len; i++) {
        int found = 0;
        for(int j=0; j<26; j++) {
            if(map[j].alien_char == human_text[i]) {
                printf("%s", map[j].human_char);
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("%c", human_text[i]);
        }
    }
}

// Function to translate a string from Alien Language to Human Language
void to_human_language(char alien_text[]) {
    int len = strlen(alien_text);
    int index = 0;
    while(index < len) {
        int found = 0;
        for(int j=0; j<26; j++) {
            if(strstr(alien_text+index, map[j].human_char) == alien_text+index) {
                printf("%c", map[j].alien_char);
                found = 1;
                index += strlen(map[j].human_char);
                break;
            }
        }
        if(!found) {
            printf("%c", alien_text[index]);
            index++;
        }
    }
}

// Main function to demonstrate the Alien Language Translator
int main() {
    int choice;
    printf("Welcome to the Alien Language Translator!\n\n");
    printf("1. Translate from Human Language to Alien Language\n");
    printf("2. Translate from Alien Language to Human Language\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if(choice == 1) {
        // Translate from Human Language to Alien Language
        char human_text[100];
        printf("\nEnter the text in Human Language: ");
        scanf(" %[^\n]s", human_text);
        printf("\nThe text in Alien Language is: ");
        to_alien_language(human_text);
    } else if(choice == 2) {
        // Translate from Alien Language to Human Language
        char alien_text[1000];
        printf("\nEnter the text in Alien Language: ");
        scanf(" %[^\n]s", alien_text);
        printf("\nThe text in Human Language is: ");
        to_human_language(alien_text);
    } else {
        printf("\nInvalid choice. Please try again.\n");
    }
    return 0;
}