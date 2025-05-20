#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 100000
#define BUFFER_SIZE 64

void evict(void* arr, size_t arr_size, size_t index) {
    if (arr) {
        memmove((void*)arr, (void*)((char*)arr + index * sizeof(int)), arr_size * sizeof(int) - index * sizeof(int));
    }
}

void use_cache(void) {
    int cache[ARRAY_SIZE];
    char* commands[BUFFER_SIZE];
    char line[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; ++i) {
        if (gets(line)) {
            char* cmd = strtok(line, " ");
            char* num = strtok(NULL, " ");

            if (cmd[0] == 'P') { // Place
                int idx = atoi(num);
                if (idx >= ARRAY_SIZE || idx < 0) {
                    printf("Invalid index!\n");
                    continue;
                }
                cache[idx] = atoi(num + 1);
                evict(commands, BUFFER_SIZE, i);
            } else if (cmd[0] == 'U') { // Use
                int idx = atoi(num);
                if (idx >= ARRAY_SIZE || idx < 0) {
                    printf("Invalid index!\n");
                    continue;
                }
                if (cache[idx] == -1) {
                    printf("Item not found!\n");
                } else {
                    printf("Item found: %d\n", cache[idx]);
                }
                evict(commands, BUFFER_SIZE, i);
            }
        } else {
            break;
        }
    }

    free(commands);
}

int main() {
    use_cache();
    return 0;
}
