//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include<stdio.h>
#include<string.h>

char alien_dict[27][3] = { // Alien language dictionary
        "a@", "b#", "c$", "d%", "e&", "f*", "g+", "h=", "i?", "j<", "k>", "l^", "m~", "n`", "o|", "p/", "q\\", "r(", "s)", "t[", "u]", "v{", "w}", "x:", "y;", "z." 
};

void alien_to_english(char *alien_word) { // Function to convert alien to English
    int i, j;
    char temp[3], english_word[1000], english_char;
    for(i=0; i<strlen(alien_word); i=i+2) {
        temp[0] = alien_word[i];
        temp[1] = alien_word[i+1];
        temp[2] = '\0';
        for(j=0; j<26; j++) {
            if(strcmp(temp, alien_dict[j]) == 0) {
                english_char = j + 'a'; 
                break;
            }
        }
        english_word[i/2] = english_char;
    }
    printf("\nTranslated English word: %s\n", english_word);
}

void english_to_alien(char *english_word) { // Function to convert English to alien
    int i, j, temp;
    char alien_word[1000];
    for(i=0; i<strlen(english_word); i++) {
        temp = english_word[i] - 'a';
        strcat(alien_word, alien_dict[temp]); 
    }
    printf("\nTranslated Alien word: %s\n", alien_word);
}

int main() {
    char input_word[1000];
    int choice;
    printf("Welcome to the C Alien Language Translator!\n");
    while(1) { // Loop to keep the program running until user chooses to exit
        printf("\nEnter 1 to translate Alien to English \nEnter 2 to translate English to Alien \nEnter any other key to exit:\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter Alien word to translate: ");
            scanf("%s", input_word);
            alien_to_english(input_word);
        } else if(choice == 2) {
            printf("Enter English word to translate: ");
            scanf("%s", input_word);
            english_to_alien(input_word);
        } else {
            printf("Thank you for using C Alien Language Translator!\n");
            break;
        }
    }
    return 0;
}