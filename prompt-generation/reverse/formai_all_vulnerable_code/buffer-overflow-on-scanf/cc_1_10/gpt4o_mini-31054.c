//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <termios.h> // For terminal settings
#include <fcntl.h> // For fcntl functions

// Function to clear the terminal screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to get character input without pressing enter
char getch() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}

// Function to generate the Fibonacci sequence up to the n-th term
void generate_fibonacci(int n) {
    long long a = 0, b = 1, c;
    printf("🌼 Fibonacci Sequence 🌼\n");
    printf("-------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

// Function to visualize the Fibonacci sequence
void visualize_fibonacci(int n) {
    long long a = 0, b = 1, c;
    clear_screen();
    
    printf("🌼 Let's Visualize the Fibonacci Sequence! 🌼\n");
    printf("Press 'q' to quit at any time. 😊\n");
    printf("Generating...\n");
    sleep(1);

    for (int i = 0; i < n; i++) {
        if (getch() == 'q') {
            printf("\nYou chose to exit the visualization! Have a great day! 🌈\n");
            break;
        }

        printf("Term %2d: %lld ", i + 1, a);
        printf("★");
        fflush(stdout); // Ensure the output is displayed immediately
        sleep(1); // Sleep for 1 second for animation effect
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n\n✨ Thank you for watching! ✨\n");
}

int main() {
    int n;

    clear_screen();
    printf("🌟 Welcome to the Fibonacci Sequence Visualizer! 🌟\n");
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("🎉 Please enter a positive integer! 🎉\n");
        while (getchar() != '\n'); // Clear the input buffer
        printf("How many terms of the Fibonacci sequence would you like to see? ");
    }

    generate_fibonacci(n);
    visualize_fibonacci(n);

    printf("\n🌼 Goodbye! See you next time! 🌼\n");
    return 0;
}