//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 30
#define MAX_SENTENCE_LENGTH 100
#define MAX_SUMMARY_LENGTH 300

// function declarations
void get_input(char *text);
int count_sentences(char *text);
void extract_sentences(char *text, char (*sentences)[MAX_SENTENCE_LENGTH+1], int num_sentences);
int count_words(char *sentence);
int compare_sentences(const void *a, const void *b);
void summarize(char (*sentences)[MAX_SENTENCE_LENGTH+1], int num_sentences, char *summary);

// main function
int main() {
    char text[1000]; // to hold user input
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH+1]; // to hold extracted sentences
    char summary[MAX_SUMMARY_LENGTH+1]; // to hold the summary
    int num_sentences; // number of sentences in the text
    
    printf("Enter text:\n");
    get_input(text);
    
    num_sentences = count_sentences(text);
    if (num_sentences == 0) {
        printf("No sentences found in text.\n");
        return 0;
    }
    
    extract_sentences(text, sentences, num_sentences);
    qsort(sentences, num_sentences, MAX_SENTENCE_LENGTH+1, compare_sentences);
    summarize(sentences, num_sentences, summary);
    
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}

// function to get input text from user
void get_input(char *text) {
    fgets(text, 1000, stdin);
    // replace newline character with null character
    text[strcspn(text, "\n")] = '\0';
}

// function to count the number of sentences in the text
int count_sentences(char *text) {
    int count = 0;
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            count++;
        }
    }
    return count;
}

// function to extract each sentence from the text and store in the sentences array
void extract_sentences(char *text, char (*sentences)[MAX_SENTENCE_LENGTH+1], int num_sentences) {
    int sentence_index = 0;
    int i, j;
    char sentence[MAX_SENTENCE_LENGTH+1];
    
    for (i = 0; i < strlen(text); i++) {
        sentence[j] = text[i];
        j++;
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentence[j-1] = '\0';
            strcpy(sentences[sentence_index], sentence);
            sentence_index++;
            j = 0;
            if (sentence_index == num_sentences) {
                break;
            }
        }
    }
}

// function to count the number of words in a sentence
int count_words(char *sentence) {
    int count = 0;
    int i;
    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            count++;
        }
    }
    return count+1;
}

// comparison function for qsort to sort sentences in descending order based on number of words
int compare_sentences(const void *a, const void *b) {
    char *sentence1 = (char*) a;
    char *sentence2 = (char*) b;
    int num_words1 = count_words(sentence1);
    int num_words2 = count_words(sentence2);
    if (num_words1 > num_words2) {
        return -1;
    } else if (num_words1 < num_words2) {
        return 1;
    } else {
        return 0;
    }
}

// function to extract the top sentences and create the summary
void summarize(char (*sentences)[MAX_SENTENCE_LENGTH+1], int num_sentences, char *summary) {
    int i;
    int summary_length = 0;
    for (i = 0; i < num_sentences; i++) {
        int num_words = count_words(sentences[i]);
        if (num_words > 2 && summary_length + strlen(sentences[i]) < MAX_SUMMARY_LENGTH) {
            strcat(summary, sentences[i]);
            strcat(summary, " ");
            summary_length += strlen(sentences[i]) + 1;
        }
    }
}