#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char sentence[50];
    printf("Enter a sentence: ");
    gets(sentence);
    
    if (strstr(sentence, "happy")) {
        printf("Sentiment: Positive\n");
    } else if (strstr(sentence, "sad")) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
    
    return 0;
}
