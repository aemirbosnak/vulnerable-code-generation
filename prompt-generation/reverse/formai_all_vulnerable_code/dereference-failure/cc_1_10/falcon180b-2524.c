//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 1000

//Structure for each thread's data
typedef struct {
    char *word;
    int count;
} ThreadData;

//Function for each thread to execute
void *count_word(void *arg) {
    ThreadData *data = (ThreadData*) arg;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    //Open input file
    FILE *input_file = fopen(data->word, "r");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", data->word);
        exit(1);
    }

    //Read input file line by line
    while ((read = getline(&line, &len, input_file))!= -1) {
        //Count occurrences of word in line
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (strcmp(word, data->word) == 0) {
                count++;
            }
            word = strtok(NULL, " ");
        }
    }

    //Close input file
    fclose(input_file);

    //Print results
    printf("Thread %d finished counting '%s' in '%s'. Count: %d\n",
           pthread_self(), data->word, data->word, count);

    //Free memory
    free(line);
    free(data->word);
    free(data);

    return NULL;
}

int main() {
    int num_threads;
    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    //Read input file to get list of words
    FILE *fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", input_file);
        exit(1);
    }

    char word[100];
    while (fscanf(fp, "%s", word)!= EOF) {
        //Create thread for each word
        pthread_t thread_id;
        ThreadData *data = (ThreadData*) malloc(sizeof(ThreadData));
        data->word = strdup(word);
        pthread_create(&thread_id, NULL, count_word, data);
    }

    //Wait for all threads to finish
    pthread_exit(0);

    return 0;
}