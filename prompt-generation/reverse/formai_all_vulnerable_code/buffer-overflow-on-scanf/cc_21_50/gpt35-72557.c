//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include<stdio.h>
#include<string.h>

//function to determine sentiment of a given string
int sentiment_analysis(char *string) {
    int sentiment = 0;
    int length = strlen(string);
    int i;

    //iterating through each character of the string
    for(i=0; i<length; i++) {
        
        //checking for positive words
        if((string[i] == 'g' || string[i] == 'G') && (string[i+1] == 'o' || string[i+1] == 'O') && (string[i+2] == 'o' || string[i+2] == 'O') && (string[i+3] == 'd' || string[i+3] == 'D')) {
            sentiment++;
        }
        if((string[i] == 'h' || string[i] == 'H') && (string[i+1] == 'a' || string[i+1] == 'A') && (string[i+2] == 'p' || string[i+2] == 'P') && (string[i+3] == 'p' || string[i+3] == 'P') && (string[i+4] == 'y' || string[i+4] == 'Y')) {
            sentiment++;
        }
        if((string[i] == 'a' || string[i] == 'A') && (string[i+1] == 'm' || string[i+1] == 'M') && (string[i+2] == 'a' || string[i+2] == 'A') && (string[i+3] == 'z' || string[i+3] == 'Z') && (string[i+4] == 'i' || string[i+4] == 'I') && (string[i+5] == 'n' || string[i+5] == 'N') && (string[i+6] == 'g' || string[i+6] == 'G')) {
            sentiment++;
        }
        if((string[i] == 'e' || string[i] == 'E') && (string[i+1] == 'x' || string[i+1] == 'X') && (string[i+2] == 'c' || string[i+2] == 'C') && (string[i+3] == 'e' || string[i+3] == 'E') && (string[i+4] == 'l' || string[i+4] == 'L') && (string[i+5] == 'l' || string[i+5] == 'L') && (string[i+6] == 'e' || string[i+6] == 'E') && (string[i+7] == 'n' || string[i+7] == 'N') && (string[i+8] == 't' || string[i+8] == 'T')) {
            sentiment++;
        }
        
        //checking for negative words
        if((string[i] == 'b' || string[i] == 'B') && (string[i+1] == 'a' || string[i+1] == 'A') && (string[i+2] == 'd' || string[i+2] == 'D')) {
            sentiment--;
        }
        if((string[i] == 's' || string[i] == 'S') && (string[i+1] == 'a' || string[i+1] == 'A') && (string[i+2] == 'd' || string[i+2] == 'D')) {
            sentiment--;
        }
        if((string[i] == 'h' || string[i] == 'H') && (string[i+1] == 'u' || string[i+1] == 'U') && (string[i+2] == 'r' || string[i+2] == 'R') && (string[i+3] == 't' || string[i+3] == 'T') && (string[i+4] == 'i' || string[i+4] == 'I') && (string[i+5] == 'n' || string[i+5] == 'N' ) && (string[i+6] == 'g' || string[i+6] == 'G')) {
            sentiment--;
        }
        if((string[i] == 'n' || string[i] == 'N') && (string[i+1] == 'e' || string[i+1] == 'E') && (string[i+2] == 'g' || string[i+2] == 'G') && (string[i+3] == 'a' || string[i+3] == 'A') && (string[i+4] == 't' || string[i+4] == 'T') && (string[i+5] == 'i' || string[i+5] == 'I') && (string[i+6] == 'v' || string[i+6] == 'V') && (string[i+7] == 'e' || string[i+7] == 'E')) {
            sentiment--;
        }
        
    }

    return sentiment;
}

//main function to test the sentiment_analysis function
int main() {
    char input[100];
    int sentiment;

    printf("Enter a string to analyze the sentiment:\n");
    scanf("%[^\n]s", input);

    sentiment = sentiment_analysis(input);

    if(sentiment > 0) {
        printf("This is a positive sentiment.\n");
    }
    else if(sentiment < 0) {
        printf("This is a negative sentiment.\n");
    }
    else {
        printf("This is a neutral sentiment.\n");
    }

    return 0;
}