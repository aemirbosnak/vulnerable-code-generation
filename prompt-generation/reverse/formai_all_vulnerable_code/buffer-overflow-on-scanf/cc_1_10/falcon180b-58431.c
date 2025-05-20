//Falcon-180B DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 3
#define DELAY_MS 1000

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to prompt the user for input and validate it
int get_input(char* prompt, int min, int max) {
    int input;

    printf("%s", prompt);
    if (scanf("%d", &input)!= 1 || input < min || input > max) {
        printf("Invalid input.\n");
        return -1;
    }

    return input;
}

int main() {
    srand(time(0));

    int tries = 0;
    while (tries < MAX_TRIES) {
        int num1 = rand_int(1, 100);
        int num2 = rand_int(1, 100);

        int correct_answer = num1 + num2;

        int user_answer = 0;
        while (user_answer!= correct_answer && tries < MAX_TRIES) {
            printf("What is %d + %d?\n", num1, num2);
            user_answer = get_input("", 0, 200);

            if (user_answer == -1) {
                printf("Too many incorrect attempts. Exiting program.\n");
                return 1;
            }

            if (user_answer!= correct_answer) {
                printf("Incorrect. Try again.\n");
            }

            tries++;
            if (tries == MAX_TRIES) {
                printf("Maximum number of tries reached. Exiting program.\n");
                return 1;
            }

            usleep(DELAY_MS * 1000);
        }

        if (user_answer == correct_answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
        }

        usleep(DELAY_MS * 1000);
    }

    return 0;
}