//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main() {

    char input[100];
    int positiveWords = 0, negativeWords = 0, neutralWords = 0;
    int i, words, length;
    
    char *positive[10] = {"good", "great", "awesome", "fantastic", "happy", "love", "excellent", "perfect", "nice", "best"};
    
    char *negative[10] = {"bad", "terrible", "horrible", "awful", "sad", "hate", "angry", "disappointing", "worst", "not good"};
    
    printf("Enter the sentence : ");
    gets(input);
    
    words = 0;
    length = strlen(input);
    
    while(input[i] != '\0') {
        if(input[i] == ' ') {
            words++;
        }
        i++;
    }
    
    words++;
    
    for(i = 0; i < words; i++) {
    
        for(int j = 0; j < 10; j++) {
        
            if(strstr(input, positive[j]) != NULL) {
                positiveWords++;
            }
            
            if(strstr(input, negative[j]) != NULL) {
                negativeWords++;
            }
        }
    }
    
    neutralWords = words - positiveWords - negativeWords;

    if(positiveWords > negativeWords) {
        printf("The sentence is positive. \n");
        printf("Positive words in the sentence are %d. \n", positiveWords);
    }
    
    else if(negativeWords > positiveWords) {
        printf("The sentence is negative. \n");
        printf("Negative words in the sentence are %d. \n", negativeWords);
    }
    
    else {
        printf("The sentence is neutral. \n");
        printf("Neutral words in the sentence are %d. \n", neutralWords);
    }

    return 0;
}