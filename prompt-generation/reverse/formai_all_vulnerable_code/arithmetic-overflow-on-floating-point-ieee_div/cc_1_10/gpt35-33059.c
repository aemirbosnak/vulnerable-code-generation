//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_WORDS 5
#define MAX_WORD_LENGTH 10

char* get_random_word();
void display_words(int num_words, char* words[]);
double calculate_typing_speed(double time, int num_words);

int main()
{
    char* words[MAX_WORDS];
    double start_time, end_time, elapsed_time, typing_speed;
    int i, num_words = MAX_WORDS;

    srand(time(NULL));
    
    for(i = 0; i < num_words; i++)
    {
        words[i] = get_random_word();
    }
    
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following %d words and hit enter:\n", num_words);
    display_words(num_words, words);
    
    start_time = clock();
    
    char input[MAX_WORDS*MAX_WORD_LENGTH];
    fgets(input, MAX_WORDS*MAX_WORD_LENGTH, stdin);
    
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    typing_speed = calculate_typing_speed(elapsed_time, num_words);
    
    printf("\n\nTime Elapsed: %.2fs\nTyping Speed: %.0f WPM\n", elapsed_time, typing_speed);

    return 0;
}

char* get_random_word()
{
    char* words[MAX_WORDS] = {"apple", "banana", "cherry", "orange", "pear"};
    int random_index = rand() % MAX_WORDS;
    return words[random_index];
}

void display_words(int num_words, char* words[])
{
    int i;
    for(i = 0; i < num_words; i++)
    {
        printf("%-10s ", words[i]);
    }
    printf("\n");
}

double calculate_typing_speed(double time, int num_words)
{
    double minutes = time / 60.0;
    double words_per_minute = num_words / minutes;
    return words_per_minute;
}