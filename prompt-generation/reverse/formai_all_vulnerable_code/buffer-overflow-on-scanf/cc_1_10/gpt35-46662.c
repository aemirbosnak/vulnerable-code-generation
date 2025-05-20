//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C Cat Language Translator.\n\n");

    char english[] = "I love eating fish.";
    char cat[] = "purr purr purr meow meow nap purr fish purr purr purr meow purr nap";
    char translated[1000];
    
    printf("Enter a sentence in English to translate to Cat Language:\n");
    fgets(english, sizeof(english), stdin);
    english[strcspn(english, "\n")] = '\0';

    printf("Translation in Cat Language:\n");

    char *word = strtok(english, " ");
    while (word != NULL) {
        if (strcmp(word, "I") == 0 || strcmp(word, "i") == 0) {
            strcat(translated, "purr");
        }
        else if (strcmp(word, "love") == 0) {
            strcat(translated, "nap purr");
        }
        else if (strcmp(word, "eating") == 0) {
            strcat(translated, "fish purr");
        }
        else if (strcmp(word, "fish") == 0) {
            strcat(translated, "meow purr");
        }
        else {
            strcat(translated, word);
        }
        strcat(translated, " ");
        word = strtok(NULL, " ");
    }

    printf("%s\n", translated);
    
    printf("\nDid you like your translation? Do you want to learn more fun cat words?");
    printf("\nPress 1 for yes and 2 for no: ");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("\nHere are some more fun cat words you can use in your English sentences:\n");
        printf("- meow: means 'hello' or 'hi there'\n");
        printf("- nap: means 'sleep' or 'rest'\n");
        printf("- purr: means 'happy' or 'contented'\n");
        printf("- fish: means 'food'\n");
        printf("- scratch: means 'stop that' or 'no'\n");
    }
    else {
        printf("\nThank you for trying out the C Cat Language Translator!");
    }

    return 0;
}