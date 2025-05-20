//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 256

// Structure to hold the data for each thread
typedef struct {
    char plaintext[BUFFER_SIZE];
    int shift;
} ThreadData;

// Function to perform Caesar cipher encryption
void* encrypt(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    char* encrypted = (char*)malloc(BUFFER_SIZE);
    int shift = data->shift;
    
    for (int i = 0; data->plaintext[i] != '\0'; i++) {
        char ch = data->plaintext[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            encrypted[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            encrypted[i] = (ch - 'a' + shift) % 26 + 'a';
        } else {
            encrypted[i] = ch; // Non-alphabetic characters are unchanged
        }
    }
    encrypted[strlen(data->plaintext)] = '\0'; // Null terminate the string

    printf("Encrypted Message: %s\n", encrypted);
    free(encrypted);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int i, thread_count = 0;

    printf("Asynchronous Encryption Program using Threads\n");
    printf("Enter messages to encrypt (type 'exit' to quit):\n");

    while (1) {
        printf("Plaintext: ");
        fgets(thread_data[thread_count].plaintext, BUFFER_SIZE, stdin);
        
        // Remove newline character
        thread_data[thread_count].plaintext[strcspn(thread_data[thread_count].plaintext, "\n")] = 0;

        // Check for exit condition
        if (strcmp(thread_data[thread_count].plaintext, "exit") == 0) {
            break;
        }

        // Get encryption shift value from the user
        printf("Enter shift value: ");
        scanf("%d", &thread_data[thread_count].shift);
        getchar(); // Consume the newline character left by scanf

        // Create a new thread for encryption
        if (pthread_create(&threads[thread_count], NULL, encrypt, &thread_data[thread_count]) != 0) {
            fprintf(stderr, "Error: Unable to create thread\n");
            exit(1);
        }

        thread_count++;
        
        // Wait for all threads to finish if we reach max threads
        if (thread_count >= MAX_THREADS) {
            for (i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset for new batch of messages
        }
    }

    // Join remaining threads
    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encryption process completed. Exiting...\n");
    return 0;
}