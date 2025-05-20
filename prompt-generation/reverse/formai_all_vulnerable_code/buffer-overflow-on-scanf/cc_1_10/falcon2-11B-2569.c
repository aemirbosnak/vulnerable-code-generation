//Falcon2-11B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

void asynchronous_bitwise_operations(int argc, char *argv[]) {
    int num1, num2, result;
    int bit_value;

    srand(time(NULL));
    int rand_num = rand() % 100;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    if (argc == 3 && strcmp(argv[1], "-b") == 0) {
        bit_value = atoi(argv[2]);
        printf("Enter the bit value: ");
        scanf("%d", &bit_value);

        result = num1 & bit_value;
        printf("AND operation: %d\n", result);

        result = num1 | bit_value;
        printf("OR operation: %d\n", result);

        result = num1 ^ bit_value;
        printf("XOR operation: %d\n", result);
    } else {
        result = num1 & num2;
        printf("AND operation: %d\n", result);

        result = num1 | num2;
        printf("OR operation: %d\n", result);

        result = num1 ^ num2;
        printf("XOR operation: %d\n", result);
    }
}

int main(int argc, char *argv[]) {
    int status;
    pid_t pid;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) == 0) {
        asynchronous_bitwise_operations(argc, argv);
        exit(EXIT_SUCCESS);
    }

    if (wait(&status)!= pid) {
        printf("Error waiting for child process\n");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}