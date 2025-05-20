//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOVE_LETTER_SIZE 1000
#define HEARTBEAT_SIZE 5

typedef struct {
    char content[LOVE_LETTER_SIZE];
    int heartbeats;
} LoveLetter;

void read_heartbeats(FILE *file, int *heartbeats) {
    int i;
    char heartbeat[HEARTBEAT_SIZE];

    for (i = 0; i < HEARTBEAT_SIZE; i++) {
        fread(&heartbeat, sizeof(char), 1, file);
        *heartbeats += heartbeat[i] - '0';
    }
}

void read_love_letter(FILE *file, LoveLetter *letter) {
    fread(letter->content, sizeof(char), LOVE_LETTER_SIZE, file);
}

int main(int argc, char *argv[]) {
    FILE *file;
    LoveLetter lost_letter;
    int heartbeats;

    if (argc != 2) {
        printf("Usage: %s <path_to_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    read_heartbeats(file, &heartbeats);
    printf("Heartbeats: %d\n", heartbeats);

    read_love_letter(file, &lost_letter);
    printf("\nMy Dearest,\n");
    printf("%s\n", lost_letter.content);
    printf("Yours Forever and Always,\n");

    fclose(file);

    return 0;
}