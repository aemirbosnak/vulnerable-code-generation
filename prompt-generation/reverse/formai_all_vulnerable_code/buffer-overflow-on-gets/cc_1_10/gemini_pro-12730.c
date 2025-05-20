//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Morse code dictionary
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
    "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
    "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".----.", "-....-",
    "--...", "-.-.-.", "-..-.", "-.--.", "--..--", ".-.-.-", "..--..", "...-..-", "....-.", ".....-",
    "-....-", "--...-", "---...", "----..", "-----.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
    "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-",
    "...-", ".--", "-..-", "-.--", "--..", ".-"
};

// Thread function to convert a character to Morse code
void *to_morse(void *arg) {
    char *c = (char *)arg;

    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 32;  // Convert to uppercase
    }

    int index = *c - 'A';
    if (index < 0 || index >= 26) {
        fprintf(stderr, "Invalid character: %c\n", *c);
        pthread_exit(NULL);
    }

    printf("%s ", morse_code[index]);

    return NULL;
}

int main() {
    // Get the input text
    char text[1024];
    printf("Enter text to convert to Morse code: ");
    gets(text);

    // Create a thread for each character in the input text
    pthread_t threads[strlen(text)];
    for (int i = 0; i < strlen(text); i++) {
        pthread_create(&threads[i], NULL, to_morse, &text[i]);
    }

    // Join all the threads
    for (int i = 0; i < strlen(text); i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");
    return 0;
}