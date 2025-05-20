//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_ART_WIDTH 80
#define MAX_ART_HEIGHT 25

typedef struct {
    char text[MAX_TEXT_LENGTH];
    int width;
    int height;
} Art;

Art generate_art(char* text) {
    Art art = {0};
    strcpy(art.text, text);

    // Determine the width and height of the art
    int max_width = 0;
    int num_lines = 0;
    char* line = strtok(art.text, "\n");
    while (line!= NULL) {
        int line_width = strlen(line);
        if (line_width > max_width) {
            max_width = line_width;
        }
        num_lines++;
        line = strtok(NULL, "\n");
    }
    art.width = max_width;
    art.height = num_lines;

    return art;
}

void print_art(Art art) {
    int i, j;
    for (i = 0; i < art.height; i++) {
        char* line = strtok(art.text, "\n");
        int line_width = strlen(line);
        for (j = 0; j < line_width; j++) {
            printf("%c", line[j]);
        }
        printf("\n");
        line = strtok(NULL, "\n");
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter your text (max %d characters): ", MAX_TEXT_LENGTH - 1);
    scanf("%s", text);

    Art art = generate_art(text);
    printf("Art width: %d\n", art.width);
    printf("Art height: %d\n", art.height);

    print_art(art);

    return 0;
}