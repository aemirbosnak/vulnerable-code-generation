//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct {
    char question[100];
    char option_a[50];
    char option_b[50];
    char option_c[50];
    char option_d[50];
    char answer;
} Question;

typedef struct {
    int question_ids[MAX_QUESTIONS];
    int num_correct_answers;
} Result;

Question questions[] = {
    {"What is the capital of France?", "London", "Berlin", "Paris", "Madrid", 'c'},
    {"What is the currency of Japan?", "Euro", "Yen", "Dollar", "Pound", 'b'},
    {"What is 2 + 2?", "1", "2", "3", "4", 'd'},
    {"What is the tallest mammal on earth?", "Giraffe", "Elephant", "Whale", "Rhino", 'a'},
    {"What is the smallest continent?", "Europe", "Asia", "Africa", "Australia", 'd'},
    {"What is the freezing point of water in Celsius?", "-20", "0", "20", "40", 'b'},
    {"What is the largest planet in our solar system?", "Earth", "Jupiter", "Mars", "Venus", 'b'},
    {"What is the smallest country by land area?", "Monaco", "Vatican City", "San Marino", "Liechtenstein", 'b'},
    {"What is the deepest ocean in the world?", "Arctic", "Indian", "Atlantic", "Pacific", 'd'},
    {"What is the most populated country in the world?", "USA", "Russia", "China", "India", 'c'}
};

void shuffle_array(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generate_question_ids(int question_ids[]) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        question_ids[i] = i;
    }
    shuffle_array(question_ids, MAX_QUESTIONS);
}

void print_question(Question question) {
    printf("%s\n", question.question);
    printf("a) %s\n", question.option_a);
    printf("b) %s\n", question.option_b);
    printf("c) %s\n", question.option_c);
    printf("d) %s\n", question.option_d);
}

char get_answer() {
    char answer;
    printf("Enter your answer (a, b, c or d): ");
    scanf(" %c", &answer);
    return answer;
}

Result take_exam() {
    int question_ids[MAX_QUESTIONS];
    generate_question_ids(question_ids);
    Result result = { {0}, 0 };
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        Question question = questions[question_ids[i]];
        print_question(question);
        char answer = get_answer();
        if (answer == question.answer) {
            result.num_correct_answers++;
        }
    }
    result.question_ids[0] = question_ids[0];
    result.question_ids[1] = question_ids[1];
    result.question_ids[2] = question_ids[2];
    return result;
}

void print_result(Result result) {
    printf("You got %d out of %d questions correct.\n", result.num_correct_answers, MAX_QUESTIONS);
    printf("The ids of the first 3 questions you answered are: %d, %d, %d\n", 
           result.question_ids[0], result.question_ids[1], result.question_ids[2]);
}

int main() {
    printf("Welcome to the Online Exam System!\n");
    printf("You will be presented with %d multiple choice questions.\n", MAX_QUESTIONS);
    printf("Please select the letter corresponding to your answer.\n");
    printf("Good luck!\n\n");
    Result result = take_exam();
    print_result(result);
    return 0;
}