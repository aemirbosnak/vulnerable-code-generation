//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ada Lovelace
// This C Cat Language Translator was written by Ada Lovelace
// It will translate your input text from English into C Cat language
// C Cat language mimics the meows and behaviors of cats

#include <stdio.h>
#include <string.h>

int main() {
    char english[1000], ccat[1000];    // Variables to store input and output text
    int i, j, english_length;
    
    // Get input from user
    printf("Enter your message in English:\n");
    gets(english);
    
    // Find length of input text
    english_length = strlen(english);
    
    // Translate each word of the input text
    for(i=0, j=0; i<english_length; i++) {
        // If letter is 's', translate to hissing sound
        if(english[i] == 's' || english[i] == 'S') {
            ccat[j] = 'h';
            ccat[j+1] = 'i';
            ccat[j+2] = 's';
            ccat[j+3] = 's';
            ccat[j+4] = '!';
            j = j+5;
        }
        // If letter is 'r', translate to extra purring
        else if(english[i] == 'r' || english[i] == 'R') {
            ccat[j] = 'p';
            ccat[j+1] = 'u';
            ccat[j+2] = 'r';
            ccat[j+3] = 'r';
            ccat[j+4] = 'r';
            j = j+5;
        }
        // If letter is 'y', translate to meowing
        else if(english[i] == 'y' || english[i] == 'Y') {
            ccat[j] = 'm';
            ccat[j+1] = 'e';
            ccat[j+2] = 'o';
            ccat[j+3] = 'w';
            ccat[j+4] = '!';
            j = j+5;
        }
        // If letter is space, add extra purring
        else if(english[i] == ' ') {
            ccat[j] = 'p';
            ccat[j+1] = 'u';
            ccat[j+2] = 'r';
            ccat[j+3] = 'r';
            ccat[j+4] = 'r';
            ccat[j+5] = ' ';
            j = j+6;
        }
        // If letter is not a cat sound, keep it in original form
        else{
            ccat[j] = english[i];
            j++;
        }
    }
    
    // Print output in C Cat language
    printf("Your message in C Cat language:\n%s", ccat);
    
    return 0;
}