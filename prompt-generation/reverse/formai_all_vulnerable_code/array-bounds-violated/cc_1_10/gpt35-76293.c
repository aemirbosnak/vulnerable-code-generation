//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Function to check if the given word is valid in the alien language
int is_valid_word(char word[]) {
    int i, n = strlen(word);
    for(i=0; i<n; i++) {
        if(word[i] < 'a' || word[i] > 'z')
            return 0; // invalid character found, hence not a valid word
    }
    return 1; // valid word
}

// Function to translate a sentence from alien language to English language
void translate(char sentence[]) {
    int i, n = strlen(sentence), j=0;
    char word[n];

    for(i=0; i<=n; i++) {
        if(sentence[i] == ' ' || sentence[i] == '\0') {
            word[j] = '\0';
            j = 0;
            if(is_valid_word(word)) {
                if(strcmp(word, "gaj") == 0)
                    printf("Hello ");
                else if(strcmp(word, "gorf") == 0)
                    printf("World ");
                else if(strcmp(word, "klerp") == 0)
                    printf("How ");
                else if(strcmp(word, "qaz") == 0)
                    printf("Are ");
                else if(strcmp(word, "zax") == 0)
                    printf("You ");
                else
                    printf("%s ", word);
            }
            else {
                printf("%s ", word);
            }
        }
        else {
            word[j] = sentence[i];
            j++;
        }
    }
}

int main() {
    char sentence[1000];

    printf("Enter a sentence in alien language: ");
    fgets(sentence, 1000, stdin);

    printf("Translated sentence: ");
    translate(sentence);

    return 0;
}