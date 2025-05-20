//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char * dictionary[MAX_WORDS] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "indian gooseberry", "jackfruit",
                                "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine",
                                "watermelon", "apricot", "blueberry", "coconut", "durian", "elderflower", "grapefruit", "berry", "jujube", "lime",
                                "mulberry", "olive", "peach", "plum", "pomegranate", "pineapple", "raisin", "redcurrant", "sultana", "tomato",
                                "ugli fruit", "vanilla bean", "yellow watermelon", "zucchini", "acai", "boysenberry", "cantaloupe", "dragonfruit", "eggplant", "feijoa" };

int compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printWord(char * word){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        printf("%c",word[i]);
    }
    printf("\n");
}

int main(){
    
    printf("Welcome to the Typing Speed Test!\n");

    int numWords = 10;
    printf("How many words do you want to type? (default is 10): ");
    char input[5];
    fgets(input,sizeof(input),stdin);
    if(input[0] != '\n'){
        numWords = atoi(input);
    }

    printf("Get ready to type:\n");

    int wordIndexes[numWords];
    for(int i = 0; i < numWords; i++){
        wordIndexes[i] = i;
    }
    shuffle(wordIndexes,numWords);

    int start = clock();
    int correct = 0;
    for(int i = 0; i < numWords; i++){
        char * word = dictionary[wordIndexes[i]];
        printWord(word);
        char input[MAX_WORD_LENGTH+1];
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")] = 0;
        if(strcmp(word,input) == 0){
            correct++;
        }
    }

    int end = clock();
    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nYou typed %d out of %d words correctly in %.2f seconds.\n",correct,numWords,elapsed);
    printf("Your typing speed was %.2f words per minute.\n",(60.0*correct)/elapsed);

    return 0;
}