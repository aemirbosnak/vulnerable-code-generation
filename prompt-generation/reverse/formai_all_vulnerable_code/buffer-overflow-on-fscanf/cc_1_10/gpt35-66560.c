//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: high level of detail
#include<stdio.h>
#include<string.h>

//Create a structure to store word and its associated sentiment score
struct Word {
    char word[50];
    int score;
};

//Function to read words and their associated scores from a file and store them in a Word struct array
void readWords(struct Word words[], char file[]) {
    FILE *fp;
    fp = fopen(file, "r");
    int i = 0;
    while(!feof(fp)) {
        fscanf(fp, "%s %d", words[i].word, &words[i].score);
        i++;
    }
    fclose(fp);
}

//Function to find sentiment score of a sentence
int getSentimentScore(char sentence[], struct Word words[], int numberOfWords) {
    //Split the sentence into words and store them in an array
    char *word;
    int i = 0;
    char *wordsArr[50];
    word = strtok(sentence, " ");
    while(word != NULL) {
        wordsArr[i++] = word;
        word = strtok(NULL, " ");
    }
    int score = 0;
    //Compare each word in the sentence with the words in the Word struct array and get its associated sentiment score
    for(int j = 0; j < i; j++) {
        for(int k = 0; k < numberOfWords; k++) {
            if(strcmp(wordsArr[j], words[k].word) == 0) {
                score += words[k].score;
                break;
            }
        }
    }
    return score;
}

int main() {
    struct Word words[30];
    int numberOfWords = 0;
    //Read words and their associated scores from a file
    readWords(words, "sentiment_scores.txt");
    numberOfWords = sizeof(words)/sizeof(struct Word);
    //Get user input
    printf("Enter a sentence: ");
    char sentence[200];
    fgets(sentence, 200, stdin);
    //Get sentiment score of the sentence
    int score = getSentimentScore(sentence, words, numberOfWords);
    if(score > 0) {
        printf("The sentence has a positive sentiment.\n");
    } else if(score < 0) {
        printf("The sentence has a negative sentiment.\n");
    } else {
        printf("The sentence has a neutral sentiment.\n");
    }
    return 0;
}