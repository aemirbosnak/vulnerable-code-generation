//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A function to make a really bad pun about recursion
void tellRecursionJoke() {
    printf("Why do programmers always mix up Christmas and Halloween?\n");
    printf("Because Oct 31 equals Dec 25!\n");
}

// A fun function that pretends to do some serious calculations,
// but really just leaves a trail of puns and giggles
int mischievousPuns(int n) {
    if (n < 1) {
        printf("I'm out of puns! Only empty promises left...\n");
        return 0;
    } else {
        printf("Here comes the pun number %d: ", n);
        tellRecursionJoke();
        // Adding a little bit of fun here, we can let it lose count!
        return n + mischievousPuns(n - 1);
    }
}

// The main function, where the real fun begins
int main() {
    int jokesCount;

    // Forcing users to enter a positive number of jokes.
    do {
        printf("Welcome to the Pun-tastic Recursion Program!\n");
        printf("Enter the number of puns you want to hear (positive number only): ");
        scanf("%d", &jokesCount);

        if (jokesCount < 1) {
            printf("Come on! Just like recursion, you gotta have some base case, right? Try again.\n");
        }
    } while (jokesCount < 1);

    // Run the mischievous function to tell the user some puns
    printf("Hold on tight! Here we go...\n");
    int totalPuns = mischievousPuns(jokesCount);
    
    // Summing up total puns in a funny way
    printf("Total puns generated: %d (Give or take some chuckles)!\n", totalPuns);
    printf("Thanks for using the Pun-tastic Recursion Program! Remember, laughter is the best code!\n");

    // Letting the user know they can quit the program,
    // because it's totally a 'pun-derful' time.
    printf("Press any key to exit (or just close the terminal, no pressure)!\n");
    
    // Wait for user input before exiting
    getchar(); // This gets rid of '\n' leftover by the last scanf
    getchar(); // Wait for the user to press Enter

    // Recursion could lead to a pun-derful adventure... but now it's time to say goodbye!
    return 0;
}