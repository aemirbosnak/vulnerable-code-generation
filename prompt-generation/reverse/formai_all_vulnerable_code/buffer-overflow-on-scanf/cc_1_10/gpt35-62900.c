//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    srand(time(NULL));
    int i, count=0, chance=3;
    char letter, response, alphabet;
    double time_interval, typing_speed;

    printf("----------------------------------------\n");
    printf("| WELCOME TO THE TYPING SPEED TEST GAME |\n");
    printf("----------------------------------------\n\n");
    printf("RULES: \n");
    printf("There will be a random alphabet displayed on the screen. You need to type the same letter and press enter.\n");
    printf("You will need to complete 10 rounds. Your goal is to type as many letters correctly as possible in the shortest possible time.\n");
    printf("Be ready to have lots of FUN!\n\n");
    printf("Press 'ENTER' to start the game!");

    getchar();

    for(i=1; i<=10; i++){
        printf("\nRound %d:\n", i);
        alphabet = 'A' + rand()%26;
        printf("Type the letter '%c': ", alphabet);
        clock_t start_time = clock();
        scanf(" %c", &letter);
        time_interval = (double)(clock() - start_time) / CLOCKS_PER_SEC;

        if(tolower(letter) == tolower(alphabet)){
            printf("Correct!\n");
            count++;
        }
        else{
            chance--;
            printf("Incorrect! You have %d chance(s) left.\n", chance);
            if(chance == 0){
                printf("GAME OVER!\n");
                printf("You completed %d round(s) and got %d letter(s) correct!\n", i-1, count);
                return 0;
            }
            i--;
            continue;
        }
        printf("Do you want to continue? [y/n]: ");
        scanf(" %c", &response);

        if(response == 'n' || response == 'N'){
            printf("You completed %d round(s) and got %d letter(s) correct!\n", i, count);
            return 0;
        }
    }
    typing_speed = (double)(count*60) / (double)time_interval;
    printf("\nCONGRATULATIONS! You completed 10 rounds in %.2f seconds with a typing speed of %.2f letters per minute!\n", time_interval, typing_speed);
    return 0;
}