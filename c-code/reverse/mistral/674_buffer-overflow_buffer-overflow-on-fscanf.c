#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100

void translate(char *word) {
    if (strchr(word, 'a') != NULL) {
        strcpy(word, "apple");
    } else if (strchr(word, 'b') != NULL) {
        strcpy(word, "banana");
    } else if (strchr(word, 'c') != NULL) {
        strcpy(word, "cherry");
    }
}

int main(int argc, char *argv[]) {
    char buffer[MAX_WORD_LENGTH];
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        translate(buffer);
        printf("%s\n", buffer);
    }

    fclose(file);
    return 0;
}
