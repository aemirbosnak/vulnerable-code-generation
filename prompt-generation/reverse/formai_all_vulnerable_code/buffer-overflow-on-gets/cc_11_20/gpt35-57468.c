//FormAI DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    char name[20], roll_no[10], ans[4], subj;
    int marks1=0, marks2=0, marks3=0, total_marks=0;
    time_t t;
    srand((unsigned) time(&t));

    printf("Enter your full name: ");
    gets(name);
    printf("Enter your Roll Number: ");
    gets(roll_no);

    printf("\n\n****************************************************************************\n\n");
    printf("Welcome to Online Examination System\n");
    printf("Choose your subject: \n");
    printf("A. C Programming\n");
    printf("B. Data Structures\n");
    printf("C. Algorithms\n");

    printf("Enter your choice: ");
    scanf("%c", &subj);

    switch(subj)
    {
        case 'A':
            printf("\n\n****************************************************************************\n\n");
            printf("Welcome to C Programming Examination\n");
            printf("All the Best %s!!\n", name);

            printf("Q1. Which are the keywords in C Programming?\n");
            printf("a.int, while, main, float\n");
            printf("b.integer, while, primary, floating\n");
            printf("c.int, while, main, double\n");
            printf("d.int, while, primary, float\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "a")==0)
            {
                printf("Correct Answer!!\n");
                marks1=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q2. What is the output of this C Program?\n");
            printf("#include<stdio.h>\n");
            printf("int main()\n");
            printf("{\n printf(\"Hello World!!\");\n return 0;\n}\n");
            printf("a. Compilation Error\n");
            printf("b. Runtime Error\n");
            printf("c. Hello World!!\n");
            printf("d. None of the Above\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "c")==0)
            {
                printf("Correct Answer!!\n");
                marks1+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q3. What is the purpose of using 'break' statement in Switch case structure?\n");
            printf("a. To come out of the Loop\n");
            printf("b. To continue the loop\n");
            printf("c. To execute a part of the loop again\n");
            printf("d. None of the Above\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "a")==0)
            {
                printf("Correct Answer!!\n");
                marks1+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            total_marks=marks1+marks2+marks3;
            printf("\n\n****************************************************************************\n\n");
            printf("Your Total Score in C Programming is: %d out of 30\n", marks1+marks2+marks3);

            break;

        case 'B':
            printf("\n\n****************************************************************************\n\n");
            printf("Welcome to Data Structures Examination\n");
            printf("All the Best %s!!\n", name);

            printf("Q1. Which is the Data Structure used to implement Recursion?\n");
            printf("a. Queue\n");
            printf("b. Stack\n");
            printf("c. Linked List\n");
            printf("d. None of the Above\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "b")==0)
            {
                printf("Correct Answer!!\n");
                marks2=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q2. Which traversal of Binary Tree is not possible?\n");
            printf("a. Inorder\n");
            printf("b. Preorder\n");
            printf("c. Postorder\n");
            printf("d. Level Order\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "d")==0)
            {
                printf("Correct Answer!!\n");
                marks2+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q3. What is the Time complexity of Quick Sort Algorithm?\n");
            printf("a. O(nlogn)\n");
            printf("b. O(n)\n");
            printf("c. O(logn)\n");
            printf("d. O(n^2)\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "a")==0)
            {
                printf("Correct Answer!!\n");
                marks2+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            total_marks=marks1+marks2+marks3;
            printf("\n\n****************************************************************************\n\n");
            printf("Your Total Score in Data Structures is: %d out of 30\n", marks1+marks2+marks3);
            
            break;

        case 'C':
            printf("\n\n****************************************************************************\n\n");
            printf("Welcome to Algorithms Examination\n");
            printf("All the Best %s!!\n", name);

            printf("Q1. What is the Time complexity of Insertion Sort?\n");
            printf("a. O(nlogn)\n");
            printf("b. O(n)\n");
            printf("c. O(logn)\n");
            printf("d. O(n^2)\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "d")==0)
            {
                printf("Correct Answer!!\n");
                marks3=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q2. Which Data Structure cannot be implemented using Linked List?\n");
            printf("a. Stack\n");
            printf("b. Queue\n");
            printf("c. Tree\n");
            printf("d. None of the Above\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "c")==0)
            {
                printf("Correct Answer!!\n");
                marks3+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            printf("Q3. What is the correct order of Infix, Prefix and Postfix Expressions?\n");
            printf("a. Infix, Prefix, Postfix\n");
            printf("b. Prefix, Infix, Postfix\n");
            printf("c. Postfix, Infix, Prefix\n");
            printf("d. Postfix, Prefix, Infix\n");
            printf("Enter your answer (a/b/c/d): ");
            scanf("%s", &ans);

            if(strcmp(ans, "d")==0)
            {
                printf("Correct Answer!!\n");
                marks3+=10;
            }
            else
            {
                printf("Wrong Answer!!\n");
            }

            total_marks=marks1+marks2+marks3;
            printf("\n\n****************************************************************************\n\n");
            printf("Your Total Score in Algorithms is: %d out of 30\n", marks1+marks2+marks3);

            break;

        default:
            printf("\n\n****************************************************************************\n\n");
            printf("Invalid Choice\n");
            exit(0);
    }

    // Generating a random Number between 100-199
    int ID = rand() % 100 + 100;

    printf("\n\n****************************************************************************\n\n");
    printf("Congratulations %s!! You have Successfully Completed the Examination\n", name);
    printf("Your Examination Score Card\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("Name: %s              Roll Number: %s         Exam ID: %d\n", name, roll_no, ID);
    printf("-----------------------------------------------------------------------------\n");
    printf(" Subject             Marks Obtained\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| C Programming         %d/%d  |\n", marks1, 30);
    printf("| Data Structures       %d/%d  |\n", marks2, 30);
    printf("| Algorithms            %d/%d  |\n", marks3, 30);
    printf("| Total                 %d/%d  |\n", total_marks, 90);
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");

    return 0;
}