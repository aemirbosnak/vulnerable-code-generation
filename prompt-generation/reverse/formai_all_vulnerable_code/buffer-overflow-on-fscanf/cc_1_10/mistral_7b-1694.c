//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MIN_VALUE 1
#define MAX_VALUE 100

typedef struct {
    int numbers[MAX_SIZE];
    int length;
} knight_pack;

void load_numbers_from_file(knight_pack *pack, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open the file:");
        printf("Error: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    pack->length = 0;
    int number;

    while (fscanf(file, "%d", &number) != EOF) {
        if (pack->length >= MAX_SIZE) {
            fprintf(stderr, "Error: The knight's pack is full.\n");
            exit(EXIT_FAILURE);
        }

        pack->numbers[pack->length++] = number;

        if (number < MIN_VALUE || number > MAX_VALUE) {
            fprintf(stderr, "Error: The number '%d' is not a valid one.\n", number);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    knight_pack pack;
    load_numbers_from_file(&pack, argv[1]);

    printf("The brave knight carries %d numbers in his pack:\n", pack.length);
    for (size_t i = 0; i < pack.length; ++i) {
        printf("%d\n", pack.numbers[i]);
    }

    return EXIT_SUCCESS;
}