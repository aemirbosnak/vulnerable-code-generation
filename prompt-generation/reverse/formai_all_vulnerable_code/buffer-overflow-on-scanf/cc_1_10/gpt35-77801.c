//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>

int main()
{
    int num_questions, num_choices, num_students;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter the number of choices per question: ");
    scanf("%d", &num_choices);
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    int correct_answers[num_questions];
    printf("Enter the correct answers for each question: \n");
    for(int i = 0; i < num_questions; i++)
    {
        char ans;
        printf("Question %d: ", i+1);
        scanf(" %c", &ans);
        correct_answers[i] = ans - 'A';
    }

    int student_answers[num_students][num_questions];

    for(int i = 0; i < num_students; i++)
    {
        printf("Student %d:\n", i+1);
        for(int j = 0; j < num_questions; j++)
        {
            char ans;
            printf("Question %d: ", j+1);
            scanf(" %c", &ans);
            int ans_index = ans - 'A';
            if(ans_index < 0 || ans_index >= num_choices)
            {
                printf("Invalid answer, please choose again.\n");
                j--;
                continue;
            }
            student_answers[i][j] = ans_index;
        }
    }

    int num_correct[num_students];
    int total_scores[num_students];
    for(int i = 0; i < num_students; i++)
    {
        num_correct[i] = 0;
        total_scores[i] = 0;
        for(int j = 0; j < num_questions; j++)
        {
            if(student_answers[i][j] == correct_answers[j])
            {
                num_correct[i]++;
                total_scores[i]++;
            }
            else
            {
                total_scores[i]--;
            }
        }
    }

    printf("Results:\n");
    for(int i = 0; i < num_students; i++)
    {
        printf("Student %d: %d/%d\n", i+1, num_correct[i], num_questions);
    }

    return 0;
}