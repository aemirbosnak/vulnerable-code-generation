//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

#define ALIEN_WORDS 5
#define MAX_WORD_LENGTH 10

int main(){

    char alien_words[ALIEN_WORDS][MAX_WORD_LENGTH];
    char english_translations[ALIEN_WORDS][MAX_WORD_LENGTH];

    strcpy(alien_words[0], "sun"); // Alien word for sun
    strcpy(alien_words[1], "moon"); // Alien word for moon
    strcpy(alien_words[2], "water"); // Alien word for water
    strcpy(alien_words[3], "sky"); // Alien word for sky
    strcpy(alien_words[4], "earth"); // Alien word for earth

    strcpy(english_translations[0], "Sol"); // Translation of sun
    strcpy(english_translations[1], "Luna"); // Translation of moon
    strcpy(english_translations[2], "Aqua"); // Translation of water
    strcpy(english_translations[3], "Ether"); // Translation of sky
    strcpy(english_translations[4], "Terra"); // Translation of earth

    char input_word[MAX_WORD_LENGTH];
    int i, j = -1;

    printf("Welcome to the Alien Language Translator!\n");

    do{
        j = -1;
        printf("\nEnter an alien word (type 'exit' to quit): ");
        scanf("%s", input_word);

        if(strcmp(input_word, "exit") == 0){
            printf("Goodbye!\n");
            break;
        }

        // Search for input_word in alien_words array
        for(i = 0; i < ALIEN_WORDS; i++){
            if(strcmp(input_word, alien_words[i]) == 0){
                j = i;
                break;
            }
        }

        if(j == -1){
            printf("Sorry, the word '%s' is not in our dictionary. Please try again.\n", input_word);
        }
        else{
            printf("Translation: %s\n", english_translations[j]);
        }

    }while(1);

    return 0;
}