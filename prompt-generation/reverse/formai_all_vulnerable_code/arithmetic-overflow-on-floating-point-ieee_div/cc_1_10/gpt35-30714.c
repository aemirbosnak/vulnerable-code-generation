//FormAI DATASET v1.0 Category: Text Summarizer ; Style: curious
#include<stdio.h>

int main() {
    printf("Welcome to the Text Summarizer program! \n");
    printf("This program will summarize a given text into a shorter version. \n");
    printf("Please enter the text you would like to summarize: \n");

    char input[5000]; //variable to hold input text
    fgets(input, 5000, stdin); //get user input

    int num_sentences = 0;
    int num_words = 1; //set to 1 to account for first word
    int num_characters = 0;

    for (int i=0; input[i]!='\0'; i++) {
        if (input[i] == '.') {
            num_sentences++;
        }
        if (input[i] == ' ') {
            num_words++;
        }
        num_characters++;
    }

    float avg_words_per_sentence = (float) num_words / num_sentences;
    float avg_characters_per_word = (float) num_characters / num_words;

    printf("\nSummary: \n");

    if (avg_words_per_sentence <= 10 && avg_characters_per_word <= 4) {
        printf("The input text is already a succinct summary.");
    } else {
        printf("The summarized text follows: \n");

        //algorithm for summarizing the text
        int j=0;
        while(j<700) {
            if (input[j] == '.' && input[j+1]==' ') {
                printf(". ");
                j += 2;
            } else {
                printf("%c", input[j]);
                j++;
            }
        }
        printf("...");
    }

    return 0;
}