//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

// Function to convert C Alien Language to English Language
void alienLanguageTranslator(char language[]) {
    int length = strlen(language);
    int i = 0;
    while(i < length) {
        if(language[i] == 'C') {
            if(language[i+1] == 'C')
                printf("Ka");
            else if(language[i+1] == 'D')
                printf("Ki");
            else if(language[i+1] == 'E')
                printf("Ku");
            else
                printf("C");
            i += 2;
        }
        else if(language[i] == 'D') {
            if(language[i+1] == 'C')
                printf("Li");
            else if(language[i+1] == 'D')
                printf("La");
            else if(language[i+1] == 'E')
                printf("Lu");
            else
                printf("D");
            i += 2;
        }
        else if(language[i] == 'E') {
            if(language[i+1] == 'C')
                printf("Pi");
            else if(language[i+1] == 'D')
                printf("Pa");
            else if(language[i+1] == 'E')
                printf("Pu");
            else
                printf("E");
            i += 2;
        }
        else {
            printf("%c", language[i]);
            i += 1;
        }
    }
}

int main() {
    char language[100];
    printf("Enter the text in C Alien Language: \n");
    gets(language);
    printf("The translation to English: ");
    alienLanguageTranslator(language);
    return 0;
}