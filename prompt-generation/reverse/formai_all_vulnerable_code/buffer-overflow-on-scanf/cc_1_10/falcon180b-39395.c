//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    int choice, age, charm, wealth, personality, married;
    char name[20];
    printf("Welcome to the world of love and romance!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    srand(time(0));
    age = rand()%100;
    charm = rand()%100;
    wealth = rand()%100;
    personality = rand()%100;
    married = 0;
    while(1){
        printf("\nYou are %d years old, with %d charm, %d wealth, and %d personality.\n", age, charm, wealth, personality);
        printf("You are currently %s.\n", married? "married" : "single");
        printf("What would you like to do?\n");
        printf("1. Go to a bar\n");
        printf("2. Visit a park\n");
        printf("3. Attend a party\n");
        printf("4. Go on a date\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("You went to a bar and met someone new.\n");
                break;
            case 2:
                printf("You visited a park and enjoyed the scenery.\n");
                break;
            case 3:
                printf("You attended a party and had a great time.\n");
                break;
            case 4:
                printf("You went on a date and it was wonderful.\n");
                break;
            case 5:
                printf("Goodbye, %s!\n", name);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        if(choice == 4){
            printf("Would you like to go on another date with the same person?\n");
            scanf("%d", &choice);
            if(choice){
                printf("You went on another date and it was even better than the last.\n");
            }else{
                printf("You decided to end things with that person.\n");
            }
        }
    }
}