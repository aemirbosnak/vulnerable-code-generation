//FormAI DATASET v1.0 Category: Online Examination System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[50];
}Question;

typedef struct{
    char name[50];
    int age;
    char email[100];
    int score;
}Candidate;

void displayMenu();
int takeTest(Candidate*);
void saveResult(Candidate);
void viewResult();

int main()
{
    int choice;
    Candidate c;
    while(1){
        displayMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                c.score = takeTest(&c);
                saveResult(c);
                break;
            case 2:
                viewResult();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

void displayMenu(){
    printf("\nWelcome to the Online C Examination System!\n");
    printf("1. Take Test\n");
    printf("2. View Result\n");
    printf("3. Exit\n");
    printf("Enter your choice(1-3): ");
}

int takeTest(Candidate* c){
    int i, score=0;
    Question q[5];
    strcpy(q[0].question, "What is the output of printf(\"%d\", sizeof(long)?\n");
    strcpy(q[0].option1, "2");
    strcpy(q[0].option2, "4");
    strcpy(q[0].option3, "8");
    strcpy(q[0].option4, "Depends on the compiler");
    strcpy(q[0].answer, "8");

    strcpy(q[1].question, "What is the size of int variable?\n");
    strcpy(q[1].option1, "4 bytes");
    strcpy(q[1].option2, "2 bytes");
    strcpy(q[1].option3, "1 byte");
    strcpy(q[1].option4, "Depends on the compiler");
    strcpy(q[1].answer, "4 bytes");

    strcpy(q[2].question, "What is the output of printf(\"%f\", 3/4)?\n");
    strcpy(q[2].option1, "0.75");
    strcpy(q[2].option2, "0");
    strcpy(q[2].option3, "1");
    strcpy(q[2].option4, "Depends on the compiler");
    strcpy(q[2].answer, "0.000000");

    strcpy(q[3].question, "Which operator is used to access structure elements?\n");
    strcpy(q[3].option1, ".");
    strcpy(q[3].option2, "->");
    strcpy(q[3].option3, "*");
    strcpy(q[3].option4, "&");
    strcpy(q[3].answer, ".");

    strcpy(q[4].question, "What is the output of printf(\"%c\", 65)?\n");
    strcpy(q[4].option1, "A");
    strcpy(q[4].option2, "65");
    strcpy(q[4].option3, "a");
    strcpy(q[4].option4, "None of the above");
    strcpy(q[4].answer, "A");

    printf("\nInstructions:\n");
    printf("1. The test consists of 5 multiple choice questions.\n");
    printf("2. Each question carries 1 point.\n");
    printf("3. There is no negative marking.\n");
    printf("4. Enter the number of the option as your answer.\n\n");

    printf("Enter your name: ");
    scanf("%s", c->name);
    printf("Enter your age: ");
    scanf("%d", &c->age);
    printf("Enter your email: ");
    scanf("%s", c->email);

    for(i=0; i<5; i++){
        printf("%d.) %s\n", i+1, q[i].question);
        printf("A.) %s\n", q[i].option1);
        printf("B.) %s\n", q[i].option2);
        printf("C.) %s\n", q[i].option3);
        printf("D.) %s\n", q[i].option4);
        printf("Your answer: ");
        char ans[10];
        scanf("%s",ans);
        if(strcmp(ans,q[i].answer)==0){
            score++;
        }
    }
    printf("Your score is %d.\n", score);
    return score;
}

void saveResult(Candidate c){
    FILE *fp;
    fp = fopen("result.txt", "a");
    fprintf(fp, "Name: %s\nAge: %d\nEmail: %s\nScore: %d/5\n\n",c.name,c.age,c.email,c.score);
    fclose(fp);
    printf("Result saved successfully!\n");
}

void viewResult(){
    FILE *fp;
    fp = fopen("result.txt", "r");
    char ch;
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    fclose(fp);
}