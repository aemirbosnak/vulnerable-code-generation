//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int correct = 0;
int incorrect = 0;

int typing_test(char word[], int size) {
    char input[size];
    int time_taken, i;

    printf("Type the following word: %s\n", word);
    clock_t tic = clock();
    
    for (i = 0; i < size; i++) {
        scanf("%c", &input[i]);

        if (input[i] == '\n') {
            printf("Entered word: ");
            for (i = 0; i < size; i++) {
                printf("%c", input[i]);
            }
            printf("\n");
            break;
        }

        if (input[i] != word[i]) {
            incorrect++;
        } else {
            correct++;
        }
    }

    clock_t toc = clock();
    time_taken = (int)(toc - tic) * 1000 / CLOCKS_PER_SEC;
    printf("Time taken: %d ms\n", time_taken);

    printf("Accuracy: %d/%d\n", correct, correct+incorrect);
    printf("---------------------------\n\n");

    char another;
    printf("Do you want to take the test again? (y/n): ");
    scanf(" %c", &another);

    if (another == 'y' || another == 'Y') {
        correct = 0;
        incorrect = 0;
        return typing_test(word, size);
    } else {
        return 0;
    }
}

int main() {
    char word1[] = "Hello";
    char word2[] = "World";
    char word3[] = "Programming";
    char word4[] = "Recursive";
    char word5[] = "Typing";
    char word6[] = "Speed";
    char word7[] = "Test";
    char words[][11] = { word1, word2, word3, word4, word5, word6, word7 };

    srand(time(NULL));
    int random = rand() % 7;
    int size = sizeof(words[random]) / sizeof(char);

    typing_test(words[random], size);

    return 0;
}