//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define the maximum size for the text
#define MAX_SIZE 100

// Define the height and width of the ASCII art
#define HEIGHT 10
#define WIDTH 50

char chars[11] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@', '\0'};
char art[HEIGHT][WIDTH+1];

void clear_art() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH+1; j++) {
            art[i][j] = '\0';
        }
    }
}

void gen_art(char* text) {
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (count >= len) {
                count = 0;
            }
            int index = (int)text[count] % 11;
            art[i][j] = chars[index];
            count++;
        }
    }
}

void print_art() {
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", art[i]);
    }
}

int main() {
    char text[MAX_SIZE];
    printf("Enter the text: ");
    fgets(text, MAX_SIZE, stdin);
    int len = strlen(text);
    if (text[len-1] == '\n') {
        text[len-1] = '\0';
    }
    clear_art();
    gen_art(text);
    print_art();
    return 0;
}