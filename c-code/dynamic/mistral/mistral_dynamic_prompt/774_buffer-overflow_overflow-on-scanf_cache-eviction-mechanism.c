#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void evict_cache(char *buf) {
    char eviction_victim[10];
    strcpy(eviction_victim, buf);
}

int main(int argc, char **argv) {
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);

    evict_cache(input);

    printf("Cache has been evicted.\n");
    return 0;
}
