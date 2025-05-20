//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Periodic Table elements
typedef struct {
    char* name;
    char symbol;
    int atomicNumber;
} Element;

// quiz questions
typedef struct {
    int num1;
    int num2;
    char operator;
    int correctAnswer;
} Question;

// function declarations
void createTable(Element table[]);
int generateQuestion();
int calculateAnswer(int num1, int num2, char operator);
void printQuestion(Question q, int questionNum);
int askQuestion(Question q, int questionNum);
void printResult(int numCorrectAnswers);

int main() {
    srand(time(NULL)); // seed random number generator
    
    Element table[118];
    createTable(table); // create the Periodic Table
    
    int numQuestions = 10;
    int numCorrectAnswers = 0;
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements in the Periodic Table.\n", numQuestions);
    printf("Please answer with the number corresponding to the correct answer.\n");
    printf("Let's get started!\n\n");
    
    for (int i = 0; i < numQuestions; i++) {
        Question q;
        int questionNum = i + 1;
        int operation = generateQuestion(); // randomly select addition or subtraction
        
        // generate two random numbers
        int num1 = rand() % 118 + 1;
        int num2 = rand() % 118 + 1;
        
        // calculate the correct answer based on the operation selected
        if (operation == 0) {
            q.correctAnswer = num1 + num2;
            q.operator = '+';
        } else {
            q.correctAnswer = num1 - num2;
            q.operator = '-';
        }
        
        // print the question and ask user for input
        printQuestion(q, questionNum);
        numCorrectAnswers += askQuestion(q, questionNum);
        printf("\n");
    }
    
    // print the final score
    printf("Your score is: %d out of %d\n", numCorrectAnswers, numQuestions);
    
    return 0;
}

void createTable(Element table[]) {
    // data from https://en.wikipedia.org/wiki/Periodic_table
    table[0].name = "Hydrogen";
    table[0].symbol = 'H';
    table[0].atomicNumber = 1;
    
    table[1].name = "Helium";
    table[1].symbol = 'He';
    table[1].atomicNumber = 2;
    
    //... and so on for all 118 elements
}

int generateQuestion() {
    // randomly select addition or subtraction
    int operation = rand() % 2;
    return operation;
}

int calculateAnswer(int num1, int num2, char operator) {
    if (operator == '+') {
        return num1 + num2;
    } else {
        return num1 - num2;
    }
}

void printQuestion(Question q, int questionNum) {
    printf("Question %d: What is %d %c %d?\n", questionNum, q.num1, q.operator, q.num2);
}

int askQuestion(Question q, int questionNum) {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    
    if (answer == q.correctAnswer) {
        printf("Correct!\n");
        return 1; // return 1 to add to the score
    } else {
        printf("Incorrect. The correct answer is %d\n", q.correctAnswer);
        return 0; // return 0 to not add to the score
    }
}

void printResult(int numCorrectAnswers) {
    printf("You got %d out of %d questions correct.\n", numCorrectAnswers, 10);
}