//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Define the cat language translator function
void* cat_translator(void* arg) {
    // Get the input string
    char* input = (char*)arg;

    // Translate the input string to cat language
    char* output = malloc(strlen(input) + 1);
    for (int i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'a':
                output[i] = 'm';
                break;
            case 'e':
                output[i] = 'o';
                break;
            case 'i':
                output[i] = 'u';
                break;
            case 'o':
                output[i] = 'e';
                break;
            case 'u':
                output[i] = 'i';
                break;
            default:
                output[i] = input[i];
                break;
        }
    }

    // Print the translated string
    printf("Cat translation: %s\n", output);

    // Free the allocated memory
    free(output);

    return NULL;
}

int main() {
    // Get the input string from the user
    char input[100];
    printf("Enter a string to translate to cat language: ");
    scanf("%s", input);

    // Create a thread to translate the input string
    pthread_t thread;
    pthread_create(&thread, NULL, cat_translator, input);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}