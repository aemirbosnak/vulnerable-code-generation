//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(char* arr, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int totalTime = 60;
    int currTime = totalTime;
    char s[] = "The quick brown fox jumps over the lazy dog";
    int len = strlen(s);
    char shuffled[len + 1];
    strcpy(shuffled, s);
    shuffle(shuffled, len);

    printf("Type the following paragraph as fast as you can:\n\n%s\n\n", shuffled);
    printf("Timer starts now! You have %d seconds...\n", totalTime);

    time_t start, end;
    double timeTaken;
    int index = 0, mistake = 0;
    char c;
    time(&start);

    while (currTime >= 0) {
        printf("Time remaining: %d seconds\n", currTime);
        c = getchar();
        if (c == shuffled[index]) {
            index++;
            printf("%c", c);
            if (index == len) {
                printf("\n\nCongratulations! You typed it correctly.\n");
                break;
            }
        } else {
            printf("\a"); // Sound alert for mistake
            mistake++;
        }
        time(&end);
        timeTaken = difftime(end, start);
        currTime = totalTime - (int) timeTaken;
    }

    printf("\nTime taken: %.2lf seconds\n", timeTaken);
    printf("Total mistakes: %d\n", mistake);
    return 0;
}