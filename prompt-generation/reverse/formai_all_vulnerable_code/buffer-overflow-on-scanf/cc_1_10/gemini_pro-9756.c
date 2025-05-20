//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the Alien language dictionary
const char *alien_dict[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

// Define the Earth language dictionary
const char *earth_dict[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

// Define the mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the thread function
void *translate(void *arg) {
    // Get the alien word from the argument
    char *alien_word = (char *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Translate the alien word to Earth language
    char earth_word[strlen(alien_word) + 1];
    for (int i = 0; i < strlen(alien_word); i++) {
        for (int j = 0; j < 26; j++) {
            if (alien_word[i] == alien_dict[j]) {
                earth_word[i] = earth_dict[j];
                break;
            }
        }
    }
    earth_word[strlen(alien_word)] = '\0';

    // Print the translated word
    printf("%s\n", earth_word);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Get the number of alien words to translate
    int n;
    printf("Enter the number of alien words to translate: ");
    scanf("%d", &n);

    // Get the alien words
    char alien_words[n][100];
    for (int i = 0; i < n; i++) {
        printf("Enter the alien word %d: ", i + 1);
        scanf("%s", alien_words[i]);
    }

    // Create the threads
    pthread_t threads[n];
    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, translate, alien_words[i]);
    }

    // Join the threads
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}