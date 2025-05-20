//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void clear() {
    system("clear||cls");
}

void menu() {
    clear();
    printf("==============================================\n\n");
    printf("       THE ROMANTIC TYPING SPEED TEST          \n\n");
    printf("==============================================\n\n");
    printf("          Press any key to start...            \n\n");
    getchar();
}

int main() {
    srand(time(NULL));
    char words[][30] = {"forever", "together", "romance", "love", "heart", "mine", "always", "beloved", "cherish", "adorable", "affectionate", "angel", "soulmate", "passionate", "sweetheart", "valentine", "devotion", "darling", "endless", "eternal"};
    int total_words = sizeof(words)/sizeof(words[0]);
    int total_chars = 0, correct_chars = 0;
    time_t start_time, end_time;
    double time_taken;
    char input[1000];

    menu();

    for(int i = 0; i < 5; i++) {
        int random_index = rand()%total_words;
        printf("Type: ");
        printf("%s\n", words[random_index]);

        printf("Your typing: ");
        time(&start_time);
        fgets(input, 1000, stdin);
        time(&end_time);

        int len = strlen(input);
        total_chars += len-1;

        for(int j = 0; j < len-1; j++) {
            if(tolower(input[j]) == tolower(words[random_index][j])) {
                correct_chars++;
            }
        }

        clear();
    }

    time_taken = difftime(end_time, start_time);
    double speed = (double)correct_chars/time_taken;
    int accuracy = (correct_chars*100)/total_chars;

    printf("==============================================\n\n");
    printf("       Congratulations! You have completed     \n");
    printf("        THE ROMANTIC TYPING SPEED TEST          \n\n");
    printf("==============================================\n\n");
    printf("            Total characters typed : %d        \n", total_chars);
    printf("           Correctly typed characters : %d     \n", correct_chars);
    printf("                   Accuracy : %d%%              \n", accuracy);
    printf("               Time taken : %.2lf seconds      \n", time_taken);
    printf("              Your typing speed : %.2lf WPM    \n", speed);

    return 0;
}