//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

// Function to convert RGB values to ANSI escape codes
void rgb_to_ansi(int r, int g, int b) {
    int max_color;
    int r_index, g_index, b_index;

    max_color = (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);

    r_index = (r + 4 * (g > max_color) + 4 * (b > max_color)) % 6;

    g_index = (g + 3 * (b > max_color) + 3 * (r > max_color)) % 6;

    b_index = (b + 2 * (r > max_color) + 2 * (g > max_color)) % 6;

    switch(r_index) {
        case 0: printf(RED); break;
        case 1: printf(GREEN); break;
        case 2: printf(YELLOW); break;
        case 3: printf(BLUE); break;
        case 4: printf(MAGENTA); break;
        case 5: printf(CYAN); break;
    }

    switch(g_index) {
        case 0: printf(RED); break;
        case 1: printf(GREEN); break;
        case 2: printf(YELLOW); break;
        case 3: printf(BLUE); break;
        case 4: printf(MAGENTA); break;
        case 5: printf(CYAN); break;
    }

    switch(b_index) {
        case 0: printf(RED); break;
        case 1: printf(GREEN); break;
        case 2: printf(YELLOW); break;
        case 3: printf(BLUE); break;
        case 4: printf(MAGENTA); break;
        case 5: printf(CYAN); break;
    }

    printf("[\033[1;1H%d,%d,%d]", r, g, b);
    printf(RESET);
}

// Main function
int main(int argc, char *argv[]) {
    int r, g, b;

    if(argc < 4) {
        printf("Usage: %s <red> <green> <blue>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    r = atoi(argv[1]);
    g = atoi(argv[2]);
    b = atoi(argv[3]);

    rgb_to_ansi(r, g, b);

    return EXIT_SUCCESS;
}