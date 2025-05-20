//FormAI DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_INPUT_LENGTH 1000

char spam_words[MAX_SPAM_WORDS][MAX_INPUT_LENGTH]; // array to store spam words
int spam_count[MAX_SPAM_WORDS] = {0}; // array to store corresponding spam counts

int main() {
    int num_spam_words = 0; // variable to store number of spam words present
    char input[MAX_INPUT_LENGTH]; // variable to store user input

    printf("Enter the number of spam words: ");
    scanf("%d", &num_spam_words);

    // loop to get all the spam words from the user
    for(int i=0; i<num_spam_words; i++) {
        printf("Enter spam word %d: ", i+1);
        scanf("%s", spam_words[i]); // read the spam word and store it in array
    }

    printf("\n\nSpam detection system initialized...\n\n");

    // loop to get input from user and check for spam words
    while(1) {
        printf("Enter text: ");
        scanf("%[^\n]%*c", input); // read the user input until newline character is encountered

        // check if user wants to quit
        if(strcmp(input, "quit") == 0) {
            printf("Exiting spam detection system...\n");
            break;
        }

        // loop to check if spam words are present in user input or not
        for(int i=0; i<num_spam_words; i++) {
            char *match = strstr(input, spam_words[i]); // search for spam word in user input

            if(match != NULL) { // if spam word is present in user input
                spam_count[i]++; // increment the spam count for this spam word
            }
        }
    }

    // loop to print the spam count for each spam word
    for(int i=0; i<num_spam_words; i++) {
        printf("'%s' spam count: %d\n", spam_words[i], spam_count[i]);
    }

    return 0; // exit program
}