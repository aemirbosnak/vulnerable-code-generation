//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void *malloc_puzzle(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory! (%zu bytes)\n", size);
        return NULL;
    }

    // Add some puzzle elements to the memory block
    char *mem = ptr;
    mem[0] = 'M';
    mem[1] = 'A';
    mem[2] = 'G';
    mem[3] = 'I';
    mem[4] = 'C';
    mem[5] = ' Number';
    mem[6] = 'E';
    mem[7] = '!';

    // Add a secret message
    char secret[] = "This is a secret message!";
    strcpy(mem + 8, secret);

    // Add some more puzzle elements
    mem[12] = 'A';
    mem[13] = 'L';
    mem[14] = 'I';
    mem[15] = 'E';
    mem[16] = 'N';
    mem[17] = 'E';
    mem[18] = '!';

    return ptr;
}

void free_puzzle(void *ptr) {
    free(ptr);
    printf("Memory freed! (%zu bytes)\n", sizeof(ptr));
}

int main() {
    void *ptr = malloc_puzzle(100);
    if (ptr == NULL) {
        printf("Error: Out of memory! (100 bytes)\n");
        return 1;
    }

    // Solve the puzzle to get the secret message
    char secret[9];
    memcpy(secret, ptr + 8, 9);
    secret[9] = '\0';

    printf("Secret message: %s\n", secret);

    free_puzzle(ptr);

    return 0;
}