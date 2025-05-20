//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

void print_table(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please select an option:\n");
    printf("1. Start Quiz\n");
    printf("2. View Scores\n");
    printf("3. Exit\n");
}

int main() {
    srand(time(NULL));

    int user_score = 0;
    int num_questions = 10;

    char choice;
    do {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                for (int i = 0; i < num_questions; i++) {
                    int element_number = rand() % 118;
                    char element_name[3];
                    sprintf(element_name, "%c%d", 'A' + element_number, element_number + 1);

                    printf("Question %d: What is the symbol for element %s?\n", i + 1, element_name);
                    char user_answer[3];
                    scanf(" %s", user_answer);

                    if (tolower(user_answer[0]) == tolower(element_name[0])) {
                        user_score++;
                    }
                }
                printf("You scored %d out of %d questions correct!\n", user_score, num_questions);
                break;

            case '2':
                printf("Sorry, this feature is not yet implemented.\n");
                break;

            case '3':
                printf("Thank you for playing the Periodic Table Quiz!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= '3');

    return 0;
}