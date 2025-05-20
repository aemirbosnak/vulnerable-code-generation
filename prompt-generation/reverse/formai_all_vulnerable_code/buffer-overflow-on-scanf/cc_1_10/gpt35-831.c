//FormAI DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structures for questions and options
typedef struct
{
    char ques[200];
    char opt1[50];
    char opt2[50];
    char opt3[50];
    char opt4[50];
    int ans;
}question;

//Function to display the question and options
void display_question(int ques_num, question ques_arr[])
{
    printf("\nQ%d. %s\n", ques_num+1, ques_arr[ques_num].ques);
    printf("1. %s\n", ques_arr[ques_num].opt1);
    printf("2. %s\n", ques_arr[ques_num].opt2);
    printf("3. %s\n", ques_arr[ques_num].opt3);
    printf("4. %s\n", ques_arr[ques_num].opt4);
}

//Function to take user's response and validate it
int take_response(int ques_num, question ques_arr[])
{
    int response;
    do
    {
        printf("\nEnter your response for Q%d: ", ques_num+1);
        fflush(stdin); //Clearing the input buffer
        scanf("%d", &response);
        if(response<1 || response>4)
            printf("\nInvalid Input! Please select a valid option.\n");
    }while(response<1 || response>4);

    //Checking if the user's response is correct and returning the result
    if(response==ques_arr[ques_num].ans)
        return 1;
    else
        return 0;
}

int main()
{
    int num_of_ques, total_marks, user_marks=0;

    printf("************* Welcome to the Online Examination System *************\n\n");

    //Taking input from user for number of questions and total marks
    printf("Enter the number of questions: ");
    scanf("%d", &num_of_ques);
    printf("Enter the total marks: ");
    scanf("%d", &total_marks);

    //Creating array of questions
    question ques_arr[num_of_ques];

    //Taking input from user for questions and options
    for(int i=0; i<num_of_ques; i++)
    {
        printf("\n**** Enter the details for Q%d ****\n", i+1);
        fflush(stdin); //Clearing the input buffer
        printf("Enter the question: ");
        fgets(ques_arr[i].ques, sizeof(ques_arr[i].ques), stdin);
        printf("Enter option 1: ");
        fgets(ques_arr[i].opt1, sizeof(ques_arr[i].opt1), stdin);
        printf("Enter option 2: ");
        fgets(ques_arr[i].opt2, sizeof(ques_arr[i].opt2), stdin);
        printf("Enter option 3: ");
        fgets(ques_arr[i].opt3, sizeof(ques_arr[i].opt3), stdin);
        printf("Enter option 4: ");
        fgets(ques_arr[i].opt4, sizeof(ques_arr[i].opt4), stdin);
        printf("Enter the correct option (1-4): ");
        scanf("%d", &ques_arr[i].ans);
    }

    //Displaying the questions one by one and taking user's response
    for(int i=0; i<num_of_ques; i++)
    {
        display_question(i, ques_arr);
        user_marks += take_response(i, ques_arr);
    }

    //Calculating the percentage of marks obtained by the user
    float percentage = (float)user_marks*100/total_marks;

    //Displaying the result
    printf("\n************* RESULT *************\n");
    printf("Marks Obtained: %d\n", user_marks);
    printf("Total Marks: %d\n", total_marks);
    printf("Percentage: %0.2f%%\n", percentage);

    return 0;
}