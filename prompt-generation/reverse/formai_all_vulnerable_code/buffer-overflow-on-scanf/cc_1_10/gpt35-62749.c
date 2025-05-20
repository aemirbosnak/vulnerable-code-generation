//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_DIGITS 32

// Global variables
unsigned int decimalNumber = 0;
char binaryNumber[MAX_DIGITS];

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function for converting decimal to binary
void *decimalToBinary(void *arg)
{
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    int i = 0;

    // Calculate binary representation of decimal number
    while (decimalNumber > 0)
    {
        binaryNumber[i] = decimalNumber % 2 + '0';
        decimalNumber /= 2;
        i++;
    }

    // Reverse binary number string
    int length = i;
    for (int j = 0; j < length / 2; j++)
    {
        char temp = binaryNumber[j];
        binaryNumber[j] = binaryNumber[length - j - 1];
        binaryNumber[length - j - 1] = temp;
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

int main()
{
    // Initialize pthread variables
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Input decimal number
    printf("Enter decimal number: ");
    scanf("%u", &decimalNumber);

    // Create thread for decimal to binary conversion
    pthread_create(&tid, &attr, decimalToBinary, NULL);

    // Wait for thread to complete
    pthread_join(tid, NULL);

    // Output binary number
    printf("Binary number: %s\n", binaryNumber);

    // Clean up pthread variables
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex);

    return 0;
}