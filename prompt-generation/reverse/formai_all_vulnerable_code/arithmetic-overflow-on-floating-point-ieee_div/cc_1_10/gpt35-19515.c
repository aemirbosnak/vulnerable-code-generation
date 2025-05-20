//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, count, correct = 0, incorrect = 0;
    char c;
    char *str[10] = {"Hello World", "Olympic Games", "Apple Pie", "New Year's Eve", "Star Wars", 
                     "Winter Wonderland", "Black Lives Matter", "Happy Birthday", "The Lion King", "Harry Potter"};

    printf("Welcome to the Typing Speed Test Program!\n");
    printf("You will be given 10 random phrases to type accurately within a specified time limit.\n");
    printf("Type the phrase and press Enter to proceed to the next one. Ready? Press Enter to begin.\n");
    getchar();

    srand(time(NULL)); // seed for random phrases

    for(i=0; i<10; i++) {
        count = 0;

        printf("Phrase %d: ", i+1);
        j = rand() % 10;
        for(k=0; k<strlen(str[j]); k++) {
            printf("%c", str[j][k]); // display phrase
            count++; // count length of phrase
        }

        time_t start = time(NULL); // start timer
        while((c=getchar()) != '\n') {
            if(c == str[j][correct]) {
                correct++;
                printf("%c", c);
            } 
            else {
                incorrect++;
                printf("*"); // display asterisk for incorrect characters
            }
        }
        time_t end = time(NULL); // end timer

        double time_taken = difftime(end, start);
        double cps = correct/time_taken;

        printf("\nTyping Speed: %.2lf cps (%d correct, %d incorrect)\n", cps, correct, incorrect);
        printf("You typed %d out of %d characters accurately.\n\n", correct, count);

        correct = 0; //reset counters for next phrase
        incorrect = 0;
    }

    printf("Thank you for using the Typing Speed Test Program!\n");

    return 0;
}