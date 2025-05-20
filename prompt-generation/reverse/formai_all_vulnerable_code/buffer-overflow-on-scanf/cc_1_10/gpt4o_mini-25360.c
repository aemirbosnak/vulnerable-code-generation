//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

// Function to compute Fibonacci numbers using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to tell a whimsical story while generating Fibonacci numbers
void whimsicalStory(int n) {
    if (n < 0) {
        printf("Once upon a time, in the land of negative numbers...\n");
        printf("They were all sad because they couldn't find their values in Fibonacci.\n");
        return;
    }
    if (n == 0) {
        printf("In the beginning, there was zero...\n");
        printf("Zero is the starting point of all things wonderful!\n");
        return;
    }
    printf("This is the tale of Fibonacci number F(%d): ", n);
    int fibNum = fibonacci(n);
    printf("%d\n", fibNum);
    printf("With this number, the magic of sequences unfolds...\n");
    
    // Recursively tell the story for the previous numbers
    whimsicalStory(n - 1);
}

// Function to welcome the user and explain the game
void welcome() {
    printf("Welcome to the Whimsical Fibonacci Adventure!\n");
    printf("In this game, we'll explore the Fibonacci numbers through a whimsical story.\n");
    printf("You get to choose how many Fibonacci numbers to generate.\n");
    printf("Ready to embark on this adventure? \n\n");
}

// Main function to run the game
int main() {
    int n;

    // Welcome message
    welcome();

    // User input for the number of Fibonacci numbers
    printf("Enter the number of Fibonacci numbers you want to explore (0 or more): ");
    scanf("%d", &n);

    // Starting the whimsical storytelling about Fibonacci numbers
    whimsicalStory(n);

    // Ending the whimsical adventure
    printf("\nAnd so, the adventure of Fibonacci numbers comes to an end.\n");
    printf("Remember, even numbers can have a story!\n");
    printf("Farewell, brave Fibonacci adventurer!\n");

    return 0;
}