//FormAI DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void enterAnswers(char answers[], int n){
    printf("\nEnter the correct answers for the exam:\n");
    for(int i=0; i<n; i++){
        printf("Question %d: ", i+1);
        fflush(stdin);
        scanf("%c", &answers[i]);
    }
}

void displayInstructions(){
    printf("\nInstructions for the Online Exam:\n");
    printf("1. This exam consists of 10 questions.\n");
    printf("2. Each question has 4 options (A, B, C, D).\n");
    printf("3. You need to choose only one option for each question.\n");
    printf("5. Total marks for the exam is 10.\n");
}

int startExam(char answers[]){
    int score=0;
    for(int i=0; i<10; i++){
        printf("\nQuestion %d:", i+1);
        printf("\nWhat is the output of the following code snippet?\n");
        switch(i+1){
            case 1: printf("\n#include<stdio.h>\nint main(){\n\tint a=5, b=2;\n\tif(a>b)\n\t    printf(\"a is greater\");\n\telse\n\t    printf(\"b is greater\");\n\treturn 0;\n}\n");
                    printf("\nA. a is greater\nB. b is greater\nC. None of the above\nD. Compilation Error\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 2: printf("\n#include<stdio.h>\nint main(){\n\tint sum=0, i=1;\n\twhile(i<10){\n\t    sum += i;\n\t    i++;\n\t}\n\tprintf(\"Sum is %d\", sum);\n\treturn 0;\n}\n");
                    printf("\nA. Sum is 45\nB. Sum is 50\nC. Sum is 55\nD. None of the above\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 3: printf("\n#include<stdio.h>\nint main(){\n\tint i=1, j=2, k=3;\n\tif(i<j<k)\n\t    printf(\"i is smaller\");\n\telse\n\t    printf(\"k is greater\");\n\treturn 0;\n}\n");
                    printf("\nA. i is smaller\nB. j is smaller\nC. k is greater\nD. Compilation Error\n");
                    if(answers[i]=='C')
                        score++;
                    break;
            case 4: printf("\n#include<stdio.h>\nint main(){\n\tint i=3, j=5, k=7;\n\tif(!(i>j) && !(k>j))\n\t    printf(\"True\");\n\telse\n\t    printf(\"False\");\n\treturn 0;\n}\n");
                    printf("\nA. True\nB. False\nC. None of the above\nD. Compilation Error\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 5: printf("\n#include<stdio.h>\nint main(){\n\tint n=10;\n\tfor(int i=0; i<n; i++){\n\t    printf(\"%d \", i);\n\t    if(i%2==0)\n\t        continue;\n\t    printf(\"Hi\\n\");\n\t}\n\treturn 0;\n}\n");
                    printf("\nA. 0 1 2 Hi 3 4 Hi 5 6 Hi 7 8 Hi 9 \nB. 0 1 2 Hi 4 Hi 6 Hi 8 Hi\nC. 0 Hi 1 2 Hi 3 4 Hi 5 6 Hi 7 8 Hi 9\nD. None of the above\n");
                    if(answers[i]=='C')
                        score++;
                    break;
            case 6: printf("\n#include<stdio.h>\nint main(){\n\tint a=10, b=5, c=0;\n\tc = a-- - --b;\n\tprintf(\"Value of c is %d\", c);\n\treturn 0;\n}\n");
                    printf("\nA. Value of c is 6\nB. Value of c is 5\nC. Value of c is 4\nD. Compilation Error\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 7: printf("\n#include<stdio.h>\nint main(){\n\tfor(int i=0; i<5; i++){\n\t    printf(\"%d \", i);\n\t}\n\tprintf(\"\\n\");\n\tfor(int i=0; i<5; ++i){\n\t    printf(\"%d \", i);\n\t}\n\treturn 0;\n}\n");
                    printf("\nA. 0 1 2 3 4 0 1 2 3 4\nB. 1 2 3 4 5 1 2 3 4 5\nC. 0 1 2 3 4 1 2 3 4 5\nD. None of the above\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 8: printf("\n#include<stdio.h>\nint main(){\n\tint a = 7.2/2;\n\tprintf(\"%d\", a);\n\treturn 0;\n}\n");
                    printf("\nA. 3\nB. 3.6\nC. 4\nD. Compilation Error\n");
                    if(answers[i]=='A')
                        score++;
                    break;
            case 9: printf("\n#include<stdio.h>\nint main(){\n\tint a=10, b=5;\n\tint*ptr1=&a;\n\tint*ptr2=&b;\n\t++(*ptr2); //Line 4\n\tprintf(\"Value of b is %d\",*ptr2);\n\t++ptr2; //Line 6\n\tprintf(\"Value of b is %d\",*ptr2);\n\treturn 0;\n}\n");
                    printf("\nA. Value of b is 6 and Value of b is 5\nB. Value of b is 6 and Value of b is garbage\nC. Compilation Error\nD. None of the above\n");
                    if(answers[i]=='B')
                        score++;
                    break;
            case 10:printf("\n#include<stdio.h>\nstruct student{\n    char name[10];\n    char branch[5];\n    int roll;\n};//Line 6\nint main(){\n    struct student obj1= {\"John\",\"CSE\",123};\n    printf(\"%s %s %d\", obj1.name, obj1.branch, obj1.roll, obj1.CGPA);\n    return 0;\n}\n");
                    printf("\nA. John CSE 123\nB. John CSE 123 0\nC. Compilation Error\nD. None of the above\n");
                    if(answers[i]=='B')
                        score++;
                    break;
        }
    }
    return score;
}

int main(){
    char answers[10];
    displayInstructions();
    enterAnswers(answers, 10);
    printf("\n\n\t\t\t***Welcome to the Online Exam***\n\n");
    printf("Press any key to start the exam......");
    getchar();
    int score = startExam(answers);
    printf("\n\n\t\t\t***Your Score is %d***\n\n",score);
    return 0;
}