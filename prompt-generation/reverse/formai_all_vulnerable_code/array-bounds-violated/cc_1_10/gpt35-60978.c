//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Function to convert alien language to English
void alienToEnglish(char* phrase) {
    // Define alien alphabets and their corresponding English words
    char aliens[] = {'#', '*', '$', '&', '%'};
    char* english[] = {"hello", "world", "have", "you", "seen"};

    // Tokenize the alien phrase by spaces
    char* word = strtok(phrase, " ");
  
    while (word != NULL) {
        int index = -1;
        
        // Find the index of the corresponding word in English
        for (int i = 0; i < 5; i++) {
            if (word[0] == aliens[i]) {
                index = i;
                break;
            }
        }
        
        // Print the English word if the corresponding index is found
        if (index != -1) {
            printf("%s ", english[index]);
        }
        
        // Move to the next word
        word = strtok(NULL, " ");
    }
}

int main() {
    char phrase[100];

    // Take input from the user
    printf("Enter an alien language phrase (use #, *, $, &, %):\n");
    fgets(phrase, 100, stdin);
    
    // Remove the newline character from the input
    phrase[strlen(phrase) - 1] = '\0';
    
    // Convert alien language to English
    alienToEnglish(phrase);
    
    printf("\n");
    
    return 0;
}