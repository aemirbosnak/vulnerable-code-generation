//FormAI DATASET v1.0 Category: Online Examination System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {               //Structure to store one question and its answer choices
    char ques[1000], ans1[1000], ans2[1000], ans3[1000], ans4[1000];
    int correct;
};

struct student {                //Structure to store the details of the student
    char name[50], roll[20];
    int marks;
};

struct results {                //Structure to store the results of one student
    struct student s;
    int marks;
};

int main() {
    struct question q[20];      //Array of questions
    struct results r[50];       //Array to store the results of each student

    for(int i=0; i<20; i++) {   //Loop to input the questions and their answer choices
        printf("Enter Question %d: ", i+1);
        fgets(q[i].ques, 1000, stdin);            //Input question
        printf("\nEnter Option 1: ");
        fgets(q[i].ans1, 1000, stdin);            //Input option 1
        printf("\nEnter Option 2: ");
        fgets(q[i].ans2, 1000, stdin);            //Input option 2
        printf("\nEnter Option 3: ");
        fgets(q[i].ans3, 1000, stdin);            //Input option 3
        printf("\nEnter Option 4: ");
        fgets(q[i].ans4, 1000, stdin);            //Input option 4
        printf("\nEnter Correct Option Number: ");
        scanf("%d", &q[i].correct);               //Input correct option number
        getchar();                                //Flush the buffer
    }

    int n, m;
    printf("\nEnter Number of Students: ");
    scanf("%d", &n);               //Input number of students

    for(int i=0; i<n; i++) {       //Loop to input the details of each student
        printf("Enter Details for Student %d:\n", i+1);
        getchar();                                //Flush the buffer
        printf("Name: ");
        fgets(r[i].s.name, 50, stdin);            //Input name of student
        printf("Roll Number: ");
        fgets(r[i].s.roll, 20, stdin);            //Input roll number of student
        r[i].marks = 0;                            //Initialize marks to 0

        for(int j=0; j<20; j++) {     //Loop to display each question and its answer choices

            printf("\nQuestion %d: %s", j+1, q[j].ques);
            printf("\nOption 1: %s", q[j].ans1);
            printf("Option 2: %s", q[j].ans2);
            printf("Option 3: %s", q[j].ans3);
            printf("Option 4: %s", q[j].ans4);
            printf("\nEnter Your Answer: ");
            scanf("%d", &m);                 //Input the answer chosen by student
            if(m==q[j].correct)              //If answer is correct, increment marks
                r[i].marks++;
            getchar();                        //Flush the buffer
        }
    }

    printf("\n\nResults:");
    for(int i=0; i<n; i++) {            //Loop to display the results of each student
        printf("\nName: %s", r[i].s.name);
        printf("Roll Number: %s", r[i].s.roll);
        printf("Marks: %d\n", r[i].marks);
    }

    return 0;
}