//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#define MAX_NAME_LENGTH 50
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_REGISTRATIONS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    int id;
    char answers[MAX_ANSWERS][MAX_NAME_LENGTH];
} Question;

typedef struct {
    Student student;
    Question question;
    char answer[MAX_ANSWERS][MAX_NAME_LENGTH];
    int selectedAnswerIndex;
} Exam;

void registerStudent(Student *students, int *numStudents);
void login(Student students[], int numStudents);
void createQuestion(Question *questions, int *numQuestions);
void selectQuestion(Question questions[], int numQuestions, Exam *exam);
void submitAnswer(Exam *exam);

int main() {
    Student students[MAX_REGISTRATIONS];
    Question questions[MAX_QUESTIONS];
    Exam exam;
    int numStudents = 0;
    int numQuestions = 0;

    while (1) {
        printf("1. Register\n2. Login\n3. Create Question\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerStudent(students, &numStudents);
                break;
            case 2:
                login(students, numStudents);
                break;
            case 3:
                createQuestion(questions, &numQuestions);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    while (1) {
        if (exam.selectedAnswerIndex != -1) {
            submitAnswer(&exam);
            break;
        }

        selectQuestion(questions, numQuestions, &exam);
    }

    return 0;
}

void registerStudent(Student *students, int *numStudents) {
    // registration logic
}

void login(Student students[], int numStudents) {
    // login logic
}

void createQuestion(Question *questions, int *numQuestions) {
    // question creation logic
}

void selectQuestion(Question questions[], int numQuestions, Exam *exam) {
    // question selection logic
}

void submitAnswer(Exam *exam) {
    // answer submission logic
}