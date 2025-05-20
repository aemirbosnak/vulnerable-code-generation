//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_SIZE 8
#define MAX_SIZE 80
#define MAX_LINES 10
#define MAX_CHARS 1000

typedef struct {
    char *text;
    int size;
    int lines;
    int chars;
} Art;

Art *create_art(const char *text) {
    Art *art = malloc(sizeof(Art));
    art->text = strdup(text);
    art->size = MIN_SIZE;
    art->lines = 1;
    art->chars = strlen(text);
    return art;
}

void destroy_art(Art *art) {
    free(art->text);
    free(art);
}

void resize_art(Art *art, int size) {
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Invalid size: %d\n", size);
        return;
    }
    art->size = size;
    art->lines = (art->chars + size - 1) / size;
}

void print_art(Art *art) {
    int i, j;
    for (i = 0; i < art->lines; i++) {
        for (j = 0; j < art->size; j++) {
            if (i * art->size + j >= art->chars) {
                printf(" ");
            } else {
                printf("%c", tolower(art->text[i * art->size + j]));
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_CHARS];
    Art *art = NULL;

    printf("ASCII Art Generator\n");
    printf("Enter some text:\n");
    fgets(input, MAX_CHARS, stdin);

    art = create_art(input);

    while (1) {
        printf("Current size: %d\n", art->size);
        printf("Press's' to change size, 'p' to print, or any other key to exit.\n");
        char choice;
        scanf(" %c", &choice);

        if (choice =='s') {
            printf("Enter new size (between %d and %d): ", MIN_SIZE, MAX_SIZE);
            int newsize;
            scanf("%d", &newsize);
            resize_art(art, newsize);
        } else if (choice == 'p') {
            print_art(art);
        } else {
            break;
        }
    }

    destroy_art(art);

    return 0;
}