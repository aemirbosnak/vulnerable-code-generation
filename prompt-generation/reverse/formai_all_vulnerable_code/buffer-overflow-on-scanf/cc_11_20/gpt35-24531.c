//FormAI DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Welcome to the immersive spell checking program!

int main() {
    char word[100];
    int flag; // 0 if word is spelled correctly, 1 if not
    const char *dict[100] = {"apple", "banana", "cherry", "pineapple", "orange", "grapefruit", "watermelon", "pear", "grape", "strawberry"}; 

    printf("Welcome to the spell checking program!\n");
    printf("Enter a word to check, or 'exit' to quit.\n");

    while(1) {
        printf("> ");
        scanf("%s", word);
        if(strcmp(word, "exit") == 0) {  
            printf("Bye!");
            break;
        }
        flag = 1;
        // Check if word is in dictionary
        for(int i = 0; i < 10; i++) {  
            if(strcmp(word, dict[i]) == 0) {
                printf("Your word is spelled correctly!\n");
                flag = 0;
                break;
            }
        }
        // If word is not in dictionary, suggest similar words
        if(flag == 1) {  
            printf("Uh oh, it looks like your word is spelled incorrectly.\n");
            printf("Here are some similar words that might work:\n");
            // Look for words that differ by only one character
            for(int j = 0; j < 10; j++) {  
                int differences = 0;
                if(strlen(word) == strlen(dict[j])) {
                    for(int k = 0; k < strlen(word); k++) {
                        if(word[k] != dict[j][k]) {
                            differences++;
                        }
                    }
                    if(differences == 1) {
                        printf("%s\n", dict[j]);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}