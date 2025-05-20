//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    clock_t start, end;
    char input[100];
    int i, error=0;
    float time_taken;

    char text[] = "This is a typing speed test example. You will be given a certain set of text which you will have to type as fast and accurately as possible. Press enter to start the test. Good luck!";
    
    printf("%s\n", text);
    
    fgets(input, 100, stdin);

    // Removing newline character from input
    if(input[strlen(input) - 1] == '\n') 
        input[strlen(input) - 1] = '\0';

    // Starting timer after enter is pressed
    start = clock();

    printf("Type the following and press enter: \n%s\n", text);

    fgets(input, 100, stdin);

    // Removing newline character from input
    if(input[strlen(input) - 1] == '\n') 
        input[strlen(input) - 1] = '\0';

    // Calculating errors
    for(i = 0; i < strlen(text); i++){
        if(text[i] != input[i]){
            error++;
        }
    }

    end = clock();

    //Calculating the time taken to complete the test
    time_taken = ((float)end - (float)start) / CLOCKS_PER_SEC;

    //Printing the result
    printf("\n---------------------------------\n");
    printf("Total time elapsed: %f seconds\n", time_taken);
    printf("Errors: %d\n", error);
    printf("Typing speed: %f characters per second\n", (float)strlen(text)/time_taken);
    printf("---------------------------------\n");

    return 0;
}