//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int question_id;
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

typedef struct {
    int student_id;
    char *student_name;
    int num_questions;
    Question *questions;
    int *answers;
    int score;
} Student;

pthread_mutex_t lock;
int num_students = 0;
Student *students = NULL;

void *student_thread(void *arg) {
    int student_id = *(int *)arg;
    Student *student = &students[student_id];

    for (int i = 0; i < student->num_questions; i++) {
        Question *question = &student->questions[i];
        int answer;

        pthread_mutex_lock(&lock);
        printf("Question %d: %s\n", question->question_id, question->question);
        for (int j = 0; j < question->num_options; j++) {
            printf("%d. %s\n", j + 1, question->options[j]);
        }
        printf("Enter your answer: ");
        scanf("%d", &answer);
        student->answers[i] = answer;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    int num_questions;
    Question *questions;
    int num_students;
    Student *students;
    pthread_t *threads;
    int *student_ids;
    int i;

    // Read the number of questions
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Allocate memory for the questions
    questions = (Question *)malloc(sizeof(Question) * num_questions);

    // Read the questions
    for (i = 0; i < num_questions; i++) {
        // Read the question ID
        printf("Enter the question ID: ");
        scanf("%d", &questions[i].question_id);

        // Read the question text
        printf("Enter the question text: ");
        scanf(" %[^\n]s", questions[i].question);

        // Read the number of options
        printf("Enter the number of options: ");
        scanf("%d", &questions[i].num_options);

        // Allocate memory for the options
        questions[i].options = (char **)malloc(sizeof(char *) * questions[i].num_options);

        // Read the options
        for (int j = 0; j < questions[i].num_options; j++) {
            // Allocate memory for the option
            questions[i].options[j] = (char *)malloc(100);

            // Read the option text
            printf("Enter option %d: ", j + 1);
            scanf(" %[^\n]s", questions[i].options[j]);
        }

        // Read the correct option
        printf("Enter the correct option: ");
        scanf("%d", &questions[i].correct_option);
    }

    // Read the number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Allocate memory for the students
    students = (Student *)malloc(sizeof(Student) * num_students);

    // Read the students
    for (i = 0; i < num_students; i++) {
        // Read the student ID
        printf("Enter the student ID: ");
        scanf("%d", &students[i].student_id);

        // Read the student name
        printf("Enter the student name: ");
        scanf(" %[^\n]s", students[i].student_name);

        // Set the number of questions
        students[i].num_questions = num_questions;

        // Allocate memory for the questions
        students[i].questions = questions;

        // Allocate memory for the answers
        students[i].answers = (int *)malloc(sizeof(int) * num_questions);

        // Set the score to 0
        students[i].score = 0;
    }

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Allocate memory for the threads
    threads = (pthread_t *)malloc(sizeof(pthread_t) * num_students);

    // Allocate memory for the student IDs
    student_ids = (int *)malloc(sizeof(int) * num_students);

    // Create the threads
    for (i = 0; i < num_students; i++) {
        student_ids[i] = i;
        pthread_create(&threads[i], NULL, student_thread, &student_ids[i]);
    }

    // Join the threads
    for (i = 0; i < num_students; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    // Calculate the scores
    for (i = 0; i < num_students; i++) {
        Student *student = &students[i];

        for (int j = 0; j < student->num_questions; j++) {
            if (student->answers[j] == student->questions[j].correct_option) {
                student->score++;
            }
        }
    }

    // Print the results
    for (i = 0; i < num_students; i++) {
        Student *student = &students[i];

        printf("Student %d (%s): %d/%d\n", student->student_id, student->student_name, student->score, student->num_questions);
    }

    // Free the memory
    for (i = 0; i < num_questions; i++) {
        for (int j = 0; j < questions[i].num_options; j++) {
            free(questions[i].options[j]);
        }
        free(questions[i].options);
    }
    free(questions);
    for (i = 0; i < num_students; i++) {
        free(students[i].answers);
    }
    free(students);
    free(threads);
    free(student_ids);

    return 0;
}