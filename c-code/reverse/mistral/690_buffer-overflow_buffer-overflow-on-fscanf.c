#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char word[BUFFER_SIZE];
    int count[256] = {0};

    file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        sscanf(buffer, "%s", word);
        count[(unsigned char)word[0]]++;
    }

    fclose(file);

    for (int i = 0; i < 256; ++i) {
        if (count[i]) {
            printf("%c: %d\n", i, count[i]);
        }
    }

    return 0;
}
