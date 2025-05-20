//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

/* Array of known words in Cat Language */
char knownWords[10][20] = {"meow", "purr", "hiss", "scratch", "fish", "sleep", "window", "bird", "milk", "nap"};

/* Array of translated words in English Language */
char translatedWords[10][20] = {"hello", "happy", "angry", "claw", "food", "rest", "view", "prey", "drink", "doze"};

/* This function translates a sentence from Cat Language to English Language */
void translateToEnglish(char sentence[]) {
    char* word;
    int i, j, k;
    printf("Translation: ");
    word = strtok(sentence, " ");
    while(word != NULL) {
        for(i = 0; i < 10; i++) {
            if(strcmp(word, knownWords[i]) == 0) {
                printf("%s ", translatedWords[i]);
                break;
            }
        }
        if(i == 10) {
            /* If the word is not known, keep it as it is */
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n\n");
}

/* This function translates a sentence from English Language to Cat Language */
void translateToCatLanguage(char sentence[]) {
    char* word;
    int i, j, k;
    printf("Translation: ");
    word = strtok(sentence, " ");
    while(word != NULL) {
        for(i = 0; i < 10; i++) {
            if(strcmp(word, translatedWords[i]) == 0) {
                printf("%s ", knownWords[i]);
                break;
            }
        }
        if(i == 10) {
            /* If the word is not known, keep it as it is */
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n\n");
}

/* Main function */
int main() {
    char sentence[100];
    int choice;

    printf("Welcome to the Cat Language Translator!\n\n");

    while(1) {
        printf("What do you want to do?\n1. Translate Cat Language to English\n2. Translate English to Cat Language\n3. Exit\n\n");
        scanf("%d", &choice);

        getchar(); // to consume the newline character after the integer input

        switch(choice) {
            case 1:
                printf("Enter the Cat Language sentence you want to translate: ");
                fgets(sentence, 100, stdin);
                translateToEnglish(sentence);
                break;

            case 2:
                printf("Enter the English sentence you want to translate: ");
                fgets(sentence, 100, stdin);
                translateToCatLanguage(sentence);
                break;

            case 3:
                printf("Thank you for using our Cat Language Translator!\n");
                return 0;

            default:
                printf("Invalid Input!\n");
        }
    }

    return 0;
}