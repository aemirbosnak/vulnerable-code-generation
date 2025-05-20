//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_CHARS_PER_THREAD 10
#define DELAY_IN_MS 1000

typedef struct {
    char morse_code[MAX_CHARS_PER_THREAD];
    int length;
} MorseCodeThreadData;

void *morseCodeThread(void *threadData) {
    MorseCodeThreadData *data = (MorseCodeThreadData *) threadData;
    int i;

    for (i = 0; i < data->length; i++) {
        printf("%c", data->morse_code[i]);
        usleep(DELAY_IN_MS * 1000);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    char *text = argv[1];
    int length = strlen(text);
    int numThreads = length / MAX_CHARS_PER_THREAD;
    if (length % MAX_CHARS_PER_THREAD!= 0) {
        numThreads++;
    }

    pthread_t threads[MAX_THREADS];
    MorseCodeThreadData threadData[MAX_THREADS];

    int i;
    for (i = 0; i < numThreads; i++) {
        int startIndex = i * MAX_CHARS_PER_THREAD;
        int endIndex = startIndex + MAX_CHARS_PER_THREAD;
        if (i == numThreads - 1) {
            endIndex = length;
        }

        strncpy(threadData[i].morse_code, text + startIndex, MAX_CHARS_PER_THREAD);
        threadData[i].length = endIndex - startIndex;

        pthread_create(&threads[i], NULL, morseCodeThread, &threadData[i]);
    }

    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}