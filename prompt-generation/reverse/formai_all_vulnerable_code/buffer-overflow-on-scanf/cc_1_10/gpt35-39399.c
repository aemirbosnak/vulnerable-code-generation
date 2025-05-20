//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include<stdio.h>
#include<string.h>

// Function to convert English to C Cat language
void to_C_Cat_language(char english[]) {

    char c_cat_language[strlen(english)];   // To store the C Cat language equivalent of the given English phrase
    int i;
    int len = strlen(english);

    for(i = 0; i < len; i++) {
        switch (english[i]) {
            case 'c':   // To convert 'c' to 'meow'
            case 'C':
                strcat(c_cat_language, "meow");
                break;

            case 't':   // To convert 't' to 'purr'
            case 'T':
                strcat(c_cat_language, "purr");
                break;

            case 'a':   // To convert 'a' to 'nom'
            case 'A':
                strcat(c_cat_language, "nom");
                break;

            case 'r':   // To convert 'r' to 'hisss'
            case 'R':
                strcat(c_cat_language, "hisss");
                break;

            case 'e':   // To convert 'e' to 'bite'
            case 'E':
                strcat(c_cat_language, "bite");
                break;

            case 'u':   // To convert 'u' to 'scratch'
            case 'U':
                strcat(c_cat_language, "scratch");
                break;

            case 'i':   // To convert 'i' to 'lick'
            case 'I':
                strcat(c_cat_language, "lick");
                break;

            case 's':   // To convert 's' to 'pounce'
            case 'S':
                strcat(c_cat_language, "pounce");
                break;

            default:    // For other characters, they remain the same
                strncat(c_cat_language, &english[i], 1);  
                break;
        }
    }

    printf("Equivalent C Cat Language: %s\n", c_cat_language);
}

int main() {

    char english[100];    // To store the given English phrase
    
    printf("Enter an English phrase to convert to C Cat Language: ");
    scanf("%[^\n]", english);
    
    printf("The given English phrase: %s\n", english);
    to_C_Cat_language(english);

    return 0;
}