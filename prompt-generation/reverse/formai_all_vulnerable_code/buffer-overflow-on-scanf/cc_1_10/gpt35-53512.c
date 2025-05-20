//FormAI DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the maximum number of words in the summary
#define MAX_SUMMARY_WORDS 20

//function to calculate the frequency of each word
int calc_frequency(char* word, char **sentences, int num_sentences) {
    int frequency = 0;
    for(int i = 0; i < num_sentences; i++) {
        char *sentence = sentences[i];
        //split the sentence into words
        const char *delimiter_characters = " \t\n";
        char *word_copy = strdup(sentence);
        char *word_token = strtok(word_copy, delimiter_characters);
        while(word_token != NULL) {
            //if the word matches the given word, increment the frequency
            if(strcmp(word_token, word) == 0) {
                frequency++;
            }
            word_token = strtok(NULL, delimiter_characters);
        }
        free(word_copy);
    }
    return frequency;
}

//function to get the top words with highest frequency
int get_top_words(int num_words, char **sentences, int num_sentences, char **top_words) {
    char *all_words[1000];
    int num_all_words = 0;
    for(int i = 0; i < num_sentences; i++) {
        char *sentence = sentences[i];
        //split the sentence into words
        const char *delimiter_characters = " \t\n";
        char *word_copy = strdup(sentence);
        char *word_token = strtok(word_copy, delimiter_characters);
        while(word_token != NULL) {
            //add the word to the list of all words
            all_words[num_all_words] = word_token;
            num_all_words++;
            word_token = strtok(NULL, delimiter_characters);
        }
        free(word_copy);
    }
    //calculate the frequency of each unique word
    int num_unique_words = 0;
    char *unique_words[1000];
    for(int i = 0; i < num_all_words; i++) {
        char *word = all_words[i];
        int is_unique = 1;
        for(int j = 0; j < num_unique_words; j++) {
            char *unique_word = unique_words[j];
            if(strcmp(word, unique_word) == 0) {
                is_unique = 0;
                break;
            }
        }
        if(is_unique) {
            unique_words[num_unique_words] = word;
            num_unique_words++;
        }
    }
    //calculate the frequency of each unique word
    int word_frequencies[1000];
    for(int i = 0; i < num_unique_words; i++) {
        char *word = unique_words[i];
        int frequency = calc_frequency(word, sentences, num_sentences);
        word_frequencies[i] = frequency;
    }
    //sort the unique words by frequency in descending order
    for(int i = 0; i < num_unique_words; i++) {
        for(int j = i; j < num_unique_words; j++) {
            if(word_frequencies[j] > word_frequencies[i]) {
                //swap the words
                char *temp_word = unique_words[i];
                unique_words[i] = unique_words[j];
                unique_words[j] = temp_word;
                //swap the frequencies
                int temp_frequency = word_frequencies[i];
                word_frequencies[i] = word_frequencies[j];
                word_frequencies[j] = temp_frequency;
            }
        }
    }
    //get the top words with the highest frequency
    int num_top_words = num_words;
    if(num_top_words > num_unique_words) {
        num_top_words = num_unique_words;
    }
    for(int i = 0; i < num_top_words; i++) {
        top_words[i] = unique_words[i];
    }
    return num_top_words;
}

//function to extract the summary from the input text
void extract_summary(char *input_text, char *output_summary, int summary_length) {
    //split the input text into sentences
    char *sentences[1000];
    int num_sentences = 0;
    const char *delimiter_characters = ".!?";
    char *sentence_copy = strdup(input_text);
    char *sentence_token = strtok(sentence_copy, delimiter_characters);
    while(sentence_token != NULL) {
        sentences[num_sentences] = sentence_token;
        num_sentences++;
        sentence_token = strtok(NULL, delimiter_characters);
    }
    free(sentence_copy);
    //get the top words with highest frequency
    char *top_words[MAX_SUMMARY_WORDS];
    int num_top_words = get_top_words(MAX_SUMMARY_WORDS, sentences, num_sentences, top_words);
    //extract the sentences containing the top words
    char *summary_sentences[1000];
    int num_summary_sentences = 0;
    for(int i = 0; i < num_sentences; i++) {
        char *sentence = sentences[i];
        for(int j = 0; j < num_top_words; j++) {
            char *top_word = top_words[j];
            if(strstr(sentence, top_word) != NULL) {
                summary_sentences[num_summary_sentences] = sentence;
                num_summary_sentences++;
                break;
            }
        }
    }
    //combine the summary sentences into the output summary
    int summary_length_used = 0;
    for(int i = 0; i < num_summary_sentences; i++) {
        char *summary_sentence = summary_sentences[i];
        int summary_sentence_length = strlen(summary_sentence);
        if(summary_length_used + summary_sentence_length > summary_length) {
            break;
        }
        strcat(output_summary, summary_sentence);
        strcat(output_summary, ". ");
        summary_length_used += summary_sentence_length + 2;
    }
}

int main() {
    //get the input text from the user
    char input_text[10000];
    printf("Enter the input text:\n");
    fgets(input_text, sizeof(input_text), stdin);
    //get the summary length from the user
    int summary_length;
    printf("Enter the summary length (in characters):\n");
    scanf("%d", &summary_length);
    //extract the summary and print it to the console
    char output_summary[10000] = "";
    extract_summary(input_text, output_summary, summary_length);
    printf("Summary:\n%s\n", output_summary);
    return 0;
}