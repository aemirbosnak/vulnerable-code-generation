//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCHAR 100 // maximum characters in a word
#define MAXWORDS 100 // maximum number of words in a document

int main()
{
    char document[MAXWORDS][MAXCHAR];
    char dict[MAXWORDS][MAXCHAR];
    int doc_size, dict_size;
    int i, j, k;
    int matches[MAXWORDS][MAXWORDS] = {0};
    int player1_score = 0, player2_score = 0;

    // Get the document from player 1
    printf("Player 1, please enter the document with words separated by spaces:\n");
    fgets(document[0], MAXCHAR, stdin);
    doc_size = 1;
    for(i=0; i<strlen(document[0]); i++){
        if(document[0][i] == ' '){
            doc_size++;
            if(doc_size == MAXWORDS){
                break;
            }
        }
    }
    for(i=1; i<doc_size; i++){
        scanf("%s", document[i]);
    }

    // Get the dictionary from player 2
    printf("\nPlayer 2, please enter the dictionary with words separated by spaces:\n");
    fgets(dict[0], MAXCHAR, stdin);
    dict_size = 1;
    for(i=0; i<strlen(dict[0]); i++){
        if(dict[0][i] == ' '){
            dict_size++;
            if(dict_size == MAXWORDS){
                break;
            }
        }
    }
    for(i=1; i<dict_size; i++){
        scanf("%s", dict[i]);
    }

    // Count the number of matches between words in the document and dictionary
    for(i=0; i<doc_size; i++){
        for(j=1; j<dict_size; j++){
            int doc_len = strlen(document[i]);
            int dict_len = strlen(dict[j]);
            if(doc_len == dict_len){
                int m = 1;
                for(k=0; k<doc_len; k++){
                    if(document[i][k] != dict[j][k]){
                        m = 0;
                        break;
                    }
                }
                if(m){
                    matches[i][j] = 1;
                }
            }
        }
    }

    // Play the game
    for(i=0; i<doc_size; i++){
        int found = 0;
        for(j=1; j<dict_size; j++){
            if(matches[i][j]){
                found = 1;
                printf("%s ", document[i]);
                if(i%2 == 0){
                    player1_score++;
                } else{
                    player2_score++;
                }
                break;
            }
        }
        if(!found){
            printf("[X] ");
        }
    }

    // Display the scores
    printf("\n\nPlayer 1 score: %d\nPlayer 2 score: %d\n", player1_score, player2_score);

    return 0;
}