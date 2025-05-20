//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *question;
    char *answer;
} QuestionAnswerPair;

QuestionAnswerPair quesAnsList[] = {
    {"What is your question? ", "The answer is hidden deep within your soul."},
    {"Will I find love soon? ", "Love finds those who seek it not."},
    {"Should I take this job offer? ", "The universe conspires in your favor."},
    {"Will I pass my exams? ", "Knowledge is a treasure, seek it with all your heart."},
    {"What is the meaning of life? ", "To seek and to find, that is the meaning of life."},
    {"Will I win the lottery? ", "Money can't buy happiness, but it sure is nice to have a little extra."},
    {"What is the future holding for me? ", "The future is what you make it, so make it bright!"},
    {"Should I trust this person? ", "Trust your instincts, they are often right."},
    {"What should I do today? ", "Do something that makes you happy, no matter how small."},
    {"What is my spirit animal? ", "Your spirit animal is the one that speaks to your soul."}
};

int randomNumberGenerator(int limit) {
    return rand() % limit;
}

void printFortune(QuestionAnswerPair quesAns) {
    printf("\nQuestion: %s", quesAns.question);
    printf("\nAnswer: %s\n", quesAns.answer);
}

void recursiveFortuneTeller(int index) {
    if (index >= 11) {
        printFortune(quesAnsList[index % 11]);
        return;
    }

    printf("\nQuestion: %s", quesAnsList[index].question);
    printf("\nAnswer: %s\n", quesAnsList[index].answer);
    recursiveFortuneTeller(index + 1);
}

int main() {
    srand(time(NULL));
    int userChoice;

    printf("Welcome to the Recursive Automated Fortune Teller!\n");
    printf("Please choose a question number from 1 to 11:\n");
    scanf("%d", &userChoice);

    if (userChoice >= 1 && userChoice <= 11) {
        recursiveFortuneTeller(userChoice);
    } else {
        printf("Invalid choice! Please try again.\n");
        main();
    }

    return 0;
}