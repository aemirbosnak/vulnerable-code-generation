//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

// Function to draw the Fibonacci sequence in a visual way
void drawFibonacci(int n) {
    int a = 0, b = 1, c;
    int maxHeight = LINES - 2; // Leave space for the bottom line
    int maxWidth = COLS; // Width of the terminal
    int x = maxWidth / 4; // Starting position
    int y = maxHeight / 2; // Start drawing vertically in the middle
    
    // Title
    mvprintw(0, maxWidth / 2 - 10, "Fibonacci Sequence Visualizer");
    
    // Draw initial two numbers
    mvprintw(y, x, "%d", a);
    mvprintw(y, x + 1, "%d", b);
    
    // Move to position for drawing numbers
    x += 3; 
    
    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        
        // Clear old number and draw new one
        mvprintw(y, x, "%d", c);
        
        // Adjust x position for next number
        x += 3;
        
        // Check if we reached the end of the screen
        if (x >= maxWidth - 1) {
            x = 2; // Reset x to the left side
            y++; // Move down to the next line
            if (y >= maxHeight) { // Check if we exceed the screen height
                y = 1; // Reset y
                clear(); // Clear the screen to continue drawing
                mvprintw(0, maxWidth / 2 - 10, "Fibonacci Sequence Visualizer");
                x = 2; // Reset x
            }
        }

        // Refresh the screen
        refresh();
        // Slow down the drawing
        usleep(500000); // Wait for half a second
    }

    // Wait for user input to exit
    mvprintw(maxHeight - 1, maxWidth / 2 - 9, "Press any key to exit...");
    refresh();
    getch();
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak(); // Disable line buffering
    noecho(); // Don't print input
    keypad(stdscr, TRUE); // Allow reading of special keys
    curs_set(0); // Hide the cursor

    int n;
    printw("Enter the number of Fibonacci terms to display: ");
    scanw("%d", &n);
    
    if (n <= 0) {
        printw("Please enter a positive integer.\nPress any key to exit...");
        getch();
        endwin(); // End ncurses mode
        return 1;
    }

    drawFibonacci(n);

    // Clean up and end ncurses mode
    endwin();
    return 0;
}