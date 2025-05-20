//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define CHUNK_SIZE 16

void* hashFunction(void* chunk);

typedef struct {
    char chunk[CHUNK_SIZE];
    int threadNum;
} ChunkThreadPair;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    char message[100];
    printf("Enter message to hash: ");
    scanf("%s", message);
    int messageLength = strlen(message);

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    ChunkThreadPair chunkThreadPairs[NUM_THREADS];

    int numChunks = messageLength / CHUNK_SIZE + 1;
    int currentChunk = 0;

    while (currentChunk < numChunks) {
        for (t = 0; t < NUM_THREADS && currentChunk < numChunks; t++, currentChunk++) {
            printf("Creating thread %ld\n", t);

            ChunkThreadPair pair;
            strncpy(pair.chunk, message + currentChunk * CHUNK_SIZE, CHUNK_SIZE);
            pair.threadNum = t;

            rc = pthread_create(&threads[t], NULL, hashFunction, (void*) &pair);

            if (rc) {
                printf("Error: return code from pthread_create() is %d\n", rc);
                exit(-1);
            }
        }

        for (t = 0; t < NUM_THREADS; t++) {
            rc = pthread_join(threads[t], NULL);

            if (rc) {
                printf("Error: return code from pthread_join() is %d\n", rc);
                exit(-1);
            }
        }
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

void* hashFunction(void* chunk) {
    ChunkThreadPair* pair = (ChunkThreadPair*) chunk;
    int threadNum = pair->threadNum;
    char* chunkStr = pair->chunk;
    int chunkLength = strlen(chunkStr);

    char* output;
    output = (char*) calloc(33, sizeof(char));

    int i;
    for(i = 0; i < chunkLength; i++){
        output[i] = (char) ((int) chunkStr[i] + threadNum);
    }

    pthread_mutex_lock(&mutex);
    printf("Thread %d hash output: %s\n", threadNum, output);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}