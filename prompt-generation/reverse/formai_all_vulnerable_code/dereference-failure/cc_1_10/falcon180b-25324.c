//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define HASH_LENGTH 64 // 64 bytes hash length

// Struct to store hash data
typedef struct {
    char hash[HASH_LENGTH];
    int index;
} HashData;

// Function to generate hash
void* generate_hash(void* arg) {
    char* input = (char*) arg;
    int len = strlen(input);
    HashData data;

    // Initialize seed with current time
    unsigned int seed = time(NULL);

    // Initialize hash with input string and seed
    sprintf(data.hash, "%08x%s", seed, input);

    // Calculate hash using MD5 algorithm
    unsigned char digest[16];
    MD5((unsigned char*) data.hash, strlen(data.hash), digest);

    // Convert digest to hexadecimal format
    for (int i = 0; i < 16; i++) {
        sprintf(&data.hash[i * 2], "%02x", digest[i]);
    }

    // Add index to hash
    sprintf(&data.hash[32], "%04x", data.index);

    // Return hash data
    return (void*) &data;
}

int main() {
    char input[100];
    HashData** hashes = (HashData**) malloc(10 * sizeof(HashData*)); // Allocate memory for 10 hashes
    int num_threads = 4; // Number of threads to use
    pthread_t threads[num_threads]; // Array to store thread IDs

    // Initialize hash indexes
    for (int i = 0; i < 10; i++) {
        hashes[i] = NULL;
    }

    // Start threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, generate_hash, (void*) &input);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], (void**) &hashes[i]);
    }

    // Print hashes
    for (int i = 0; i < 10; i++) {
        if (hashes[i]!= NULL) {
            printf("Hash %d: %s\n", i, hashes[i]->hash);
        }
    }

    // Free memory
    for (int i = 0; i < 10; i++) {
        if (hashes[i]!= NULL) {
            free(hashes[i]);
        }
    }
    free(hashes);

    return 0;
}