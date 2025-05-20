//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    int qno; 
    char ques[256];
    char opt1[64];  
    char opt2[64];
    char opt3[64];
    char opt4[64];
    int ans;   
};

struct student {
    char name[64]; 
    int id;
    int score; 
};

int main() {
    struct question q[10]; 
    struct student s;
    int n, i, j; 
    char ch;
    FILE *fp; 
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", &s.name);
    printf("Please enter your student ID: ");
    scanf("%d", &s.id);
    printf("You will be presented with 10 multiple choice questions.\n");
    printf("Each question is worth 10 points.\n");
    printf("Press enter to begin the exam.");
    getchar();

    fp = fopen("questions.txt", "r");
    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    i = 0;
    while(!feof(fp)) {
        fscanf(fp, "%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%d%c", &q[i].qno, q[i].ques, q[i].opt1, q[i].opt2, q[i].opt3, q[i].opt4, &q[i].ans, &ch);
        i++;
    }
    fclose(fp);

    n = 0;
    s.score = 0;
    while(n < 10) {
        printf("\nQuestion #%d: %s\n", q[n].qno, q[n].ques);
        printf("1. %s\n", q[n].opt1);
        printf("2. %s\n", q[n].opt2);
        printf("3. %s\n", q[n].opt3);
        printf("4. %s\n", q[n].opt4);
        printf("Select your answer (1-4) : ");
        scanf("%d%c", &i, &ch);
        if(i == q[n].ans) {
            printf("Correct Answer! You have earned 10 points.\n");
            s.score += 10;
        } else {
            printf("Sorry, that is incorrect. The correct answer is %d.\n", q[n].ans);
        }
        n++;
    }

    printf("\nThank you for taking the exam.\n");
    printf("Your final score is %d out of 100.\n", s.score);
    fp = fopen("results.txt", "a");
    fprintf(fp, "%s, %d, %d\n", s.name, s.id, s.score);
    fclose(fp);

    return 0;
}