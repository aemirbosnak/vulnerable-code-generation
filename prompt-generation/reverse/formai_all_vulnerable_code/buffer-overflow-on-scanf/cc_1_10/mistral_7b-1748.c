//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_CHARS 128

typedef struct {
    int x, y;
} Point;

typedef struct {
    char symbol;
    Point pos;
} Character;

void print_char(Character ch) {
    int i, j;
    for (i = 0; i < 2 * WIDTH + 1; i++) {
        if (i == 2 * ch.pos.x || i == 2 * ch.pos.x + WIDTH - 1)
            putchar(ch.symbol);
        else if (i >= 2 * ch.pos.y && i <= 2 * ch.pos.y + WIDTH - 1) {
            if (i == 2 * ch.pos.y)
                putchar(' ');
            else
                putchar(i % 2 == 0 ? '#' : ' ');
        } else
            putchar(' ');
    }
    putchar('\n');
}

void print_char_array(Character arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        print_char(arr[i]);
}

void generate_text_to_ascii(char text[], Character arr[], int size) {
    int i, j, len = strlen(text);
    for (i = 0; i < len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
        for (j = 0; j < size; j++) {
            if (arr[j].symbol == text[i]) {
                arr[j].pos.x = i % WIDTH;
                arr[j].pos.y = i / WIDTH;
                break;
            }
        }
        if (j == size) {
            Character new_char;
            new_char.symbol = text[i];
            new_char.pos.x = i % WIDTH;
            new_char.pos.y = i / WIDTH;
            if (size < MAX_CHARS) {
                arr[size] = new_char;
                size++;
            } else {
                printf("Error: Maximum number of characters reached.\n");
                exit(1);
            }
        }
    }
}

int main() {
    char text[100];
    Character arr[MAX_CHARS];
    int size = 0;
    printf("Enter the text to convert to ASCII art (max 100 characters):\n");
    scanf("%s", text);
    generate_text_to_ascii(text, arr, size);
    print_char_array(arr, size);
    return 0;
}