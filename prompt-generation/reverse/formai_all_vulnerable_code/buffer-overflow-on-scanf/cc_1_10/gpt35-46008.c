//FormAI DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10 // maximum number of spam words to detect
#define MAX_MESSAGE_LENGTH 1024 // maximum length of a message to check
#define SPAM_THRESHOLD 0.5 // percentage of spam words in a message to be considered spam

int check_spam(char *message, int message_length, char spam_words[MAX_SPAM_WORDS][50], int num_spam_words);
// function to check a message for spam words

int main(){
    char message[MAX_MESSAGE_LENGTH];
    char spam_words[MAX_SPAM_WORDS][50];
    int num_spam_words;
    int message_length;

    // get spam words from user
    printf("Enter the number of spam words to detect: ");
    scanf("%d", &num_spam_words);
    printf("Enter the spam words:\n");
    for(int i=0; i<num_spam_words; i++){
        scanf("%s", spam_words[i]);
    }

    // get message from user
    printf("Enter a message to check for spam: ");
    getchar(); // remove newline character left in buffer
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // check for spam
    if(check_spam(message, message_length, spam_words, num_spam_words)){
        printf("The message contains spam.\n");
    }
    else{
        printf("The message is clean.\n");
    }

    return 0;
}

int check_spam(char *message, int message_length, char spam_words[MAX_SPAM_WORDS][50], int num_spam_words){
    int num_spam_occurrences = 0;

    for(int i=0; i<num_spam_words; i++){
        char *word = spam_words[i];
        int word_length = strlen(word);

        for(int j=0; j<message_length-word_length+1; j++){
            if(strncmp(&message[j], word, word_length) == 0){
                num_spam_occurrences++;
            }
        }
    }

    float spam_ratio = (float)num_spam_occurrences / (float)strlen(message);
    if(spam_ratio >= SPAM_THRESHOLD){
        return 1;
    }
    else{
        return 0;
    }
}