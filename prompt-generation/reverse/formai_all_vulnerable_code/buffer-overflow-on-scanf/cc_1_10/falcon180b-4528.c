//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENTS 50

//Student structure
struct student{
    int roll_no;
    char name[50];
};

//Question structure
struct question{
    char question[200];
    int option1, option2, option3, option4, correct_answer;
};

//Exam structure
struct exam{
    int num_questions;
    struct question questions[50];
};

//Main function
int main(){
    int num_students, num_exams, i, j, k, choice;
    char filename[50];
    struct student students[MAX_STUDENTS];
    struct exam exams[MAX_STUDENTS];

    //Initializing variables
    num_students = 0;
    num_exams = 0;

    //Menu driven program
    while(1){
        printf("\n\nOnline Examination System\n");
        printf("1. Add Student\n2. Add Exam\n3. View Students\n4. View Exams\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter student name: ");
                scanf("%s", students[num_students].name);
                printf("Enter student roll number: ");
                scanf("%d", &students[num_students].roll_no);
                num_students++;
                break;

            case 2:
                printf("\nEnter exam name: ");
                scanf("%s", exams[num_exams].questions[0].question);
                printf("Enter number of questions: ");
                scanf("%d", &exams[num_exams].num_questions);

                for(i=1; i<=exams[num_exams].num_questions; i++){
                    printf("\nEnter question %d: ", i);
                    scanf("%s", exams[num_exams].questions[i].question);
                    printf("Enter option 1: ");
                    scanf("%d", &exams[num_exams].questions[i].option1);
                    printf("Enter option 2: ");
                    scanf("%d", &exams[num_exams].questions[i].option2);
                    printf("Enter option 3: ");
                    scanf("%d", &exams[num_exams].questions[i].option3);
                    printf("Enter option 4: ");
                    scanf("%d", &exams[num_exams].questions[i].option4);
                    printf("Enter correct answer (1/2/3/4): ");
                    scanf("%d", &exams[num_exams].questions[i].correct_answer);
                }
                num_exams++;
                break;

            case 3:
                printf("\nStudent Name\tRoll No\n");
                for(i=0; i<num_students; i++){
                    printf("%s\t%d\n", students[i].name, students[i].roll_no);
                }
                break;

            case 4:
                printf("\nExam Name\n");
                for(i=0; i<num_exams; i++){
                    printf("%s\n", exams[i].questions[0].question);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}