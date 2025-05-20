//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int words_typed, correct_words, wrong_words, total_words;
    float speed, accuracy;
    char word[100];
    FILE *file;
    time_t start, end;
    char filename[100];
    int choice;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    time(&start);
    words_typed = 0;
    correct_words = 0;
    wrong_words = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        printf("%s ", word);
        fflush(stdout);
        if (fgets(word, sizeof(word), stdin) == NULL) {
            printf("\n");
            exit(1);
        }
        if (strcmp(word, word) == 0) {
            correct_words++;
        } else {
            wrong_words++;
        }
        words_typed++;
    }

    time(&end);
    speed = (float)words_typed / (end - start);
    accuracy = (float)correct_words / words_typed;

    printf("\nTest Results:\n");
    printf("Words Typed: %d\n", words_typed);
    printf("Correct Words: %d\n", correct_words);
    printf("Wrong Words: %d\n", wrong_words);
    printf("Total Words: %d\n", total_words);
    printf("Speed: %.2f wpm\n", speed);
    printf("Accuracy: %.2f %%\n", accuracy * 100);

    printf("\nDo you want to save the results to a file? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *result_file;
        result_file = fopen("result.txt", "w");
        fprintf(result_file, "Words Typed: %d\n", words_typed);
        fprintf(result_file, "Correct Words: %d\n", correct_words);
        fprintf(result_file, "Wrong Words: %d\n", wrong_words);
        fprintf(result_file, "Total Words: %d\n", total_words);
        fprintf(result_file, "Speed: %.2f wpm\n", speed);
        fprintf(result_file, "Accuracy: %.2f %%\n", accuracy * 100);
        fclose(result_file);
        printf("\nResults saved to result.txt!\n");
    } else {
        printf("\nResults not saved.\n");
    }

    return 0;
}