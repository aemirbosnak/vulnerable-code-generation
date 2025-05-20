//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_WORDS 10
#define MAX_CHARS_PER_WORD 10

// Generates a random string of characters
char *gen_rand_string(int length){
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *random_string = malloc(sizeof(char) * (length + 1));
    int key;
    srand(time(NULL));

    if (random_string){
        for (int i = 0; i < length; i++) {
            key = rand() % (int)(sizeof(charset) - 1);
            random_string[i] = charset[key];
        }
        random_string[length] = '\0';
    }
    return random_string;
}

int main(){
    char *words[MAX_WORDS];
    int word_lengths[MAX_WORDS];
    int no_of_words, total_chars, correct_chars = 0, wrong_chars = 0;;
    double time_taken;
    clock_t start, end;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a set of words and you will need to type them as fast and accurately as possible.\n");
    printf("Enter the number of words to type: ");
    scanf("%d", &no_of_words);

    for(int i = 0; i < no_of_words; i++){
        words[i] = gen_rand_string(MAX_CHARS_PER_WORD);
        word_lengths[i] = strlen(words[i]);
        total_chars += word_lengths[i];
    }

    printf("Type the following words: \n");

    for(int i = 0; i < no_of_words; i++){
        printf("%s ", words[i]);
    }

    printf("\n");

    start = clock();

    for(int i = 0; i < no_of_words; i++){
        char input[MAX_CHARS_PER_WORD];
        scanf("%s", input);

        if(strcmp(input, words[i]) == 0){
            correct_chars += word_lengths[i];
        }
        else {
            wrong_chars += word_lengths[i];
        }
    }

    end = clock();

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);
    printf("Total characters: %d\n", total_chars);
    printf("Correct characters: %d\n", correct_chars);
    printf("Wrong characters: %d\n", wrong_chars);
    printf("Accuracy: %f%%\n", ((double) correct_chars)*100/total_chars);

    return 0;
}