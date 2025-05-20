//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_LETTER_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char love_letter[MAX_LETTER_LENGTH];
} LoveLetter;

void write_love_letter(const char *filename, const LoveLetter *letter) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Could not open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Dear %s,\n\n", letter->name);
    fprintf(file, "%s\n", letter->love_letter);
    fprintf(file, "\nForever yours,\nYour loving partner.\n");

    fclose(file);
    printf("Love letter written successfully.\n");
}

LoveLetter read_love_letter(const char *filename) {
    FILE *file = fopen(filename, "r");
    LoveLetter letter;
    char name[MAX_NAME_LENGTH];
    char love_letter[MAX_LETTER_LENGTH];
    int name_length = 0;
    int letter_length = 0;

    if (file == NULL) {
        printf("Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }

    fgets(name, sizeof(name), file);
    name_length = strlen(name) - 1;
    if (name[name_length] == '\n') name[name_length] = '\0';

    while (fgets(love_letter + letter_length, sizeof(love_letter) - letter_length, file)) {
        letter_length += strlen(love_letter + letter_length);
    }

    strncpy(letter.name, name, sizeof(letter.name));
    strncpy(letter.love_letter, love_letter, sizeof(letter.love_letter));

    fclose(file);

    return letter;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <name> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    LoveLetter letter = { .name = { 0 }, .love_letter = { 0} };

    strcpy(letter.name, argv[1]);

    printf("Enter a romantic message for %s:\n", argv[1]);
    fgets(letter.love_letter, sizeof(letter.love_letter), stdin);

    write_love_letter("love_letter.txt", &letter);
    LoveLetter read_letter = read_love_letter("love_letter.txt");

    printf("\nDear %s,\n\n", read_letter.name);
    printf("%s", read_letter.love_letter);
    printf("\nForever yours,\nYour loving partner.\n");

    return EXIT_SUCCESS;
}