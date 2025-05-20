//FormAI DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>

int spam_detector(char *msg){
    // Define keywords that might indicate spam
    char keywords[5][20] = {"money", "free", "discount", "limited", "offer"};

    int i, j, len;
    char word[20];

    // Convert the message to lowercase for case-insensitive detection
    for(i=0, len=strlen(msg); i<len; i++){
        if(msg[i] >= 'A' && msg[i] <= 'Z'){
            msg[i] = msg[i] + 32;
        }
    }

    // Check if the message contains any of the keywords
    for(i=0; i<5; i++){
        j=0;
        while(msg[j] != '\0'){
            // Check for word boundary
            if(msg[j-1] != ' ' && j != 0){
                j++;
                continue;
            }

            // Extract word from message
            sscanf(msg+j, "%s", word);

            // Compare word with keyword
            if(strcmp(word, keywords[i]) == 0){
                return 1;
            }

            j += strlen(word);
        }
    }

    // If none of the keywords were found, assume message is not spam
    return 0;
}

int main(){
    char msg[100];

    // Prompt user for message input
    printf("Enter message: ");
    fgets(msg, 100, stdin);

    // Remove newline character from message
    if(msg[strlen(msg)-1] == '\n'){
        msg[strlen(msg)-1] = '\0';
    }

    // Check if message is spam
    if(spam_detector(msg)){
        printf("Spam detected!");
    } else {
        printf("Not spam.");
    }

    return 0;
}