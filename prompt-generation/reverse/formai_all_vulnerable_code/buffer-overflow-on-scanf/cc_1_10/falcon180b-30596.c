//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int correct = 0, incorrect = 0, total = 0;
    char sentence[100], input[100];
    FILE *file;
    time_t start, end;
    double duration;
    
    printf("Welcome to the C Typing Speed Test!\n");
    printf("In this test, you will be given a sentence to type.\n");
    printf("Type the sentence as quickly and accurately as possible.\n");
    printf("At the end of the test, your typing speed and accuracy will be displayed.\n");
    printf("Are you ready? (y/n)\n");
    scanf("%s", input);
    
    if (input[0]!= 'y' && input[0]!= 'Y') {
        printf("Exiting program...\n");
        return 0;
    }
    
    printf("Opening sentence file...\n");
    file = fopen("sentences.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    
    time(&start);
    while (fgets(sentence, 100, file)!= NULL) {
        printf("%s", sentence);
        fflush(stdout);
        if (fgets(input, 100, stdin)!= NULL) {
            total++;
            if (strcmp(sentence, input) == 0) {
                correct++;
            } else {
                incorrect++;
            }
        }
    }
    time(&end);
    duration = difftime(end, start);
    
    printf("\nTest complete!\n");
    printf("You typed %d characters in %.2f seconds.\n", total, duration);
    printf("Your typing speed is %.2f characters per second.\n", (double)total/duration);
    printf("You made %d correct keystrokes and %d incorrect keystrokes.\n", correct, incorrect);
    printf("Your typing accuracy is %.2f%%.\n", ((double)correct/(double)total)*100);
    
    fclose(file);
    return 0;
}