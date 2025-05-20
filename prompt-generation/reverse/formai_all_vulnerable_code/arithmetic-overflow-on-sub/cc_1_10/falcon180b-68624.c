//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
    int width;
} TextBlock;

void generate_ascii_art(TextBlock *text_blocks) {
    int max_width = 0;
    for (int i = 0; i < text_blocks->length; i++) {
        if (text_blocks[i].width > max_width) {
            max_width = text_blocks[i].width;
        }
    }
    for (int i = 0; i < text_blocks->length; i++) {
        int padding = (max_width - text_blocks[i].width) / 2;
        printf("%*s", padding, "");
        printf("%s\n", text_blocks[i].text);
    }
}

int main() {
    char input_text[MAX_LINE_LENGTH];
    printf("Enter some text: ");
    fgets(input_text, MAX_LINE_LENGTH, stdin);

    TextBlock text_blocks[10];
    int num_blocks = 0;

    char *token = strtok(input_text, "\n");
    while (token!= NULL) {
        if (num_blocks >= 10) {
            printf("Error: Too many lines.\n");
            exit(1);
        }
        text_blocks[num_blocks].text = token;
        text_blocks[num_blocks].length = strlen(token);
        text_blocks[num_blocks].width = text_blocks[num_blocks].length;
        num_blocks++;
        token = strtok(NULL, "\n");
    }

    generate_ascii_art(text_blocks);

    return 0;
}