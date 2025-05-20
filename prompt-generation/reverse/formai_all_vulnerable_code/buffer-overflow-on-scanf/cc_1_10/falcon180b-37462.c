//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4

// structure to hold question and answer information
typedef struct {
    char question[100];
    int num_options;
    char options[MAX_OPTIONS][100];
    int answer_index;
} Question;

// structure to hold student information
typedef struct {
    char name[50];
    int score;
} Student;

// function prototypes
void read_questions(Question questions[]);
void display_question(Question question);
int get_answer(Question question, int answer_index);
void grade_question(Question question, int answer_index);
void display_results(Student students[], int num_students);

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[100];
    int num_questions, num_students;

    // read in number of questions
    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    // read in questions
    read_questions(questions);

    // read in number of students
    printf("Enter number of students: ");
    scanf("%d", &num_students);

    // loop through each student
    for (int i = 0; i < num_students; i++) {
        // get student name
        printf("Enter student name: ");
        scanf("%s", students[i].name);

        // take exam
        int score = 0;
        for (int j = 0; j < num_questions; j++) {
            display_question(questions[j]);
            int answer_index = get_answer(questions[j], 0);
            grade_question(questions[j], answer_index);
            if (answer_index == questions[j].answer_index) {
                score++;
            }
        }

        // display results
        printf("\n%s's score: %d\n", students[i].name, score);
    }

    // display overall results
    printf("\nOverall results:\n");
    display_results(students, num_students);

    return 0;
}

void read_questions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %d %s %s %d", questions[count].question, &questions[count].num_options, questions[count].options[0], questions[count].options[1], &questions[count].answer_index)!= EOF) {
        count++;
        if (count >= MAX_QUESTIONS) {
            printf("Maximum number of questions exceeded.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void display_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < question.num_options; i++) {
        printf("%d. %s\n", i+1, question.options[i]);
    }
}

int get_answer(Question question, int answer_index) {
    printf("Enter your answer: ");
    scanf("%d", &answer_index);

    if (answer_index < 1 || answer_index > question.num_options) {
        printf("Invalid answer.\n");
        return -1;
    }

    return answer_index;
}

void grade_question(Question question, int answer_index) {
    if (answer_index == question.answer_index) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer is %d.\n", question.answer_index+1);
    }
}

void display_results(Student students[], int num_students) {
    printf("\nResults:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}