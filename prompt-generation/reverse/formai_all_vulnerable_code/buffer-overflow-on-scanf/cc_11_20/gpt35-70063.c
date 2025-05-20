//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
/* C Cat Language Translator */
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char sentence[100], translated[100];

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please select an option:\n");
    printf("1. English to C Cat\n");
    printf("2. C Cat to English\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter English sentence: ");
            scanf(" %[^\n]s", sentence);

            /* Translation algorithm */
            for(int i=0; i<strlen(sentence); i++) {
                if(sentence[i] == ' ') {
                    strcat(translated, "meow ");
                } else if(sentence[i] == 'a') {
                    strcat(translated, "nya ");
                } else if(sentence[i] == 'e') {
                    strcat(translated, "purrs ");
                } else if(sentence[i] == 'i') {
                    strcat(translated, "hiss ");
                } else if(sentence[i] == 'o') {
                    strcat(translated, "purr ");
                } else if(sentence[i] == 'u') {
                    strcat(translated, "mew ");
                } else {
                    // retain original character
                    char c[2] = { sentence[i], '\0' };
                    strcat(translated, c);
                }
            }

            printf("C Cat Translation: %s\n", translated);
            break;

        case 2:
            printf("Enter C Cat sentence: ");
            scanf(" %[^\n]s", sentence);

            /* Translation algorithm */
            char *token = strtok(sentence, " ");

            while(token != NULL) {
                if(strcmp(token, "meow") == 0) {
                    strcat(translated, " ");
                } else if(strcmp(token, "nya") == 0) {
                    strcat(translated, "a");
                } else if(strcmp(token, "purrs") == 0) {
                    strcat(translated, "e");
                } else if(strcmp(token, "hiss") == 0) {
                    strcat(translated, "i");
                } else if(strcmp(token, "purr") == 0) {
                    strcat(translated, "o");
                } else if(strcmp(token, "mew") == 0) {
                    strcat(translated, "u");
                } else {
                    // retain original string
                    strcat(translated, token);
                }

                // get next token
                token = strtok(NULL, " ");
            }

            printf("English Translation: %s\n", translated);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}