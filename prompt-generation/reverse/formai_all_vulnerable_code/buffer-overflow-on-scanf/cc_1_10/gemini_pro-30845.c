//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Shared data
struct shared_data {
    bool prime;
    unsigned long long number;
};

// Thread function
void *prime_checker(void *arg) {
    struct shared_data *data = (struct shared_data *)arg;

    for (unsigned long long i = 2; i < data->number / 2; i++) {
        if (data->number % i == 0) {
            data->prime = false;
            return NULL;
        }
    }

    data->prime = true;
    return NULL;
}

int main() {
    // Create a shared data structure
    struct shared_data data;
    data.prime = false;
    data.number = 0;

    // Create a thread
    pthread_t thread;
    pthread_create(&thread, NULL, prime_checker, &data);

    // Get user input
    while (true) {
        printf("Enter a number to check if it is prime (0 to exit): ");
        scanf("%llu", &data.number);

        if (data.number == 0) {
            break;
        }

        // Join the thread to wait for the result
        pthread_join(thread, NULL);

        // Print the result
        if (data.prime) {
            printf("%llu is a prime number.\n", data.number);
        } else {
            printf("%llu is not a prime number.\n", data.number);
        }
    }

    return 0;
}