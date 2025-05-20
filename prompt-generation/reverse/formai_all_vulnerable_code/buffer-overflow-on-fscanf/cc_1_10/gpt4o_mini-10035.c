//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 255
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[4][MAX_ANSWER_LENGTH];
    char correctAnswer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
int questionCount = 0;

// Function prototypes
void loadQuestions(const char *filename);
void addQuestion();
void startExam();
void displayResults(Student student);
char getUserInput(char *prompt);

int main() {
    int choice;

    while (1) {
        printf("\nOnline Examination System\n");
        printf("1. Load Questions\n");
        printf("2. Add Question\n");
        printf("3. Start Exam\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                loadQuestions("questions.txt");
                break;
            case 2:
                addQuestion();
                break;
            case 3:
                startExam();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Load questions from a file
void loadQuestions(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fscanf(file, " %[^\n] %[^\n] %[^\n] %[^\n] %c\n", 
                  questions[questionCount].question, 
                  questions[questionCount].choices[0], 
                  questions[questionCount].choices[1], 
                  questions[questionCount].choices[2], 
                  &questions[questionCount].correctAnswer) != EOF) {
        questionCount++;
    }

    fclose(file);
    printf("Loaded %d questions successfully.\n", questionCount);
}

// Add a new question to the question bank
void addQuestion() {
    if (questionCount >= MAX_QUESTIONS) {
        printf("Maximum question limit reached!\n");
        return;
    }

    printf("Enter a question: ");
    fgets(questions[questionCount].question, MAX_ANSWER_LENGTH, stdin);
    questions[questionCount].question[strcspn(questions[questionCount].question, "\n")] = 0; // Remove newline

    for (int i = 0; i < 4; i++) {
        printf("Enter choice %d: ", i + 1);
        fgets(questions[questionCount].choices[i], MAX_ANSWER_LENGTH, stdin);
        questions[questionCount].choices[i][strcspn(questions[questionCount].choices[i], "\n")] = 0; // Remove newline
    }

    printf("Enter correct answer (A, B, C, D): ");
    scanf(" %c", &questions[questionCount].correctAnswer);
    getchar(); // Consume newline

    questionCount++;
    printf("Question added successfully!\n");
}

// Start the examination process
void startExam() {
    Student student;
    student.score = 0;
    
    printf("Enter student's name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline

    for (int i = 0; i < questionCount; i++) {
        printf("\nQ%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  %c. %s\n", 'A' + j, questions[i].choices[j]);
        }

        char answer = getUserInput("Your answer (A/B/C/D): ");
        if (answer == questions[i].correctAnswer) {
            student.score++;
        }
    }

    displayResults(student);
}

// Get user input with a prompt
char getUserInput(char *prompt) {
    char answer;
    printf("%s", prompt);
    scanf(" %c", &answer);
    getchar(); // Consume newline
    return answer;
}

// Display the results of the exam
void displayResults(Student student) {
    printf("\nResults for %s:\n", student.name);
    printf("Score: %d out of %d\n", student.score, questionCount);
}