//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("****************************************************\n");
    printf("            Welcome to Typing Speed Test!            \n");
    printf("****************************************************\n\n");
    printf("You will be provided with 10 random words to type.\n");
    printf("Press 'ENTER' to begin.\n\n");
    getchar(); //wait for user to press enter before beginning the test

    char words[10][10] = {"car", "book", "phone", "computer", "apple", "table", "window", "chair", "lamp", "bag"}; //10 random words for this test

    srand(time(NULL));
    int i, j, score = 0;
    clock_t start, end; //using clock to calculate time taken

    for(i=0; i<10; i++){
        printf("Word %d: %s\n", i+1, words[i]);
        char user_input[10];
        start = clock(); //start the clock on user's input of word

        gets(user_input); //accept user's typed word (without spaces)

        end = clock(); //stop the clock after user has typed the word

        //counting score and time taken
        for(j=0; j<10; j++){
            if(user_input[j] != words[i][j]){
                printf("Incorrect! Try again.\n");
                break;
            }
            if(j == 9){
                score++;
                printf("Correct!\n");
            }
        }

        printf("Time taken: %f seconds\n", ((double)(end - start))/CLOCKS_PER_SEC); //display time taken for each word

        printf("\n");
    }

    printf("****************************************************\n");
    printf("            Congratulations on your score!            \n");
    printf("****************************************************\n\n");
    printf("Your typing speed is %d words per minute!\n", (int)(((double)score*60)/((double)(end-start))/CLOCKS_PER_SEC)); //display overall typing speed

    return 0;
}