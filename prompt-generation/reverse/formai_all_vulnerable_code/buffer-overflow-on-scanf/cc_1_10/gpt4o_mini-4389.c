//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/sha.h>

#define HASH_SIZE 65

typedef struct {
    char *input;
    char output[HASH_SIZE];
} hash_data_t;

void *compute_hash(void *arg) {
    hash_data_t *data = (hash_data_t *)arg;
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256((unsigned char *)data->input, strlen(data->input), hash);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&(data->output[i * 2]), "%02x", hash[i]);
    }
    return NULL;
}

void menu() {
    printf("Welcome to the Asynchronous SHA-256 Hash Calculator!\n");
    printf("1. Compute hash\n");
    printf("2. Exit\n");
}

int main() {
    char input[256];
    int choice;

    while(1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else if (choice == 1) {
            printf("Enter a string to hash: ");
            scanf(" %[^\n]", input);  // Read until newline is encountered

            hash_data_t data;
            data.input = input;

            pthread_t hash_thread;
            pthread_create(&hash_thread, NULL, compute_hash, (void *)&data);
            pthread_join(hash_thread, NULL); // Wait for the thread to finish

            printf("SHA-256 hash: %s\n", data.output);
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}