//FormAI DATASET v1.0 Category: Online Examination System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question {
    char q[200];
    char op1[100];
    char op2[100];
    char op3[100];
    char op4[100];
    int ans;
};

struct User {
    char name[100];
    int marks;
};

void displayQuestion(struct Question quest) {
    printf("\n%s\n", quest.q);
    printf("1. %s\n", quest.op1);
    printf("2. %s\n", quest.op2);
    printf("3. %s\n", quest.op3);
    printf("4. %s\n", quest.op4);
}

int main() {
    int i, count, option, userAnswer, correct = 0, wrong = 0;
    struct User user;

    printf("Enter your name: ");
    scanf("%[^\n]%*c", user.name);

    printf("\nWelcome %s!\n", user.name);

    printf("\nInstructions:\n1. Select the option number for the correct answer.\n2. Each correct answer will add 4 marks to your total score, while each wrong answer will deduct 1 mark.\n3. You can't skip or change an answer once selected.\n4. The exam consists of 5 questions.\n\nPress enter to continue...");
    getchar();

    struct Question q[5] = {
        {"What is the capital of India?", "New Delhi", "Mumbai", "Chennai", "Kolkata", 1},
        {"What is the largest bird alive?", "Ostrich", "Emu", "Albatross", "Condor", 1},
        {"Which is the smallest state in India by area?", "Goa", "Sikkim", "Nagaland", "Manipur", 2},
        {"What is the pH value of water?", "9", "7", "5", "3", 2},
        {"Who was the first president of India?", "S. Radhakrishnan", "Rajendra Prasad", "Zakir Hussain", "V.V. Giri", 2}
    };

    count = sizeof(q)/sizeof(q[0]);
    
    for(i = 0; i < count; i++) {
        displayQuestion(q[i]);

        printf("\nEnter your answer: ");
        scanf("%d", &userAnswer);

        if(userAnswer == q[i].ans) {
            printf("You are correct!\n");
            user.marks += 4;
            correct++;
        }
        else {
            printf("You are wrong!\n");
            user.marks -= 1;
            wrong++;
        }

        printf("Your current score is %d.\n", user.marks);
    }

    printf("\n\nThank you for taking the exam, %s!\n\nFinal score: %d out of %d.\n\nNumber of correct answers: %d\nNumber of wrong answers: %d\n", user.name, user.marks, count*4, correct, wrong);

    return 0;
}