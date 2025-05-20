//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100], c;
    int i, choice;

    printf("Welcome to the Alien Language Translator!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Translate from Alien to English\n");
        printf("2. Translate from English to Alien\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter the text you would like to translate from Alien to English:\n");
            scanf(" %[^\n]", input); // read entire line

            printf("\nTranslating...\n");

            for (i = 0; i < strlen(input); i++) {
                c = input[i];
                if (c == 'X') {
                    output[i] = 'A';
                } else if (c == 'Y') {
                    output[i] = 'B';
                } else if (c == 'Z') {
                    output[i] = 'C';
                } else if (c >= 'A' && c < 'X') {
                    output[i] = c + 3;
                } else if (c >= 'a' && c < 'x') {
                    output[i] = c + 3;
                } else {
                    output[i] = c; // if not X, Y, Z or A-Z/a-z letters then copy the symbol as is
                }
            }
            output[i] = '\0'; // terminate the output string

            printf("\nTranslation complete! The English text is:\n%s\n", output);
        } else if (choice == 2) {
            printf("\nEnter the text you would like to translate from English to Alien:\n");
            scanf(" %[^\n]", input); // read entire line

            printf("\nTranslating...\n");

            for (i = 0; i < strlen(input); i++) {
                c = input[i];
                if (c == 'A') {
                    output[i] = 'X';
                } else if (c == 'B') {
                    output[i] = 'Y';
                } else if (c == 'C') {
                    output[i] = 'Z';
                } else if (c >= 'a' && c <= 'z') {
                    output[i] = c - 3;
                } else if (c >= 'A' && c <= 'Z') {
                    output[i] = c - 3;
                } else {
                    output[i] = c; // if not A-Z/a-z letters then copy the symbol as is
                }
            }
            output[i] = '\0'; // terminate the output string

            printf("\nTranslation complete! The Alien text is:\n%s\n", output);
        } else if (choice == 3) {
            printf("\nThank you for using the Alien Language Translator!\n");
        } else {
            printf("\nInvalid choice! Please enter 1, 2 or 3.\n");
        }
    } while (choice != 3);

    return 0;
}