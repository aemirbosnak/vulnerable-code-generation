//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Question {
    char prompt[256];
    char options[4][64];
    int correctOption;
};

struct Player {
    char name[64];
    int score;
};

void printOptions(char options[][64], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c) %s\n", 65+i, options[i]);
    }
}

int main() {
    printf("Welcome to the C Programming Online Examination System!\n");

    // Create questions
    struct Question questions[3] = {
        {"What is the value of the expression 3 * 4 + 2?", {"10", "14", "16", "18"}, 3},
        {"What is the output of the following code?\nint x = 10;\nif (x < 5) { printf(\"Hello\"); }\nelse if (x < 15) { printf(\"World\"); }\nelse { printf(\"!\"); }", {"Hello", "World", "!", "Compilation Error"}, 1},
        {"Which of the following is a storage class specifier in C?", {"auto", "static", "register", "both auto and static"}, 3}
    };

    // Get player name
    struct Player player;
    printf("Please enter your name: ");
    scanf("%s", player.name);
    player.score = 0;

    // Randomize question order
    srand(time(NULL));
    int questionOrder[] = {0, 1, 2};
    for (int i = 0; i < 3; i++) {
        int randomIndex = rand() % 3;
        int temp = questionOrder[i];
        questionOrder[i] = questionOrder[randomIndex];
        questionOrder[randomIndex] = temp;
    }

    // Ask questions
    for (int i = 0; i < 3; i++) {
        printf("\n\nQuestion %d:\n%s\n", i+1, questions[questionOrder[i]].prompt);
        printOptions(questions[questionOrder[i]].options, 4);

        // Get answer
        char choice[2];
        printf("\nYour Answer (A/B/C/D): ");
        scanf("%s", choice);

        // Check answer
        int chosenOption = (int)choice[0] - 65;
        if (chosenOption == questions[questionOrder[i]].correctOption) {
            printf("Correct!\n");
            player.score++;
        } else {
            printf("Incorrect. The correct answer is %c) %s\n", 65+questions[questionOrder[i]].correctOption, questions[questionOrder[i]].options[questions[questionOrder[i]].correctOption]);
        }
    }

    // Print final score
    printf("\n\nCongratulations, %s! Your final score is %d/3.\n", player.name, player.score);

    return 0;
}