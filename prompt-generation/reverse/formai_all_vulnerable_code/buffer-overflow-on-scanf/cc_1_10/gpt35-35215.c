//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
/*C Online Examination System*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*function declarations*/
void menu(void);
void registerUser(void);
void loginUser(void);
void startExam(void);
int generateRandomNumber(int);
void displayQuestion(int, int);
int inputAnswer(void);
void submitExam(int);

/*global variables*/
char username[20];
char password[20];
int no_of_questions = 5;
int total_marks = 0;

/*structure to store questions*/
struct question {
    char text[100];
    char options[4][50];
    int correct_answer;
};

/*array to store questions*/
struct question questions[10] = {
    {"What is the capital of India?", {"A. Mumbai", "B. Delhi", "C. Kolkata", "D. Chennai"}, 2},
    {"Who is the CEO of Tesla?", {"A. Elon Musk", "B. Bill Gates", "C. Mark Zuckerberg", "D. Jeff Bezos"}, 1},
    {"What is the currency of Japan?", {"A. Dollar", "B. Yen", "C. Pound", "D. Euro"}, 1},
    {"What is the largest planet in our solar system?", {"A. Earth", "B. Jupiter", "C. Mars", "D. Uranus"}, 1},
    {"What is the world's tallest mountain?", {"A. Mount Everest", "B. Mount Kilimanjaro", "C. Mount Fuji", "D. Mount Aconcagua"}, 1}
};

int main() {
    menu();
    return 0;
}

/*function to display the menu and get input from user*/
void menu(void) {
    int choice;
    printf("Welcome to the Online Examination System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: registerUser();
                break;
        case 2: loginUser();
                break;
        case 3: exit(0);
        default: printf("Invalid choice\n");
                 menu();
    }
}

/*function to register a new user*/
void registerUser(void) {
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Registration successful\n");
    menu();
}

/*function to verify login credentials*/
void loginUser(void) {
    char input_username[20];
    char input_password[20];
    printf("Enter your username: ");
    scanf("%s", input_username);
    printf("Enter your password: ");
    scanf("%s", input_password);
    if(strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
        printf("Login successful\n");
        startExam();
    }
    else {
        printf("Invalid username or password\n");
        menu();
    }
}

/*function to start the exam*/
void startExam(void) {
    int i, question_no, answer;
    printf("Welcome to the Exam\n");
    printf("The exam contains %d multiple choice questions\n", no_of_questions);
    srand(time(NULL)); /*seeding the random number generator*/
    for(i = 0; i < no_of_questions; i++) {
        question_no = generateRandomNumber(no_of_questions); /*generate a random question number*/
        printf("Question %d: ", i+1);
        displayQuestion(question_no, i+1); /*display the question*/
        answer = inputAnswer(); /*get the user's answer*/
        if(answer == questions[question_no].correct_answer) { /*compare the user's answer with the correct answer*/
            printf("Your answer is correct\n");
            total_marks++; /*increment the marks by 1*/
        }
        else {
            printf("Your answer is incorrect\n");
        }
    }
    submitExam(total_marks); /*submit the exam and display the results*/
}

/*function to generate a random number between 0 and max_number*/
int generateRandomNumber(int max_number) {
    int random_number;
    random_number = rand() % max_number;
    return random_number;
}

/*function to display a question*/
void displayQuestion(int question_no, int question_serial) {
    int i;
    printf("%s\n", questions[question_no].text); /*display the question text*/
    for(i = 0; i < 4; i++) {
        printf("%s\n", questions[question_no].options[i]); /*display the options*/
    }
}

/*function to get input from user*/
int inputAnswer(void) {
    int answer;
    printf("Enter your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    switch(answer) {
        case 'A':
        case 'a': return 1;
        case 'B':
        case 'b': return 2;
        case 'C':
        case 'c': return 3;
        case 'D':
        case 'd': return 4;
        default: printf("Invalid answer. Please enter A/B/C/D\n");
                 return inputAnswer(); /*recursive call to inputAnswer function*/
    }
}

/*function to submit the exam and display the results*/
void submitExam(int marks) {
    printf("Your exam is submitted\n");
    printf("Total marks obtained: %d/%d\n", marks, no_of_questions);
    if(marks >= 3) /*passing marks is 3 out of 5*/
        printf("Congratulations! You have passed the exam\n");
    else
        printf("Sorry! You have failed the exam\n");
    menu();
}