//FormAI DATASET v1.0 Category: Online Examination System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int main()
{
    int num_of_questions, num_of_options, time_limit;
    char ans;
    char student_ans;
    int count=0;
    char* student_name;
    float score;
    time_t start_time, end_time, elapsed_time;
    int *seq, *rseq;
    char** questions;
    char** options;
    int** options_num;
    char* correct_ans;
    int i, j, k, l;
    srand(time(NULL));
    printf("\n***** C Online Examination System *****\n");
    printf("Enter name: ");
    scanf("%ms", &student_name); //Using %ms specifier to read input strings of unknown size
    
    printf("Enter number of questions: ");
    scanf("%d", &num_of_questions);
    
    questions = (char**)malloc(num_of_questions*sizeof(char*));
    options = (char**)malloc(num_of_questions*sizeof(char*));
    options_num = (int**)malloc(num_of_questions*sizeof(int*));
    correct_ans = (char*)malloc(num_of_questions*sizeof(char));
    
    seq = (int*)malloc(num_of_questions*sizeof(int));
    for(i=0;i<num_of_questions;i++) // Generating a random sequence of questions
        seq[i] = i;
    rseq = (int*)malloc(num_of_questions*sizeof(int));
    for(i=0;i<num_of_questions;i++)
    {
        l = rand()%num_of_questions;
        while(seq[l] == -1)
            l = (l+1)%num_of_questions;
        rseq[i] = seq[l];
        seq[l] = -1;
    }
    free(seq);
    
    printf("Enter number of options: ");
    scanf("%d", &num_of_options);
    options_num[0] = (int*)malloc(num_of_questions*num_of_options*sizeof(int)); // options_num is a 2D integer array to store the option number to which each character corresponds
    for(i=1;i<num_of_questions;i++)
        options_num[i] = options_num[i-1] + num_of_options;
        
    printf("Enter time limit in seconds: ");
    scanf("%d", &time_limit);
    printf("Time limit for each question: %d seconds.\n", time_limit);
    printf("Press any key to start the examination.\n");
    getchar();
    
    start_time = time(NULL);
    
    for(i=0;i<num_of_questions;i++) // reading the questions and options
    {
        printf("Question %d\n", i+1);
        printf("Enter the question: ");
        scanf(" %[^\n]", questions[rseq[i]]);
        options[rseq[i]] = (char*)malloc(num_of_options*sizeof(char));
        memset(options_num[rseq[i]], 0, num_of_options*sizeof(int));
        printf("Enter the options:\n");
        for(j=0;j<num_of_options;j++)
        {
            printf("%d. ", j+1);
            scanf(" %[^\n]s", &options[rseq[i]][j]);
            for(k=0;k<strlen(options[rseq[i]]) ;k++)
            {
                if(isalpha(options[rseq[i]][j])) // converting options to lower case and storing their corresponding option numbers
                {
                    options[rseq[i]][j] = tolower(options[rseq[i]][j]);
                    options_num[rseq[i]][j] = options[rseq[i]][j] - 'a';
                }
            }
        }
        printf("Enter the correct answer (a, b, c, d, e, ...): ");
        scanf(" %c", &correct_ans[rseq[i]]);
        correct_ans[rseq[i]] = tolower(correct_ans[rseq[i]]); // converting correct answer to lower case
    }
    
    end_time = time(NULL);
    elapsed_time = end_time - start_time;
    printf("Time taken to enter questions: %ld seconds.\n", elapsed_time);
    printf("Press any key to start answering the questions.\n");
    getchar();
    
    start_time = time(NULL);
    
    for(i=0;i<num_of_questions;i++) // asking the questions and recording student answer
    {
        printf("\nQuestion %d\n", i+1);
        printf("%s\n", questions[rseq[i]]);
        for(j=0;j<num_of_options;j++)
        {
            printf("%c) %s\n", 'A'+j, &options[rseq[i]][j]);
        }
        printf("Enter your answer (a, b, c, d, e, ...): ");
        scanf(" %c", &student_ans);
        student_ans = tolower(student_ans);
        if(student_ans == correct_ans[rseq[i]])
            count++; //incrementing count if answer is correct
    }
    end_time = time(NULL);
    elapsed_time = end_time - start_time;
    printf("Time taken to answer questions: %ld seconds.\n", elapsed_time);
    
    printf("Your score: %.2f out of %d. \n", (float)count/num_of_questions*100, num_of_questions);
    
    printf("Press any key to exit.\n");

    free(questions);
    free(options);
    free(options_num[0]);
    free(options_num);
    free(correct_ans);
    free(rseq);
    free(student_name);

    getchar();
    return 0;
}