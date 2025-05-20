//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of words to type: ");
    scanf("%d", &n);
    
    char* words[n];
    int total_words = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        words[i] = malloc(sizeof(char) * (rand() % 20 + 1));
        total_words++;
    }
    
    int correct_words = 0;
    int total_words_typed = 0;
    int total_time_spent = 0;
    
    clock_t start_time, end_time;
    
    for (int i = 0; i < n; i++) {
        start_time = clock();
        
        for (int j = 0; j < strlen(words[i]); j++) {
            char c = getchar();
            
            if (c!= words[i][j]) {
                correct_words++;
            }
        }
        
        end_time = clock();
        total_time_spent += (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
        total_words_typed++;
    }
    
    double average_words_per_second = (double)correct_words / (double)total_time_spent;
    printf("Average words per second: %.2f\n", average_words_per_second);
    printf("Total words typed: %d\n", total_words_typed);
    printf("Total words correct: %d\n", correct_words);
    printf("Total time spent: %.2f seconds\n", total_time_spent);
    
    free(words[0]);
    for (int i = 1; i < n; i++) {
        free(words[i]);
    }
    
    return 0;
}