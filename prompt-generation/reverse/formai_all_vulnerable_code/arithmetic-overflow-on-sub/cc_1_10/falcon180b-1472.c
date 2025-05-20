//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 50

char *words[NUM_WORDS] = {
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "kiwi",
    "lemon",
    "mango",
    "nectarine",
    "orange",
    "pear",
    "quince",
    "raspberry",
    "strawberry",
    "tangerine",
    "watermelon",
    "xylophone",
    "yogurt",
    "zeppelin",
    "cat",
    "dog",
    "elephant",
    "giraffe",
    "hippopotamus",
    "iguana",
    "jaguar",
    "kangaroo",
    "lion",
    "monkey",
    "newt",
    "ostrich",
    "penguin",
    "quail",
    "rabbit",
    "snake",
    "tiger",
    "unicorn",
    "vulture",
    "walrus",
    "xerus",
    "yak",
    "zebra"
};

int main() {
    srand(time(NULL));
    int index = rand() % NUM_WORDS;
    char *word = words[index];
    printf("Type the following word as fast as you can:\n");
    printf("%s\n", word);

    int start_time = clock();
    while (1) {
        char c = getchar();
        if (c == '\n') {
            int end_time = clock();
            int elapsed_time = end_time - start_time;
            printf("You typed '%s' in %d milliseconds.\n", word, elapsed_time);
            break;
        }
        if (c!= word[strlen(word) - 1]) {
            printf("Incorrect letter! Please try again.\n");
            break;
        }
        word = word + strlen(word) - 1;
    }

    return 0;
}