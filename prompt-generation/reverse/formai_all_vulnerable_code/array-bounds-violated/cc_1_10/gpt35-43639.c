//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void to_lower_case(char *word){
    int i = 0;
    while(word[i]){
        word[i] = tolower(word[i]);
        i++;
    }
}

int check_word_exist(char *word, char **words_list, int count){
    int i;
    for(i=0; i<count; i++){
        if(strcmp(words_list[i], word) == 0){
            return i;
        }
    }
    return -1;
}

void update_word_count(int *word_count, int word_index){
    if(word_index >=0){
        word_count[word_index]++;
    }
}

void print_word_count(char **words_list, int *word_count, int count){
    printf("\nFrequency of each unique word in the text is:\n\n");
    int i;
    for(i=0; i<count; i++){
        printf("'%s': %d\n", words_list[i], word_count[i]);
    }
}

int main(){
    printf("Welcome to the word frequency counter multiplayer game\n\n");
    printf("Game rules:\n1. Players will input a phrase or sentence.\n"
           "2. The program will count the frequency of each unique word in the text.\n"
           "3. The player with the highest frequency count will win the game.\n\n");

    char **words_list = (char **) malloc(MAX_WORDS * sizeof(char *));
    int *word_count = (int *) calloc(MAX_WORDS, sizeof(int));
    int num_words = 0;
    int max_word_count = 0;
    int player_num = 1;

    while(1) {
        char input_text[200];
        printf("Player %d, enter a phrase or sentence (Enter 'END' to quit): ", player_num);
        fgets(input_text, 200, stdin);
        input_text[strlen(input_text)-1] = '\0';

        if(strcmp(input_text, "END") == 0){
            break;
        }

        char *word = strtok(input_text, " ");
        while(word){
            to_lower_case(word);
            int word_index = check_word_exist(word, words_list, num_words);
            if(word_index == -1){
                words_list[num_words] = (char *) malloc(MAX_WORD_LENGTH * sizeof(char));
                strcpy(words_list[num_words], word);
                update_word_count(word_count, num_words);
                num_words++;
            }
            else{
                update_word_count(word_count, word_index);
            }
            word = strtok(NULL, " ");
        }

        printf("\nCurrent frequency of each unique word in the text is:\n\n");
        print_word_count(words_list, word_count, num_words);

        printf("\nPress any key to continue to next player...");
        getchar();
        printf("\n");

        //update player
        player_num++;
        if(player_num > 2){
            player_num = 1;
        }
    }

    printf("\n\nFinal frequency of each unique word in the text is:\n\n");
    print_word_count(words_list, word_count, num_words);

    printf("\n\nWinner of the game with %d word(s) count is Player %d\n\n", max_word_count, player_num);
    printf("Thank you for playing!\n");

    //free memory
    int i;
    for(i=0; i<num_words; i++){
        free(words_list[i]);
    }
    free(words_list);
    free(word_count);

    return 0;
}