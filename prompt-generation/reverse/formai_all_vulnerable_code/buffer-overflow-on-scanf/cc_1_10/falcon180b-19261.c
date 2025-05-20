//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char words[][10] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

int main() {
    int i, j, k, l, score = 0, correct = 0, wrong = 0, total = 0;
    char input[100];
    FILE *fp;
    time_t start, end;
    
    srand(time(NULL));
    int rand_index = rand() % 9;
    char *rand_word = words[rand_index];

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following sentence:\n");
    printf("%s\n", rand_word);
    printf("Press enter to begin...\n");
    scanf("%c", &input[0]);

    start = clock();

    for (i = 0; words[i][0]!= '\0'; i++) {
        if (strcmp(rand_word, words[i]) == 0) {
            j = i;
            break;
        }
    }

    for (k = 0; words[j][k]!= '\0'; k++) {
        printf("*");
        total++;
    }

    printf("\n");

    while (1) {
        fflush(stdin);
        scanf("%c", &input[0]);

        if (input[0] == '\n') {
            end = clock();
            double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken: %lf seconds\n", time_taken);
            printf("Words per minute: %d\n", (total / time_taken) * 60);
            break;
        }

        if (input[0] == words[j][k]) {
            correct++;
            k++;
        } else {
            wrong++;
            k = 0;
        }

        if (k == strlen(words[j])) {
            k = 0;
            j++;
            if (j == 9) {
                score = 100;
                break;
            }
        }

        total++;
    }

    if (score == 0) {
        score = (100 * correct) / total;
    }

    printf("Your final score is: %d%%\n", score);

    return 0;
}