//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for sentiment polarity
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// define constants for sentiment analysis threshold
#define POS_THRESHOLD 0.5
#define NEG_THRESHOLD -0.5

// define structure for holding word and its polarity
typedef struct{
    char word[50];
    int polarity;
} Word;

// function to read and store words and their polarities from a file
Word* read_words(char* filename, int len){
    FILE *file = fopen(filename, "r"); // open file
    if (file == NULL) {  // check if file exists
        printf("File %s not found.\n", filename);
        return NULL;
    }

    Word* words = malloc(len * sizeof(Word)); // allocate memory for Word array
    char line[100]; // buffer for reading each line from file

    for(int i=0;i<len;i++){
        fgets(line, sizeof(line), file); // read line from file
        line[strlen(line)-1] = '\0'; // remove newline character

        char* ptr = strchr(line, ','); // find comma
        *ptr = '\0'; // replace with null character
        ptr++; // move pointer to next word

        strcpy(words[i].word, ptr); // copy word to struct

        int score = atoi(line); // convert polarity score to integer
        if(score > 0){
            words[i].polarity = POSITIVE; // set positive polarity
        }
        else if(score < 0){
            words[i].polarity = NEGATIVE; // set negative polarity
        }
        else{
            words[i].polarity = NEUTRAL; // set neutral polarity
        }
    }

    fclose(file); // close file
    return words; // return Word array
}

// function to perform sentiment analysis on a text
int sentiment_analysis(char* text, Word* words, int len){
    char* token = strtok(text, " "); // get first word in text

    int polarity_sum = 0; // initialize polarity sum to 0
    int word_count = 0; // initialize word count to 0

    while(token != NULL){ // loop through all words in text
        for(int i=0;i<len;i++){
            if(strcmp(words[i].word, token) == 0){ // check if word is present in polarity dictionary
                polarity_sum += words[i].polarity; // add polarity to sum
                word_count++; // increment word count
                break; // break out of loop when matching word is found
            }
        }
        token = strtok(NULL, " "); // get next word in text
    }

    if(word_count == 0){ // check for empty text
        return NEUTRAL;
    }

    double polarity_avg = (double)polarity_sum / word_count; // calculate polarity average

    if(polarity_avg > POS_THRESHOLD){ // check for positive polarity
        return POSITIVE;
    }
    else if(polarity_avg < NEG_THRESHOLD){ // check for negative polarity
        return NEGATIVE;
    }
    else{ // otherwise return neutral polarity
        return NEUTRAL;
    }
}

// main function
int main(){
    char text[1000]; // buffer for reading input text
    Word* words = read_words("polarity.txt", 354); // read and store words and their polarities

    printf("Enter text (max 1000 characters):\n");
    fgets(text, sizeof(text), stdin); // read input text from user
    text[strlen(text)-1] = '\0'; // remove newline character

    int result = sentiment_analysis(text, words, 354); // perform sentiment analysis on input text

    switch(result){ // display sentiment analysis result
        case POSITIVE:
            printf("Positive sentiment detected.\n");
            break;
        case NEGATIVE:
            printf("Negative sentiment detected.\n");
            break;
        default:
            printf("Neutral sentiment detected.\n");
            break;
    }

    free(words); // free memory allocated for Word array

    return 0;
}