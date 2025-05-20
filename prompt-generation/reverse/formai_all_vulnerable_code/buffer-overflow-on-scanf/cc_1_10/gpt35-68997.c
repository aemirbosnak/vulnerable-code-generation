//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h> // for multi-threading
#include <unistd.h> // for sleep() function
 
#define MASK 255 // bitmask of 11111111
 
unsigned char num1, num2, bitwise_result; // global variables to hold the numbers and the result of bitwise operation
 
// function to perform bitwise operation (AND) on two numbers
void *perform_bitwise_operation(void *arg) {
    int *thread_no = (int*)arg; // thread number as argument
    printf("Thread %d performing bitwise operation ...\n", *thread_no);
    bitwise_result = num1 & num2; // perform bitwise AND operation
    printf("Bitwise AND result: %d\n", bitwise_result);
    return NULL;
}
 
// main function
int main() {
    printf("Enter two numbers between 0 and 255: ");
    scanf("%hhu %hhu", &num1, &num2);
 
    pthread_t tid; // thread identifier
    int thread_no = 1; // thread number
 
    // create a new thread to perform bitwise operation
    if(pthread_create(&tid, NULL, perform_bitwise_operation, &thread_no)) {
        fprintf(stderr, "Error creating thread.\n");
        return 1;
    }
 
    // wait for the thread to complete
    pthread_join(tid, NULL); // NULL argument for thread return value as it is not used
 
    // print the binary representation of the two numbers
    printf("Binary representation of %d: ", num1);
    for(int i=7; i>=0; i--) {
        if(num1 & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    printf("Binary representation of %d: ", num2);
    for(int i=7; i>=0; i--) {
        if(num2 & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
 
    // print the binary representation of the bitwise AND result
    printf("Binary representation of bitwise AND result: ");
    for(int i=7; i>=0; i--) {
        if(bitwise_result & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
 
    return 0;
}