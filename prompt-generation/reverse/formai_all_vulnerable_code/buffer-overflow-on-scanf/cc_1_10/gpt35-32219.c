//FormAI DATASET v1.0 Category: Spell checking ; Style: surprised
#include<stdio.h>
#include<string.h>

int main(){

    printf("Welcome to the Spell Checker program!\n");

    char dictionary[100][100] = {"apple", "banana", "cherry", "orange", "pear", "grape", "pineapple", "watermelon", "papaya", "strawberry"}; //Dictionary of common words
    int dict_length = 10; //Number of words in dictionary

    char input[100];
    printf("Please enter a word to check its spelling: ");
    scanf("%s", input);

    int found = 0;
    for(int i=0; i<dict_length; i++){
        if(strcmp(input, dictionary[i]) == 0){ //Compare input with each word in the dictionary
            found = 1; //If match found, set found to 1
            break; //Stop searching the dictionary
        }
    }

    if(found){
        printf("%s is spelled correctly!\n", input);
    } else {
        printf("Did you mean ");
        for(int i=0; i<dict_length; i++){
            int distance = levenshtein_distance(input, dictionary[i]); //Calculate the Levenshtein distance between the input and each word in dictionary
            if(distance == 1){ //If distance is 1 (meaning only one character needs to be added, deleted, or replaced), suggest the word
                printf("%s, ", dictionary[i]);
            }
        }
        printf("?\n");
    }

    return 0;
}

int levenshtein_distance(char *s1, char *s2){
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int matrix[s1len+1][s2len+1];

    for(int i=0; i<=s1len; i++){
        matrix[i][0] = i;
    }
    for(int j=0; j<=s2len; j++){
        matrix[0][j] = j;
    }

    for(int j=1; j<=s2len; j++){
        for(int i=1; i<=s1len; i++){
            if(s1[i-1] == s2[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int minimum = matrix[i-1][j] + 1;
                if(matrix[i][j-1]+1 < minimum){
                    minimum = matrix[i][j-1]+1;
                }
                if(matrix[i-1][j-1]+1 < minimum){
                    minimum = matrix[i-1][j-1]+1;
                }
                matrix[i][j] = minimum;
            }
        }
    }

    return matrix[s1len][s2len];
}