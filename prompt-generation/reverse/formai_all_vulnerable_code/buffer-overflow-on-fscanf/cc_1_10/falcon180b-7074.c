//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, correct = 0, incorrect = 0;
    char word[100], input[100];
    FILE *file;

    srand(time(NULL));
    int rand_num = rand() % 3 + 1; // 1-3 random number of words

    switch(rand_num) {
        case 1:
            file = fopen("words1.txt", "r");
            break;
        case 2:
            file = fopen("words2.txt", "r");
            break;
        case 3:
            file = fopen("words3.txt", "r");
            break;
    }

    if(file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%s", word);

    printf("Type the following word or phrase:\n");
    printf("%s\n", word);

    fgets(input, sizeof(input), stdin);

    if(strcmp(input, word) == 0) {
        correct++;
    } else {
        incorrect++;
    }

    while(fscanf(file, "%s", word)!= EOF) {
        if(strcmp(word, "")!= 0) {
            printf("Type the following word or phrase:\n");
            printf("%s\n", word);

            fgets(input, sizeof(input), stdin);

            if(strcmp(input, word) == 0) {
                correct++;
            } else {
                incorrect++;
            }
        }
    }

    score = (correct * 100) / (correct + incorrect);

    printf("\nYour final score is: %d%%\n", score);

    fclose(file);
    return 0;
}