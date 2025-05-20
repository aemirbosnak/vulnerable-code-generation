//FormAI DATASET v1.0 Category: Online Examination System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
  char userName[100], userPass[100];
  int marks = 0, totalMarks = 50;

  printf("Welcome to the C Online Examination System!\n");
  printf("Please enter your username: ");
  scanf("%s", userName);

  printf("Please enter your password: ");
  scanf("%s", userPass);

  if(strcmp(userName, "admin") == 0 && strcmp(userPass, "password") == 0) {
    printf("\nHello admin! Please select an option:\n");
    printf("1. Add Question\n2. View Questions\n3. Logout\n");
    int option;
    scanf("%d", &option);

    switch(option) {
      case 1: {
        char question[400], a[100], b[100], c[100], d[100], answer;
        printf("\nEnter the question: ");
        getchar();
        fgets(question, 400, stdin);
        printf("Enter option A: ");
        fgets(a, 100, stdin);
        printf("Enter option B: ");
        fgets(b, 100, stdin);
        printf("Enter option C: ");
        fgets(c, 100, stdin);
        printf("Enter option D: ");
        fgets(d, 100, stdin);
        printf("Enter the correct answer: ");
        scanf("%c", &answer);
        FILE *fp = fopen("questions.txt", "a");
        fprintf(fp, "%s\nA. %sB. %sC. %sD. %sAnswer: %c\n", question, a, b, c, d, answer);
        printf("Question successfully added!\n");
        fclose(fp);
        break;
      }
      case 2: {
        FILE *fp = fopen("questions.txt", "r");
        char line[500];
        while(fgets(line, 500, fp)) {
          printf("%s", line);
        }
        fclose(fp);
        break;
      }
      case 3: {
        printf("Logout successful!");
        break;
      }
    }
  }
  else {
    FILE *fp = fopen("questions.txt", "r");
    if(fp == NULL) {
      printf("Error opening file!");
      exit(1);
    }
    char q[400], a[100], b[100], c[100], d[100], ans;
    while(fscanf(fp, "%[^\n]\n", q) != EOF) {
      printf("%s\n", q);
      printf("A. ");
      fscanf(fp, "%[^\n]\n", a);
      printf("%s\n", a);
      printf("B. ");
      fscanf(fp, "%[^\n]\n", b);
      printf("%s\n", b);
      printf("C. ");
      fscanf(fp, "%[^\n]\n", c);
      printf("%s\n", c);
      printf("D. ");
      fscanf(fp, "%[^\n]\n", d);
      printf("%s\n", d);
      printf("Enter your answer: ");
      scanf("%c", &ans);
      getchar();
      if(ans == 'A' || ans == 'a') {
        marks += 10;
      }
      else if(ans == 'B' || ans == 'b') {
        marks += 10;
      }
      else if(ans == 'C' || ans == 'c') {
        marks += 10;
      }
      else if(ans == 'D' || ans == 'd') {
        marks += 10;
      }
      else {
        marks += 0;
      }
    }
    fclose(fp);
    printf("\nYour final score is: %d/%d", marks, totalMarks);
  }
  return 0;
}