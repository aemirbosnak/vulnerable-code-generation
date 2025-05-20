//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 1000

void display(char word[]) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", word);
}

int main() {
    char sentence[SIZE], input[SIZE];
    int len, i, correct=0;
    double time_spent;
    clock_t begin, end;
    
    srand(time(0));
    char words[][20] = {"programming", "algorithm", "developer", "optimization", "debugging", 
                        "computer", "software", "hardware", "application", "network"};
    int index = rand()%10;
    strcpy(sentence, words[index]);
    len = strlen(sentence);
    
    printf("\t\t\t\t\tTyping Speed Test\n\n");
    printf("Instructions:\n Type the word as quickly and accurately as possible.\n");
    printf("Press enter to start...\n");
    getchar();
    
    display(sentence);
    begin = clock();
    scanf("%[^\n]", input);
    end = clock();
    
    time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    for(i=0; i<len; i++) {
        if(sentence[i] == input[i])
            correct++;
    }
    
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\tYou've typed:\n");
    printf("\t\t\t\t\t\t\t\t\t\t  %s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", input);
    printf("Results:\n");
    printf("Time elapsed: %.2lf seconds\n", time_spent);
    printf("Characters typed correctly: %d/%d\n", correct, len);
    printf("Words per minute (WPM): %.2lf\n", ((double)correct/5)/time_spent*60);
    
    return 0;
}