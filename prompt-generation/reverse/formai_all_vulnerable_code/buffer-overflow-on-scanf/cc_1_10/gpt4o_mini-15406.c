//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION_LENGTH 50
#define MAX_NAME_LENGTH 100

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    int answer; // 0-indexed choice
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Participant;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int question_count;
} QuestionBank;

// Function prototypes
void add_question(QuestionBank *qb);
void take_exam(QuestionBank qb, Participant *participant);
void display_result(Participant participant);
void clear_input_buffer();

int main() {
    QuestionBank qb;
    qb.question_count = 0;
    
    Participant participant;
    
    int choice;
    do {
        printf("\nOnline Examination System\n");
        printf("1. Add Question\n");
        printf("2. Take Exam\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_question(&qb);
                break;
            case 2:
                printf("Enter your name: ");
                fgets(participant.name, MAX_NAME_LENGTH, stdin);
                participant.name[strcspn(participant.name, "\n")] = '\0'; // Remove newline
                participant.score = 0;
                take_exam(qb, &participant);
                break;
            case 3:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}

void add_question(QuestionBank *qb) {
    if (qb->question_count >= MAX_QUESTIONS) {
        printf("Question bank is full. Cannot add more questions.\n");
        return;
    }

    Question new_question;
    printf("Enter the question: ");
    fgets(new_question.question, sizeof(new_question.question), stdin);
    new_question.question[strcspn(new_question.question, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < 4; i++) {
        printf("Enter option %d: ", i + 1);
        fgets(new_question.options[i], MAX_OPTION_LENGTH, stdin);
        new_question.options[i][strcspn(new_question.options[i], "\n")] = '\0'; // Remove newline
    }

    printf("Enter the correct option number (1-4): ");
    scanf("%d", &new_question.answer);
    clear_input_buffer();
    new_question.answer--; // Convert to 0-indexed

    qb->questions[qb->question_count] = new_question;
    qb->question_count++;
    printf("Question added successfully!\n");
}

void take_exam(QuestionBank qb, Participant *participant) {
    printf("\nStarting Exam for %s\n", participant->name);
    for (int i = 0; i < qb.question_count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, qb.questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, qb.questions[i].options[j]);
        }

        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        clear_input_buffer();
        
        if (answer - 1 == qb.questions[i].answer) {
            participant->score++;
        }
    }
    printf("Exam finished!\n");
    display_result(*participant);
}

void display_result(Participant participant) {
    printf("\nExam Results for %s:\n", participant.name);
    printf("Total Score: %d\n", participant.score);
}

void clear_input_buffer() {
    // Clear the input buffer to handle any extra characters left in it
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}