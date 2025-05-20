//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <signal.h>

void sigint_handler(int sig) {
    exit(0);
}

void temperature_update(int new_temperature) {
    if (new_temperature > 70) {
        printf("Warning! The temperature is high!\n");
    } else {
        printf("Temperature: %d\n", new_temperature);
    }
}

int main() {
    // Initialize ncurses
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);
    signal(SIGINT, sigint_handler);

    // Create a window for the temperature display
    WINDOW *temp_win = newwin(5, 40, 0, 0);
    wattron(temp_win, A_BOLD);
    mvwaddstr(temp_win, 0, 0, "Temperature Monitor");
    wattroff(temp_win, A_BOLD);

    // Loop forever
    while (1) {
        // Get the current temperature
        char buffer[10];
        scanf("%s", buffer);
        int temperature = atoi(buffer);

        // Update the temperature display
        temperature_update(temperature);

        // Redraw the window
        wrefresh(temp_win);

        // Wait for a keypress
        wgetch(temp_win);
    }

    return 0;
}