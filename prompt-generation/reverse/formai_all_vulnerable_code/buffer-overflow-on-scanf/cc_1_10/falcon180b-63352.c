//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define TEXT_COLOR "\033[1;37m"
#define BACKGROUND_COLOR "\033[0;40m"

void generate_art(char* input_text) {
    srand(time(NULL));
    int font_size = rand() % 3 + 1;
    int art_width = rand() % MAX_WIDTH + 1;
    int art_height = rand() % MAX_HEIGHT + 1;

    char* art_text = malloc(art_width * art_height + 1);
    for (int i = 0; i < art_height; i++) {
        for (int j = 0; j < art_width; j++) {
            int ascii_value = rand() % 127;
            art_text[i * art_width + j] = ascii_value;
        }
    }

    char* final_art = malloc(art_width * art_height + strlen(input_text) + 2);
    sprintf(final_art, "%s%s\n", TEXT_COLOR, input_text);

    for (int i = 0; i < art_height; i++) {
        for (int j = 0; j < art_width; j++) {
            if (art_text[i * art_width + j] == 32) {
                strcat(final_art, BACKGROUND_COLOR);
            } else {
                strcat(final_art, TEXT_COLOR);
            }
            strcat(final_art, &art_text[i * art_width + j]);
        }
        strcat(final_art, "\n");
    }

    printf("%s", final_art);
    free(art_text);
    free(final_art);
}

int main() {
    char input_text[100];
    printf("Enter some text to generate ASCII art: ");
    scanf("%s", input_text);
    generate_art(input_text);
    return 0;
}