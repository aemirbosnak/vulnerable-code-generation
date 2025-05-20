//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

/* Function to convert string to lowercase */
void toLowerCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

/* Function to convert string to uppercase */
void toUpperCase(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    int choice;

    printf("Welcome to the Cat Language Translator!\n");
    printf("Please enter the text you want to translate: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Please choose the translation you want to perform:\n");
    printf("1. Meow to Human\n");
    printf("2. Human to Meow\n");
    scanf("%d", &choice);

    if (choice == 1) {
        /* Translate from Meow to Human */
        toLowerCase(input);
        strcpy(output, input);
        toUpperCase(output);
        printf("Translation Result: %s\n", output);
    } else if (choice == 2) {
        /* Translate from Human to Meow */
        toUpperCase(input);
        strcpy(output, input);
        toLowerCase(output);
        printf("Translation Result: %s\n", output);
    } else {
        printf("Invalid choice!");
    }

    return 0;
}