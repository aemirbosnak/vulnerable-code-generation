//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// define all the elements in the periodic table
#define H 1
#define He 2
#define Li 3
#define Be 4
#define B 5
#define C 6
#define N 7
#define O 8
#define F 9
#define Ne 10
#define Na 11
#define Mg 12
#define Al 13
#define Si 14
#define P 15
#define S 16
#define Cl 17
#define Ar 18
#define K 19
#define Ca 20

// function to start the quiz
void start_quiz(){
    int score = 0; // keep track of user's score
    int user_input; // user's selected element
    
    // introduce the quiz
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter the atomic number of the element shown: \n\n");
    
    // set up the element array
    int elements[] = {H, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca};
    
    // seed random number generator
    srand(time(0));
    
    // loop through 10 questions
    for(int i=0;i<10;i++){
        // get a random element from the array
        int rand_index = rand() % 20;
        int current_element = elements[rand_index];
        
        // print out the question
        printf("Question %d:\n", i+1);
        printf("%d) ", current_element);
        
        // prompt user for answer
        scanf("%d", &user_input);
        
        // check if user is correct
        if(user_input == current_element){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect. The correct answer is %d.\n", current_element);
        }
    }
    
    // print out final score
    printf("\nYour final score is %d/10.\n", score);
}

// main function to start the program
int main(){
    start_quiz();
    return 0;
}