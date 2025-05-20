//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include<stdio.h>

// function to calculate sentiment score
int sentiment_score(char text[]) {
    int positive_words = 0, negative_words = 0, score = 0;
    char word[50];
    FILE *fp;

    // open positive words file
    fp = fopen("positive_words.txt", "r");
    while(fscanf(fp, "%s", word) != EOF) {
        // check if word is present in text
        if(strstr(text, word) != NULL) {
            positive_words++;
        }
    }
    fclose(fp);

    // open negative words file
    fp = fopen("negative_words.txt", "r");
    while(fscanf(fp, "%s", word) != EOF) {
        // check if word is present in text
        if(strstr(text, word) != NULL) {
            negative_words++;
        }
    }
    fclose(fp);

    // calculate score
    score = (positive_words - negative_words) * 100 / (positive_words + negative_words);
    return score;
}

int main() {
    char text[1000];
    int score;

    // get input text
    printf("Enter text: ");
    fgets(text, 1000, stdin);
    text[strlen(text)-1] = '\0';

    // calculate sentiment score
    score = sentiment_score(text);

    // print result
    if(score > 0) {
        printf("Positive Sentiment\n");
    }
    else if(score < 0) {
        printf("Negative Sentiment\n");    
    }
    else {
        printf("Neutral Sentiment\n");    
    }

    return 0;
}