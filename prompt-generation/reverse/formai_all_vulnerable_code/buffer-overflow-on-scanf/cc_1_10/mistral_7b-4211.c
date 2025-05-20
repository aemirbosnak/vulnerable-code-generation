//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAGIC_NUMBER 0xDEADBEEF

typedef struct {
    uint8_t data[BUFFER_SIZE];
    size_t read;
    size_t write;
} circular_buffer;

circular_buffer cb;

void init_buffer() {
    cb.read = 0;
    cb.write = 0;
    memset(cb.data, MAGIC_NUMBER, BUFFER_SIZE);
}

size_t get_free_memory() {
    size_t total_memory = BUFFER_SIZE * sizeof(uint8_t);
    size_t used_memory = cb.write - cb.read;
    return total_memory - used_memory;
}

void print_ram_usage() {
    size_t free_memory = get_free_memory();
    float percentage = ((float)free_memory / (float)BUFFER_SIZE) * 100;

    printf("\n[");
    for (size_t i = 0; i < cb.read; i++) {
        if ((i + 1) % 10 == 0)
            printf("\n  %d%c", (int)cb.data[i], (i + 1) % 10 == 0 ? ']' : ' ');
        else
            printf("%c", cb.data[i]);
    }

    printf("\nFree Memory: %ld bytes (%0.2f%%)\n", (long)free_memory, percentage);
}

int main() {
    init_buffer();

    char input;
    while (1) {
        scanf("%c", &input);
        cb.data[cb.write++] = input;
        if (cb.write >= BUFFER_SIZE)
            cb.write = 0;

        print_ram_usage();
    }

    return 0;
}