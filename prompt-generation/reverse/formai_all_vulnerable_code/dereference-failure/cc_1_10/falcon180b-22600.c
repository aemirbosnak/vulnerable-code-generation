//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 10

typedef struct {
    int* numbers;
    int length;
} NumberArray;

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_random_array(NumberArray* array, int min, int max) {
    for (int i = 0; i < array->length; i++) {
        array->numbers[i] = generate_random_number(min, max);
    }
}

void print_array(NumberArray* array) {
    for (int i = 0; i < array->length; i++) {
        printf("%d ", array->numbers[i]);
    }
    printf("\n");
}

int main() {
    NumberArray public_key, private_key;

    public_key.length = generate_random_number(1, MAX_NUMBERS);
    public_key.numbers = (int*) malloc(public_key.length * sizeof(int));
    generate_random_array(&public_key, 1, 100);

    private_key.length = public_key.length;
    private_key.numbers = (int*) malloc(private_key.length * sizeof(int));
    for (int i = 0; i < private_key.length; i++) {
        private_key.numbers[i] = generate_random_number(1, 100);
    }

    int message = generate_random_number(1, 100);

    int encrypted_message = 0;

    for (int i = 0; i < public_key.length; i++) {
        encrypted_message += message * public_key.numbers[i];
        encrypted_message %= 100;
    }

    int decrypted_message = 0;

    for (int i = 0; i < private_key.length; i++) {
        decrypted_message += encrypted_message * private_key.numbers[i];
        decrypted_message %= 100;
    }

    printf("Public key: ");
    print_array(&public_key);
    printf("Private key: ");
    print_array(&private_key);
    printf("Message: %d\n", message);
    printf("Encrypted message: %d\n", encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);

    free(public_key.numbers);
    free(private_key.numbers);

    return 0;
}