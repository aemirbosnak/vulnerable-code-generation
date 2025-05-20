//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEART "♥"
#define ROSE "🌹"
#define BOX "╔════════════════╗"
#define BORDER "║"
#define EMPTY " "
#define LINE_FEED "\n"

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    char **text;
    int width;
    int height;
} TextArt;

TextArt* generate_art(char* input) {
    TextArt* art = malloc(sizeof(TextArt));
    art->width = strlen(input) / 2;
    art->height = 1;
    art->text = malloc(art->width * sizeof(char*));

    for (int i = 0; i < art->width; i++) {
        art->text[i] = malloc(MAX_HEIGHT * sizeof(char));
        memset(art->text[i], EMPTY, MAX_HEIGHT);
    }

    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '\n') {
            j++;
        } else {
            art->text[j][i%MAX_HEIGHT] = input[i];
        }
    }

    return art;
}

void print_art(TextArt* art) {
    printf("%s", BOX);

    for (int i = 0; i < art->width; i++) {
        printf("%s", art->text[i]);
    }

    printf("%s", BOX);
}

void free_art(TextArt* art) {
    for (int i = 0; i < art->width; i++) {
        free(art->text[i]);
    }
    free(art->text);
    free(art);
}

int main() {
    char input[MAX_WIDTH + 1];
    TextArt* art;

    printf("Enter a message: ");
    fgets(input, MAX_WIDTH, stdin);

    art = generate_art(input);
    print_art(art);

    free_art(art);

    return 0;
}