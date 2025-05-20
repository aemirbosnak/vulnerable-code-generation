//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include<stdio.h>

int main() {
    // Define the translation library 
    char cat_phrase[20][20] = {"meow", "purr", "hiss", "scratch", "play", "sleep", "eat", "drink", "jump", "climb", "stalk", "bath", "clean", "in", "out", "stop", "run", "walk", "hide", "pat"};
    char english_phrase[20][20] = {"hello", "happy", "angry", "uncomfortable", "fun", "rest", "hunger", "thirst", "leap", "ascend", "hunting", "cleanse", "bathe", "enter", "exit", "halt", "speed", "travel", "conceal", "care"};

    char in_phrase[100];
    int i = 0, j = 0, found = 0, len;

    // Get input phrase from the user
    printf("Enter a phrase in C Cat Language: ");
    scanf("%[^\n]s", in_phrase);

    // Calculate length of input phrase
    len = strlen(in_phrase);

    // Translate the input phrase to English
    for(i = 0; i < len; i++) {
        
        // Check if current character is an alphabet or space
        if(in_phrase[i] != ' ') {
            
            // Build the current_word
            english_phrase[j][found] = in_phrase[i];
            found++;
        } else {

            // End the current_word
            english_phrase[j][found] = '\0';

            // Set found counter to zero
            found = 0;

            // Try to find the current_word in the library
            for(int k = 0; k < 20; ++k) {
                if(strcmp(cat_phrase[k], english_phrase[j]) == 0) {
                    printf("%s ", english_phrase[j]);
                    break;
                }
            }

            // Increment the index of current_word
            j++;
        }
    }

    // End the final current_word
    english_phrase[j][found] = '\0';

    // Try to find the final current_word in the library
    for(int k = 0; k < 20; ++k) {
        if(strcmp(cat_phrase[k], english_phrase[j]) == 0) {
            printf("%s ", english_phrase[j]);
            break;
        }
    }

    return 0;
}