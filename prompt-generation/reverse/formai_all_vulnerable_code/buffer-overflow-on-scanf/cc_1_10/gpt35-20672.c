//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void instructions(); // Function declaration for displaying instructions
void startExam(char[], char[]); // Function declaration for starting exam
void displayResult(char[], char[]); // Function declaration for displaying result

int main()
{
    char username[20]; // Maximum length of username is 20
    char password[20]; // Maximum length of password is 20
    char choice;

    printf("\t\t Welcome to Online Examination System\n");
    printf("\t\t ----------------------------------------\n");

    printf("\nEnter your Username: ");
    scanf("%s", username);

    printf("\nEnter your Password: ");
    scanf("%s", password);

    if (strcmp(username,"admin")==0 && strcmp(password, "admin123")==0) // checking login credentials 
    {
        printf("\nLogin Successfull!!\n");
        instructions(); // displaying instructions
        printf("\nEnter your choice (start/display) : ");
        scanf(" %c", &choice);
        switch(choice)
        {
            case 's':
            case 'S': startExam(username, password); // starting exam
                      break;

            case 'd':
            case 'D': displayResult(username, password); // displaying result
                      break;

            default: printf("Invalid choice, please try again!"); // if choice is other then start/display
                     break;
        }
    }
    else
    {
        printf("\nLogin Failed!! Please try again."); // If login credentials are incorrect
    }
    return 0;
}

void instructions()
{
    printf("\nInstructions:\n");
    printf("1. This exam consists of 10 questions.\n");
    printf("2. Each question carries 10 marks.\n");
    printf("3. You will be given 30 seconds to answer each question.\n");
    printf("4. There is no negative marking.\n\n");
}

void startExam(char username[], char password[])
{
    int score=0, i;
    char ans[11][2]={}; // 2-dimensional array to store the answers

    printf("\n\n*****WELCOME TO THE EXAM*****\n");
    printf("********************************\n");
    printf("Q1. Which of the following is not a programming language?\n");
    printf("a. C  b. Python  c. HTML  d. Java\n");
    printf("Ans: ");
    scanf(" %s", ans[1]);
    if(strcmp(ans[1], "c")==0)
        score+=10; // updating score

    printf("\nQ2. Which of the following keyword is used for including a file in C program?\n");
    printf("a. include  b. exclude  c. import  d. require\n");
    printf("Ans: ");
    scanf(" %s", ans[2]);
    if(strcmp(ans[2], "a")==0)
        score+=10;

    printf("\nQ3. Which of the following is not a storage class?\n");
    printf("a. int  b. extern  c. static  d. auto\n");
    printf("Ans: ");
    scanf(" %s", ans[3]);
    if(strcmp(ans[3], "a")==0)
        score+=10;

    printf("\nQ4. What is the output of the following code snippet?\n");
    printf("\n    void main()\n    {\n        int i;\n        for (i=1; i<=5; i++)\n        {\n            if (i%2==0)\n                continue;\n            printf(\"%d \",i);\n        }\n    }");
    printf("\na. 1 2 3 4 5  b. 1 3 5  c. 2 4  d. 1 2 3 4\n");
    printf("Ans: ");
    scanf(" %s", ans[4]);
    if(strcmp(ans[4], "b")==0)
        score+=10;

    printf("\nQ5. Which of the following is correct way to declare a character pointer?\n");
    printf("a. char *name;  b. character *name;  c. char name;  d. None of the above\n");
    printf("Ans: ");
    scanf(" %s", ans[5]);
    if(strcmp(ans[5], "a")==0)
        score+=10;

    printf("\nQ6. What is the size of integer data type in C?\n");
    printf("a. 2 bytes  b. 4 bytes  c. 8 bytes  d. 1 byte\n");
    printf("Ans: ");
    scanf(" %s", ans[6]);
    if(strcmp(ans[6], "b")==0)
        score+=10;

    printf("\nQ7. What is the output of the following code snippet?\n");
    printf("\n    void main()\n    {\n        int i=1;\n        while(i<=5)\n        {\n            printf(\"%d \",i*i);\n            i++;\n        }\n    }");
    printf("\na. 1 4 9 16 25  b. 1 3 5 7 9  c. 2 4 6 8 10  d. None of the above\n");
    printf("Ans: ");
    scanf(" %s", ans[7]);
    if(strcmp(ans[7], "a")==0)
        score+=10;

    printf("\nQ8. What is the output of the following code snippet?\n");
    printf("\n    void main()\n    {\n        int n=5, i, f=1;\n        for(i=1; i<=n; i++)\n        {\n            f *= i;\n        }\n        printf(\"Factorial of %d is %d\", n, f);\n    }");
    printf("\na. Factorial of 5 is 5  b. Factorial of 5 is 1  c. Factorial of 5 is 25  d. Factorial of 5 is 120\n");
    printf("Ans: ");
    scanf(" %s", ans[8]);
    if(strcmp(ans[8], "d")==0)
        score+=10;

    printf("\nQ9. What is the output of the following code snippet?\n");
    printf("\n    void main()\n    {\n        int a=5, b=10, c, d;\n        c = ++a;\n        d = b++;\n        printf(\"a=%d b=%d c=%d d=%d\", a, b, c, d);\n    }");
    printf("\na. a=6 b=11 c=5 d=10  b. a=6 b=10 c=5 d=10  c. a=5 b=11 c=6 d=10  d. None of the above\n");
    printf("Ans: ");
    scanf(" %s", ans[9]);
    if(strcmp(ans[9], "b")==0)
        score+=10;

    printf("\nQ10. What is the output of the following code snippet?\n");
    printf("\n    void main()\n    {\n        int i=10;\n        do\n        {\n            printf(\"%d \", i);\n            i-=3;\n        }while(i>=1);\n    }");
    printf("\na. 10 7 4 1  b. 10 8 6 4 2  c. 10 6 2  d. None of the above\n");
    printf("Ans: ");
    scanf(" %s", ans[10]);
    if(strcmp(ans[10], "a")==0)
        score+=10;

    printf("\n\n****RESULT****\n");
    printf("*******************\n");
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);
    printf("Score: %d/100\n", score);
    printf("*******************\n");
}

void displayResult(char username[], char password[])
{
    printf("\n\n****RESULT****\n");
    printf("*******************\n");
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);
    printf("You have not attempted the exam yet!!\n");
    printf("*******************\n");
}