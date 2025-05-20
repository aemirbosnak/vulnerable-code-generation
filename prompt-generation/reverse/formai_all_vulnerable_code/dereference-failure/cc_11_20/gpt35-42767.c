//FormAI DATASET v1.0 Category: Text processing ; Style: creative
//This program reads in a text file, tokenize it, and creates a map of 
//each word's frequency. Then, it outputs the most commonly repeated word(s).

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define MAX_BUF_SIZE 4096
#define MAX_WORD_SIZE 40

int main(int argc, char* argv[]){

    //Check for arguments (file path)
    if(argc < 2){
        printf("Usage: %s <file>", argv[0]);
        return 1;
    }

    //Open file
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("File not found or cannot be read.");
        return 1;
    }

    //Create map
    char word[MAX_WORD_SIZE], buf[MAX_BUF_SIZE], cur;
    int i, j, word_count;
    unsigned int hash = 0;

    int** map = malloc(sizeof(int*) * 26);
    for(i=0; i<26; i++){ //Initialize all values to 0
        map[i] = calloc(sizeof(int), 26);
    }

    //Tokenize file
    while(fgets(buf, MAX_BUF_SIZE, fp) != NULL){

        i = 0, j = 0, word_count = 0;

        while(buf[i] != '\0'){

            cur = buf[i];

            //Check if current character is alphabetic
            if(isalpha(cur)){

                //Convert any capital letters to lowercase
                if(isupper(cur)){
                    cur = tolower(cur);
                }

                //Add current letter to current word
                word[j] = cur;

                //Check if word is too long
                if(j == MAX_WORD_SIZE){
                    printf("Error: Word is too long.");
                    return 1;
                }

                j++;

            } else { //Current character is not alphabetic

                if(j > 0){

                    //Terminate current word
                    word[j] = '\0';

                    //Calculate hash for current word
                    for(i=0; i<strlen(word); i++){
                        hash += (unsigned int) word[i];
                    }

                    //Increment frequency of current word
                    map[hash % 26][word_count]++;

                    //Reset variables for current word and hash
                    memset(word, 0, MAX_WORD_SIZE);
                    hash = 0;
                    word_count++;

                    //Check if there are too many unique words
                    if(word_count == 26){
                        printf("Error: Too many unique words.");
                        return 1;
                    }

                }

                //Reset variables for current character and current word
                j = 0;
                memset(&cur, 0, sizeof(char));

            }

            i++;

        }

    }

    //Close file
    fclose(fp);

    //Find most commonly repeated word(s)
    int max_freq = 0;
    for(i=0; i<26; i++){
        for(j=0; j<26; j++){
            if(map[i][j] > max_freq){
                max_freq = map[i][j];
            }
        }
    }

    //Output most commonly repeated words
    printf("Most commonly repeated word(s):");
    for(i=0; i<26; i++){
        for(j=0; j<26; j++){
            if(map[i][j] == max_freq){
                printf(" %c", (char) (i+97));
            }
        }
    }

    //Free memory used by map
    for(i=0; i<26; i++){
        free(map[i]);
    }
    free(map);

    return 0;

}