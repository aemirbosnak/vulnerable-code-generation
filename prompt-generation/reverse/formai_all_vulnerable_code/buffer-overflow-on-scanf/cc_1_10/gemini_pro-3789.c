//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define the Morse code mapping
const char *morse_code[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-.."  // L
};

// Define the thread function
void *convert_to_morse(void *arg) {
    // Get the input string
    char *input = (char *)arg;

    // Convert the input string to Morse code
    char morse_code[strlen(input) * 4 + 1];
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            c -= 'A';
        } else if (c >= 'a' && c <= 'z') {
            c -= 'a';
        }
        strcat(morse_code, morse_code[c]);
        strcat(morse_code, " ");
    }

    // Print the Morse code
    printf("%s\n", morse_code);

    return NULL;
}

int main() {
    // Get the input string
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    scanf("%s", input);

    // Create a thread to convert the string to Morse code
    pthread_t thread;
    pthread_create(&thread, NULL, convert_to_morse, input);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}