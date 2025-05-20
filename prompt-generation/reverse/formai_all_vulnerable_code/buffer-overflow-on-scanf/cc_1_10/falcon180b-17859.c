//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CODE_LEN 1000

// Morse code table
char *morse_code[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

void *morse_thread(void *arg) {
    char *code = arg;
    int len = strlen(code);
    for (int i = 0; i < len; i++) {
        printf("%c", morse_code[code[i] - 'A']);
        usleep(100000);
    }
    printf("\n");
    return NULL;
}

int main() {
    char input[MAX_CODE_LEN];
    printf("Enter Morse code: ");
    scanf("%s", input);

    // Start threads
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached.\n");
            break;
        }
        pthread_create(&threads[num_threads], NULL, morse_thread, &input[i]);
        num_threads++;
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}