//FormAI DATASET v1.0 Category: Text Summarizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the summary of a text
void find_summary(char* text, int summary_length){
    
    // Tokenize the text into sentences
    char* sentence = strtok(text, "."); 
    
    // Array to store all the sentences
    char sentences[1000][1000];
    int count = 0; // Count of sentences
    
    while(sentence != NULL){
        // Add the sentence to the array
        strcpy(sentences[count], sentence);
        count++;
        sentence = strtok(NULL, ".");
    }
    
    int sentence_scores[1000]; // Array to store the score of each sentence
    int i, j;
    for(i=0; i<count; i++){
        sentence_scores[i]=0; // Initialize all scores to 0
        // Count the number of words in each sentence
        char* word = strtok(sentences[i], " ");
        int word_count = 0;
        while(word != NULL){
            word_count++;
            word = strtok(NULL, " ");
        }
        // Assign score based on sentence length
        if(word_count<=10){
            sentence_scores[i]+=3;
        }else if(word_count<=20){
            sentence_scores[i]+=2;
        }else{
            sentence_scores[i]+=1;
        }
        
        // Assign score based on presence of keywords
        if(strstr(sentences[i], "futuristic") != NULL){
            sentence_scores[i]+=2;
        }
        if(strstr(sentences[i], "technology") != NULL){
            sentence_scores[i]+=1;
        }
    }
    
    // Bubble sort the sentence scores in descending order
    for(i=0; i<count-1; i++){
        for(j=0; j<count-i-1; j++){
            if(sentence_scores[j] < sentence_scores[j+1]){
                // Swap sentences
                char temp[1000];
                strcpy(temp, sentences[j]);
                strcpy(sentences[j], sentences[j+1]);
                strcpy(sentences[j+1], temp);
                // Swap scores
                int temp_score = sentence_scores[j];
                sentence_scores[j] = sentence_scores[j+1];
                sentence_scores[j+1] = temp_score;
            }
        }
    }
    
    // Print the summary
    int summary_count = 0;
    for(i=0; i<count; i++){
        printf("%s. ", sentences[i]);
        summary_count++;
        if(summary_count == summary_length)
            break;
    }
}

// Main function
int main(){
    char text[10000]; // Input text
    printf("Enter the text to summarize:\n");
    fgets(text, 10000, stdin);
    int summary_length; // Length of summary
    printf("Enter length of summary (in sentences):\n");
    scanf("%d", &summary_length);
    printf("\nSummary:\n");
    find_summary(text, summary_length); // Call the function to find summary
    return 0;
}