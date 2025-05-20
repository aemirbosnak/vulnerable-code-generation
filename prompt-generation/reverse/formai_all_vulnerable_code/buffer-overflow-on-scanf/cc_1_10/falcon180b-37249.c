//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the multiplication table of a given number
void multiplication_table(int num) {
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

// Function to play a simple number guessing game
void number_guessing_game() {
    int num, guess, attempts = 0;

    // Generate a random number between 1 and 100
    num = rand_num(1, 100);

    // Prompt the user to guess the number
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess);

    // Check if the guess is correct and give hints if it's not
    while (guess!= num) {
        if (guess < num) {
            printf("Too low. Try again: ");
        } else {
            printf("Too high. Try again: ");
        }
        scanf("%d", &guess);
        attempts++;
    }

    // Print the number of attempts and congratulate the user
    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
}

// Function to print a random quote about peace
void print_peace_quote() {
    int i;
    const char* quotes[] = {
        "Peace cannot be kept by force; it can only be achieved by understanding. - Albert Einstein",
        "If we have no peace, it is because we have forgotten that we belong to each other. - Mother Teresa",
        "Peace is not absence of conflict, it is the ability to handle conflict by peaceful means. - Ronald Reagan",
        "Peace begins with a smile. - Mother Teresa",
        "An eye for an eye will only make the whole world blind. - Mahatma Gandhi",
        "Imagine all the people living life in peace. You may say I'm a dreamer, but I'm not the only one. - John Lennon",
        "Peace is a journey of a thousand miles and it must be taken one step at a time. - Lyndon B. Johnson",
        "The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela",
        "When the power of love overcomes the love of power the world will know peace. - Jimi Hendrix",
        "Peace is not merely a distant goal that we seek, but a means by which we arrive at that goal. - Martin Luther King Jr."
    };

    i = rand() % 10;
    printf("%s\n", quotes[i]);
}

int main() {
    int choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print the menu and get the user's choice
    printf("Welcome to the Arithmetic Program!\n");
    printf("Please choose an option:\n");
    printf("1. Multiplication table\n");
    printf("2. Number guessing game\n");
    printf("3. Print a peace quote\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    // Perform the chosen operation
    switch (choice) {
        case 1:
            printf("Enter a number to print its multiplication table:\n");
            scanf("%d", &choice);
            multiplication_table(choice);
            break;
        case 2:
            number_guessing_game();
            break;
        case 3:
            print_peace_quote();
            break;
        case 4:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}