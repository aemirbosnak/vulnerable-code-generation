//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128
#define ART_WIDTH 20
#define ART_HEIGHT 5

typedef struct {
    char symbol;
    char *ascii_art;
} art_t;

art_t arts[26] = {
    {'A', "\
 _____\n\
/_____/\n\
|    |\n\
|  O  |\n\
|_____|"},
    {'B', "\
 _____\n\
/_____/\n\
|    |\n\
|  O O|\n\
|_____|"},
    // Add more characters and their corresponding ASCII art here...
};

void generate_art(char text[], art_t arts[], int size) {
    int i, j, text_len;

    text_len = strlen(text);

    for (i = 0; i < text_len; i++) {
        for (j = 0; j < size; j++) {
            if (text[i] == arts[j].symbol) {
                printf("%s", arts[j].ascii_art);
                break;
            }
        }
        if (j == size) {
            printf("Invalid character: %c", text[i]);
        }
    }
}

int main() {
    char text[100];

    printf("Enter text: ");
    scanf("%s", text);

    generate_art(text, arts, sizeof(arts) / sizeof(art_t));

    return 0;
}