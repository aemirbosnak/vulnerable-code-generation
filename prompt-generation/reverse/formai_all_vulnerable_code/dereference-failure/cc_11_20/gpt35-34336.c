//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Element{
    int atomic_number;
    char symbol[3];
    char name[20];
    char category[20];
    float atomic_mass;
};

int main(){
    struct Element elements[118];
    FILE *fptr;

    fptr = fopen("periodic_table.txt", "r");
    if(fptr == NULL){
        printf("Failed to open the file!\n");
        exit(1);
    }

    char buffer[50], *token;
    int i = 0;

    while(fgets(buffer, 50, fptr) != NULL){
        token = strtok(buffer, " ");
        elements[i].atomic_number = atoi(token);

        token = strtok(NULL, " ");
        strcpy(elements[i].symbol, token);

        token = strtok(NULL, " ");
        strcpy(elements[i].name, token);

        token = strtok(NULL, " ");
        strcpy(elements[i].category, token);

        token = strtok(NULL, " ");
        elements[i].atomic_mass = atof(token);

        i++;
    }

    fclose(fptr);

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("This quiz contains 10 questions. Each question has 4 options, only one of which is correct.\n");
    printf("For each correct answer, you will get 10 points. There is no negative marking.\n\n");

    char choices[4] = {'A','B','C','D'};
    int score = 0, qno;

    for(int j=0;j<10;j++){
        qno = rand() % 117;

        printf("Question %d:\n", j+1);
        printf("%s is the symbol for which element?\n", elements[qno].symbol);

        int correct_option = rand() % 4;

        for(int k=0;k<4;k++){
            if(k == correct_option){
                printf("%c. %s\n", choices[k], elements[qno].name);
            }
            else{
                int opt = rand() % 117;
                printf("%c. %s\n", choices[k], elements[opt].name);
            }
        }

        char option_chosen;

        while(1){
            printf("Choose your answer: ");
            scanf(" %c", &option_chosen);

            if(option_chosen == 'A' || option_chosen == 'B' || option_chosen == 'C' || option_chosen == 'D')
                break;

            printf("Invalid input! Please try again.\n");
        }

        if(option_chosen == choices[correct_option]){
            printf("Correct Answer!\n");
            score += 10;
        }
        else{
            printf("Wrong Answer! The correct answer is %s.\n", elements[qno].name);
        }

        printf("\n");
    }

    printf("Your total score is %d.\n", score);

    return 0;
}