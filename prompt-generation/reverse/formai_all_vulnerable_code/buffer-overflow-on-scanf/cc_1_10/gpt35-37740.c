//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i;
    char userInput[100];
    int correctCount=0, mistakeCount=0; //variables to keep track of user's accuracy
    float accuracy;
    time_t initialTime, finalTime; //variables to calculate time taken by user
    
    printf("\nWelcome to Typing Speed Test!\n");
    printf("You will be given random words to type in the given time.\n");
    printf("Type as fast and accurately as you can.\n");
    printf("Press 'Enter' key to start the test\n");
    getchar(); //to wait till user presses enter
    
    srand(time(NULL)); //to generate new random word every time
    
    initialTime = time(NULL);
    
    //loop to generate random word and ask user to type it
    for(i=0;i<10;i++){
        char randomWord[10];
        
        //generate random lowercase alphabets
        for(int j=0;j<5;j++){
            randomWord[j] = 'a' + rand()%26;
        }
        //set last character as null to make it a string
        randomWord[5] = '\0';
        
        printf("Type: %s\n", randomWord);
        scanf("%s", userInput);
        
        //check if user input corresponds to the random word
        if(strcmp(userInput,randomWord)==0){
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Wrong!\n");
            mistakeCount++;
        }
    }
    
    finalTime = time(NULL);
    //calculate time taken and accuracy
    printf("\nYou took %ld seconds to complete the test.\n", finalTime-initialTime);
    accuracy = (float)correctCount/(correctCount+mistakeCount)*100;
    printf("Your typing speed is %.2f WPM (Words Per Minute).\n", accuracy*12); //assuming 5 characters per word
    
    return 0;
}