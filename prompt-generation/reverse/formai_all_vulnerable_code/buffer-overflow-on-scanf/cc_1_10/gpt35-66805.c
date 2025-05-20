//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

// Define the unique C Alien language
char* alien[] = {"kli", "faf", "umt", "zor", "taz", "dur", "per", "lek", "jik", "hin"};

// Define the translation function
void translate(char* word) {
    int i;
    // Find a match for the input word in the alien language
    for (i = 0; i < 10; i++) {
        if (strcmp(word, alien[i]) == 0) {
            printf("Translation: ");
            // Print the corresponding index in English
            switch(i) {
                case 0:
                    printf("Hello");
                    break;
                case 1:
                    printf("Goodbye");
                    break;
                case 2:
                    printf("Yes");
                    break;
                case 3:
                    printf("No");
                    break;
                case 4:
                    printf("Friend");
                    break;
                case 5:
                    printf("Enemy");
                    break;
                case 6:
                    printf("Love");
                    break;
                case 7:
                    printf("Hate");
                    break;
                case 8:
                    printf("Peace");
                    break;
                case 9:
                    printf("War");
                    break;
            }
            printf("\n");
            return;
        }
    }
    // If there's no match, print an error message
    printf("Error: Word not found in the alien language.\n");
}

int main() {
    char word[4];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a word in the alien language (3 characters): ");
    scanf("%s", word);
    translate(word);
    return 0;
}