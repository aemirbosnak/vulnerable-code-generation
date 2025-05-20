//FormAI DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_TEXT_SIZE 10000
#define MAX_SENTENCES 1000

char text[MAX_TEXT_SIZE], summary[MAX_TEXT_SIZE];

//helper function to get the number of sentences in the text
int get_sentence_count(char *text){
    int count = 0;
    for(int i=0; text[i]!='\0'; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            count++;
        }
    }
    return count;
}

//helper function to get the index of nth sentence in the text
int get_nth_sentence_index(char *text, int n){
    int count = 0, i;
    for(i=0; text[i]!='\0'; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            count++;
            if(count == n){
                break;
            }
        }
    }
    return i+1; //returning next index after the delimiter
}

//main function for text summarization
void summarize_text(char *text, int num_sentences){
    int total_sentences = get_sentence_count(text);
    if(num_sentences >= total_sentences){ //if number of sentences required is more than the available sentences
        strcpy(summary, text);
        return;
    }

    int *selected_sentences = (int*)malloc(num_sentences * sizeof(int));
    if(selected_sentences == NULL){
        printf("Error: Memory allocation failed!");
        exit(1);
    }

    //selecting the nth sentence using a simplified approach for this example program
    for(int i=1; i<=num_sentences; i++){
        selected_sentences[i-1] = get_nth_sentence_index(text, i);
    }

    //sorting the selected sentence indexes in ascending order
    for(int i=0; i<num_sentences-1; i++){
        for(int j=i+1; j<num_sentences; j++){
            if(selected_sentences[i] > selected_sentences[j]){
                int temp = selected_sentences[i];
                selected_sentences[i] = selected_sentences[j];
                selected_sentences[j] = temp;
            }
        }
    }

    //constructing the summary by copying the selected sentences
    int i = 0, j = 0, k = 0;
    while(text[i] != '\0'){
        if(i == selected_sentences[j]){
            while(text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != '\0'){
                summary[k++] = text[i++];
            }
            summary[k++] = text[i++];
            summary[k++] = ' ';
            j++;
            if(j == num_sentences){
                break;
            }
        }
        else{
            i++;
        }
    }
    summary[k] = '\0';

    free(selected_sentences); //freeing the dynamically allocated array
}

int main(){
    printf("Enter the text to be summarized: \n");
    fgets(text, MAX_TEXT_SIZE, stdin); //reading the input text from user
    text[strlen(text)-1] = '\0';

    int num_sentences;
    printf("Enter the number of sentences required in the summary: ");
    scanf("%d", &num_sentences);

    summarize_text(text, num_sentences);
    printf("\nSummary:\n");
    printf("%s\n", summary);
    
    return 0;
}