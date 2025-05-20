//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main(){
    char name[20];
    char response[5];
    int choice;
    printf("\nWelcome to the Romeo and Juliet Adventure Game!\n");
    printf("The Capulets and Montagues are at war.\n");
    printf("You are a member of the Capulet family.\n");
    printf("What is your name?");
    scanf("%s", &name);

    
    printf("%s, your family has arranged for you to marry Paris, a nobleman from Verona.\n", name);
    printf("However, you have fallen deeply in love with Romeo, a member of the Montague family.\n");
    printf("What will you do? Choose your fate.\n");
    
    printf("1. Accept the arranged marriage with Paris.\n");
    printf("2. Elope with Romeo and run away from Verona forever.\n");
    scanf("%d", &choice);

    if(choice == 1){
        printf("You have chosen to marry Paris.\n");
        printf("Romeo hears of your decision and becomes distraught. \n");
        printf("He drinks poison and dies at your feet.\n");
        printf("You realize the true depth of your love for Romeo.");
        printf("Game over.");
    }else if(choice == 2){
        printf("You have chosen to elope with Romeo.\n");
        printf("You both know that there will be severe consequences if you are caught.\n");
        printf("Do you continue with your plan? yes or no? ");
        scanf("%s", &response);
        if(strcmp(response, "yes") == 0){
            printf("You and Romeo run away from Verona together and live a happy life, but always looking over your shoulders in fear.\n");
            printf("The Capulet and Montague families never reconcile, and the feud continues.");
            printf("Congratulations, you have survived the Romeo and Juliet adventure game!\n");
        }else{
            printf("Romeo is heartbroken by your decision to not follow through with your plan.\n");
            printf("He believes that you do not truly love him.");
            printf("He goes to the Capulet tomb and tragically takes his own life.\n");
            printf("You eventually marry Paris and live the rest of your life with regret.");
            printf("Game over.");
        }
    }else{
        printf("Invalid choice. Please try again.");
        printf("Game over.");
    }
    return 0;
}