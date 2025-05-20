//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to shuffle an array
void shuffle(int arr[], int n){

    srand(time(NULL));
    for(int i=n-1; i>0; i--){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){

    // Initialize the period and group arrays
    int periods[] = {1, 2, 3, 4, 5, 6, 7};
    int groups[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    char symbols[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar"};

    // Shuffle the arrays
    shuffle(periods, 7);
    shuffle(groups, 18);

    // Initialize score and question variables
    int score = 0;
    int questionNum = 1;

    // Ask 10 questions
    while(questionNum <= 10){

        // Randomly select a group and period
        int randGroup = groups[questionNum-1];
        int randPeriod = periods[questionNum-1];

        // Print the question
        printf("Question %d: What is the symbol of the element in period %d and group %d?\n", questionNum, randPeriod, randGroup);

        // Get the user's answer
        char answer[3];
        scanf("%s", answer);

        // Check if the answer is correct
        if(answer[0] == symbols[(randPeriod-1)*18 + randGroup-1][0] && answer[1] == symbols[(randPeriod-1)*18 + randGroup-1][1]){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect. The correct answer is %s.\n", symbols[(randPeriod-1)*18 + randGroup-1]);
        }

        // Increase question number
        questionNum++;
    }

    // Print final score
    printf("Your score is %d out of 10.\n", score);

    return 0;
}