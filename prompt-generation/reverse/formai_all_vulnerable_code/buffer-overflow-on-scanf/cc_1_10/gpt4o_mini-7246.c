//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_MSG_LEN 1024
#define NUM_THREADS 4

typedef struct {
    char *message;
    char *encrypted_message;
    int shift;
} encryption_data;

sem_t sem;

void *encrypt_message(void *data) {
    encryption_data *enc_data = (encryption_data *)data;
    
    // Wait for the semaphore to ensure no race conditions
    sem_wait(&sem);
    
    int length = strlen(enc_data->message);
    enc_data->encrypted_message = (char *)malloc(length + 1);

    for (int i = 0; i < length; i++) {
        // Encrypting using Caesar Cipher
        if (enc_data->message[i] >= 'a' && enc_data->message[i] <= 'z') {
            enc_data->encrypted_message[i] = (enc_data->message[i] - 'a' + enc_data->shift) % 26 + 'a';
        } else if (enc_data->message[i] >= 'A' && enc_data->message[i] <= 'Z') {
            enc_data->encrypted_message[i] = (enc_data->message[i] - 'A' + enc_data->shift) % 26 + 'A';
        } else {
            enc_data->encrypted_message[i] = enc_data->message[i];  // Leave non-alphabetic characters unchanged
        }
    }
    enc_data->encrypted_message[length] = '\0';  // Null-terminating the string
    
    // Signal that the encryption is done
    sem_post(&sem);
    
    return NULL;
}

int main() {
    char message[MAX_MSG_LEN];
    int shift;
    pthread_t threads[NUM_THREADS];
    encryption_data enc_data[NUM_THREADS];
    
    printf("Enter a message (max %d characters): ", MAX_MSG_LEN);
    fgets(message, sizeof(message), stdin);
    // Remove newline character from the message
    message[strcspn(message, "\n")] = 0;
    
    printf("Enter shift value for encryption: ");
    scanf("%d", &shift);
    
    // Initialize the semaphore
    sem_init(&sem, 0, 1);
    
    // Split the message into chunks for processing
    int length_per_thread = strlen(message) / NUM_THREADS;
    
    for (int i = 0; i < NUM_THREADS; i++) {
        enc_data[i].message = &message[i * length_per_thread];
        enc_data[i].shift = shift;

        // If it's the last thread, take the remaining parts of the message
        if (i == NUM_THREADS - 1) {
            enc_data[i].message = message + (i * length_per_thread); 
        }
        
        pthread_create(&threads[i], NULL, encrypt_message, (void *)&enc_data[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine encrypted messages
    char encrypted_message[MAX_MSG_LEN];
    strcpy(encrypted_message, "");

    for (int i = 0; i < NUM_THREADS; i++) {
        strcat(encrypted_message, enc_data[i].encrypted_message);
        free(enc_data[i].encrypted_message);  // Free allocated memory
    }

    printf("Encrypted message: %s\n", encrypted_message);
    
    // Destroy the semaphore
    sem_destroy(&sem);
    
    return 0;
}