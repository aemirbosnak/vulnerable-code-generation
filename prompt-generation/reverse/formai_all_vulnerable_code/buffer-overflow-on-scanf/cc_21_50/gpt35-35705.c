//FormAI DATASET v1.0 Category: Online Examination System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,i,j,k,ans,key,temp;
    char ch, name[50];
    int score=0;
    printf("**********Welcome to C Online Examination System**********");
    printf("\nEnter your name: ");
    fgets(name,50,stdin);
    printf("\nHello %s",name);
    printf("Please select one of the following categories:\n");
    printf("1. Basic C concepts\n2. Pointers and arrays\n3. Functions\n4. Structures\n");
    printf("\nEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("You have selected Basic C concepts. Get ready for the quiz!\n");
            printf("Q1: What is the size of int variable in bytes?\n");
            printf("a. 2\tb. 4\nc. 8\td. cannot be determined\n");
            ans=2;
            break;
        case 2:
            printf("You have selected Pointers and arrays. Get ready for the quiz!\n");
            printf("Q1: What is the output of the following program?\nint a[3]={1,2,3};\nint* b=a;\nprintf(\"%d\",*b);\n");
            printf("a. 1\tb. 2\nc. 3\td. garbage value\n");
            ans=1;
            break;
        case 3:
            printf("You have selected Functions. Get ready for the quiz!\n");
            printf("Q1: What is the output of the following program?\nvoid display(int a)\n{\nprintf(\"%d\",a);\n}\nint main()\n{\ndisplay();\n}\n");
            printf("a. 0\tb. nothing is printed\nc. error\td. none of the above\n");
            ans=3;
            break;
        case 4:
            printf("You have selected Structures. Get ready for the quiz!\n");
            printf("Q1: What is the output of the following program?\nstruct employee\n{\nint id;\nchar name[20];\n};\nvoid main()\n{\nstruct employee emp1,emp2;\nprintf(\"%d\",sizeof(emp2));\n}\n");
            printf("a. 20\tb. 24\nc. 26\td. 28\n");
            ans=2;
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }
    printf("Enter your answer(a,b,c,d): ");
    getchar();
    ch=getchar();
    switch(ch)
    {
        case 'a':
            key=1;
            break;
        case 'b':
            key=2;
            break;
        case 'c':
            key=3;
            break;
        case 'd':
            key=4;
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }
    if(key==ans)
    {
        printf("Correct answer!\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n");
        score--;
    }
    printf("\nDo you want to continue(y/n)? ");
    getchar();
    ch=getchar();
    if(ch=='y' || ch=='Y')
    {
        printf("\nPlease select one of the following categories:\n");
        printf("1. Basic C concepts\n2. Pointers and arrays\n3. Functions\n4. Structures\n");
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("You have selected Basic C concepts. Get ready for the quiz!\n");
                printf("Q1: What is the size of int variable in bytes?\n");
                printf("a. 2\tb. 4\nc. 8\td. cannot be determined\n");
                ans=2;
                break;
            case 2:
                printf("You have selected Pointers and arrays. Get ready for the quiz!\n");
                printf("Q1: What is the output of the following program?\nint a[3]={1,2,3};\nint* b=a;\nprintf(\"%d\",*b);\n");
                printf("a. 1\tb. 2\nc. 3\td. garbage value\n");
                ans=1;
                break;
            case 3:
                printf("You have selected Functions. Get ready for the quiz!\n");
                printf("Q1: What is the output of the following program?\nvoid display(int a)\n{\nprintf(\"%d\",a);\n}\nint main()\n{\ndisplay();\n}\n");
                printf("a. 0\tb. nothing is printed\nc. error\td. none of the above\n");
                ans=3;
                break;
            case 4:
                printf("You have selected Structures. Get ready for the quiz!\n");
                printf("Q1: What is the output of the following program?\nstruct employee\n{\nint id;\nchar name[20];\n};\nvoid main()\n{\nstruct employee emp1,emp2;\nprintf(\"%d\",sizeof(emp2));\n}\n");
                printf("a. 20\tb. 24\nc. 26\td. 28\n");
                ans=2;
                break;
            default:
                printf("Invalid choice\n");
                exit(0);
        }
        printf("Enter your answer(a,b,c,d): ");
        getchar();
        ch=getchar();
        switch(ch)
        {
            case 'a':
                key=1;
                break;
            case 'b':
                key=2;
                break;
            case 'c':
                key=3;
                break;
            case 'd':
                key=4;
                break;
            default:
                printf("Invalid choice\n");
                exit(0);
        }
        if(key==ans)
        {
            printf("Correct answer!\n");
            score++;
        }
        else
        {
            printf("Wrong answer!\n");
            score--;
        }
    }
    printf("\nDo you want to view the result(y/n)? ");
    getchar();
    ch=getchar();
    if(ch=='y' || ch=='Y')
    {
        printf("\n\n********** Result **********\n");
        printf("Name of candidate: %s\n",name);
        printf("Total score: %d\n",score);
        if(score==2)
        {
            printf("Congratulations! You have passed the quiz.\n");
        }
        else
        {
            printf("Sorry! You have failed the quiz.\n");
        }
    }
    else
    {
        printf("Thank you for taking the quiz.\n");
    }
    return 0;
}