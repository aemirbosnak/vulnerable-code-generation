//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char *str1 = "Type as fast as you can to survive!";
    char *str2 = "The zombies are coming...";
    char *str3 = "Be quick or be turned into a zombie yourself!";
    char *str4 = "Press enter to begin...";
    char *words[] = {"survivor", "apocalypse", "zombie", "desolate", "wasteland", "scavenger", "mutant", "hazardous", "radiation", "outpost"};
    int words_count = 10, correct_words = 0, incorrect_words = 0;
    double time_taken = 0.0;

    printf("%s\n%s\n%s\n%s", str1, str2, str3, str4);
    getchar();
    printf("Ready...Set...GO!\n");

    clock_t start = clock();

    for(int i=0; i<words_count; i++)
    {
        int rand_index = rand()%words_count;
        printf("%s: ", words[rand_index]);
        fflush(stdout);         //flushes any buffered output
        char word_input[50];    
        scanf("%s", word_input);
        if(strcmp(word_input, words[rand_index]) == 0)
            correct_words++;
        else
            incorrect_words++;
    }

    clock_t end = clock();
    time_taken = (double)(end-start)/CLOCKS_PER_SEC;
    double wpm = (double)correct_words*6/time_taken;  //average word length = 6 letters

    printf("\nResults:\n=======\n");
    printf("Words typed correctly: %d\n", correct_words);
    printf("Words typed incorrectly: %d\n", incorrect_words);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f WPM\n", wpm);

    if(wpm < 30.0)
        printf("You are now a zombie, please report to the nearest outpost for processing...");
    else
        printf("Congratulations! You have survived the post-apocalyptic typing test!");

    return 0;
}