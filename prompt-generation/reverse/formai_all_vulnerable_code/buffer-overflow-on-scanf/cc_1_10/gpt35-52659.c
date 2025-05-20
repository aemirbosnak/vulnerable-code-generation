//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 5

int num_questions = 0;
char questions[MAX_QUESTIONS][255]; 
char options[MAX_QUESTIONS][MAX_OPTIONS][255];
int answers[MAX_QUESTIONS];

int score = 0;

void add_question(char* question, char* option1, char* option2, char* option3, char* option4, int answer){
    if(num_questions == MAX_QUESTIONS){
        printf("Maximum limit of questions reached\n");
        return;
    }
    strcpy(questions[num_questions], question);
    strcpy(options[num_questions][0], option1);
    strcpy(options[num_questions][1], option2);
    strcpy(options[num_questions][2], option3);
    strcpy(options[num_questions][3], option4);
    answers[num_questions] = answer;
    num_questions++;
}

int main(){
    char name[255];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s!\n\n", name);

    add_question("What is the capital of India?", "Delhi", "Mumbai", "Kolkata", "Chennai", 0);
    add_question("What is the smallest planet in our solar system?", "Mercury", "Venus", "Mars", "Jupiter", 0);
    add_question("Who painted the Mona Lisa?", "Vincent Van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Michelangelo", 1);
    add_question("What is the largest mammal in the world?", "Elephant", "Whale", "Giraffe", "Lion", 1);
    add_question("What is the currency of Japan?", "Yen", "Dollar", "Euro", "Pound", 0);

    printf("Instructions:\n");
    printf("1. There are %d questions in total.\n", num_questions);
    printf("2. Each question has 4 options, out of which only one is correct.\n");
    printf("3. For each correct answer, you will get 10 points.\n");
    printf("4. For each wrong answer, you will lose 5 points.\n");
    printf("5. All the best!\n\n");

    for(int i = 0; i < num_questions; i++){
        printf("%d. %s\n", i+1, questions[i]);
        for(int j = 0; j < 4; j++){
            printf("%c) %s\n", 'A'+j, options[i][j]);
        }
        char answer;
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        if(answer == answers[i]+'A'){
            score += 10;
            printf("Correct answer! +10 points\n\n");
        }
        else{
            score -= 5;
            printf("Wrong answer! -5 points\n\n");    
        }
    }

    printf("\n\nYour final score is %d\n", score);

    return 0;
}