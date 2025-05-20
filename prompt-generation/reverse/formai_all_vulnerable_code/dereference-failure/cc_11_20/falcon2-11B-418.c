//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int main(int argc, char **argv)
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    srand(time(NULL));

    int i = 0, j = 0, k = 0;
    char c = '0';

    int max_col = 30;
    int max_row = 20;

    int window_col = max_col - 1;
    int window_row = max_row - 1;

    int *window_coordinates = calloc(max_col * max_row, sizeof(int));

    int *window_char_coordinates = calloc(max_col * max_row, sizeof(int));

    for (i = 0; i < max_col * max_row; i++) {
        window_coordinates[i] = rand() % max_col + 1;
        window_char_coordinates[i] = rand() % max_col + 1;
    }

    for (i = 0; i < max_col; i++) {
        for (j = 0; j < max_row; j++) {
            if (j == 0)
                wmove(stdscr, i, j);
            else
                wmove(stdscr, i, j - 1);
            if (i == 0)
                wmove(stdscr, i, j);
            else
                wmove(stdscr, i - 1, j);
            if (j == max_row - 1)
                wmove(stdscr, i, j);
            else
                wmove(stdscr, i, j + 1);
            if (i == max_col - 1)
                wmove(stdscr, i, j);
            else
                wmove(stdscr, i + 1, j);
            waddch(stdscr, window_coordinates[j * max_col + i]);
        }
    }

    for (i = 0; i < max_col; i++) {
        for (j = 0; j < max_row; j++) {
            if (window_char_coordinates[j * max_col + i] == c) {
                waddstr(stdscr, " ");
            } else {
                waddch(stdscr, c);
            }
        }
    }

    wrefresh(stdscr);
    getch();
    endwin();

    return 0;
}