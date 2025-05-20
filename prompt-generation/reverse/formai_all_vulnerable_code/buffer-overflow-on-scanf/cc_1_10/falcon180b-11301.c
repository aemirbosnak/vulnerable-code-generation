//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements, num_questions, correct_answers = 0, total_questions = 0;
    int element_num, user_answer;
    char element_name[20], element_symbol[20];
    FILE *fp;
    struct tm *tm_info;
    time_t now;
    srand(time(NULL));
    now = time(NULL);
    tm_info = localtime(&now);
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Today's date is %s\n", asctime(tm_info));
    printf("How many elements would you like to quiz on? ");
    scanf("%d", &num_elements);
    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    printf("Loading elements...\n");
    while (fscanf(fp, "%s %s", element_name, element_symbol)!= EOF) {
        printf("%s (%s)\n", element_name, element_symbol);
    }
    fclose(fp);
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);
    while (total_questions < num_questions) {
        element_num = rand() % num_elements;
        fseek(fp, 0L, SEEK_SET);
        while (fscanf(fp, "%s %s", element_name, element_symbol)!= EOF) {
            if (total_questions == num_questions) {
                break;
            }
            total_questions++;
            if (total_questions == element_num) {
                printf("What is the name of element %s? ", element_name);
                scanf("%s", element_name);
                if (strcmp(element_name, element_name) == 0) {
                    correct_answers++;
                }
            }
        }
    }
    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);
    return 0;
}