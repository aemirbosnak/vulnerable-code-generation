//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define structures for knight and treasure
struct Knight{
    char name[20];
    int strength;
    int agility;
    int bravery;
    int intelligence;
};

struct Treasure{
    char type[20];
    int value;
};

int main(){
    //seed random number generator
    srand(time(0));

    //create an array of knights and treasures
    struct Knight knights[5] = {
        {"Arthur", 30, 25, 40, 30},
        {"Lancelot", 40, 30, 35, 25},
        {"Galahad", 30, 40, 35, 25},
        {"Perceval", 35, 30, 30, 35},
        {"Gawain", 40, 35, 25, 35}
    };

    struct Treasure treasures[7] = {
        {"Gold", 100},
        {"Silver", 75},
        {"Jewels", 150},
        {"Gems", 200},
        {"Diamonds", 250},
        {"Emeralds", 300},
        {"Sapphires", 350}
    };

    //ask user which knight to select
    printf("Welcome to the Kingdom of Camelot! Please select a knight:\n");
    for(int i=0; i<5; i++){
        printf("%d. %s\n", i+1, knights[i].name);
    }
    int choice;
    scanf("%d", &choice);

    //validate user input
    while(choice < 1 || choice > 5){
        printf("Invalid input. Please select a knight:\n");
        for(int i=0; i<5; i++){
            printf("%d. %s\n", i+1, knights[i].name);
        }
        scanf("%d", &choice);
    }

    //selected knight
    struct Knight selected_knight = knights[choice-1];
    printf("You have selected %s.\n\n", selected_knight.name);

    //generate random treasure
    int random_index = rand() % 7;
    struct Treasure random_treasure = treasures[random_index];
    printf("You have found a chest containing %s worth %d gold pieces!\n\n", random_treasure.type, random_treasure.value);

    //calculate score
    int score = selected_knight.strength + selected_knight.agility + selected_knight.bravery + selected_knight.intelligence + random_treasure.value;
    printf("Your score is %d.\n", score);

    //determine knight's rank
    char* rank;
    if(score >= 600){
        rank = "Grand Master";
    }
    else if(score >= 500){
        rank = "Master";
    }
    else if(score >= 400){
        rank = "Knight Commander";
    }
    else if(score >= 300){
        rank = "Knight";
    }
    else{
        rank = "Squire";
    }

    printf("Your rank is %s.\n", rank);

    return 0;
}