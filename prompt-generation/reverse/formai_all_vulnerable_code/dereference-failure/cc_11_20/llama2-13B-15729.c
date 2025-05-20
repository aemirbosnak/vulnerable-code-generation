//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 6
#define MAX_QUESTIONS 10
#define MAX_CLUES 5

struct guest {
    char name[50];
    char occupation[50];
    int age;
    int seat_number;
};

struct clue {
    char description[100];
    int value;
};

struct question {
    char text[100];
    int answer;
};

int main() {
    srand(time(NULL));

    // Initialize game variables
    int num_guests = 0;
    struct guest *guests = NULL;
    int num_questions = 0;
    struct question *questions = NULL;
    int num_clues = 0;
    struct clue *clues = NULL;

    // Initialize game state
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].occupation[0] = '\0';
        guests[i].age = 0;
        guests[i].seat_number = 0;
    }

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].text[0] = '\0';
        questions[i].answer = 0;
    }

    for (int i = 0; i < MAX_CLUES; i++) {
        clues[i].description[0] = '\0';
        clues[i].value = 0;
    }

    // Start game loop
    while (1) {
        // Ask player to enter a question
        printf("Ask a question to the guests: ");
        fgets(questions[num_questions].text, 100, stdin);
        num_questions++;

        // Ask guests for answers
        for (int i = 0; i < MAX_GUESTS; i++) {
            printf("Guest %d: ", i + 1);
            fgets(guests[i].name, 50, stdin);
            printf("Guest %d's occupation: ", i + 1);
            fgets(guests[i].occupation, 50, stdin);
            printf("Guest %d's age: ", i + 1);
            scanf("%d", &guests[i].age);
            printf("Guest %d's seat number: ", i + 1);
            scanf("%d", &guests[i].seat_number);
        }

        // Check for clues
        for (int i = 0; i < MAX_CLUES; i++) {
            if (clues[i].description[0] != '\0') {
                printf("Clue %d: %s\n", i + 1, clues[i].description);
                // Add clue to list of possible answers
                for (int j = 0; j < MAX_GUESTS; j++) {
                    if (strstr(guests[j].name, clues[i].description)) {
                        questions[num_questions - 1].answer++;
                    }
                }
            }
        }

        // Check if solution found
        if (questions[num_questions - 1].answer == MAX_GUESTS) {
            printf("Solution found! The murderer is: ");
            for (int i = 0; i < MAX_GUESTS; i++) {
                if (questions[num_questions - 1].answer & (1 << i)) {
                    printf("%d ", i + 1);
                }
            }
            printf("\nGame over! Congratulations, you solved the mystery!)\n");
            break;
        }

        // Print game state
        printf("Game state: ");
        for (int i = 0; i < MAX_GUESTS; i++) {
            printf("%d. %s (%d %d)\n", i + 1, guests[i].name, guests[i].age, guests[i].seat_number);
        }
        printf("\nQuestions: ");
        for (int i = 0; i < num_questions; i++) {
            printf("%d. %s\n", i + 1, questions[i].text);
        }
        printf("\nClues: ");
        for (int i = 0; i < num_clues; i++) {
            printf("%d. %s\n", i + 1, clues[i].description);
        }

        // Get player input to continue game
        printf("Continue? (y/n): ");
        char input[2];
        fgets(input, 2, stdin);
        if (input[0] == 'y' || input[0] == 'Y') {
            continue;
        } else {
            break;
        }
    }

    return 0;
}