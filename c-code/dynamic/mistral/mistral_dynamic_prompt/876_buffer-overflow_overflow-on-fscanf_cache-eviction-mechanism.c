#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10
#define LINE_SIZE 256

void evict(char *cache) {
    if (strlen(cache) > BUFFER_SIZE) {
        cache[0] = '\0'; // Clear the first element to evict the oldest entry
    }
}

int main(int argc, char *argv[]) {
    char cache[BUFFER_SIZE][LINE_SIZE];
    int i = 0;

    while (1) {
        char line[LINE_SIZE];
        fgets(line, LINE_SIZE, stdin);

        if (strlen(line) >= LINE_SIZE - 1) { // This will trigger the buffer overflow
            printf("Overflow detected! Input too long.\n");
            continue;
        }

        evict(cache[i]);
        strcpy(cache[i], line);
        printf("Storing line %d: %s\n", i, cache[i]);
        i = (i + 1) % BUFFER_SIZE;
    }

    return 0;
}
