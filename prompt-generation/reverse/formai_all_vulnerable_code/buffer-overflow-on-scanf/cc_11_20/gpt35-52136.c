//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char english_input[1000], alien_output[1000];
    int i, j, choice;

    printf("Welcome to Alien Language Translator\n");
    printf("Please select an option:\n");
    printf("1. English to Alien\n");
    printf("2. Alien to English\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter English sentence: ");
            getchar();
            fgets(english_input, sizeof(english_input), stdin);
            printf("Translating...\n");
            // Conversion code goes here
            for(i = 0; i < strlen(english_input); i++) {
                switch(english_input[i]) {
                    case 'a':
                        strcat(alien_output, "ooka");
                        break;
                    case 'b':
                        strcat(alien_output, "munya");
                        break;
                    case 'c':
                        strcat(alien_output, "foda");
                        break;

                    // More cases for each English alphabet
                    // ...

                    default:
                        strcat(alien_output, " ");
                }
            }
            printf("Alien language output: %s\n", alien_output);
            break;

        case 2:
            printf("Enter Alien sentence: ");
            getchar();
            fgets(alien_output, sizeof(alien_output), stdin);
            printf("Translating...\n");
            // Conversion code goes here
            for(i = 0; i < strlen(alien_output); i++) {
                if(alien_output[i] == 'o') {
                    if(alien_output[i+1] == 'o') {
                        if(alien_output[i+2] == 'k') {
                            english_input[j++] = 'a';
                            i += 2;
                        }
                    }
                }
                else if(alien_output[i] == 'm') {
                    if(alien_output[i+1] == 'u') {
                        if(alien_output[i+2] == 'n') {
                            if(alien_output[i+3] == 'y') {
                                english_input[j++] = 'b';
                                i += 3;
                            }
                        }
                    }
                }

                // More complex cases for each Alien alphabet
                // ...

                else {
                    english_input[j++] = ' ';
                }
            }
            english_input[j] = '\0';
            printf("English output: %s\n", english_input);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}