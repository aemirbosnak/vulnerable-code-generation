//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //declaring variables
    int num, i, result;
    char name[20];
    
    //getting user name
    printf("Hello there! What's your name?\n");
    scanf("%s", name);
    printf("\n%s, I'm a fortune teller. Do you want to know your future?\n", name);
    printf("(Enter 1 for Yes and 0 for No)\n");
    scanf("%d", &num);
    
    //checking user input
    if(num == 0){
        printf("\nOk, have a nice day!");
        exit(0);
    } else if(num != 1 && num != 0) {
        do{
            printf("\nPlease enter a valid input (1 or 0)\n");
            scanf("%d", &num);
        } while(num != 1 && num != 0);
        if(num == 0){
            printf("\nOk, have a nice day!");
            exit(0);
        }
    }
    
    //generating random numbers
    srand(time(NULL));
    for(i=0;i<3;i++){
        result = rand() % 10;
        printf("%d ", result);
    }
    
    //displaying result of fortune teller
    if(result == 0) {
        printf("\nOh no %s! Your future doesn't look good. You must be careful from now on.", name);
    } else if(result == 1) {
        printf("\nWow %s! Your future is looking really bright. Keep up the good work!", name);
    } else if(result == 2) {
        printf("\n%s, you are going to meet someone special soon. Keep an open heart.", name);
    } else if(result == 3) {
        printf("\nYou will experience a new beginning in your life, %s. Embrace the change!", name);
    } else if(result == 4) {
        printf("\n%s, your financial situation will improve significantly.",
        name);
        printf(" Don't forget to thank the support you received in the past.");
    } else if(result == 5) {
        printf("\nYour health will improve %s! Take good care of yourself and keep on moving forward.", name);
    } else if(result == 6) {
        printf("\nYou will have a big decision to make soon, %s. Trust yourself and follow your intuition. ", name);    } else if(result == 7) {
        printf("\n%s, you will receive an unexpected gift soon. Cherish it and be grateful.", name);
    } else if(result == 8) {
        printf("\nYour family will play an important role in your future, %s. Strengthen your bond with them.", name);
    } else if(result == 9) {
        printf("\nYou will travel to an exciting place soon, %s. Get ready for a new adventure!", name);
    }
    
    printf("\n\nThank you for using our fortune teller service. Have a great day, %s!", name);
    
    return 0;
}