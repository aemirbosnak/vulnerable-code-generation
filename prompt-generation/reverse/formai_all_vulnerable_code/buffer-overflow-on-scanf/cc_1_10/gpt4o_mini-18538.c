//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to print colored text
void print_color(const char *text, const char *color) {
    printf("%s%s\033[0m", color, text);
}

// Recursive function to solve Tower of Hanoi
void tower_of_hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        print_color("Moving disc 1 from ", "\033[1;33m");
        putchar(source);
        print_color(" to ", "\033[1;34m");
        putchar(target);
        putchar('\n');
        return;
    }
    
    // Move top n-1 discs from source to auxiliary
    tower_of_hanoi(n - 1, source, auxiliary, target);
    
    // Move nth disc from source to target
    print_color("Moving disc ", "\033[1;32m");
    printf("%d ", n);
    print_color("from ", "\033[1;33m");
    putchar(source);
    print_color(" to ", "\033[1;34m");
    putchar(target);
    putchar('\n');
    
    // Move the n-1 discs from auxiliary to target
    tower_of_hanoi(n - 1, auxiliary, target, source);
}

// Function to print instructions
void print_instructions() {
    print_color("Welcome to the Tower of Hanoi simulator!\n", "\033[1;35m");
    print_color("Your goal is to move all the discs from the Source rod to the Target rod,\n", "\033[1;36m");
    print_color("using the Auxiliary rod, following these rules:\n", "\033[1;36m");
    print_color("1. Only one disc can be moved at a time.\n", "\033[1;36m");
    print_color("2. Each move consists of taking the upper disc from one of the stacks\n", "\033[1;36m");
    print_color("   and placing it on top of another stack or on an empty rod.\n", "\033[1;36m");
    print_color("3. No larger disc may be placed on top of a smaller disc.\n", "\033[1;36m");
    print_color("Let's begin! How many discs do you want to move? ", "\033[1;37m");
}

// Function to get user input
int get_user_input() {
    int n;
    scanf("%d", &n);
    return n;
}

// Main function
int main() {
    print_instructions();
    
    int n = get_user_input();
    
    if (n <= 0) {
        print_color("Oops! That's not a valid number of discs!\n", "\033[1;31m");
        return 1;
    }
    
    print_color("Great! You chose to move ", "\033[1;32m");
    printf("%d ", n);
    print_color("disc(s).\n", "\033[1;32m");
    
    print_color("Starting the Tower of Hanoi with ", "\033[1;32m");
    putchar('A'); // Source rod
    print_color(" as source, ", "\033[1;32m");
    putchar('C'); // Target rod
    print_color(" as target and ", "\033[1;32m");
    putchar('B'); // Auxiliary rod
    putchar('\n');

    sleep(1); // Adding a little delay for surprise

    // Start the solution
    tower_of_hanoi(n, 'A', 'C', 'B');
    
    print_color("\nCongratulations! You've solved the Tower of Hanoi!\n", "\033[1;35m");
    return 0;
}