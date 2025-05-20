//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int i, j, k;
    char* subjects[]={"Aliens", "Illuminati", "Reptilians", "Big Pharma", "Zombies", "NWO", "Vaccines", "Chemtrails", "Clones", "AI"};
    char* actions[]={"Control", "Manipulate", "Brainwash", "Covertly rule", "Dominate", "Infiltrate", "Subjugate", "Implant"};
    char* objects[]={"Government", "Society", "Media", "Education", "Weather", "Economy", "Food supply", "Technology"};

    srand(time(NULL));

    printf("Welcome to our random conspiracy theory generator!\n");

    while(1){
        printf("\nGenerating new conspiracy theory...\n\n");

        for(i=0;i<5;i++){
            j=rand()%10; //random index for subjects array
            k=rand()%8; //random index for actions array

            printf("%-15s %-20s %s\n", subjects[j], actions[k], objects[i]);
        }

        printf("\nDo you believe this conspiracy theory? (yes/no)\n");

        char response[10];
        scanf("%s", response);

        if(strcmp(response,"yes")==0){
            printf("We knew it! The truth is out there...\n");
        }else{
            printf("You are one of THEM, aren't you?\n");
        }

        printf("\nWould you like to generate another conspiracy theory? (yes/no)\n");

        scanf("%s", response);

        if(strcmp(response,"yes")==0){
            continue;
        }else{
            printf("Thanks for using our random conspiracy theory generator. Stay woke!\n");
            break;
        }
    }

    return 0;
}