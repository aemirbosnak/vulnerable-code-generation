//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char question[100];
    int answer;
} Question;

Question questions[] = {
    {"Will I win the lottery?", 1},
    {"Will my crush text me back?", 0},
    {"Should I quit my job?", 1},
    {"Will I get a promotion?", 1},
    {"Will my favorite team win the championship?", 1},
    {"Is there life after death?", 1},
    {"Should I marry my partner?", 1},
    {"Will I get a good grade on this test?", 1},
    {"Will my car start in the morning?", 1},
    {"Will my dog live a long life?", 1},
    {"Is my boss secretly my father?", 0}
};

int randint(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));
    int user_choice;
    int index;

    printf("***** WELCOME TO THE SHOCKED AUTOMATED FORTUNE TELLER *****\n");
    printf("** Do not be alarmed if you get a shocking answer! **\n");
    printf("** Press a number from 1 to 11 to ask your question **\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s", questions[randint(0, 10)].question);
        scanf("%d", &user_choice);

        if (user_choice < 1 || user_choice > 11) {
            printf("Invalid choice! Try again.\n");
            i--;
            continue;
        }

        index = user_choice - 1;
        printf("Answer: ");

        if (questions[index].answer) {
            printf("Yes, you will be %s!\n", questions[index].question[strcspn(questions[index].question, "?")] == 'w' ? "shocked" : "happy");
        } else {
            printf("No, you will be %s!\n", "shocked");
            printf("** SHOCK! **\n");
            printf("** You better prepare yourself for the unexpected! **\n");
        }
    }

    printf("***** THANK YOU FOR USING THE SHOCKED AUTOMATED FORTUNE TELLER *****\n");
    return 0;
}