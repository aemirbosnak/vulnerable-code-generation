//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>

#define SPAM_THRESHOLD 0.7 //Spam threshold probability for the input

int main() {
    char input[100]; //Input string to be analyzed
    int i, j, k, n;

    do {
        printf("Enter input string: ");
        fgets(input, 100, stdin); //Reading input from user
        n = strlen(input); //Length of input string
        input[n-1] = '\0'; //Removing trailing newline character

        //Tokenizing the input string
        char tokens[n/2][20]; //Array to store tokens
        int num_tokens = 0; //Number of tokens
        char *token = strtok(input, " ");

        while(token != NULL) {
            strcpy(tokens[num_tokens], token);
            num_tokens++;
            token = strtok(NULL, " ");
        }

        //Computing spam probability for each token
        double spam_prob[num_tokens]; //Array to store spam probability of each token
        for(i=0; i<num_tokens; i++) {
            spam_prob[i] = 0;

            if(strlen(tokens[i]) > 5 && strlen(tokens[i]) < 20) {
                for(j=0; j<strlen(tokens[i]); j++) {
                    double prob = 0;
                    for(k=0; k<strlen(tokens[i]); k++) {
                        if(k != j) {
                            if((int)tokens[i][j] == (int)tokens[i][k]) {
                                prob += 0.1;
                            }
                        }
                    }
                    spam_prob[i] += prob/strlen(tokens[i]);
                }
                spam_prob[i] /= strlen(tokens[i]);
            }
        }

        //Computing overall spam probability for the input
        double overall_spam_prob = 0; //Overall spam probability
        for(i=0; i<num_tokens; i++) {
            overall_spam_prob += spam_prob[i];
        }
        overall_spam_prob /= num_tokens;

        //Checking if input is spam or not
        if(overall_spam_prob > SPAM_THRESHOLD) {
            printf("This input is spam.\n");
        }
        else {
            printf("This input is not spam.\n");
        }
    } while(1);

    return 0;
}