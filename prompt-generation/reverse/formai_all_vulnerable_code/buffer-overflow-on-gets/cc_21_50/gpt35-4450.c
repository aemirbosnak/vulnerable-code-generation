//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

int main(){
    char text[1000], temp[1000];
    int i, j;
    int positive = 0, negative = 0, neutral = 0;

    printf("Enter the text to be analyzed:\n");
    gets(text);

    for(i=0; text[i]!='\0'; i++){
        if(text[i] == ' ' || text[i] == '\n' || text[i] == '\t'){
            temp[j] = '\0';

            if(strcmp(temp, "loved")==0 || strcmp(temp, "love")==0 || strcmp(temp, "like")==0 || strcmp(temp, "happy")==0 || strcmp(temp, "joy")==0 || strcmp(temp, "wins")==0 || strcmp(temp, "appreciate")==0 || strcmp(temp, "pleasure")==0){
                positive++;
            }
            else if(strcmp(temp, "hate")==0 || strcmp(temp, "despise")==0 || strcmp(temp, "kill")==0 || strcmp(temp, "sad")==0 || strcmp(temp, "anguish")==0 || strcmp(temp, "loses")==0 || strcmp(temp, "dislike")==0 || strcmp(temp, "pain")==0){
                negative++;
            }
            else{
                neutral++;
            }
            j=0;
        }
        else{
            temp[j++] = text[i];
        }
    }

    printf("\n%s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n%s", "Romeo's Sentiment Analysis Tool");
    printf("\n%s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n%s", "          ___");
    printf("\n%s", "     . -^   `--,");
    printf("\n%s", "    /#_/^ _^  `\\");
    printf("\n%s", "  .'//^ ^/^ '^ `\\");
    printf("\n%s", " /'/^/^^ ^ ^^\\^\\`\\ ");
    printf("\n%s", "  \\|^\\|^ ^ ^|/|^\\|");
    printf("\n%s", "   \\ \\ \\^_^_/ / /__");
    printf("\n%s", "    `\\\\/Q\\ /Q\\/..\\`-.");
    printf("\n%s", "      `\\_\\/_\\/_/ ..\\`-.");
    printf("\n%s", "        `\\ \\ . \\ \\;:`:`:`:`:`!:`:`:`\\:");
    printf("\n%s", "          `\\ \\ `.\\:`:`:`:`:`\\`\\:`:`\\;");
    printf("\n%s", "            `\\ \\ !:`:`:`\\:`\\:`\\`\\:;");
    printf("\n%s", "              `\\ `:`:`\\:`\\ \\:`\\`\\;");
    printf("\n%s", "              _|_`.\\:`:`:`:`:`.`\\:\\:");
    printf("\n%s", "             / `|`. `\\:||\n");

    if(positive > negative){
        printf("\n%s", "O, she doth teach the torches to burn bright!");
        printf("\n%s", "This code is full of love and light");
    }
    else if(negative > positive){
        printf("\n%s", "O, I am fortune's fool!");
        printf("\n%s", "This code is full of negative fuel");
    }
    else{
        printf("\n%s", "Good night, good night! Parting is such sweet sorrow,");
        printf("\n%s", "This code is true to the neutral hollow");
    }

    printf("\n%s", "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printf("\n\nSentiment Analysis Results:");
    printf("\nPositive words: %d", positive);
    printf("\nNegative words: %d", negative);
    printf("\nNeutral words: %d", neutral);

    return 0;
}