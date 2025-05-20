//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    printf("Welcome to the surreal spell checker!\n\n");
    printf("Please enter the word you would like to check:\n");

    char input[100];
    scanf("%s", input);

    // Remove vowels
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            input[i] = ' ';
        }
    }

    // Replace letters with symbols
    for(int j = 0; j < strlen(input); j++) {
        switch(input[j]) {
            case 'b':
                input[j] = '$';
                break;
            case 'c':
                input[j] = '(';
                break;
            case 'd':
                input[j] = '|)';
                break;
            case 'f':
                input[j] = '/';
                break;
            case 'g':
                input[j] = '9';
                break;
            case 'h':
                input[j] = '#';
                break;
            case 'j':
                input[j] = '.';
                break;
            case 'k':
                input[j] = '|<';
                break;
            case 'l':
                input[j] = '1';
                break;
            case 'm':
                input[j] = '|\\/|';
                break;
            case 'n':
                input[j] = '|\\|';
                break;
            case 'p':
                input[j] = '|o';
                break;
            case 'q':
                input[j] = '0,';
                break;
            case 'r':
                input[j] = '|2';
                break;
            case 's':
                input[j] = '$';
                break;
            case 't':
                input[j] = '7';
                break;
            case 'v':
                input[j] = '\\/';
                break;
            case 'w':
                input[j] = '\\/\\/';
                break;
            case 'x':
                input[j] = '%';
                break;
            case 'y':
                input[j] = '`/';
                break;
            case 'z':
                input[j] = '2';
                break;
            default:
                break;
        }
    }

    // Print the new word and ask if it's correct
    printf("\nYour word in surreal format is: %s\n", input);

    char answer[10];
    printf("Is this correct? (y/n)\n");
    scanf("%s", answer);

    // If the word is incorrect, suggest a correction
    if(strcmp(answer, "n") == 0 || strcmp(answer, "N") == 0) {
        printf("\nOkay, let's see if we can find a better match.\n");

        // Possible alternative spellings
        char possible_spellings[5][100] = {"n3v3r g0nn4 g1v3 y0u up", "4ll 7he b35t", "viva la 50ng", "3nc0re", "p5yh1c 3n3rgy"};

        printf("Here are some possible alternative spellings:\n");
        for(int k = 0; k < 5; k++) {
            printf("%d. %s\n", k+1, possible_spellings[k]);
        }

        // Ask the user for their choice
        int choice;
        printf("Which one do you think is correct? (1-5)\n");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 5) {
            printf("\nGreat choice! Your word has been corrected to: %s\n", possible_spellings[choice-1]);
        } else {
            printf("\nI'm sorry, I don't understand your selection. Please try again.\n");
        }
    } else {
        printf("\nThank you for using the surreal spell checker!\n");
    }

    return 0;
}