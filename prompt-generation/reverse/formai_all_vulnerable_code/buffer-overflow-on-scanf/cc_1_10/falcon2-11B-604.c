//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void spellCheck(char* sentence, int length) {
    if (length == 0)
        return;
    
    if (isalpha(sentence[length - 1])) {
        char* word = sentence + length - 1;
        int i = 0;
        int j = length - 1;
        
        while (i < j) {
            while (i < j &&!isalpha(sentence[i]))
                i++;
            while (i < j &&!isalpha(sentence[j]))
                j--;
            if (tolower(sentence[i])!= tolower(sentence[j])) {
                if (isalpha(sentence[i]) && isalpha(sentence[j])) {
                    word[i] = '.';
                    word[j] = '.';
                } else {
                    word[i] = '.';
                }
                spellCheck(sentence, i + 1);
                spellCheck(sentence, j - 1);
                return;
            }
            i++;
            j--;
        }
        word[length - 1] = '.';
        spellCheck(sentence, 0);
    }
}

int main() {
    char sentence[100];
    int length;
    
    printf("Enter a sentence: ");
    scanf("%s", sentence);
    length = strlen(sentence);
    
    spellCheck(sentence, length);
    
    printf("Spelling checked sentence: %s\n", sentence);
    
    return 0;
}