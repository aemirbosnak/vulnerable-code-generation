//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int num = 0; // The number to be manipulated by bitwise operations
int result_and, result_or, result_xor, result_compl; // The results of the bitwise operations

void *and_operation(void *arg) {
    result_and = num & *(int*)arg;
    pthread_exit(NULL);
}

void *or_operation(void *arg) {
    result_or = num | *(int*)arg;
    pthread_exit(NULL);
}

void *xor_operation(void *arg) {
    result_xor = num ^ *(int*)arg;
    pthread_exit(NULL);
}

void *compl_operation(void *arg) {
    result_compl = ~num;
    pthread_exit(NULL);
}

int main() {
    int operand;
    printf("Enter the number for bitwise operations: ");
    scanf("%d", &num);
    printf("Enter the operand for bitwise AND operation: ");
    scanf("%d", &operand);

    pthread_t threads[4];

    pthread_create(&threads[0], NULL, and_operation, (void *)&operand);
    pthread_create(&threads[1], NULL, or_operation, (void *)&operand);
    pthread_create(&threads[2], NULL, xor_operation, (void *)&operand);
    pthread_create(&threads[3], NULL, compl_operation, NULL);

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The result of bitwise AND operation with %d: %d\n", operand, result_and);
    printf("The result of bitwise OR operation with %d: %d\n", operand, result_or);
    printf("The result of bitwise XOR operation with %d: %d\n", operand, result_xor);
    printf("The result of bitwise complement operation: %d\n", result_compl);

    return 0;
}