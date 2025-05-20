//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Declare our alien language dictionary
char *alienDict[] = {
    "akuk",
    "bim",
    "cramfall",
    "dall",
    "ekit",
    "fin",
    "gol",
    "hup",
    "itix",
    "jum",
    "klix",
    "lokon",
    "mik",
    "nem",
    "opix",
    "pil",
    "quon",
    "rovix",
    "sik",
    "tuk",
    "ulvix",
    "ver",
    "wop",
    "xix",
    "yin",
    "zal"
};

// Declare our function to translate the alien language to English
void translateAlien(char *alien) {
    // Loop through each letter in the alien word
    for (int i = 0; i < strlen(alien); i++) {
        // Convert the letter to its corresponding number
        int letterNum = alien[i] - 'a';
        // Print the English word associated with that number in our alien dictionary
        printf("%s ", alienDict[letterNum]);
    }
    printf("\n");
}

int main() {
    // Prompt the user for an alien word to translate
    printf("Enter an alien word to translate to English: ");
    // Declare a char array to store the user's input
    char alienInput[100];
    // Scan the user's input
    scanf("%s", alienInput);
    // Call our translate function with the user's input
    translateAlien(alienInput);
    // Return 0 to end the program
    return 0;
}