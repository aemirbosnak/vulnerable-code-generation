//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to translate from English to Cat
void english_to_cat(char* input) {
    char* vowels = "aeiouAEIOU";
    char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char* output = malloc(strlen(input) + 1);
    int i, j;

    for (i = 0; input[i]!= '\0'; i++) {
        if (strchr(vowels, input[i])!= NULL) {
            output[i] = input[i];
        } else {
            j = rand() % strlen(consonants);
            output[i] = consonants[j];
        }
    }

    output[i] = '\0';
    printf("Cat translation: %s\n", output);
}

// Function to translate from Cat to English
void cat_to_english(char* input) {
    char* vowels = "aeiouAEIOU";
    char* consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char* output = malloc(strlen(input) + 1);
    int i, j;

    for (i = 0; input[i]!= '\0'; i++) {
        if (strchr(consonants, input[i])!= NULL) {
            output[i] = input[i];
        } else {
            j = rand() % strlen(vowels);
            output[i] = vowels[j];
        }
    }

    output[i] = '\0';
    printf("English translation: %s\n", output);
}

int main() {
    char* input;
    int choice;

    printf("Welcome to the Cat Language Translator!\n");
    printf("Please choose a translation direction:\n1. English to Cat\n2. Cat to English\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter an English sentence: ");
        scanf("%s", input);
        english_to_cat(input);
    } else if (choice == 2) {
        printf("Enter a Cat sentence: ");
        scanf("%s", input);
        cat_to_english(input);
    } else {
        printf("Invalid choice!\n");
    }

    free(input);
    return 0;
}