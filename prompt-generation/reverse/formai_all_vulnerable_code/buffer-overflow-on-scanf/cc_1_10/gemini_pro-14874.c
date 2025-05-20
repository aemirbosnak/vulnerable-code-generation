//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

// Morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
    "--..--", "-....-", "-.-.-", "---..."
};

// Mutex to protect shared resources
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal that the Morse code has been converted
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Boolean to indicate whether the Morse code has been converted
int converted = 0;

// Function to convert a character to Morse code
char *char_to_morse(char c) {
    // Lock the mutex to protect the shared resources
    pthread_mutex_lock(&mutex);

    // Check if the character is a letter
    if (isalpha(c)) {
        // Convert the character to uppercase
        c = toupper(c);

        // Get the Morse code for the character
        char *morse = morse_table[c - 'A'];

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Return the Morse code
        return morse;
    }
    // Check if the character is a number
    else if (isdigit(c)) {
        // Get the Morse code for the number
        char *morse = morse_table[c - '0' + 26];

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Return the Morse code
        return morse;
    }
    // Check if the character is a punctuation mark
    else if (ispunct(c)) {
        // Get the Morse code for the punctuation mark
        char *morse = morse_table[36 + strchr(".,?!:;()'", c) - strchr(".,?!:;()'", '.')];

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Return the Morse code
        return morse;
    }
    // Otherwise, return an empty string
    else {
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Return an empty string
        return "";
    }
}

// Function to convert a string to Morse code
char *string_to_morse(char *str) {
    // Allocate memory for the Morse code string
    char *morse = malloc(strlen(str) * 5);

    // Convert each character in the string to Morse code
    for (int i = 0; i < strlen(str); i++) {
        strcat(morse, char_to_morse(str[i]));
        strcat(morse, " ");
    }

    // Return the Morse code string
    return morse;
}

// Function to send the Morse code to the other player
void send_morse(char *morse) {
    // Lock the mutex to protect the shared resources
    pthread_mutex_lock(&mutex);

    // Send the Morse code to the other player
    printf("Sending Morse code: %s\n", morse);

    // Signal that the Morse code has been sent
    converted = 1;
    pthread_cond_signal(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to receive the Morse code from the other player
char *receive_morse() {
    // Lock the mutex to protect the shared resources
    pthread_mutex_lock(&mutex);

    // Wait for the other player to send the Morse code
    while (!converted) {
        pthread_cond_wait(&cond, &mutex);
    }

    // Get the Morse code from the other player
    char *morse = malloc(1024);
    scanf("%s", morse);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Return the Morse code
    return morse;
}

// Function to play the Morse code
void play_morse(char *morse) {
    // Convert the Morse code to a sound file
    system("espeak -w morse.wav -s 120 \"morse\"");

    // Play the sound file
    system("aplay morse.wav");
}

// Main function
int main() {
    // Get the text from the user
    char *text = malloc(1024);
    printf("Enter the text to convert to Morse code: ");
    scanf("%s", text);

    // Convert the text to Morse code
    char *morse = string_to_morse(text);

    // Send the Morse code to the other player
    send_morse(morse);

    // Receive the Morse code from the other player
    char *received_morse = receive_morse();

    // Play the Morse code
    play_morse(received_morse);

    // Free the allocated memory
    free(text);
    free(morse);
    free(received_morse);

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}