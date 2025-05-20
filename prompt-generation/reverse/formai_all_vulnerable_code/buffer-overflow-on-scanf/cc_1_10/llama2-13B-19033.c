//LLAMA2-13B DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SURPRISED 1

int main() {
    // Surprised! You found a talking cat!
    printf("Meow! Did you really just say 'hello' to me? That's purr-fectly amazing!\n");

    // Generate a random surprise message
    char *message = "Oh my whiskers! I can't believe you just";
    int index = rand() % 3;
    switch (index) {
        case 0:
            message[strcspn(message, "")] = 'B';
            break;
        case 1:
            message[strcspn(message, "")] = 'E';
            break;
        case 2:
            message[strcspn(message, "")] = 'G';
            break;
    }
    message[strlen(message)] = '\0';

    // Print the surprise message
    printf("%s! I never would have guessed you had such a great sense of humor. Keep it up, human!\n", message);

    // Play a game of "guess the number"
    int secretNumber = 100;
    int guess = 0;
    do {
        printf("Alright, human, guess the number: ");
        scanf("%d", &guess);
        if (guess > secretNumber) {
            printf("Too high! The number is lower than that. Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! The number is higher than that. Keep trying!\n");
        } else {
            printf("You got it right! The number was %d. Good job!\n", secretNumber);
            break;
        }
    } while (guess != secretNumber);

    // Give a final surprise
    if (guess == secretNumber) {
        printf("Wow, you're a natural at this game! Here's one final surprise: *poof* you just won a lifetime supply of catnip!\n");
    } else {
        printf("Well, it was a good try. Better luck next time, human. Maybe you should stick to playing with mice instead? *giggle*");
    }

    return 0;
}