//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l, count = 0;
    char input[20], output[20];
    double time_spent;
    clock_t begin, end;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following random string:\n");
    
    char string[100] = "bdhjksfkrgnmeqoilaxucpytz";
    
    for(i = 0; i < 10; i++) {
        j = rand() % 20;
        output[i] = string[j];
        printf("%c ", output[i]);
    }
    
    printf("\n");
    
    begin = clock();
    
    scanf("%s", &input);
    
    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    for(k = 0, l = 0; l < strlen(input); k++, l++) {
        if(input[l] != output[k]) {
            printf("Incorrect!\n");
            count++;
        }
    }
    
    if(count == 0) {
        printf("Congratulations! You typed the string correctly!\n");
        printf("Your typing speed is: %.2f seconds per character.\n", time_spent/10);
        printf("Thanks for playing!");
    }
    else {
        printf("Better luck next time!");
    }

    return 0;

}