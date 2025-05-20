//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {

    char str[100];
    char repeat = 'y';
    int i, length, errors;
    double time_taken;
    clock_t start, end;

    while (tolower(repeat) == 'y'){

        printf("\n Type the following text as fast as you can without making any mistakes\n\n");

        // Choose one of three random texts to type
        int rand_num = rand() % 3;
        char *prompt[] = {"The quick brown fox jumps over the lazy dog",
                          "Sphinx of black quartz, judge my vow",
                          "Pack my box with five dozen liquor jugs"};

        printf("%s\n", prompt[rand_num]);

        // Start the timer
        start = clock();

        // Get the user's input
        fgets(str, 100, stdin);

        // End the timer
        end = clock();

        // Calculate the time taken
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

        // Remove new line character from fgets input
        if (str[strlen(str)-1] == '\n')
            str[strlen(str)-1] = '\0';

        // Calculate typing speed in wpm
        length = strlen(prompt[rand_num]);
        errors = 0;
        for(i = 0; str[i]; i++){
            if(str[i] != prompt[rand_num][i]){
                errors++;
            }
        }
        int wpm = ((length-errors)/5)/(time_taken/60);

        printf("\n\nCongrats! You typed at %d wpm with %.2f seconds with %d errors \n", wpm, time_taken, errors);

        //Ask user if they want to repeat test
        printf("\n\nDo you want to take the test again? (Y/N): ");
        scanf("%c", &repeat);
        fflush(stdin);
    }
    printf("\n Goodbye! \n");
    return 0;
}