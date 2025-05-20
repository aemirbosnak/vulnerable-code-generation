#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[10];
    int count[256] = {0};
    char word[256];

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        strcpy(word, buffer);
        for (int i = 0; word[i]; i++) {
            count[(int)word[i]]++;
        }
    }

    fclose(file);

    for (int i = 0; i < 256; i++) {
        if (count[i]) {
            printf("%c: %d\n", i, count[i]);
        }
    }

    return 0;
}
