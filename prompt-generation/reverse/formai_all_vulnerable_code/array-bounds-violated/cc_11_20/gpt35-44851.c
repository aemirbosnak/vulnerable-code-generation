//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Welcome to the C Cat Language Translator!\n");
    while (1) {
        printf("\nEnter a sentence in C Cat Language: ");
        fgets(input, sizeof(input), stdin);
        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        
        // Check for common C Cat phrases
        if (strcmp(input, "meow") == 0) {
            printf("Translation: Hello\n");
        }
        else if (strcmp(input, "purr") == 0) {
            printf("Translation: Thank you\n");
        }
        else if (strcmp(input, "hiss") == 0) {
            printf("Translation: No\n");
        }
        else if (strcmp(input, "scratch") == 0) {
            printf("Translation: I'm bored\n");
        }
        else if (strcmp(input, "lick") == 0) {
            printf("Translation: Yum\n");
        }
        else if (strcmp(input, "sleep") == 0) {
            printf("Translation: Goodnight\n");
        }
       
        // Check for unique C Cat phrases
        else if (strstr(input, "meow meow") != NULL) {
            printf("Translation: Hello, how are you?\n");
        }
        else if (strstr(input, "scratch scratch") != NULL) {
            printf("Translation: Can we play?\n");
        }
        else if (strstr(input, "sleep sleep") != NULL) {
            printf("Translation: I'm so tired\n");
        }
       
        // If input is not recognized
        else {
            printf("Translation: I'm sorry, I don't understand.\n");
        }
    }
    return 0;
}