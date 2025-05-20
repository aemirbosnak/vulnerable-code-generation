//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a funny macro for maximum silliness
#define MAX_SILLINESS 50

// Function prototypes
void displayMainMenu();
void performOperation(int operation);
int addNumbers(int a, int b);
int subtractNumbers(int a, int b);
int multiplyNumbers(int a, int b);
float divideNumbers(int a, int b);
void jokeOfTheDay();
void giveSillyAdvice();

int main() {
    // Seed the random number generator
    srand(time(0));

    int choice;

    do {
        displayMainMenu();
        printf("\nEnter your choice (1-4 for operations, 5 for a joke, 6 for silly advice, 0 to quit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Goodbye, math wizard! May your calculations be ever in your favor!\n");
            break;
        }

        performOperation(choice);
    } while (choice != 0);

    return 0;
}

void displayMainMenu() {
    printf("\n================== Math Fun Land ==================\n");
    printf("1. Add two numbers (or just add some silliness)\n");
    printf("2. Subtract two numbers (who likes division anyway?)\n");
    printf("3. Multiply two numbers (let's create some math monster)\n");
    printf("4. Divide two numbers (it's more like a divide-and-conquer)\n");
    printf("5. Get a joke of the day!\n");
    printf("6. Get silly advice (because everyone needs it)\n");
    printf("====================================================\n");
}

void performOperation(int operation) {
    int a, b;
    switch (operation) {
        case 1:
            printf("Enter two numbers to add (do you promise they are integers?): ");
            scanf("%d %d", &a, &b);
            printf("Result: %d + %d = %d (and that makes you a math wizard!)\n", a, b, addNumbers(a, b));
            break;
        case 2:
            printf("Enter two numbers to subtract (remember, no crying!): ");
            scanf("%d %d", &a, &b);
            printf("Result: %d - %d = %d (now you know how to subtract your problems!)\n", a, b, subtractNumbers(a, b));
            break;
        case 3:
            printf("Enter two numbers to multiply (let's create some math magic!): ");
            scanf("%d %d", &a, &b);
            printf("Result: %d * %d = %d (that's a lot of fun math magic!)\n", a, b, multiplyNumbers(a, b));
            break;
        case 4:
            printf("Enter two numbers to divide (let's divide this conversation!): ");
            scanf("%d %d", &a, &b);
            if (b == 0) {
                printf("Whoa there! You can't divide by zero! (Try another number!)\n");
                break;
            }
            printf("Result: %d / %d = %.2f (just like sharing snacks)\n", a, b, divideNumbers(a, b));
            break;
        case 5:
            jokeOfTheDay();
            break;
        case 6:
            giveSillyAdvice();
            break;
        default:
            printf("Umm, that’s not a valid choice! Try again, silly!\n");
            break;
    }
}

int addNumbers(int a, int b) {
    return a + b;
}

int subtractNumbers(int a, int b) {
    return a - b;
}

int multiplyNumbers(int a, int b) {
    return a * b;
}

float divideNumbers(int a, int b) {
    return (float) a / b;
}

void jokeOfTheDay() {
    const char* jokes[] = {
        "Why was the equal sign so humble? Because it knew it wasn't less than or greater than anyone else!",
        "What do you call a number that can't keep still? A roamin' numeral!",
        "Why do plants hate math? Because it gives them square roots!",
        "Why did the math book look sad? Because it had too many problems!",
        "Parallel lines have so much in common. It's a shame they'll never meet!"
    };
    
    int index = rand() % (sizeof(jokes) / sizeof(jokes[0]));
    printf("Joke: %s\n", jokes[index]);
}

void giveSillyAdvice() {
    const char* advice[] = {
        "If at first you don't succeed, redefine success!",
        "Always borrow money from a pessimist. They won’t expect it back!",
        "Never trust math teachers who use rulers. They’re definitely measuring their fun!",
        "Don't be afraid to fail; be afraid of not trying to make math fun!",
        "Counting your blessings is not as important as counting your snacks!"
    };
    
    int index = rand() % (sizeof(advice) / sizeof(advice[0]));
    printf("Silly Advice: %s\n", advice[index]);
}