//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

char wordList[MAX][10] = {
    "apple",
    "banana",
    "orange",
    "grape",
    "watermelon",
    "kiwi",
    "mango",
    "peach",
    "cherry",
    "pineapple",
    "papaya",
    "strawberry",
    "blueberry",
    "raspberry",
    "blackberry",
    "pear",
    "apricot",
    "avocado",
    "fig",
    "pomegranate",
    "lemon",
    "lime",
    "coconut",
    "passionfruit",
    "guava",
    "melon",
    "nectarine"
};

int main()
{
    srand(time(0));
    int i, j, count = 0;
    char input[20];

    printf("--- Typing Speed Test ---\n\n");
    printf("Type in the following words:\n\n");

    for (i = 0; i < 10; i++) {
        j = rand() % MAX;
        printf("%s\n", wordList[j]);

        scanf("%s", input);
        if (!strcmp(input, wordList[j])) {
            printf("Correct!\n\n");
            count++;
        } else {
            printf("Wrong!\n\n");
        }
    }

    int score = count * 10;
    printf("You typed %d words correctly in 10 tries.\n", count);
    printf("Your typing speed is %d wpm!\n", score);

    return 0;
}