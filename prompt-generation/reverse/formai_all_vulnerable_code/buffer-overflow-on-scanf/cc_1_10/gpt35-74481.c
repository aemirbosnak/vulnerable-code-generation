//FormAI DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* binaryConverter(void* dec_num) {
    //Converting decimal to binary
    long long decimal = (long long) dec_num;
    int binary[64], index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }
    //Printing the binary number
    printf("The binary conversion of %lld is: ", (long long) dec_num);
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    int num_of_threads;
    printf("Enter the number of decimal numbers you would like to convert to binary: ");
    scanf("%d", &num_of_threads);

    pthread_t threads[num_of_threads];
    long long input_nums[num_of_threads];

    for (int i = 0; i < num_of_threads; i++) {
        printf("Enter decimal number %d: ", i + 1);
        scanf("%lld", &input_nums[i]);
    }

    //Creating threads to convert input decimal numbers to binary
    for (int i = 0; i < num_of_threads; i++) {
        int thread_creation_status = pthread_create(&threads[i], NULL, binaryConverter, (void*) input_nums[i]);
        if (thread_creation_status) {
            printf("Error in thread creation. Status code: %d\n", thread_creation_status);
            exit(-1);
        }
    }

    //Waiting for all threads to complete
    for (int i = 0; i < num_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Binary conversion completed for all input numbers!\n");
    return 0;
}