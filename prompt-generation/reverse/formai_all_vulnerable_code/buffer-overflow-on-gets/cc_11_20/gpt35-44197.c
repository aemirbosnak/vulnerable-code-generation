//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

int main()
{
    char c[100], cat[100];
    int i, j, k;

    /* Prompt user to enter a sentence in English */
    printf("Enter a sentence in English: ");
    gets(c);

    /* Convert the sentence to C Cat language */
    j = 0;
    for (i = 0; i < strlen(c); i++) {

        /* If the character is a space, just add it to the C Cat sentence */
        if (c[i] == ' ') {
            cat[j++] = ' ';
        }

        /* If the character is a vowel, add "meow" after it */
        else if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' 
            || c[i] == 'o' || c[i] == 'u' || c[i] == 'A' 
            || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' 
            || c[i] == 'U') {
            cat[j++] = c[i];
            cat[j++] = 'm';
            cat[j++] = 'e';
            cat[j++] = 'o';
            cat[j++] = 'w';
        }

        /* If the character is a consonant, add "meow" before it */
        else if ((c[i] >= 'a' && c[i] <= 'z') 
                || (c[i] >= 'A' && c[i] <= 'Z')) {
            cat[j++] = 'm';
            cat[j++] = 'e';
            cat[j++] = 'o';
            cat[j++] = 'w';
            cat[j++] = c[i];
        }
    }

    /* Add a period at the end of the C Cat sentence */
    cat[j++] = '.';

    /* Print out the C Cat sentence */
    printf("Your sentence in C Cat language is: ");
    for (k = 0; k < j; k++) {
        printf("%c", cat[k]);
    }

    return 0;
}