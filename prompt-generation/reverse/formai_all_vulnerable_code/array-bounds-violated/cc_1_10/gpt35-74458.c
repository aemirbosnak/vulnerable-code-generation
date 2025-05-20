//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    //Declare variables
    int i, j, k, l, m, n, o, p, q, r, s, t;
    int count = 0, incorrect = 0;
    char input[50];
    char text[] = "The quick brown fox jumps over the lazy dog";
    
    printf("Welcome to the C Typing Speed Test! You will be given a quote to type. Let's get started:\n");
    printf("\n%s\n", text);
    printf("Press enter to begin typing...");
    
    getchar(); //Wait for user to press enter
    
    clock_t start = clock(); //Start timer
    
    for (i = 0; i < 3; i++) { //3 rounds of typing the quote
        
        printf("Round %d:\n", i+1);
        
        //Print quote for current round
        for (j = 0; j < 8; j++) {
            for (k = j*6; k < (j*6)+6; k++) {
                printf("%c", text[k]);
            }
            printf(" ");
        }
        printf("\n");
        
        //Get user input for quote
        fgets(input, sizeof(input), stdin);
        
        //Check user input against quote
        for (l = 0; l < 8; l++) {
            for (m = l*6; m < (l*6)+6; m++) {
                if (input[count] != text[m]) {
                    printf("^");
                    incorrect++;
                } else {
                    printf(" ");
                }
                count++;
            }
            printf(" ");
        }
        printf("\n");
    }
    
    clock_t end = clock(); //Stop timer
    
    float time_taken = ((float)(end - start))/CLOCKS_PER_SEC; //Calculate time taken in seconds
    
    //Calculate wpm and accuracy
    float wpm = ((float)(count/5))/time_taken * 60;
    float accuracy = ((float)(count-incorrect))/count * 100;
    
    printf("Congratulations! You have completed the C Typing Speed Test.\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Words per minute: %.2f wpm\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);
    
    return 0;
}