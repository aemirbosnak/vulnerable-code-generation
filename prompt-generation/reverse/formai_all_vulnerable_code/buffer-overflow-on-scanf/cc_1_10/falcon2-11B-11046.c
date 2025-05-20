//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define a structure to store the alien language
struct AlienLanguage {
    char language[100];
    char translation[100];
};

int main() {
    // Define an array to store the alien language
    struct AlienLanguage languages[10];

    // Initialize the alien language array with some words
    strcpy(languages[0].language, "Gracious");
    strcpy(languages[1].language, "Polite");
    strcpy(languages[2].language, "Respectful");
    strcpy(languages[3].language, "Considerate");
    strcpy(languages[4].language, "Courteous");
    strcpy(languages[5].language, "Compassionate");
    strcpy(languages[6].language, "Sympathetic");
    strcpy(languages[7].language, "Generous");
    strcpy(languages[8].language, "Caring");
    strcpy(languages[9].language, "Benevolent");

    // Print the alien language translations
    printf("Alien Language Translator\n\n");
    printf("Enter the word to be translated: ");
    scanf("%s", languages[0].translation);
    printf("Translation: %s\n\n", languages[0].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[1].translation);
    printf("Translation: %s\n\n", languages[1].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[2].translation);
    printf("Translation: %s\n\n", languages[2].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[3].translation);
    printf("Translation: %s\n\n", languages[3].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[4].translation);
    printf("Translation: %s\n\n", languages[4].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[5].translation);
    printf("Translation: %s\n\n", languages[5].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[6].translation);
    printf("Translation: %s\n\n", languages[6].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[7].translation);
    printf("Translation: %s\n\n", languages[7].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[8].translation);
    printf("Translation: %s\n\n", languages[8].translation);
    printf("Enter the word to be translated: ");
    scanf("%s", languages[9].translation);
    printf("Translation: %s\n\n", languages[9].translation);

    return 0;
}