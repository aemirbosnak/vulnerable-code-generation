//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #elif __unix__
        system("clear");
    #endif
}

void delay(int seconds){
    int mseconds = 1000 * seconds;
    clock_t start = clock();
    while (clock() < start + mseconds);
}

void printText(char *text){
    int i = 0;
    while(text[i] != '\0'){
        printf("%c", text[i]);
        fflush(stdout);
        delay(0.03);
        i++;
    }
}

int adventure(char *name){
    clearScreen();
    char intro[] = "\n\nWelcome to Adventure Island, %s! You have been stranded on this mysterious island and your goal is to find a way to escape. Good luck!\n\n";
    printf(intro, name);
    delay(2);

    char choice1[] = "You find yourself on a lush green beach. Do you want to explore the forest to your left or climb the mountain to your right?\n";
    char choice2[] = "You made it to the forest. In a clearing, you see a backpack and a map. Which one do you take?\n";
    char choice3[] = "You made it to the top of the mountain. In the distance, you see a plane flying overhead. Do you stay put and build a signal fire or start walking towards the coast?\n";
    char win[] = "Congratulations, %s! You made it off the island!\n\n";
    char lose[] = "Unfortunately, %s, you were not able to escape Adventure Island. Better luck next time!\n\n";

    char answer[10];
    clearScreen();

    printf(choice1);
    scanf("%s", answer);

    if(strcmp(answer, "left") == 0){
        printf(choice2);
        scanf("%s", answer);
        if(strcmp(answer, "backpack") == 0){
            printf(choice3);
            scanf("%s", answer);
            if(strcmp(answer, "fire") == 0){
                printf(win, name);
                return 1;
            }
            else{
                printf(lose, name);
                return 0;
            }
        }
        else{
            printf(lose, name);
            return 0;
        }
    }
    else{
        printf(choice3);
        scanf("%s", answer);
        if(strcmp(answer, "fire") == 0){
            printf(win, name);
            return 1;
        }
        else{
            printf(lose, name);
            return 0;
        }
    }
}

int main(){
    char name[20];
    printf("Welcome to Adventure Island! What is your name?\n");
    scanf("%s", name);
    adventure(name);
    return 0;
}