//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// We'll be working with a mysterious array of integers.
int32_t *array;
uint32_t array_size;

// Our puzzling enigma: the enigmalic_function.
int32_t enigmalic_function(int32_t n) {
    // A secret twist: we'll use bitwise operations to conceal our intentions.
    int32_t a = n & 0x0000FFFF;   // Extract lower 16 bits
    int32_t b = (n >> 16) & 0x0000FFFF;  // Extract higher 16 bits
    return (a ^ b) + (a & b);   // Apply bitwise XOR and AND
}

// The main event: where the enigma unfolds.
int main(void) {
    printf("Welcome to the Enigma Cipher.\n");
    printf("Enter the size of your puzzling array (less than 100): ");
    scanf("%u", &array_size);

    // Allocate memory for our enigmatic array.
    array = malloc(sizeof(int32_t) * array_size);

    // Now, the enchanting part: let's fill our array with enigmatic values.
    for (uint32_t i = 0; i < array_size; i++) {
        printf("Enter the %uth value for the array: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Prepare to witness the enigmatic transformation.
    printf("\nBehold, the Enigma Cipher at work:\n");

    // With each step, the enigma unfolds.
    for (uint32_t i = 0; i < array_size; i++) {
        printf("Original Value: %d\t", array[i]);
        array[i] = enigmalic_function(array[i]);
        printf("Enigmatic Result: %d\n", array[i]);
    }

    // As the dust settles, we unveil the secret message.
    printf("\nThe Enigma Cipher has spoken. Your enigmatic message is:\n");

    // Reveal the concealed message within the transformed array.
    for (uint32_t i = 0; i < array_size; i++) {
        putchar((array[i] % 26) + 'a');
    }

    // Release the memory we borrowed during our enigmatic adventure.
    free(array);

    return 0;
}