//FormAI DATASET v1.0 Category: Online Examination System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct for student information
typedef struct {
    char name[50];
    int roll_number;
    float marks_obtained;
    float total_marks;
} student;

//Function for displaying instructions before the exam
void display_instructions() {
    printf("Welcome to the C Online Examination System!\n");
    printf("Please read the instructions carefully before starting the exam.\n");
    printf("1. This is a C programming exam with a total of 50 questions.\n");
    printf("2. You have 60 minutes to complete the exam.\n");
    printf("3. Each correct answer will give you 2 marks and each wrong answer will deduct 1 mark.\n");
    printf("4. To select an answer, type the option (a, b, c or d) and press enter.\n");
    printf("5. Once you start the exam, you cannot exit until you complete it.\n");
    printf("6. Good luck!\n\n");
}

//Function for generating questions
void generate_questions() {
    char questions[50][200] = {
        "What keyword is used to declare a variable constant in C?",
        "What is the output of the following code: int x=2, y=5; printf(\"%d\", x+y);",
        "What is the output of the following code: int x=5; if(x>3 && x<7) {printf(\"Hello World!\");}",
        "What is a pointer variable in C?",
        "What is the output of the following code: int x=10, y=5; printf(\"%d\", x/y);",
        //...and so on
    };
    char options[50][4][50] = {
        {"const", "static", "final", "volatile"},
        {"7", "2", "5", "10"},
        {"Hello World!", "", "", ""},
        {"A variable that stores address of another variable", "A variable that stores a value", "A variable that stores a text string", "A variable that stores a function pointer"},
        {"2", "5", "1", "Error - Division by 0"},
        //...and so on
    };
    char answers[50] = {'a', 'd', 'a', 'a', '4', //...and so on
    };
    int i, j;
    char response;
    int num_questions = 50;
    float marks_obtained = 0;
    float total_marks = num_questions * 2;

    //Loop through each question
    for(i=0; i<num_questions; i++) {
        printf("%d) %s\n", i+1, questions[i]);
        for(j=0; j<4; j++) {
            printf("    %c) %s\n", 'a'+j, options[i][j]);
        }

        //Get user's response
        printf("Your answer: ");
        scanf(" %c", &response);

        //Check if the user's response is correct
        if(response == answers[i]) {
            printf("Correct answer! +2 marks\n");
            marks_obtained += 2;
        } else {
            printf("Wrong answer :( -1 mark\n");
            marks_obtained -= 1;
        }
    }

    printf("\n\nCongratulations, you have completed the exam!\n");
    printf("Total marks obtained: %.2f/%.2f\n", marks_obtained, total_marks);

    //Save student's results to a file
    FILE *fp;
    student stu;
    printf("\n\nPlease enter your name: ");
    scanf("%s", stu.name);
    printf("Please enter your roll number: ");
    scanf("%d", &stu.roll_number);
    stu.marks_obtained = marks_obtained;
    stu.total_marks = total_marks;
    fp = fopen("results.txt", "a");
    fwrite(&stu, sizeof(student), 1, fp);
    fclose(fp);
}

//Main function
int main() {
    char response;
    printf("Welcome to the C Online Examination System!\n\n");
    printf("Do you want to start the exam (y/n)? ");
    scanf(" %c", &response);

    if(response == 'y') {
        display_instructions();
        generate_questions();
    } else {
        printf("Thank you for visiting the C Online Examination System!\n");
    }

    return 0;
}