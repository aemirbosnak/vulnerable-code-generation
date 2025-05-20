//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    printf("Welcome to Wi-Fi Signal Strength Analyzer\n\n");
    
    //randomly generating signal strength
    srand(time(NULL));
    int strength = rand() % 100;
    
    int option = 0;
    printf("Please select an option:\n");
    printf("1. Check Signal Strength\n");
    printf("2. Analyze Signal Strength\n");
    printf("3. Quit\n");
    
    //taking user input and performing action based on selected option
    scanf("%d", &option);
    switch(option){
        case 1:{
            printf("The signal strength is: %d\n", strength);
            break;
        }
        case 2:{
            int level = 0;
            if(strength>=90){
                level = 5;
            }
            else if(strength>=70){
                level = 4;
            }
            else if(strength>=50){
                level = 3;
            }
            else if(strength>=30){
                level = 2;
            }
            else if(strength>=10){
                level = 1;
            }
            else{
                printf("No signal available\n");
                exit(0);
            }
            printf("The signal strength is at level %d\n", level);
            break;
        }
        case 3:{
            printf("Thank you for using Wi-Fi Signal Strength Analyzer\n");
            exit(0);
        }
        default:{
            printf("Invalid option selected\n");
            break;
        }
    }
    
    //ask user if they want to perform another action
    int choice = 0;
    printf("\nDo you want to perform another action?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &choice);
    if(choice==1){
        main();
    }
    else if(choice==2){
        printf("Thank you for using Wi-Fi Signal Strength Analyzer\n");
        exit(0);
    }
    else{
        printf("Invalid input. Exiting...\n");
        exit(0);
    }
    
    return 0;
}