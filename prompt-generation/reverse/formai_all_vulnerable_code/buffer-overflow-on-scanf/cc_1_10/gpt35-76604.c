//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

char *random_words[MAX_WORDS];
int num_words = 0;

void load_words(){
    FILE *fp;
    fp = fopen("words.txt", "r");
    if(fp == NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char buffer[MAX_WORD_LEN];
    while(fgets(buffer, MAX_WORD_LEN, fp)){
        buffer[strcspn(buffer, "\n")] = 0;
        random_words[num_words] = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(random_words[num_words], buffer);
        num_words++;
    }
    fclose(fp);
}

void free_words(){
    for(int i=0; i<num_words; i++){
        free(random_words[i]);
    }
}

void shuffle(char *arr[], int n){
    srand(time(NULL));
    for(int i=n-1; i>0; i--){
        int j = rand() % (i+1);
        char *temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    int num_tests;
    printf("Welcome to the Paranoid Typing Speed Test\n");
    printf("Are you ready to prove your typing abilities? (yes or no): ");
    char response[5];
    scanf("%s", response);
    if(strcmp(response, "yes") !=0){
        printf("Oh, come on! Let's give it a try!.\n");
        return 0;
    }
    printf("Great! Let's start with how many words you want to type : ");
    scanf("%d", &num_tests);
    if(num_tests <= 0){
        printf("Invalid input!\n");
        return 1;
    }
    load_words();
    shuffle(random_words, num_words);
    printf("I'll give you %d words to type. Ready? (yes or no): ", num_tests);
    scanf("%s", response);
    if(strcmp(response, "yes")!=0){
        printf("You don't seem to be confident. Try again next time.\n");
        free_words();
        return 0;
    }
    printf("-----------------------------------------\n");
    printf("Type the following words:\n");
    int num_correct = 0;
    clock_t start_time = clock();
    for(int i=0; i<num_tests; i++){
        printf(">%s\n", random_words[i]);
        char typed_word[MAX_WORD_LEN];
        scanf("%s", typed_word);
        if(strcmp(typed_word, random_words[i]) == 0){
            num_correct++;
        }
    }
    clock_t end_time = clock();
    float typing_time = (float) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("-----------------------------------------\n");
    printf("Results:\n");
    printf("Number of correct words: %d\n", num_correct);
    printf("Accuracy: %.2f%%\n", (float) num_correct / num_tests * 100);
    printf("Typing time: %.2f seconds\n", typing_time);
    printf("Typing speed: %.2f words per minute\n", (float) num_tests / typing_time * 60);
    free_words();
    return 0;
}